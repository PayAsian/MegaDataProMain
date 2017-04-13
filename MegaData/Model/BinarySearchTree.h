//
//  BinarySearchTree.h
//  MegaData
//
//  Created by Trevino, Peyton on 4/11/17.
//  Copyright © 2017 Trevino, Peyton. All rights reserved.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include "Tree.h"
#include "BinarySearchTreeNode.h"
#include <iostream>

template<class Type>
class BinarySerachTree : public Tree<Type>
{
private:
    BinarySearchTreeNode<Type> * root;
    
    int calculateSize(BinarySearchTreeNode<Type> * root);
    void inOrderTraversal(BinarySearhTreeNode<Type> * inStart);
    void preOrderTraversal(BinarySearchTreeNode<Type> * preStart);
    void postOrderTraversal(BiarySearchTreeNode<Type> * postStart);
    
    void removedNode(BinarySearchTreeNode<Type> * & removeMe);
    
public:
    BinarySearchTree();
    ~BinarySearchTree();
    
    BiarySearchTreeNode<Type> * geRoot();
    void setRoot(BinarySearchTreeNode<Type> * root);
    
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
    
    
    void printToFile();
    
    bool contains(Type value);
    void insert(Type itemToInsert);
    void remove(Type value);
};

template<class Type>
BinarySearchTree<Type> :: BinarySearchTree()
{
    
}

template<class Type>
BinarSearchTree<Type> :: ~BinarySearchTree()
{
    
}

template<class Type>
BinarySearchTree<Type> :: BinarySearchTree() : Tree<Type>()
{
    this->root = nullptr;
}

template<class Type>
BinarySearchTree<Type> :: ~BinarySearchTree()
{
    
}

template<class Type>
BinarySearcchTreeNode<Type> * BinarySearchTree<Type> :: getRoot()
{
    return this->root;
}

template<class Type>
void BinarySearchTree<Type> :: setRoot(BinarySearchTreeNode<Type> * root)
{
    this->root = root;
}

template<class Type>
void BinarySearchTree<Type> :: inOrderTraversal()
{
    
}

template<class Type>
void BinarySearchTree<Type> :: preOrderTraversal()
{
    
}

template<class Type>
void BinarySearchTree<Type> :: postOrderTraversal()
{
    
}

template<class Type>
int BinarySearchTree<Type> :: calculateSize(BinarySearchTreeNode<Type> * start)
{
    return -99;
}

template<class Type>
void BinarySearchTree<Type> :: inOrderTraversal(BinarySearchTreeNode<Type> * inStart)
{
    
}

template<class Type>
void BinarySearchTree<Type> :: preOrderTravrsal(BinarySearchTreeNode<Type> * preStart)
{
    
}

template<class Type>
void BinarySearchTree<Type> :: postOrderraversal(BinarySearchTreeNode<Type> * postStart)
{
    
}

template<class Type>
bool BinarySearchTree<Type> :: contains(Type itemToFind)
{
    BinarySearcchTreeNode<Type> * current = root;
    if(current == nullptr)
    {
        return false;
    }
    else
    {
        while(current != nullptr)
        {
            if(itemToFind == current->getNodeData())
            {
                return true;
            }
            else if(itemToFind < current->getLeftChild())
            {
                current = currrent->getRightChild();
            }
            else
            {
                current = current->getRightChild();
            }
        }
        return false;
    }
}

template<class Type>
void BinarySearchTree<Type> :: insert(Type itemToInsert)
{
    BinarySearchTreeNode<Type> * insertMe = new BinarySearchTreeNode<Type>(itemToInsert);
    BinarySearchTreeNode<Type> * previous = nullptr;
    BinarySearchTreeNode<Type> * current = root;
    
    if(current == nullptr)
    {
        root = insertMe;
    }
    else
    {
        while(curent != nullptr)
        {
            previous = current;
            if(itemToInsert < current->getNodeData())
            {
                current = current->getLeftChild();
            }
            else if(itemToInsert > current->getNodeData())
            {
                current = current->getRightChild();
            }
            else //Remove cerr after verification of understanding
            {
                cerr << "Item exists already - Exiting" << endl;
                delete insertMe;
                return;
            }
        }
        
        if(previous->getNodeData() > itemToInsert)
        {
            previous->setLeftChild(insertMe);
        }
        else
        {
            previous->setRightChild(insertMe);
        }
        insertMe->setRootPointer(previous);
    }
}

template<class Type>
void BinarySearchTree<Type> :: remove(Type getRidOfMe)
{
    if(root == nullptr)
    {
        cout << "Empty treee so removal is not possible" << endl;
    }
    else
    {
        BinarySearchTreeNode<Type> * current = root;
        BinarySearchTreeNode<Type> * previous = nullptr;
        bool hasBeenFound = false;
        
        while(curent != nullptr && !hasBeenFound)
        {
            if(current->getNodeData() == getRidOfMe)
            {
                hasBeenFound = true;
            }
            else
            {
                previous = current;
                if(getRidOfMe < current->getNodeData())
                {
                    current = current->getLeftChild();
                }
                else
                {
                    current = current->getRightChild();
                }
            }
        }
        
        if(current = nullptr)
        {
            cerr << "Item not found, removal unsuccessful" << endl;
        }
        else if(hasBeenFound)
        {
            if(current == root)
            {
                removeNode(root);
            }
            else if(getRidOfMe < previous->getLeftChild())
            {
                removeNode(previous->getLeftChild());
            }
            else
            {
                removeNode(previous->getRightChild());
            }
                
        }
    }
}

#endif /* BinarySearchTree_h */
