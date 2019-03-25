// test_shape.cpp
//

#include <memory>

#include "catch.hpp"
#include "../CPS/shape.h"
#include "../CPS/compoundshape.h"

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
    std::vector<CompoundShape::Shape_ptr> v1;
    std::vector<CompoundShape::Shape_ptr> v2;
    v2.push_back(std::make_unique<Circle>());
    std::vector<CompoundShape::Shape_ptr> v3;
    v3.push_back(std::make_unique<Circle>(10));
    std::vector<CompoundShape::Shape_ptr> v4;
    v4.push_back(std::make_unique<Circle>(10));
    v4.push_back(std::make_unique<Circle>(15));

    auto layered1 = std::make_unique<LayeredShapes>(std::move(v1));
    auto layered2 = std::make_unique<LayeredShapes>(std::move(v2));
    auto layered3 = std::make_unique<LayeredShapes>(std::move(v3));
    auto layered4 = std::make_unique<LayeredShapes>(std::move(v4));

    int diameter1{0};
    int diameter2{0};
    int diameter3{20};
    int diameter4{30};

	SECTION("Width")
	{
		REQUIRE(layered1->get_width() == diameter1);
        REQUIRE(layered2->get_width() == diameter2);
        REQUIRE(layered3->get_width() == diameter3);
        REQUIRE(layered4->get_width() == diameter4);
	}

	SECTION("Height")
	{
		REQUIRE(layered1->get_height() == diameter1);
        REQUIRE(layered2->get_height() == diameter2);
        REQUIRE(layered3->get_height() == diameter3);
        REQUIRE(layered4->get_height() == diameter4);
	}

    SECTION("Code Generation")
    {
        REQUIRE(layered1->generate().str() == "");
        REQUIRE(layered2->generate().str() == "0 0 0 0 360 arc stroke\n");
        REQUIRE(layered3->generate().str() == "0 0 10 0 360 arc stroke\n");
        REQUIRE(layered4->generate().str() == "0 0 10 0 360 arc stroke\n0 0 15 0 360 arc stroke\n");
    }
}
