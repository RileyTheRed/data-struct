/*
This program is used to test the defined line.cpp file by creating several lines and then testing to see
if the intersect() fuction returns the correct x_component of the point of intersection

Author: Rileuy Wells
*/

#include <iostream>
#include "line.h"

using namespace std;

int main() {

	// create some lines to test
	Line l1 = Line(-11.1111105, 478.05);
	Line l2 = Line(4.05, 5.05);

	//start of the try/catch blocks
	try {
		cout << l1.intersect(l2) << endl;
	}
	catch (const EqualLines e) { //catch block that recieves an EqualLines exception
		cout << e.what() << endl;
	}
	catch (const ParallelLines e) { //catch block that recieves a ParallelLines exception
		cout << e.what() << endl;
	}

	return 0;


}
