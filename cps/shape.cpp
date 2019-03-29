//
// Created by Mark, Bryant and Jacob on 3/20/2019.
//

#include "shape.h"

// Base Class
double Shape::get_height() const
{
    return _height;
}

double Shape::get_width() const
{
    return _width;
}

void Shape::set_height(double height)
{
    _height = height;
}

void Shape::set_width(double width)
{
    _width = width;
}

// Circle Class
void Circle::setRadius(double radius)
{
    set_height(radius*2);
    set_width(radius*2);
}

Circle::Circle(double radius)
{
    setRadius(radius);
}

std::stringstream Circle::generate()
{
    return std::stringstream("0 0 " + std::to_string(get_height()/2) + " 0 360 arc stroke");
}

// Rectangle Class
std::stringstream Rectangle::generate()
{
    return std::stringstream("newpath\n"
                             + std::to_string(-1*get_width()/2) + " " + std::to_string(-1*get_height()/2) + " moveto\n"
                             + std::to_string(get_width()) + " 0 rlineto\n"
                             + "0 " + std::to_string(get_height()) + " rlineto\n"
                             + std::to_string(-1*get_width()) + " 0 rlineto\n"
                             "closepath\n"
                             "stroke");
}

Rectangle::Rectangle(double width, double height)
{
    set_height(height);
    set_width(width);
}
