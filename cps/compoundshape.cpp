//
// Created by Mark, Bryant and Jacob on 3/20/2019.
//

#include "compoundshape.h"

using std::vector;
using std::stringstream;
using std::move;
using std::to_string;

CompoundShape::CompoundShape(vector<Shape_ptr> shapes)
	: _shapes(move(shapes))
{}

void CompoundShape::pushShape(Shape_ptr shape)
{
	_shapes.push_back(move(shape));
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

	for (auto shape = begin(); shape != end(); ++shape)
	{
		postScriptFragment << (*shape)->generate().str() << "\n";
	}

	return postScriptFragment;
}

Rotated::Rotated(std::unique_ptr<Shape> shape, int degrees) : _rotation{degrees}
{
    if(degrees == 90 || degrees == 270)
    {
        set_height(shape->get_width());
        set_width(shape->get_height());
    }
    else
    {
        set_width(shape->get_width());
        set_height(shape->get_height());
    }

    _originalShape = std::move(shape);
}

std::stringstream Rotated::generate()
{
    return std::stringstream ("gsave\n"
                              + std::to_string(_rotation) + " rotate\n"
                              + _originalShape->generate().str()
                              + "grestore\n");
}
