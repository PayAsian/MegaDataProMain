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
    
    it heightDifferencce(BinarySearchTreeNode<Type> * parent);
    
public:
    AVLTree();
    ~AVLTree();
    
    void insert(Type itemToInsert);
    void remove(Type value);
};
#endif /* AVLTree_hpp */
