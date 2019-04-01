//
// Created by Mark, Bryant and Jacob on 3/20/2019.
//

#include "compoundshape.hpp"

namespace cps {

using std::vector;
using std::stringstream;
using std::move;
using std::to_string;

void CompoundShape::pushShape(Shape_ptr shape)
{
	_shapes.push_back(move(shape));
}
size_t CompoundShape::get_numShapes() const {
	return _shapes.size();
}

CompoundShape::iterator CompoundShape::begin()
{
	return _shapes.begin();
}
CompoundShape::iterator CompoundShape::end()
{
	return _shapes.end();
}
CompoundShape::const_iterator CompoundShape::begin() const
{
	return _shapes.begin();
}
CompoundShape::const_iterator CompoundShape::end() const
{
	return _shapes.end();
}

void CompoundShape::setShapes(std::vector<Shape_ptr> shapes)
{
    _shapes = std::move(shapes);
}

//CompoundShape::CompoundShape(std::shared_ptr<CompoundShape> shape)
//{
//    for (auto singleShape = shape->begin(); singleShape < shape->end(); singleShape++)
//    {
//        _shapes.push_back(std::move(*singleShape));
//    }
//}

LayeredShapes::LayeredShapes(vector<Shape_ptr> shapes)
{
    setShapes(std::move(shapes));

    auto maxHeight{0.0};
    for (auto shape = begin(); shape != end(); ++shape)
    {
        if ((*shape)->get_height() > maxHeight) {
            maxHeight = (*shape)->get_height();
        }
    }
    set_height(maxHeight);
}

double LayeredShapes::get_width() const
{
	auto maxWidth{0.0};
	for (auto shape = begin(); shape != end(); ++shape)
	{
		if ((*shape)->get_width() > maxWidth) {
			maxWidth = (*shape)->get_width();
		}
	}
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

HorizontalShapes::HorizontalShapes(std::vector<Shape_ptr> shapes)
{
    setShapes(std::move(shapes));

    auto totalWidth{0.0};
    for (auto shape = begin(); shape != end(); ++shape)
    {
        totalWidth += (*shape)->get_width();
    }
    set_width(totalWidth);
}

double HorizontalShapes::get_height() const
{
	auto maxHeight{0.0};
	for (auto shape = begin(); shape != end(); ++shape)
	{
		if ((*shape)->get_height() > maxHeight) {
			maxHeight = (*shape)->get_height();
		}
	}
	return maxHeight;
}

std::stringstream HorizontalShapes::generate()
{
	stringstream postScriptFragment;
	auto relativeCurrentPoint{0.0};
	for (auto shape = begin(); shape != end(); ++shape)
	{
	    if (shape != begin())
        {
            relativeCurrentPoint += (*shape)->get_width()/2;
			postScriptFragment << std::to_string((*shape)->get_width()/2) << " " << "0 translate\n";
        }
		postScriptFragment << (*shape)->generate().str();
		if (shape + 1 != end()) {
            relativeCurrentPoint += (*shape)->get_width()/2;
			postScriptFragment << std::to_string((*shape)->get_width()/2) << " " << "0 translate\n";
		}
	}
	if (get_numShapes() > 1) {
		postScriptFragment << to_string(-relativeCurrentPoint) << " 0 translate\n";
	}
	return postScriptFragment;
}

VerticalShapes::VerticalShapes(vector<Shape_ptr> shapes)
{
    setShapes(move(shapes));

    auto maxWidth{0.0};
    for (auto shape = begin(); shape != end(); ++shape)
    {
        if ((*shape)->get_width() > maxWidth) {
            maxWidth = (*shape)->get_width();
        }
    }
    set_width(maxWidth);
}

double VerticalShapes::get_height() const
{
	auto totalHeight{0.0};
	for (auto shape = begin(); shape != end(); ++shape)
	{
		totalHeight += (*shape)->get_width();
	}
	return totalHeight;
}

stringstream VerticalShapes::generate()
{
	stringstream postScriptFragment;
	auto relativeCurrentPoint{0.0};
	for (auto shape = begin(); shape != end(); ++shape)
	{
	    if (shape != begin())
        {
            relativeCurrentPoint += (*shape)->get_height()/2;
			postScriptFragment << 0 << " " << to_string((*shape)->get_height()/2) << " translate\n";
        }
		postScriptFragment << (*shape)->generate().str();
		if (shape + 1 != end()) {
			relativeCurrentPoint += (*shape)->get_height()/2;
			postScriptFragment << 0 << " " << to_string((*shape)->get_height()/2) << " translate\n";
		}
	}
	if (get_numShapes() > 1) {
		postScriptFragment << "0 " << to_string(-relativeCurrentPoint) << " translate\n";
	}
	return postScriptFragment;
}

}

Scaled::Scaled(const std::shared_ptr<CompoundShape>& shape, double scaleFactorX, double scaleFactorY)
    : _scaleFactorX{scaleFactorX}, _scaleFactorY{scaleFactorY}, _originalShape{shape}
{
    set_width(shape->get_width()*scaleFactorX);
    set_height(shape->get_height()*scaleFactorY);
}

std::stringstream Scaled::generate()
{
    std::shared_ptr<CompoundShape> scaledShape = _originalShape;
    std::vector<Shape_ptr> newShapes;
    for (auto shape = scaledShape->begin(); shape < scaledShape->end(); shape++)
    {
        (*shape)->set_height((*shape)->get_height()*_scaleFactorY);
        (*shape)->set_width((*shape)->get_width()*_scaleFactorX);
    }

    std::stringstream output;
    output << "gsave" << std::endl;
    output << scaledShape->generate().str();
    output << "grestore" << std::endl;

    return output;
}
