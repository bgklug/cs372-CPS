//
// Created by Mark, Bryant and Jacob on 3/20/2019.
//

#ifndef CS372_CPS_COUMPOUNDSHAPE_H
#define CS372_CPS_COUMPOUNDSHAPE_H

#include <algorithm>
using std::for_each;
#include <vector>;
using std::vector;
#include "shape.h"

class CompoundShape: public Shape {
public:
	CompoundShape(const vector<Shape*> &shapes);
	virtual ~CompoundShape()=default;

	int get_width() const override;
	int get_height() const override;
	void set_width(int width);
	void set_height(int width);
private:
	vector<Shape*> _shapes;
};

class VirticalShapes: public CompoundShape {
public:

private:

};

#endif //CS372_CPS_COUMPOUNDSHAPE_H
