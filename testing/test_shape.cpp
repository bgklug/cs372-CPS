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

    Circle c2(1);
    Circle c3(10000);
    Circle c4(10.9);
    SECTION("Single-Parameter Constructor")
    {
        REQUIRE(c2.get_height() == 1);
        REQUIRE(c2.get_width() == 1);

        REQUIRE(c3.get_height() == 10000);
        REQUIRE(c3.get_width() == 10000);

        REQUIRE(c4.get_height() == 10);
        REQUIRE(c4.get_width() == 10);
    }

    SECTION("Code Generation")
    {
        std::string testcircle = "0 0 1 0 360 arc stroke";
        REQUIRE(c2.generate().str() == testcircle);
    }
}

