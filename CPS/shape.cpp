//
// Created by Mark, Bryant and Jacob on 3/20/2019.
//

#include "shape.h"
#include <cmath>

const int Shape::get_height()
{
    return _height;
}

const int Shape::get_width()
{
    return _width;
}

void Shape::set_height(int height)
{
    _height = height;
}

void Shape::set_width(int width)
{
    _width = width;
}

Polygon::Polygon(int numSides, int sideLength)
{
    const double pi =  std::acos(-1);

    if(numSides % 2 == 1)
    {
        set_height( sideLength * (1.0 + std::cos(pi / numSides)) / (2.0 * std::sin(pi / numSides)) );
        set_width( (sideLength * std::sin(pi * (numSides - 1) / (2 * numSides))) / std::sin(pi / numSides) );
    }
    else if(numSides % 4 == 0)
    {
        set_height( sideLength * (std::cos(pi / numSides)) / (std::sin(pi / numSides)) );
        set_width( get_height() );
    }
    else
    {
        set_height( sideLength * (std::cos(pi / numSides)) / (std::sin(pi / numSides)) );
        set_width( sideLength / std::sin(pi / numSides) );
    }
}


