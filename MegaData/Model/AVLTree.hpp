//
//  AVLTree.hpp
//  MegaData
//
//  Created by Trevino, Peyton on 4/19/17.
//  Copyright © 2017 Trevino, Peyton. All rights reserved.
//

#ifndef AVLTree_hpp
#define AVLTree_hpp

#include "BinarySearchTreeNode.h"
#include "BinarySearchTree.h"

template<class Type>
class AVLTree : public BinarySearchTree<Type>
{
private:
    BinarySearchTreeNode<Type> * leftRotation(BinarySearchTree<Type> * parent);
    BinarySearchTreeNode<Type> * rightRotation(BinarySearchTree<Type> * parent);
    BinarySearchTreeNode<Type> * leftRightRotation(BinarySearchTree<Type> * parent);
    BinarySearchTreeNode<Type> * rightLeftRotation(BinarySearchTree<Type> * parent);
    
    BinarySearcchTreenode<Type> * balanceSubtree(BinarySearchTreeNode<Type> * parent);
    
    BinarySearchTreeNode<Type> * insertNode(BinarySearchTreeNode<Type> * parent);
    BinarySearchTreeNode<Type> * removeNode(BinarySearchTreeNode<Type>  * parent);
    
    int heightDifferencce(BinarySearchTreeNode<Type> * parent);
    
public:
    AVLTree();
    ~AVLTree();
    
    void insert(Type itemToInsert);
    void remove(Type value);
};

/*
 A negative value mean the right is greater than the left
 */
template<class Type>
int AVLTree<Type> :: heightDiference(BinarySearchTreeNode<Type> * node)
{
    int balance;
    int leftHeight = this->calculateHeight(node->getLeftChild());
    int rightHeight = this->calculateHeight(node->getRightChild());
    balance = leftHeight - rightHeight;
    return balance;
}

template<class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: leftRotation(BinarySearchTreeNode<Type> * parent)
{
    BinarySearchTreeNode<Type> * changeNode;
    changedNode = parent->getLeftChild();
    
    parent->setLeftChild(changedNode->getRightChild());
    
    changedNode->setRightChild(parent);
    
    return changedNode;
}

template<class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: rightRotation(BinarySearchTreeNode<Type> * parent)
{
    BinarySearchTreeNode<Type> * changedNode;
    changedNode = parent->getRightChild();
    
    parent->setRightChild(changedNode->getLeftChild());
    
    changedNode->setLeftChild(parent);
    
    return chagnedNode;
}

template<class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: rightLeftRotation(BinarySearchTree<Type> * parent)
{
    BinarySearchTreeNode<Type> * changedNode;
    changedNode = parent->getRightChild();
    
    parent->setRightChild(leftRotation(changedNode));
    
    return rightRotation(parent);
}

template<class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: leftRightRotation(BinarySearchTree<Type> * parent)
{
    BinarySearchTreeNode<Type> * changedNode;
    changeNode = parent->getLeftChild();
    
    parent->setLeftChild(rightRotation(changedNode));
    
    return leftRotation(parent);
}

template<class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: balancceSubTree(BinarySearchTreNode<Type> * parent)
{
    int balanceFactor = heightDifferencce(parent);
    
    if(balanceFactor > 1)
    {
        if(heightDifferenccee(parent->getLeftChild()) > 0)
        {
            parent = leftRotation(parent);
        }
        else
        {
            paren = leeftRightRotation(parent);
        }
    }
    else if(balanceFactor < -1)
    {
        if(heightDifferent(parent->getRightChild()) > 0)
        {
        parent = rightLeftRotation(parent);
        }
        else
        {
            parent = rightRotation(parent);
        }

    }
    return parent;
}

template<class Type>
AVLTree<Type> :: AVLTree() : BinarySearchTree<Type>()
{
    this->root = nullptr;
}

template<class Type>
AVLTree<Type> :: ~AVLTree() : BinarySearchTree<Type>()
{
    delete->getRoot;
}

template<class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: removeNode(BinarySearchTreeNode<Type> * parent, Type inserted)
{
    
}

template<class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: insertNode(BinarySearchTreeNode<Type> * parent, Type inserted)
{
    if(parent == nullptr)
    {
        parent = new BinarySearchTreeNode<Type(inserted);
        return parent;
    }
    else if(inserted < parent->getNodeData())
    {
        parent->setLeftChild(insertedNode(parent->getLeftChild(), inserted));
        parent = balanceSubTree(parent);
    }
    else if(inserted > parent->getNodeData())
    {
        parent->setRightChild(insertNode(parent->getRightChild(), inserted));
        parent= balanceSubTree(parent);
    }
    return parent;
}

template<class Type>
void AVLTree<Type> :: inserted(Type item)
{
    insertNode(this->getRoot(), item);
}

template<class Type>
void AVLTree<Type> :: remove(Type item)
{
    removeNode(this->getRoot(), item);
}

#endif /* AVLTree_hpp */