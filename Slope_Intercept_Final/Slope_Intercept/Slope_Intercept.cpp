/**
file: SlopeIntercept.cpp
by: Ben Heins
org: COP 2001, 10409
desc: Calculates a lines length, point slope form, angle, and graphs the line
*/

#include <iostream>		// Console Library

#include <iomanip>	

#include "fgcugl.h"
#include "Slope_Intercept.h"	// Main application header file
#include "Point.h"
#include "Line.h"

Mode getProblem();
Point getPoint();
void get2Point(Line& line);
void getPointSlope(Line& line);
void calcLine(Mode userInput, Line& line);
void displayLine(Line line);
void display2point(Line line);
void displayPointSlope(Line line);
void displaySlopeIntercept(Line line);
void drawLine(Line line);


int main()
{
	Line line;

	bool running = false;

	while (!running) {

		Mode userInput = getProblem();

		if (userInput == TWO_POINT)
		{
			get2Point(line);
			calcLine(userInput, line);
			displayLine(line);
			display2point(line);
			displaySlopeIntercept(line);
			drawLine(line);
		}

		else if (userInput == POINT_SLOPE)
		{
			getPointSlope(line);
			calcLine(userInput, line);
			displayLine(line);
			displayPointSlope(line);
			displaySlopeIntercept(line);
			drawLine(line);

		}

		else if (userInput == EXIT)
			running = true;


	}


}

/**
  Prompt the user for the problem they need to complete

  Return:

*/
Mode getProblem(){

	int userInput;

	std::cout << "\tSelect the form that you would like to convert to slope-intercept form:" << std::endl;
	std::cout << "\t\t1) Two-point form (you know the two points of the line)" << std::endl;
	std::cout << "\t\t2) Point-slope form (you know the line's slop and one point)" << std::endl;
	std::cout << "\t\t3) Exit" << std::endl;
	std::cout <<  "\t" << "=> ", std::cin >> userInput;

	if (userInput == 1)
		return TWO_POINT;

	else if (userInput == 2)
		return POINT_SLOPE;

	else if (userInput == 3)
		return EXIT;


}

/**
 Parameters:

 Returns:
 Point		x and y coordinates

*/
 Point getPoint() {
	
	Point point;

	float X;
	float Y;

	std::cout << "\tEnter X and Y coordinates seperated by spaces: ";

	std::cin >> X >> Y;

	point.setXCoordinate(X);
	point.setYCoordinate(Y);
    point = Point(X, Y);
	return point;
}

/**
 Parameters:
 line			first point on the graph and the second point of the graph

 Returns:
*/
void get2Point(Line& line) {

	std::cout << "\n\tEnter your first point: \n" << std::endl;
	line.setPoint1(getPoint());

	std::cout << "\n\tEnter your second point: \n" << std::endl;
	line.setPoint2(getPoint());

}

/**
 Parameters:
 line			first point on the graph and the slope of the graph

 Returns:
*/
void getPointSlope(Line& line) {

	float slope;

	std::cout << "\n\tEnter a point for the line" << std::endl;
	line.setPoint1(getPoint());

	std::cout << "\n\tEnter the slope of the line: ";
	std::cin >> slope;

	line.setSlope(slope);

}

/**
 Parameters:
 line			the yIntercept and the slope

 Returns:
*/
void calcLine(Mode userInput, Line& line) {
	Point point;
	if (userInput == TWO_POINT) {
		line.setSlope(line.calcSlope());
		line.setYIntercept(line.calcYIntercept());
	}
	else if (userInput == POINT_SLOPE) {
		line.setYIntercept(line.calcYIntercept());
		line.setPoint2(Point(0.0, line.calcYIntercept()));
		
	}

	line.setLength(line.calcLength());
	line.setAngle(line.calcAngle());
}

/**
 Parameters:
 line			first point on the graph (X and Y positions) and the second point on the graph (X and Y positions)
				and slope, and the Y-Intercept, and length, and Angle

 Returns:
*/
void displayLine(Line line) {
	std::cout << "\n\tLine:" << std::endl;
	std::cout << "\t\tPoint-1  " << "(" << line.getPoint1().getXCoordinate() << ", " << line.getPoint1().getYCoordinate() << ")" << std::endl;
	std::cout << "\t\tPoint-2  " << "(" << line.getPoint2().getXCoordinate() << ", " << line.getPoint2().getYCoordinate() << ")" << std::endl;
	std::cout << "\t\t  Slope = " << std::setprecision(3) << line.calcSlope() << std::endl;
	std::cout << "\t       Y-intcpt = " << std::setprecision(3) << line.calcYIntercept() << std::endl;
	std::cout << "\t\t Length = " << std::setprecision(3) <<line.calcLength() << std::endl;
	std::cout << "\t\t  Angle = " << std::setprecision(3) <<line.calcAngle() << "\n" << std::endl;
}

/**
 Parameters:
 line		first point on the graph (X and Y positions) and the second point on the graph (X and Y positions)	

 Returns:
*/
void display2point(Line line) {
	std::cout << "\n\tTwo-point form:" << std::endl;
	std::cout << "\t\t       (" << line.getPoint2().getYCoordinate() << " - " << line.getPoint1().getYCoordinate() << ")" << std::endl;
	std::cout << "\t\tm = --------------------" << std::endl;
	std::cout << "\t\t       (" << line.getPoint2().getXCoordinate() << " - " << line.getPoint1().getXCoordinate() << ")" << std::endl;
}

/**
 Parameters:
 line		first point on the graph (X and Y positions) and the slope

 Returns:
*/
void displayPointSlope(Line line) {
	std::cout << "\n\tPoint-slope form:" << std::endl;
	std::cout << "\t       y - " << line.getPoint1().getYCoordinate() << " = " << line.calcSlope() << "(x - " << line.getPoint1().getXCoordinate() << ")" << std::endl;
}

/**
 Parameters:
 line		slope and y-intercept

 Returns:
*/
void displaySlopeIntercept(Line line) {

	std::cout << "\n\tSlope-Intercept form:" << std::endl;
	std::cout << "\t       y = " << line.calcSlope() << "x + " << line.calcYIntercept() << "\n" << std::endl;
}

void drawLine(Line line) {

	//Graph Window
	fgcugl::openWindow(GRAPH_WINDOW_WIDTH, GRAPH_WINDOW_HEIGHT, GRAPH_WINDOW_TITLE, false);

	//main graph loop
	bool closeWindow = false;
	while (!closeWindow) {
		fgcugl::drawLine(0.0 , GRAPH_WINDOW_HEIGHT / 2.0, GRAPH_WINDOW_WIDTH, GRAPH_WINDOW_HEIGHT / 2.0);
		fgcugl::drawLine(GRAPH_WINDOW_WIDTH / 2.0, 0, GRAPH_WINDOW_WIDTH / 2.0, GRAPH_WINDOW_HEIGHT);
		fgcugl::drawLine(line.getPoint1().getXCoordinate() + GRAPH_WINDOW_WIDTH / 2.0, line.getPoint1().getYCoordinate() + GRAPH_WINDOW_HEIGHT / 2.0, line.getPoint2().getXCoordinate() + GRAPH_WINDOW_WIDTH / 2.0, line.getPoint2().getYCoordinate() + GRAPH_WINDOW_HEIGHT / 2.0);

		fgcugl::windowPaint();

		fgcugl::getEvents();
		
		closeWindow = closeWindow || fgcugl::windowClosing();
	}
	fgcugl::cleanup();
}