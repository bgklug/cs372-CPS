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

