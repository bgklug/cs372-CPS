// test_shape.cpp
//

#include <memory>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::make_unique;

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

        REQUIRE(c4.get_height() == 21.8);
        REQUIRE(c4.get_width() == 21.8);
    }

    SECTION("PostScript Generation")
    {
        string testCircle1 = "0 0 1.000000 0 360 arc stroke";
        string testCircle2 = "0 0 10000.000000 0 360 arc stroke";
        string testCircle3 = "0 0 10.900000 0 360 arc stroke";
        REQUIRE(c2.generate().str() == testCircle1);
        REQUIRE(c3.generate().str() == testCircle2);
        REQUIRE(c4.generate().str() == testCircle3);
    }
}

TEST_CASE("Polygon","[polygon]")
{
    SECTION("Triangle")
    {
        Polygon t(3,100);
        REQUIRE(t.get_width() == 100);
    }
    SECTION("Draw triangle")
    {
        Polygon t(3, 100);

        REQUIRE( t.generate().str() == "%!\n" \
            "newpath\n" \
            "/length 100.000000 def\n" \
            "/nSides 3.000000 def\n" \
            "/angle { 360 nSides div } def\n" \
            "gsave\n" \
            "newpath\n" \
            "0 0 moveto\n" \
            "0 angle 360 {\n" \
            "length 0 lineto\n" \
            "length 0 translate\n" \
            "angle rotate\n" \
            "} for\n" \
            "closepath\n" \
            "stroke\n" \
            "grestore\n" \
            "showpage\n");

    }
}

TEST_CASE("Layered Shape")
{
    vector<CompoundShape::Shape_ptr> v2;
    v2.push_back(make_unique<Circle>(10));
    vector<CompoundShape::Shape_ptr> v3;
    v3.push_back(make_unique<Circle>(10));
    v3.push_back(make_unique<Rectangle>(10, 25));

    auto layered1 = make_unique<LayeredShapes>();
    auto layered2 = make_unique<LayeredShapes>(move(v2));
    auto layered3 = make_unique<LayeredShapes>(move(v3));

	SECTION("Width")
	{
		REQUIRE(layered1->get_width() == 0);
		REQUIRE(layered2->get_width() == 20);
		REQUIRE(layered3->get_width() == 20);
	}

	SECTION("Height")
	{
		REQUIRE(layered1->get_height() == 0);
		REQUIRE(layered2->get_height() == 20);
		REQUIRE(layered3->get_height() == 25);
    }

    SECTION("Generate")
    {
		REQUIRE(layered1->generate().str() == "");
    }
}

TEST_CASE("Horizontal Shape")
{
    vector<CompoundShape::Shape_ptr> v2;
    v2.push_back(make_unique<Circle>(10));
    vector<CompoundShape::Shape_ptr> v3;
    v3.push_back(make_unique<Circle>(10));
    v3.push_back(make_unique<Rectangle>(10, 25));

    auto horizontal1 = make_unique<LayeredShapes>();
    auto horizontal2 = make_unique<LayeredShapes>(move(v2));
    auto horizontal3 = make_unique<LayeredShapes>(move(v3));

	SECTION("Width")
	{
		REQUIRE(horizontal1->get_width() == 0);
		REQUIRE(horizontal2->get_width() == 20);
		REQUIRE(horizontal3->get_width() == 20);
	}
	SECTION("Height")
	{
		REQUIRE(horizontal1->get_height() == 0);
		REQUIRE(horizontal2->get_height() == 20);
		REQUIRE(horizontal3->get_height() == 25);
	}
	SECTION("PostScript Generation")
	{
		REQUIRE(horizontal1->generate().str() == "");
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

        REQUIRE(r3.get_height() == 20.1);
        REQUIRE(r3.get_width() == 10);

        REQUIRE(r4.get_height() == 400000);
        REQUIRE(r4.get_width() == 10000);
    }

    SECTION("PostScript Generation")
    {
        REQUIRE(r2.generate().str() == "newpath\n"
                                       "-0.500000 -2.500000 moveto\n"
                                       "1.000000 0 rlineto\n"
                                       "0 5.000000 rlineto\n"
                                       "-1.000000 0 rlineto\n"
                                       "closepath\n"
                                       "stroke");

        REQUIRE(r3.generate().str() == "newpath\n"
                                       "-5.000000 -10.050000 moveto\n"
                                       "10.000000 0 rlineto\n"
                                       "0 20.100000 rlineto\n"
                                       "-10.000000 0 rlineto\n"
                                       "closepath\n"
                                       "stroke");

        REQUIRE(r4.generate().str() == "newpath\n"
                                       "-5000.000000 -200000.000000 moveto\n"
                                       "10000.000000 0 rlineto\n"
                                       "0 400000.000000 rlineto\n"
                                       "-10000.000000 0 rlineto\n"
                                       "closepath\n"
                                       "stroke");

    }
}
