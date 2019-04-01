// example.cpp

#include <fstream>
using std::fstream;

//#include "../cps/cps.hpp"

int main() {
    auto fileName{"test.ps"};
    fstream file(fileName, std::fstream::out);

    file << "%!PS\n";

    file << "showpage\n";
}