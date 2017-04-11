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

template<class Type>
class BinarySerachTree : public Tree<Type>
{
private:
    BinarySearchTreeNode<Type> * root;
    
    int calculateSize(BinarySearchTreeNode<Type> * root);
    void inOrderTraversal(BinarySearhTreeNode<Type> * inStart);
    void preOrderTraversal(BinarySearchTreeNode<Type> * preStart);
    void postOrderTraversal(BiarySearchTreeNode<Type> * postStart);
    
public:
    BinarySearchTree();
    ~BinarySearchTree();
    
    BiarySearchTreeNode<Type> * geRoot();
    void setRoot(BinarySearchTreeNode<Type> * root);
    
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
};

template<class Type>
BinarySearchTree<Type> :: BinarySearchTree() : Tree<Type>()
{
    this->root = nullptr;
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
int BinarySearchTree<Type> :: calculateSize(BinarySearchTreeNode<Type> * star)
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

#endif /* BinarySearchTree_h */
