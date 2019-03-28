//
// Created by Mark, Bryant and Jacob on 3/20/2019.
//

#ifndef CS372_CPS_SHAPE_H
#define CS372_CPS_SHAPE_H

#include <sstream>

class Shape
{
public:
    virtual double get_height() const;
    virtual double get_width() const;
    void set_height(double height);
    void set_width(double width);

    virtual std::stringstream generate()=0;

private:
    double _height { 0 };
    double _width { 0 };
};

class Circle : public Shape
{
public:
    Circle() = default;
    explicit Circle(int);

    std::stringstream generate() override;
private:
    void setRadius(int);
};

class Rectangle : public Shape
{
public:
    Rectangle() = default;
    Rectangle(int, int);
    std::stringstream generate() override;
private:
};

#endif //CS372_CPS_SHAPE_H
