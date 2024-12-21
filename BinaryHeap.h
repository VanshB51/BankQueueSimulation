/* 
 * BinaryHeap.h
 *
 * Description: Min Binary Heap ADT class.
 *
 * Class Invariant: Always a Min Binary Heap.
 * 
 * Author: Vansh Bansal and Adityapal Waraich
 * Last Modification: Nov. 2023
 *
 */
#ifndef BinaryHeap_H
#define BinaryHeap_H

#include <iostream>
#include <stdexcept>
#include "Event.h" 

using std::cin;
using std::cout;
using std::nothrow;

template<class ElementType>
class BinaryHeap{

private:

    static unsigned int const INITIAL_CAPACITY = 100;
    unsigned int CAPACITY = INITIAL_CAPACITY;
    unsigned int elementcount = 0;
    ElementType *elements = nullptr;


    // Utility method
    // Description: Recursively put the array back into a Min Binary Heap.
    void reheapup(unsigned int bottom);

    // Utility method
    // Description: Recursively put the array back into a Min Binary Heap.
    void reheapdown(unsigned int root);
    

public:

   //constructor & destructor
   BinaryHeap();
   ~BinaryHeap();

   // Description: Returns the number of elements in the Binary Heap.
   // Postcondition: The Binary Heap is unchanged by this operation.
   // Time Efficiency: O(1)
   unsigned int getElementCount() const;

   // Description: Inserts newElement into the Binary Heap. 
   //              It returns true if successful, otherwise false.      
   // Time Efficiency: O(log2 n)
   bool insert(ElementType & newElement);

   // Description: Removes (but does not return) the necessary element.
   // Precondition: This Binary Heap is not empty.
   // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
   // Time Efficiency: O(log2 n)
   void remove();

   // Description: Retrieves (but does not remove) the necessary element.
   // Precondition: This Binary Heap is not empty.
   // Postcondition: This Binary Heap is unchanged.
   // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
   // Time Efficiency: O(1) 
   ElementType & retrieve() const;


};

#include "BinaryHeap.cpp"
#endif