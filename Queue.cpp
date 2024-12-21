/*
 * Queue.cpp
 *
 * Description: Link list based implementation of Queue for a bank simulation
 *
 * Class Invariant: FIFO or LILO order
 *                  
 *
 * Author: Vansh Bansal and Adityapal Waraich
 * Last Modified: Mar. 2024
 */


#include "Queue.h"
#include "EmptyDataCollectionException.h"

// Description: Constructor
template<class ElementType>
Queue<ElementType>::Queue(){
    head = nullptr;
    tail = nullptr;
    elementcount = 0;
}

// Description: Destructor
template<class ElementType>
Queue<ElementType>::~Queue(){
    while(!isEmpty()){
        dequeue();
    }
}


// Description: Returns true if this Queue is empty, otherwise false.
// Postcondition: This Queue is unchanged by this operation.
// Time Efficiency: O(1)
template<class ElementType>
bool Queue<ElementType>::isEmpty() const{
    return head == nullptr;
}

// Description: Inserts newElement at the "back" of this Queue 
//              (not necessarily the "back" of this Queue's data structure) 
//              and returns true if successful, otherwise false.
// Time Efficiency: O(1)
template<class ElementType>
bool Queue<ElementType>::enqueue(ElementType & newElement){

    QueueNode* newNode = new(nothrow) QueueNode(newElement);
    if(newNode == nullptr){
        //memory allocation failed
        return false;
    }

    // If the queue is empty, set both head and tail to the new node
    if(isEmpty()){
        head = newNode;
        tail = newNode;
        elementcount++;
        return true;
    }else{
    tail->next = newNode;
    tail = tail->next;
    }

    elementcount++;

    return true;
}

// Description: Removes (but does not return) the element at the "front" of this Queue 
//              (not necessarily the "front" of this Queue's data structure).
// Precondition: This Queue is not empty.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.   
// Time Efficiency: O(1)
template<class ElementType>
void Queue<ElementType>::dequeue(){

    if(isEmpty()){
        throw EmptyDataCollectionException("removing from empty queue");
    }
    if(elementcount == 1){
    delete head;
    head = nullptr;
    tail = nullptr;
    elementcount--;
    }else{
    // Remove the element at the front of the queue
    QueueNode* tobedeleted = head;
    head = head->next;
    delete tobedeleted;
    tobedeleted = nullptr;
    elementcount--;
    }
}


// Description: Returns (but does not remove) the element at the "front" of this Queue
//              (not necessarily the "front" of this Queue's data structure).
// Precondition: This Queue is not empty.
// Postcondition: This Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1)
template<class ElementType>
ElementType& Queue<ElementType>:: peek() const{
if(isEmpty()){
    throw EmptyDataCollectionException("trying to peek from an empty data set");
}else{
return head->data;
}
}

