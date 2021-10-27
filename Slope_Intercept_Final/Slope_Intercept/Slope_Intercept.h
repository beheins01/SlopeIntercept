// file: SlopeIntercept.h
// by: Ben Heins
// org: 2001, 202101, 10409
// desc: main configuration header for the slope intercept program
// ----------------------------------------------------

#ifndef SLOPE_INTERCEPT_H
#define SLOPE_INTERCEPT_H

#include <iostream>
#include <string>		//for window title

// Global Constants
//-----------------------------------------------------

// Graph Window Constants
const int GRAPH_WINDOW_WIDTH = 400;
const int GRAPH_WINDOW_HEIGHT = 400;
const std::string GRAPH_WINDOW_TITLE = "Slope Intercept Graph";

enum Mode {
	TWO_POINT,
	POINT_SLOPE,
	EXIT

};

#endif //SSLOPE_INTERCEPT_H
