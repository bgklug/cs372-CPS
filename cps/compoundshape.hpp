//
// Created by Mark, Bryant and Jacob on 3/20/2019.
//

#ifndef CS372_CPS_COMPOUNDSHAPE_H
#define CS372_CPS_COMPOUNDSHAPE_H

#include <vector>

#include "shape.h"

namespace cps {

class CompoundShape: public Shape {
public:
	using iterator = std::vector<Shape_ptr>::iterator;
	using const_iterator = std::vector<Shape_ptr>::const_iterator;

	explicit CompoundShape(std::vector<Shape_ptr> shapes);

	virtual ~CompoundShape()=default;

	virtual double get_height() const override=0;
	virtual double get_width() const override=0;
	void set_height(double height) override {};
	void set_width(double width) override {};

	void pushShape(Shape_ptr shape);
	size_t get_numShapes() const;
	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;
private:
	std::vector<Shape_ptr> _shapes;
};

class LayeredShapes: public CompoundShape {
public:
	explicit LayeredShapes(std::vector<Shape_ptr> shapes = {});

	double get_height() const override;
	double get_width() const override;

	std::stringstream generate() override;
private:

};

class HorizontalShapes: public CompoundShape {
public:
	explicit HorizontalShapes(std::vector<Shape_ptr> shapes = {});

	double get_height() const override;
	double get_width() const override;

	std::stringstream generate() override;
private:

};

class VerticalShapes: public CompoundShape {
public:
	explicit VerticalShapes(std::vector<Shape_ptr> shapes = {});

	double get_height() const override;
	double get_width() const override;

	std::stringstream generate() override;
private:

};

}

#endif //CS372_CPS_COMPOUNDSHAPE_H
