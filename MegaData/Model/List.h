//
//  List.h
//  MegaData
//
//  Created by Trevino, Peyton on 2/21/17.
//  Copyright © 2017 Trevino, Peyton. All rights reserved.
//

#ifndef List_h
#define List_h

#include <assert.h>
#include "Node.hpp"


template<class Type>
class List
{
private:
    int size;
    Node<Type> * front;
    Node<Type> * end;
    
public:
    List(int size);
    List<Type>();
    List<Type>(const List<Type> & toBeCopied);
    ~List<Type>();
    
    Type getFromIndex(int index);
    Type setAtIndex(int index, Type data);
    void addAtIndex(int index, Type value);
    void addFront(Type value);
    void addEnd(Type value);
    
    Type remove(int index);
    int getSize() const;
    bool contains(Type value);
    Node<Type> * getFront() const;
    Node<Type> * getEnd() const;
    
};

template<class Type>
List<Type> :: ~List()
{
    Node<Type> * destruction = front;
    while(front != nullptr)
    {
        front = front->getnextPointer();
        delete destruction;
        destruction = front;
    }
}

template<class Type>
Type List<Type> :: setAtIndex(int index, Type data)
{
    assert(index >= 0 && index < size);
    Type removedData;
    
    Node<Type> * current = front;
    
    for(int spot = 0; spot < index; spot++)
    {
        current = current->getnextPointer();
    }
    
    removedData = current->getNodeData();
    current->setNodeData(data);
    
    return removedData;
}

template<class Type>
Type List<Type> :: getFromIndex(int index)
{
    assert(index >= 0 && index < size);
    Type information;
    
    Node<Type> * current = front;
    for(int position = 0; position < index; position++)
    {
        current = current->getnextPointer();
    }
    
    information = current->getNodeData();
    
    return information;
}

template<class Type>
List<Type> :: List()
{
    this->size = 0;
    this->front = nullptr;
    this->end = nullptr;
}

template<class Type>
int List<Type> :: getSize() const
{
    return this->size;
}

template<class Type>
bool List<Type> :: contains(Type findMe)
{
    bool isInList = false;
    Node<Type> * current = front;
    
    for(int index = 0; index < size; index++)
    {
        if(current->getNodeData == findMe)
        {
            isInList = true;
            return isInList;
        }
    }
    return isInList;
}

template<class Type>
Node<Type> * List<Type> :: getFront() const
{
    return this->front;
}

template<class Type>
Node<Type> * List<Type> :: getEnd() const
{
    return this->end;
}



template<class Type>
void List<Type> :: addFront(Type value)
{
    if(size == 0)
    {
        Node<Type> * newFirst = new Node<Type>();
        newFirst->setNodeData(value);
        newFirst->setnextPointer(front);
        
        this->front = newFirst;
    }
    
    size++;
}

template<class Type>
void List<Type> :: addEnd(Type data)
{
    Node<Type> * added = new Node<Type>(data);
    if(size == 0)
    {
        this->front = added;
        this->end = added;
    }
    else
    {
        end->setnextPointer(added);
        this->end = added;
    }
    
    size++;
}

template<class Type>
void List<Type> :: addAtIndex(int index, Type value)
{
    assert(index >= 0 && index <= size);
    if(index == 0)
    {
        addFront(value);
    }
    else if(index == 0)
    {
        addEnd(value);
    }
    else
    {
        Node<Type> * insertedNode = new Node<Type>(value);
        Node<Type> * current = front;
        Node<Type> * previous = nullptr;
        
        for(int position = 0; position < index; position++)
        {
            previous = current;
            current = current->getnextPointer();
        }
        
        previous->setnextPointer(insertedNode);
        insertedNode->setnextPointer(current);
        
            size++;
    }
 
}

template<class Type>
Type List<Type> :: remove(int index)
{
    assert(index >= 0 && index < size);
    Type removed;
    
    Node<Type> * current = front;
    Node<Type> * previous = nullptr;
    Node<Type> * toBeRemoved = nullptr;
    
    if(index == 0)
    {
        toBeRemoved = front;
        this->front = front->getnextPointer();
    }
    
    toBeRemoved = current;
    previous->setnextPointer(nullptr);
    this->end = previous;
    
    if(index == 0)
    {
        toBeRemoved = front;
        this->front = front->getnextPointer();
    }
    else if(index == size - 1)
    {
        for(int spot = 0; spot < index; spot++)
        {
            previous = current;
            current = current->getnextPointer();
        }
        
        toBeRemoved = current;
        previous->setnextPointer(nullptr);
        this->end = previous;
    }
        else
        {
            for(int spot = 0; spot < index; spot++)
            {
                previous = current;
                current = current->getnextPointer();
            }
            
            toBeRemoved = current;
            current = toBeRemoved->getnextPointer();
            previous->setnextPointer(current);
            
        }
        
        removed = toBeRemoved->getNodeData();
        
        delete toBeRemoved;
        
        size--;
        return removed;
    }
    



#endif /* List_h */
