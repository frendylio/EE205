#include"Point2D.hpp"
#include <iostream>
// run ./a.out
using namespace std;

// Default Consturctor
Point2D::Point2D(){
	x = 0;
	y = 0;
}

// Overload Constructor
Point2D::Point2D(float a, float b){
	x = a;
	y = b;
}

//Getters
float Point2D::get_x(){
return x;
}

float Point2D::get_y(){
return y;
}

//Setters
void Point2D::set_x(float f){
	x = f;
}

void Point2D::set_y(float f){
	y = f;
}


//-----------------Operations-------------------------------------//


//------------------------(+)------------------------------------//
Point2D operator+(Point2D lhs, Point2D rhs){

// Calling the Class
Point2D TempObject;

//Do operation
TempObject.x = lhs.x + rhs.x;
TempObject.y = lhs.y + rhs.y;

//Return TempObject
return TempObject;
}

//------------------------(-)------------------------------------//
Point2D operator-(Point2D lhs, Point2D rhs){

// Calling the Class
Point2D TempObject;

//Do operation
TempObject.x = lhs.x - rhs.x;
TempObject.y = lhs.y - rhs.y;

//Return TempObject
return TempObject;
}

//------------------------(*)------------------------------------//
Point2D operator*(Point2D lhs, Point2D rhs){

// Calling the Class
Point2D TempObject;

//Do operation
TempObject.x = lhs.x * rhs.x;
TempObject.y = lhs.y * rhs.y;

//Return TempObject
return TempObject;
}

//------------------------(/)------------------------------------//
Point2D operator/(Point2D lhs, Point2D rhs){

// Calling the Class
Point2D TempObject;

//Do operation
TempObject.x = lhs.x / rhs.x;
TempObject.y = lhs.y / rhs.y;

//Return TempObject
return TempObject;
}
