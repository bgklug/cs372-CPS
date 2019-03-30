//
// Created by Mark, Bryant and Jacob on 3/20/2019.
//

#ifndef CS372_CPS_COMPOUNDSHAPE_H
#define CS372_CPS_COMPOUNDSHAPE_H

#include <memory>
#include <sstream>
#include <vector>

#include "shape.h"

class CompoundShape: public Shape {
public:
	using Shape_ptr = std::unique_ptr<Shape>;

	explicit CompoundShape(std::vector<Shape_ptr> shapes);
	virtual ~CompoundShape()=default;

	virtual double get_height() const=0;
	virtual double get_width() const=0;
	void set_height(double height)=delete;
	void set_width(double width)=delete;

	void pushShape(Shape_ptr shape);

	auto begin();
	auto end();
	auto begin() const;
	auto end() const;
private:
	std::vector<Shape_ptr> _shapes;
};

class LayeredShapes: public CompoundShape {
public:
	explicit LayeredShapes(std::vector<Shape_ptr> shapes = {});

	double get_height() const override;
	double get_width() const override;

	std::stringstream generate();
private:

};

class Rotated : public Shape
{
public:
    Rotated(std::unique_ptr<Shape>, int);
    std::stringstream generate() override;
private:
   std::unique_ptr<Shape> _originalShape;
   int _rotation;
};

#endif //CS372_CPS_COMPOUNDSHAPE_H
