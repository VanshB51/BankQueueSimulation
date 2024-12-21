/*
 * Queue.h
 *
 * Description: Link list based implementation of Queue for a bank simulation
 *
 * Class Invariant: FIFO or LILO order
 *                  
 *
 * Author: Vansh Bansal and Adityapal Waraich
 * Last Modified: Mar. 2024
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>

using std::cout;
using std::cin;
using std::nothrow;
using std::endl;

template<class ElementType>
class Queue{

    private:

        // Description:  Nodes for a singly-linked list
        class QueueNode{
            public:
                ElementType data;
                QueueNode* next;

                // Constructors
                QueueNode() {}
                QueueNode(ElementType data) { this->data = data;}

                QueueNode(ElementType data, QueueNode * next) {
                this->data = data;
                this->next = next;
                }
        };
    
    QueueNode* head ;
    QueueNode* tail ;
    unsigned int elementcount = 0;

    public:

   // Description: Constructor
    Queue();

    // Description: Destructor
    ~Queue();


   // Description: Returns true if this Queue is empty, otherwise false.
   // Postcondition: This Queue is unchanged by this operation.
   // Time Efficiency: O(1)
   bool isEmpty() const;
   
   // Description: Inserts newElement at the "back" of this Queue 
   //              (not necessarily the "back" of this Queue's data structure) 
   //              and returns true if successful, otherwise false.
   // Time Efficiency: O(1)
   bool enqueue(ElementType & newElement);
   
   // Description: Removes (but does not return) the element at the "front" of this Queue 
   //              (not necessarily the "front" of this Queue's data structure).
   // Precondition: This Queue is not empty.
   // Exception: Throws EmptyDataCollectionException if this Queue is empty.   
   // Time Efficiency: O(1)
   void dequeue(); 

   // Description: Returns (but does not remove) the element at the "front" of this Queue
   //              (not necessarily the "front" of this Queue's data structure).
   // Precondition: This Queue is not empty.
   // Postcondition: This Queue is unchanged by this operation.
   // Exception: Throws EmptyDataCollectionException if this Queue is empty.
   // Time Efficiency: O(1)
   ElementType & peek() const;


};
#include "Queue.cpp"
#endif