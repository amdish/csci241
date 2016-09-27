
#include <iostream>
#include <vector>
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

using namespace std;

int main ()
{
	cout << "Welcome to shape creater" << endl;

	vector<Shape> theShapes;	//Vector of shape objects
	
	Circle("red", 2);	//Create circle
	
	

	//Dynamically create two circles
	//Loops through shapes and print
	//Loops through shapes and print triangles only
	//Loops through list and delete each object

	return 0;
}
