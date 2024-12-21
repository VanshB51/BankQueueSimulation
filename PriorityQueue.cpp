/* 
 * BPriorityQueue.cpp
 *
 * Description: Priority Queue ADT class.
 *
 * Class Invariant: 
 * 
 * Author: Vansh Bansal and Adityapal Waraich
 * Last Modification: Nov. 2023
 *
 */

#include "PriorityQueue.h"


// Description: Returns true if this Priority Queue is empty, otherwise false.
// Postcondition: This Priority Queue is unchanged by this operation.
// Time Efficiency: O(1)
template<class ElementType>
bool PriorityQueue<ElementType>:: isEmpty() const{
if(priority.getElementCount()==0)
return true;
else
return false;
}

// Description: Inserts newElement in this Priority Queue and 
//              returns true if successful, otherwise false.
// Time Efficiency: O(log2 n)
template<class ElementType>
bool PriorityQueue<ElementType>::enqueue(ElementType & newElement){
return priority.insert(newElement);
}

// Description: Removes (but does not return) the element with the next
//              "highest" priority value from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
// Time Efficiency: O(log2 n)
template<class ElementType>
void PriorityQueue<ElementType>:: dequeue(){
priority.remove();
}

// Description: Returns (but does not remove) the element with the next 
//              "highest" priority value from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1)
template<class ElementType>
ElementType & PriorityQueue<ElementType>:: peek() const{
    if(priority.getElementCount()== 0){
        throw EmptyDataCollectionException("empty priority queue");
    }else{
   return priority.retrieve();
    }
}