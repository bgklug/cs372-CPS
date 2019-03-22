//
// Created by Mark, Bryant and Jacob on 3/20/2019.
//

#ifndef CS372_CPS_SHAPE_H
#define CS372_CPS_SHAPE_H


class Shape
{
public:
//    Shape(){}

//    ~Shape(){}

    const int getHeight();
    const int getWidth();
    virtual void generate()=0;

private:
    int _height { 0 };
    int _width { 0 };
};

class Circle : public Shape
{
public:
    Circle() = default;

    void generate(){};
private:
};

#endif //CS372_CPS_SHAPE_H
