#include"Person.hpp"
#include <iostream>
#include <string>
#include "Point2D.hpp"

using namespace std;

// Default Consturctor
Person::Person(){
	name = "";

// Initialize object from POint2D x,y
	Point2D temp;
	location = temp; // sets location (x,y) which is default constructor (0,0)
}

// OVerload COnstructor
Person::Person(std::string tempname, float a, float b){
	name = tempname;
	Point2D templocation(a,b); //to call a OVerlaod consturctor
	location = templocation;
}


//Getters
std::string Person::get_name(){
return name;
}

Point2D Person::get_location(){
return location;
}

//Setters
void Person::set_name(std::string tempname){
	name = tempname;
}

void Person::set_location(Point2D templocation){
	location = templocation;
}


