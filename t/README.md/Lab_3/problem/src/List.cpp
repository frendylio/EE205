#include "List.hpp"

#include <iostream>
#include <utility>

// Initializes the list
List::List() :
  head(nullptr),
  length(0) {}

// Performs a deep copy, copying each node of the other list
// into this one
List::List(const List& other){
  ListNode* otherHead = other.head;
  length = other.length;
  while (otherHead != nullptr){
    otherHead = otherHead->next;
    }
  }

// Performs a move, moving the internal list from the other
// vector to this one, and invalidates the other list pointer
// for its memory
List::List(List&& other) :
  head(std::move(other.head)),
  length(std::move(other.length)){
  other.head = nullptr;
  other.length = 0;
  }

// Deallocates the memory in this list.
List::~List(){
  this->head = nullptr;
}

// For all of the following functions,
// throw a const char* (string) if the index is out of
// the bounds of the list.

// Appends a ListNode onto the end of the list
//
// Throw a const char* if the index is out of bounds
void List::append(int num){
  //if appending to an empty list
  if(this->head == nullptr){
    this->head = new ListNode(num);
  }
  //otherwise appending to an existing node
  else {
    ListNode *it = this->head;
    while(it->next != nullptr){
      it = it->next;
    }
    it->next = new ListNode(num);
  }
  length++;
}

// Inserts a ListNode before the index
//
// Throw a const char* if the index is out of bounds.
// Appending at the end is valid (e.g. insert(list.size(), 0)
// is valid)
void List::insert(int index, int num){
  if(index < 0 || index > length){
    throw "List.insert: index out of bounds";
  }
  //if inserting to an empty list
  if(this->head == nullptr){
    this->head = new ListNode(num);
  }
  //either insert in middle of list or end
  else{
    ListNode* temp = this->head;
    for(int i = 1; i != index; i++){
      temp = temp->next;
    }
    temp->next = new ListNode(num);
  }
  length++;
}

// Removes the ListNode at the index
//
// Throw a const char* if the index is out of bounds.
void List::remove(int index){
  if(index < 0 || index > length || this->head == nullptr){
    throw "List.remove: index out of bounds";
  }
  ListNode *it = this->head;
  for(int i = 0; i != index; i++){
    it = it->next;
  }
  delete it;
  length--;
  this->head = it->next;
}

// Returns the int at the index
//
// Throw a const char* if the index is out of bounds.
int List::get(int index) const{
  if(index < 0 || index > length){
    throw "List.insert: index out of bounds";
  }
  ListNode *c = head;
  int count = 0;
  while(c != nullptr){
    if(count == index){
      return(c->data);
    }
    c = c->next;
    count++;
  }
  return 0;
}

// Returns the length of the list
std::size_t List::size() const{ return length;}

// Reutrns a readable/writeable reference to the element at index
//
// Throw a const char* if the index is out of bounds.
int& List::operator[](int index){
  if(index < 0 || index > length){
    throw "List.operator: index out of bounds";
  }

  ListNode *c = head;
  int count = 0;
  while(c != nullptr){
    if(count == index){
      int& ref = c->data;
        std::cout << std::endl;
      return(ref);
    }
  
    c = c->next;
    count++;    
    
      std::cout << "test" << std::endl;
  std::cout << index << std::endl;
  std::cout << "end test" << std::endl;
  }

}
