/* 
 * BPriorityQueue.h
 *
 * Description: Priority Queue ADT class.
 *
 * Class Invariant: 
 * 
 * Author: Vansh Bansal and Adityapal Waraich
 * Last Modification: Nov. 2023
 *
 */

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <stdexcept>
#include "BinaryHeap.h"
#include "Event.h"

using std::cout;
using std::cin;
using std::nothrow;

template <class ElementType>
class PriorityQueue{
private:

BinaryHeap<ElementType> priority;  

public:

   // Description: Returns true if this Priority Queue is empty, otherwise false.
   // Postcondition: This Priority Queue is unchanged by this operation.
   // Time Efficiency: O(1)
   bool isEmpty() const;

   // Description: Inserts newElement in this Priority Queue and 
   //              returns true if successful, otherwise false.
   // Time Efficiency: O(log2 n)
   bool enqueue(ElementType & newElement);

   // Description: Removes (but does not return) the element with the next
   //              "highest" priority value from the Priority Queue.
   // Precondition: This Priority Queue is not empty.
   // Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
   // Time Efficiency: O(log2 n)
   void dequeue();
   
   // Description: Returns (but does not remove) the element with the next 
   //              "highest" priority value from the Priority Queue.
   // Precondition: This Priority Queue is not empty.
   // Postcondition: This Priority Queue is unchanged by this operation.
   // Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
   // Time Efficiency: O(1)
   ElementType & peek() const;


};
#include "PriorityQueue.cpp"
#endif