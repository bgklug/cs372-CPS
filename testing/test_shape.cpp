// test_shape.cpp
//

#include "catch.hpp"
#include "../CPS/shape.h"


TEST_CASE("Circle")
{
    Circle c1;

    SECTION("Getters")
    {
        REQUIRE(c1.get_height() == 0);
        REQUIRE(c1.get_width() == 0);
    }

    SECTION("Single-Parameter Constructor")
    {
        Circle c2(1);
        REQUIRE(c2.get_height() == 1);
        REQUIRE(c2.get_width() == 1);
    }

    SECTION("Code Generation")
    {

    }
}

