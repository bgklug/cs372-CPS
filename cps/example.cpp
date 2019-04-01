#include <fstream>
#include <memory>
using std::unique_ptr;
using std::make_unique;
using std::move;

#include <vector>
using std::vector;

#include "shape.hpp"
#include "compoundshape.hpp"

int main(){

    auto circ1 = make_unique<cps::Circle>(36);
    auto inch_space = make_unique<cps::Spacer>(72, 72);
    auto center_space = make_unique<cps::Spacer>(612, 360);

    vector<unique_ptr<cps::Shape>> shape_list(move(center_space), move(circ1));

    auto circle_centered = make_unique<cps::VerticalShapes>(shape_list);

    std::ofstream example_file ("example.ext", std::ofstream::out);

    example_file << "%!\n";
    example_file << circle_centered->generate();
    example_file << "showpage\n";

    example_file.close();

    return 0;
}
