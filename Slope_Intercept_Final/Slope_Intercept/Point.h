// file: Point.h
// by: Ben Heins
// org: 2001, 202101, 10409
// desc: declaration of the point class object
// ----------------------------------------------------

#ifndef POINT_H
#define POINT_H

#include "fgcugl.h"

class Point {
public:
	Point();
	Point(float X, float Y);

	//getters
	float getXCoordinate();
	float getYCoordinate();

	//setters 
	void setXCoordinate(float value);
	void setYCoordinate(float value);




private:
	float XPosition;
	float YPosition;
};

#endif //POINT_H