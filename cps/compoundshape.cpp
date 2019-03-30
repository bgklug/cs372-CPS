//
// Created by Mark, Bryant and Jacob on 3/20/2019.
//

#include "compoundshape.h"

using std::vector;
using std::stringstream;
using std::move;

CompoundShape::CompoundShape(vector<Shape_ptr> shapes)
	: _shapes(move(shapes))
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

LayeredShapes::LayeredShapes(vector<Shape_ptr> shapes)
	: CompoundShape(move(shapes))
{}

double LayeredShapes::get_height() const
{
	auto maxHeight{0};
	for (auto shape = begin(); shape != end(); ++shape)
	{
		if ((*shape)->get_height() > maxHeight) {
			maxHeight = (*shape)->get_height();
		}
	}
	return maxHeight;
}

double LayeredShapes::get_width() const
{
	auto maxWidth{0};
	for (auto shape = begin(); shape != end(); ++shape)
	{
		if ((*shape)->get_width() > maxWidth) {
			maxWidth = (*shape)->get_width();
		}
	};
	return maxWidth;
}

stringstream LayeredShapes::generate()
{
	stringstream postScriptFragment;

	return postScriptFragment;
}

Scaled::Scaled(std::unique_ptr<Shape>, int)
{

}

std::stringstream Scaled::generate()
{
    return std::stringstream();
}
