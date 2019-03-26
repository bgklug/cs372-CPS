// test_shape.cpp
//

#include <memory>

#include "catch.hpp"
#include "../CPS/shape.h"
#include "../CPS/compoundshape.h"

using std::vector;
using std::move;
using std::make_unique;

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

    SECTION("Code Generation")
    {
        std::string testCircle1 = "0 0 1 0 360 arc stroke";
        std::string testCircle2 = "0 0 10000 0 360 arc stroke";
        std::string testCircle3 = "0 0 10 0 360 arc stroke";
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

TEST_CASE("Vertical Shape")
{
	auto vertical1 = make_unique<VerticalShapes>();
	auto vertical2 = make_unique<VerticalShapes>();
	vertical2->pushShape(move(make_unique<Circle>(3)));
	SECTION("Width")
	{
		REQUIRE(vertical1->get_width() == 0);
		REQUIRE(vertical2->get_width() == 6);
	}
	SECTION("Height")
	{
		REQUIRE(vertical1->get_height() == 0);
		REQUIRE(vertical2->get_width() == 6);
	}
	SECTION("Generate PostScript")
	{
		REQUIRE(vertical1->generate().str() == "");
		REQUIRE(vertical2->generate().str() == "0 0 3 0 360 arc stroke");
	}
}
