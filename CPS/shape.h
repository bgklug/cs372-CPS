//
// Created by Mark, Bryant and Jacob on 3/20/2019.
//

#ifndef CS372_CPS_SHAPE_H
#define CS372_CPS_SHAPE_H

#include <sstream>
#include <cmath>


class Shape
{
public:
    int get_height() const;
    int get_width() const;
    void set_height(int height);
    void set_width(int width);

    virtual std::stringstream generate()=0;

private:
    int _height { 0 };
    int _width { 0 };
};


class Circle : public Shape
{
public:
    Circle() = default;

    std::stringstream generate(){};
private:
};


class Polygon : public Shape
{
public:
    ~Polygon() = default;
    Polygon(int, double);

    std::stringstream generate();

private:
    const double pi =  std::acos(-1);
    float _numSides{0};
    float _sideLength{0};
};


#endif //CS372_CPS_SHAPE_H
