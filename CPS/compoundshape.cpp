//
// Created by Mark, Bryant and Jacob on 3/20/2019.
//

#include "compoundshape.h"

CompoundShape::CompoundShape(const vector<Shape*> &shapes)
	: _shapes = shapes
{}

int CompoundShape::get_width() const
{
	// auto total = 0;
	// for_each(_shapes.begin(), _shapes.end(),
	// 	[total](Shape shape){total += shape->get_width()});
	// return total;
}
int CompoundShape::get_height() const
{

}