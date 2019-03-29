//
// Created by Mark, Bryant and Jacob on 3/20/2019.
//

#ifndef CS372_CPS_COUMPOUNDSHAPE_H
#define CS372_CPS_COUMPOUNDSHAPE_H

#include <memory>
#include <sstream>
#include <vector>

#include "shape.h"

class CompoundShape: public Shape {
public:
	using Shape_ptr = std::unique_ptr<Shape>;
	using iterator = std::vector<Shape_ptr>::iterator;
	using const_iterator = std::vector<Shape_ptr>::const_iterator;
	CompoundShape(std::vector<Shape_ptr> shapes);
	virtual ~CompoundShape()=default;

	double get_height() const=0;
	double get_width() const=0;
	void set_height(double height)=delete;
	void set_width(double width)=delete;

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
	LayeredShapes(std::vector<Shape_ptr> shapes = {});

	double get_height() const override;
	double get_width() const override;

	std::stringstream generate();
private:

};

class HorizontalShapes: public CompoundShape {
public:
	HorizontalShapes(std::vector<Shape_ptr> shapes = {});

	double get_height() const override;
	double get_width() const override;

	std::stringstream generate();
private:

};

#endif //CS372_CPS_COUMPOUNDSHAPE_H
