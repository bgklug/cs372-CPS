// test_shape.cpp
//

#include <memory>

#include "catch.hpp"
#include "../CPS/shape.h"
#include "../CPS/compoundshape.h"

TEST_CASE("Circle")
{
    Circle c1;
//    Circle c2(1.0);
//    Circle c3(10.0);
//    Circle c4(1000.0);

    SECTION("Getters")
    {
        REQUIRE(c1.get_height() == 0);
        REQUIRE(c1.get_width() == 0);
    }

    SECTION("Setters")
    {

    }

    SECTION("Code Generation")
    {

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
