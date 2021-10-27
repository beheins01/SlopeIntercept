/**
file: Line.cpp
by: Ben Heins
org: COP 2001, 10409
desc: implementation of the line class object
*/

#include <iostream>

#define _USE_MATH_DEFINES	//enable M_PI
#include <math.h>		// sqrt, pow, atan2, M_PI

#include "Line.h"
#include "Point.h"

Line::Line()
{
	firstVertex;
	secondVertex;
	slope = 0.0;
	yIntercept = 0.0;
	length = 0.0;
	angle = 0.0;

}

/**
* properties constructor - initializes to parameter values
*/
Line::Line(Point point1, Point point2) 
{
	firstVertex = point1;
	secondVertex = point2;

}

Line::Line(Point point1, float slope)
{
	firstVertex = point1;
	this->slope = slope;
}
// getters
Point Line::getPoint1() { return firstVertex; }
Point Line::getPoint2() { return secondVertex; }
float Line::getSlope() { return slope; }
float Line::getYIntercept() { return yIntercept; }
float Line::getLength() { return length; }
float Line::getAngle() { return angle; }


//setters
void Line::setPoint1(Point value) 
{ 
	firstVertex = value;
}
void Line::setPoint2(Point value) 
{ 
	secondVertex = value; 
}
void Line::setSlope(float value)
{
	slope = value;
}
void Line::setYIntercept(float value) 
{ 
	yIntercept = value; 
}
void Line::setLength(float value)
{
	length = value;
}
void Line::setAngle(float value)
{
	angle = value;
}


//member methods

// calculates the difference between the x-coordinates
float Line::differenceX() 
{
	return secondVertex.getXCoordinate() - firstVertex.getXCoordinate();
}

// calculates the difference between the y-coordinates
float Line::differenceY()
{
	return secondVertex.getYCoordinate() - firstVertex.getYCoordinate();
}

/**
 Parameters:
 line			first point on the graph (X and Y positions) and the second point on the graph (X and Y positions)

 Returns:
 lineSlope		The slope of the line
*/
float Line::calcSlope()
{
	float slope;
	slope = differenceY() / differenceX();
	return slope;
}

/**
 Parameters:
 line			first point on the graph (X and Y positions) and the second point on the graph (X and Y positions)

 Returns:
 yIntercept		Gives you the y intercept
*/
float Line::calcYIntercept()
{
	return (firstVertex.getYCoordinate() - (slope *firstVertex.getXCoordinate()));
}

/**
 Parameters:
 line			first point on the graph (X and Y positions) and the second point on the graph (X and Y positions)

 Returns:
 distanceOfLine		Gives you the length of the line
*/
float Line::calcLength()
{
	return sqrt(pow(secondVertex.getXCoordinate() - firstVertex.getXCoordinate(),2) + pow(secondVertex.getYCoordinate() - firstVertex.getYCoordinate(), 2));
}

/**
 Parameters:
 line			first point on the graph (X and Y positions) and the second point on the graph (X and Y positions)

 Returns:
 cardnial		Gives you the angle degree
*/
float Line::calcAngle()
{
	
	float radians = std::atan2(differenceY(), differenceX());
	float angle = radians * 180.0 / M_PI;		// relative to X-axis
	float degrees = 90.0 - angle;					// rotate angle to left 90 degrees
	float cardnial = (degrees > 0.0 ? degrees : degrees + 360.0);		// fix negative cardnial

	return cardnial;
}
