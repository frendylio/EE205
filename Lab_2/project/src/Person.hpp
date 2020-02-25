#ifndef PERSON_HPP
#define PERSON_HPP

#include "Point2D.hpp"

// std::string is a class from the C++ standard
// library that can be default-constructed
// and constructed from a C-style string (string
// literal like "Hello world")
#include <string>

// Make sure to use both Point2D and std::string
// as member variables in the class below.
class Person { 

private:

//Public Class
public:
//Variable
std::string name;
Point2D location;

//Default Constructor
Person();

//Overloaded Constructor
Person(std::string tempname, float a, float b);

//Get name
std::string get_name();

//Get location
Point2D get_location();

//Setter Name
void set_name(std::string tempname);

//Setter Location
void set_location(Point2D templocation);

};

#endif // PERSON_HPP
