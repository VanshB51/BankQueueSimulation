/* 
 * BinaryHeap.cpp
 *
 * Description: Min Binary Heap ADT class.
 *
 * Class Invariant: Always a Min Binary Heap.
 * 
 * Author: Vansh Bansal and Adityapal Waraich
 * Last Modification: Nov. 2023
 *
 */

#include "BinaryHeap.h"
#include "EmptyDataCollectionException.h"

//constructor
template<class ElementType>
BinaryHeap<ElementType>:: BinaryHeap(){
    elementcount = 0 ;
    elements = new ElementType[CAPACITY];

}

//destructor
template<class ElementType>
BinaryHeap<ElementType>:: ~BinaryHeap(){
    if(elements!= nullptr)
    delete[] elements;
}

// Description: Returns the number of elements in the Binary Heap.
// Postcondition: The Binary Heap is unchanged by this operation.
// Time Efficiency: O(1)
template<class ElementType>
unsigned int BinaryHeap<ElementType>::getElementCount() const{
return elementcount;
}

// Description: Inserts newElement into the Binary Heap. 
//              It returns true if successful, otherwise false.      
// Time Efficiency: O(log2 n)
template<class ElementType>
bool BinaryHeap<ElementType>::insert(ElementType & newElement){


    if(elementcount>= CAPACITY){
        ElementType* newElements = new ElementType[CAPACITY * 2];
         if (newElements == nullptr){
            return false;
        }
        for(unsigned int i = 0; i<CAPACITY ; i++){
            newElements[i] = elements[i];
        }
        delete [] elements;
        elements = newElements;
        CAPACITY *= 2;
    }

    elements[elementcount] = newElement;
    unsigned int bottom = elementcount;
    ++elementcount;

    reheapup(bottom);
    return true;
}

// Utility method
// Description: Recursively put the array back into a Min Binary Heap.
template<class ElementType>
void BinaryHeap<ElementType>::reheapup(unsigned int bottom){

    if(bottom>0){
        unsigned int parent = (bottom-1)/2;
        
        if(elements[bottom] <= elements[parent]){
            ElementType temp = elements[parent];
            elements[parent] = elements[bottom];
            elements[bottom] = temp;
        }
        reheapup(parent);
    }else{
        return;
    }
}

// Description: Removes (but does not return) the necessary element.
// Precondition: This Binary Heap is not empty.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(log2 n)
template<class ElementType>
void BinaryHeap<ElementType>::remove(){
    if (elementcount == 0) {
    throw EmptyDataCollectionException("remove() called with an empty BinaryHeap.");
    }

    if(CAPACITY>INITIAL_CAPACITY && elementcount < (CAPACITY/4)){

        CAPACITY = CAPACITY/2;
        ElementType *array = new ElementType [CAPACITY];

        for (unsigned int i = 0; i< elementcount ; i++){
            array[i] = elements[i];
        }
        delete[] elements;
        elements = array;
    }
    
    elements[0] = elements[elementcount-1];
    elementcount--;

    // No need to call reheapDown() if we have just removed the only element
    if ( elementcount > 0 ) 
    reheapdown(0);
    return ;
}

// Utility method
// Description: Recursively put the array back into a Min Binary Heap.
template<class ElementType>
void BinaryHeap<ElementType>::reheapdown(unsigned int root){
    unsigned int leftchild = 2*root + 1;
    unsigned int rightchild = 2*root + 2;
    unsigned int min = root;
     if(leftchild<elementcount){
    
    
    if (rightchild < elementcount && elements[rightchild] <= elements[leftchild]) {
     min = rightchild;
    }else{
     min = leftchild;
    }
    
    if(elements[min]<=elements[root] && min!=root){
        ElementType temp = elements[min];
        elements[min] = elements[root];
        elements[root] = temp;
        reheapdown(min);
       }
     }
    }   

// Description: Retrieves (but does not remove) the necessary element.
// Precondition: This Binary Heap is not empty.
// Postcondition: This Binary Heap is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(1) 
template<class ElementType>
ElementType & BinaryHeap<ElementType>::retrieve() const{
    if(elementcount == 0){
        throw EmptyDataCollectionException("cannot retrieve from an empty heap");
    }else{
    return elements[0];
    }
}

