#include <iostream>
  
/* Link list node */
class Node 
{ 
    int data; 
    class Node* next; 
}; 
  
// Removeduplicates
void removeDuplicates(Node* head) 
{ 
    // Go to the Head list
    class Node* current = head; 
  
    // storage the list after the one that is duplicate
    class Node* next_next;  

    //Storage node for start
    class Node* start;

    // Go till end  
    while (current->next != nullptr)  
    { 
        start = current->next;
        while (start->data == current->data){  
       // IF LIST SAME TO NEXT ONE
       if (current->data == current->next->data)  
       { 
           //Put in temp variable to storage the Node after; ej 1  -1  - 1 - 2 (will storage 2)
           next_next = current->next->next; 

           // Delete the first copy ej 1(a) - 1(b) - 2 (deletes 1(a))
           free(current->next); 

           // make 1(b) position to 1(a), since 2 is connectted to 1(b) no need to move back
           current->next = next_next;   
       } 
    }
       else // everyhing gud, move next
       { 
          current = current->next;  
       } 
    } 

    
}
} 
