//
// Created by bryant on 4/10/19.
//


#include <fstream>
using std::fstream;
#include <vector>
using std::vector;
#include <memory>
using std::make_unique;
using std::move;

#include <iostream>

#include "../cps/cps.hpp"
using namespace cps;

int main() {
    auto fileName{"hw5.ps"};
    fstream file(fileName, fstream::out);

    file << START_FILE;

    file << Spacer(4*INCH, 4*INCH).generate().str();

    {
        auto shapes = vector<Shape::Shape_ptr>();
        shapes.push_back(make_unique<Triangle>(INCH));
        shapes.push_back(make_unique<Square>(INCH));
        shapes.push_back(make_unique<Polygon>(5, INCH));
        shapes.push_back(make_unique<Polygon>(6, INCH));
        shapes.push_back(make_unique<Polygon>(7, INCH));

        LayeredShapes column(move(shapes));

        file << column.generate().str();
    }

    file << Spacer(-3*INCH, -3*INCH).generate().str();
    {
        auto shapes = vector<Shape::Shape_ptr>();
        shapes.push_back(make_unique<Triangle>(INCH));
        shapes.push_back(make_unique<Square>(INCH));
        shapes.push_back(make_unique<Polygon>(5, INCH));
        shapes.push_back(make_unique<Polygon>(6, INCH));
        shapes.push_back(make_unique<Polygon>(7, INCH));

        HorizontalShapes column(move(shapes));

        file << column.generate().str();
    }

    file << Spacer(0, 1*INCH).generate().str();

    {
        auto shapes = vector<Shape::Shape_ptr>();
        shapes.push_back(make_unique<Triangle>(INCH));
        shapes.push_back(make_unique<Square>(INCH));
        shapes.push_back(make_unique<Polygon>(5, INCH));
        shapes.push_back(make_unique<Polygon>(6, INCH));
        shapes.push_back(make_unique<Polygon>(7, INCH));

        VerticalShapes column(move(shapes));

        file << column.generate().str();
    }

    file << Spacer(-5*INCH, -5*INCH).generate().str();



    file << SHOWPAGE;

    return 0;
}