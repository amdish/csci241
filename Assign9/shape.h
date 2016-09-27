//shape.h
#ifndef SHAPE_H
#define SHAPE_H

#include <string>
using namespace std;

class Shape {

	public:
		Shape();	//Constructor
		void print();	//Virtual print method
		double get_area();	

	private:
		string color; 
};

#endif
