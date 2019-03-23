//
// Created by Mark, Bryant and Jacob on 3/20/2019.
//

#include "shape.h"

int Shape::get_height() const 
{
    return _height;
}

int Shape::get_width() const
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

void Circle::setRadius(int radius)
{
    set_height(radius);
    set_width(radius);
}

Circle::Circle(int radius)
{
    setRadius(radius);
}

std::stringstream Circle::generate()
{
    return std::stringstream("0 0 " + std::to_string(get_height()) + " 0 360 arc stroke");
}

