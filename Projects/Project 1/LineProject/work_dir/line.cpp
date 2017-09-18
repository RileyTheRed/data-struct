// line.cpp
// Author: Riley Wells

#include <iostream>
#include "line.h"

using namespace std;


const char * EqualLines::what() const throw() {
  
	return "The lines are equal: infinite intersection";
  
} 

const char *ParallelLines::what() const throw () {
  
	return "The lines are parallel: no intersection";
  
}

double Line::intersect(const Line L) const {


  
	if (a == L.a && b == L.b) //test to see if the two lines are equal
		throw EqualLines();
	else if (a == L.a && b != L.b) //test to see if the two lines are parallel
		throw ParallelLines();
	else {

		// two doubles to hold the balanced equation when both lines are set equal to each other
		double slope;
		double y_intercept;

		//test to see if the y_intercept of THIS.Line is negative
		if (b < 0)
			y_intercept = L.b + b;
		else
			y_intercept = L.b - b;

		//test to see if the slope of L.line is negative
		if (L.a < 0)
			slope = a + L.a;
		else
			slope = a - L.a;

		//return the point of intersection of the two lines
		return (y_intercept / slope);

	}
  
} 

