// example.cpp

#include <fstream>
using std::fstream;
#include <vector>
using std::vector;
#include <memory>
using std::make_unique;
using std::move;

#include <iostream>

#include "../../cps/cps.hpp"
using namespace cps;

int main() {
    auto fileName{"test.ps"};
    fstream file(fileName, fstream::out);

    file << START_FILE;

    file << Spacer(4*INCH, 1*INCH).generate().str();
    file << Skyline(10).generate().str();

    file << Spacer(-1*INCH, 3*INCH).generate().str();

    { // 3x3 grid
        auto rectangles = vector<Shape::Shape_ptr>();
        rectangles.push_back(make_unique<Rectangle>(INCH, INCH));
        rectangles.push_back(make_unique<Rectangle>(INCH, INCH));
        VerticalShapes column(move(rectangles));
        column.pushShape(make_unique<Rectangle>(INCH, INCH));
        
        file << column.generate().str();
        file << Spacer(INCH, 0).generate().str();
        file << column.generate().str();
        file << Spacer(INCH, 0).generate().str();
        file << column.generate().str();
    }

    file << Spacer(-1*INCH, -2*INCH).generate().str();

    Circle c1(0.5*INCH);
    file << Scaled(c1, {1, 1}).generate().str();
    file << Scaled(c1, {2, 1}).generate().str();
    file << Scaled(c1, {4, 1}).generate().str();
 
    file << Spacer(-1*INCH, 6*INCH).generate().str();

    HorizontalShapes horizontal;
    horizontal.pushShape(make_unique<Square>(INCH));
    horizontal.pushShape(make_unique<Circle>(INCH));
    file << Scaled(horizontal, {2, 1}).generate().str();

    file << SHOWPAGE;

    return 0;
}