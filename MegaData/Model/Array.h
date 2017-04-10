//
//  Array.h
//  MegaData
//
//  Created by Trevino, Peyton on 2/15/17.
//  Copyright © 2017 Trevino, Peyton. All rights reserved.
//

#ifndef Array_h
#define Array_h

#include "Node.hpp"
#include <assert.h>
#include <iostream>
using namespace std;

template<class Type>
class Array
{
private:
    int size;
    Node<Type> * front;
public:
    Array();
    Array(int size);
    
    //Destructor
    ~Array<Type>();
    //Copy Constructor
    Array<Type>(const Array<Type> & toBeCopied);
    Node<Type> * getFront() const;
    
    //Helper Methods
    void setAtIndex(int index, Type value);
    Type getFromIndex(int index);
    int getSize() const;
    
};

template <class Type>
Array<Type> :: Array()
{
    //Never used
    //Default construstor only supplied to avoid compilation error!
    
    
}

template <class Type>
Array<Type> :: Array(int size)
{
    assert(size > 0);
    
    this->size = size;
    this->front = new Node<Type>();
    
    for(int index = 1; index < size; index++)
    {
        Node<Type> * current = new Node<Type>();
        current->setnextPointer(front);
        front = current;
    }
}

template <class Type>
void Array<Type> :: setAtIndex(int index, Type data)
{
    assert(index >= 0 && index < size);
    Node<Type> * current = front;
    for(int spot = 0; spot < index; spot++)
    {
        current = current->getnextPointer();
    }
    current->setNodeData(data);
}

template <class Type>
Type Array<Type> :: getFromIndex(int index)
{
    assert(index >= 0 && index < size);
    Type value;
    
    Node<Type> * current = front;
    
    for(int position = 0; position < index; position++)
    {
        current = current->getnextPointer();
    }
    value = current->getNodeData();
    return value;
    
}

template <class Type>
int Array<Type> :: getSize() const
{
    return this->size;
}

template <class Type>
Array<Type> :: ~Array()
{
    int count = size;
    Node<Type> * remove = front;
    while(front != nullptr)
    {
        //Move to next node in Array
        front = front->getnextPointer();
        cout << "Moving to the next node. At: " << count << endl;
        //Delete the gront pointer
        delete remove;
        cout << "Deleting the old front pointer." << endl;
        //Move delete to the new front
        remove = front;
        cout << "Moving to a new front pointer." << endl;
        count--;
        cout << "Front is at: " << front << " count is: " << count << endl;
    }
}

template <class Type>
Array<Type> :: Array(const Array<Type> & toBeCopied)
{
    this->size = toBeCopied.getSize();
    
    //Build Data Structor
    this->front = new Node<Type>();
    for(int index = 1; index < size; index++)
    {
        Node<Type> * temp = new Node<Type>();
        temp->setNdoePointer(front);
        front = temp;
    }
    //Copy values into new Array.
    //This could be done at the same time as the build step
    //but this is easier to explain
    Node<Type> * copyTemp = toBeCopied.getFront();
    Node<Type> * updated = this->front;
    for(int index = 0; index < size; index++)
    {
        updated->setNodeData(copyTemp->getNodeData());
        updated = updated->getnextPointer();
        copyTemp = copyTemp->getnextPointer();
    }
}

template <class Type>
Node<Type> * Array<Type> :: getFront () const
{
    return front;
}

#endif /* Array_h */

