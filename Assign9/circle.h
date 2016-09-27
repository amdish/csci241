//circle.h

#ifndef CIRCLE_H
#define CIRCLE_H

#include <string>

using namespace std;

class Circle {

	public:
		Circle(string, int);	//Constructor
		~Circle();		//Destructor
		
		void print();		//Overridden
		double get_area();
	
	private:
		int radius;	//Radius of object
};

Circle::Circle(string in, int in2){}


Circle::~Circle(){}

#endif
