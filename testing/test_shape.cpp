// test_shape.cpp
//

#include <memory>
#include <string>
using std::string;

#include "catch.hpp"
#include "../cps/shape.h"
#include "../cps/compoundshape.h"

TEST_CASE("Circle")
{
    Circle c1;
    SECTION("Getters")
    {
        REQUIRE(c1.get_height() == 0);
        REQUIRE(c1.get_width() == 0);
    }

    Circle c2(1);
    Circle c3(10000);
    Circle c4(10.9);
    SECTION("Single-Parameter Constructor")
    {
        REQUIRE(c2.get_height() == 2);
        REQUIRE(c2.get_width() == 2);

        REQUIRE(c3.get_height() == 20000);
        REQUIRE(c3.get_width() == 20000);

        REQUIRE(c4.get_height() == 20);
        REQUIRE(c4.get_width() == 20);
    }

    SECTION("PostScript Generation")
    {
        string testCircle1 = "0 0 1 0 360 arc stroke";
        string testCircle2 = "0 0 10000 0 360 arc stroke";
        string testCircle3 = "0 0 10 0 360 arc stroke";
        REQUIRE(c2.generate().str() == testCircle1);
        REQUIRE(c3.generate().str() == testCircle2);
        REQUIRE(c4.generate().str() == testCircle3);
    }
}


TEST_CASE("Layered Shape")
{
	auto v1 = std::vector<std::unique_ptr<Shape>>();
	v1.push_back(std::make_unique<Circle>());
	
	auto layered1 = std::make_unique<LayeredShapes>(
		std::move(v1)
	);
	SECTION("width")
	{
		REQUIRE(layered1->get_width() == 0);
	}

	SECTION("height")
	{
		REQUIRE(layered1->get_height() == 0);
	}
}


TEST_CASE("Rectangle")
{
    Rectangle r1;
    Rectangle r2(1,5);
    Rectangle r3(10,20.1);
    Rectangle r4(10000,400000);

    SECTION("Getters")
    {
        REQUIRE(r1.get_width() == 0);
        REQUIRE(r1.get_height() == 0);
    }

    SECTION("Two Parameter Constructor")
    {
        REQUIRE(r2.get_height() == 5);
        REQUIRE(r2.get_width() == 1);

        REQUIRE(r3.get_height() == 20);
        REQUIRE(r3.get_width() == 10);

        REQUIRE(r4.get_height() == 400000);
        REQUIRE(r4.get_width() == 10000);
    }

    SECTION("PostScript Generation")
    {
        REQUIRE(r2.generate().str() == "newpath\n"
                                       "0 -2 moveto\n"
                                       "1 0 rlineto\n"
                                       "0 5 rlineto\n"
                                       "-1 0 rlineto\n"
                                       "closepath\n"
                                       "stroke");

        REQUIRE(r3.generate().str() == "newpath\n"
                                       "-5 -10 moveto\n"
                                       "10 0 rlineto\n"
                                       "0 20 rlineto\n"
                                       "-10 0 rlineto\n"
                                       "closepath\n"
                                       "stroke");

        REQUIRE(r4.generate().str() == "newpath\n"
                                       "-5000 -200000 moveto\n"
                                       "10000 0 rlineto\n"
                                       "0 400000 rlineto\n"
                                       "-10000 0 rlineto\n"
                                       "closepath\n"
                                       "stroke");

    }
}