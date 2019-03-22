// test_shape.cpp
//

#include "catch.hpp"
#include "../CPS/shape.h"


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

