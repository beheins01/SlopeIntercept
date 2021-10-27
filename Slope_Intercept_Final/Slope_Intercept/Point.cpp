/**
file: Point.cpp
by: Ben Heins
org: COP 2001, 10409
desc: implementation of the point class object
//---------------------------------------------------------
*/

#include "Point.h"

Point::Point()
{
	XPosition = 0.0;
	YPosition = 0.0;
}

/**
* properties constructor - initialize to parameter values
*/
Point::Point(float X, float Y)
{
	XPosition = X;
	YPosition = Y;
}

// getters
float Point::getXCoordinate() { return XPosition; }
float Point::getYCoordinate() { return YPosition; }

//---------------------------------------------------------

// setters
void Point::setXCoordinate(float value) { XPosition = value; }
void Point::setYCoordinate(float value) { YPosition = value; }



