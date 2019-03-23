//
// Created by Mark, Bryant and Jacob on 3/20/2019.
//

#include "compoundshape.h"

using std::vector;
using std::for_each;
using std::stringstream;

CompoundShape::CompoundShape(const vector<Shape_ptr> &shapes)
	: _shapes{shapes}
{}

size_t CompoundShape::CompoundShape::get_numShapes() const
{
	return _shapes.size();
}

auto CompoundShape::begin()
{
	return _shapes.begin();
}
auto CompoundShape::end()
{
	return _shapes.end();
}
auto CompoundShape::begin() const
{
	return _shapes.begin();
}
auto CompoundShape::end() const
{
	return _shapes.end();
}

LayeredShapes::LayeredShapes(const vector<Shape_ptr> &shapes)
	: CompoundShape(shapes)
{}

int LayeredShapes::get_height() const
{
	auto maxHeight{0};
	for_each(begin(), end(),
		[&maxHeight](Shape_ptr shape)
		{
			if (shape->get_height() > maxHeight) {
				maxHeight = shape->get_height();
			}
		}
	);
	return maxHeight;
}

int LayeredShapes::get_width() const
{
	auto maxWidth{0};
	for_each(begin(), end(),
		[&maxWidth](Shape_ptr shape)
		{
			if (shape->get_width() > maxWidth) {
				maxWidth = shape->get_width();
			}
		}
	);
	return maxWidth;
}

stringstream LayeredShapes::generate() const
{
	stringstream postScriptFragment;

	return postScriptFragment;
}

