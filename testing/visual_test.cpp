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
    auto fileName{"visual_test.ps"};
    fstream file(fileName, fstream::out);

    file << START_FILE;

    file << Spacer(4*INCH, 4*INCH).generate();

    file << Triangle(1).generate();

    { // 3x3 grid
        auto shapes = vector<Shape::Shape_ptr>();
        shapes.push_back(make_unique<Triangle>(INCH));
        shapes.push_back(make_unique<Square>(INCH));
        shapes.push_back(make_unique<Polygon>(5, INCH));
        shapes.push_back(make_unique<Polygon>(6, INCH));
        shapes.push_back(make_unique<Polygon>(7, INCH));
        shapes.push_back(make_unique<Polygon>(8, INCH));

        LayeredShapes column(move(shapes));

        file << column.generate();
    }


    file << SHOWPAGE;

    return 0;
}