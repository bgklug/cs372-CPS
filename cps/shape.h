//
// Created by Mark, Bryant and Jacob on 3/20/2019.
//

#ifndef CS372_CPS_SHAPE_H
#define CS372_CPS_SHAPE_H

#include <sstream>
#include <cmath>
#include <vector>


class Shape
{
public:
    virtual double get_height() const;
    virtual double get_width() const;

    virtual std::stringstream generate()=0;

protected:
    void set_height(double height);
    void set_width(double width);

private:
    double _height { 0 };
    double _width { 0 };
};


class Circle : public Shape
{
public:
    Circle() = default;
    explicit Circle(double);

    std::stringstream generate() override;
private:
    void setRadius(double);
};

class Rectangle : public Shape
{
public:
    Rectangle() = default;
    Rectangle(double, double);
    std::stringstream generate() override;
private:
};


class Polygon : public Shape
{
public:
    ~Polygon() = default;
    Polygon(int, double);

    std::stringstream generate() override;

private:
    const double pi =  std::acos(-1);
    float _numSides{0};
    float _sideLength{0};
};

class Skyline : public Shape
{
public:
    explicit Skyline(int);

    std::stringstream generate() override;
private:
    struct Building
    {
        double spacing;
        double height;
        double width;
    };

    std::vector<Building> generateBuildings(int);

    std::vector<Building> _buildings;
};


#endif //CS372_CPS_SHAPE_H
