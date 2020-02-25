#include "Vector.hpp"
#include <utility>

//Default Constructor
Vector::Vector() :
  arr(new int[1]),
  length(0),
  capacity(1) {}

//Copy Constructor
Vector::Vector(const Vector& other) :
  arr(new int [other.size()]),
  length(other.size()),
  capacity(other.capacity){
    for (std::size_t i=0; i<other.size(); i++){
      this->arr[i] = other.arr[i];
    }
  }

//Move Constructor
Vector::Vector(Vector&& other){
  arr = other.arr;
  length = other.length;
  other.arr = nullptr;
  other.length = 0;
}

//Destructor that deallocates memory
Vector::~Vector(void){
  delete [] arr;
}

//appends a number to the end of the Vector
void Vector::append(int num){
    if(length+1 > capacity){ double_capacity(); }
    arr[length] = num;
    length++;
}

//inserts a new number before the index
void Vector::insert(int index, int num){
  if(index < 0 || index > length){
    throw "Vector.insert: index out of bounds";
  }
  if(this->length +1 >= this->capacity){
    this->double_capacity();
  }
  for(int i = this->length; i > index; --i){
    arr[i] = arr[i-1];
  }
  arr[index] = num;
  length++;
}

// Removes a number at the index
void Vector::remove(int index){
  if(index < 0 || index >= length){
    throw "Vector.remove: index out of bounds";
  }
  else{
    for (; index<length; index++)
      arr[index] = arr[index+1];
    arr[length-1] = 0;
    length--;
  }
}

// Gets a number at the index
int Vector::get(int index) const{
  if(index < 0 || index > length){
    throw "Vector.get: index out of bounds";
  }
  return arr[index];
}

//double_capacity
void Vector::double_capacity(){
  int *temp = new int[2*capacity];
  std::size_t temp_capacity = 2*capacity;
  for(std::size_t i=0; i < this->length; i++){
    temp[i] = arr[i];
  }
  delete [] arr;
  this->arr = temp;
  this->capacity = temp_capacity;
}

// Returns the length of the vector
std::size_t Vector::size() const{ return length; }

// Returns a readable/writable referece to an element
// Throw a const char* if the index is out of bounds
int& Vector::operator[](int index){
  if(index < 0 || index > length){
    throw "Vector.operator: index out of bounds";
  }
  int& ref = arr[index];
  return ref;
}
