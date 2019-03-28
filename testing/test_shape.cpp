// test_shape.cpp
//
#include <fstream>
using std::ofstream, std::ios;
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
