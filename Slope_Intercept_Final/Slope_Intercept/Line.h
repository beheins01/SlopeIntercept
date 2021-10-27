// file: Line.h
// by: Ben Heins
// org: 2001, 202101, 10409
// desc: declaration of the line class object
// ----------------------------------------------------

#ifndef LINE_H
#define LINE_H

#include "fgcugl.h"
#include "Point.h"

class Line {

public:
	Line();
	Line(Point point1, Point point2);

	Line(Point point1, float slope);

	// getters
	Point getPoint1();
	Point getPoint2();
	float getSlope();
	float getYIntercept();
	float getLength();
	float getAngle();

	//setters
	void setPoint1(Point value);
	void setPoint2(Point value);
	void setSlope(float value);
	void setYIntercept(float value);
	void setLength(float value);
	void setAngle(float value);

	//member methods
	float differenceX();
	float differenceY();
	float calcSlope();
	float calcYIntercept();
	float calcLength();
	float calcAngle();

private:
	Point firstVertex;
	Point secondVertex;
	float slope;
	float yIntercept;
	float length;
	float angle;
};

#endif //LINE_H