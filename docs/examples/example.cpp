// example.cpp

#include <fstream>
using std::fstream;
#include <vector>
using std::vector;
#include <memory>
using std::make_unique;
using std::move;

#include "../../cps/cps.hpp"
using namespace cps;

int main() {
    auto fileName{"test.ps"};
    fstream file(fileName, fstream::out);

    file << startfile;

    file << Spacer(inch,inch).generate().str();
    file << Circle(10).generate().str();

    file << Spacer(3*inch, 3*inch).generate().str();

    { // 3x3 grid
        auto rectangles = vector<Shape::Shape_ptr>();
        rectangles.push_back(make_unique<Rectangle>(inch, inch));
        rectangles.push_back(make_unique<Rectangle>(inch, inch));
        VerticalShapes column(move(rectangles));
        column.pushShape(make_unique<Rectangle>(inch, inch));
        
        file << column.generate().str();
        file << Spacer(inch, 0).generate().str();
        file << column.generate().str();
        file << Spacer(inch, 0).generate().str();
        file << column.generate().str();
    }

    file << showpage;

    return 0;
}