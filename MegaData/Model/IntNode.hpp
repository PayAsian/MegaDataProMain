//
//  IntNode.hpp
//  MegaData
//
//  Created by Trevino, Peyton on 2/6/17.
//  Copyright © 2017 Trevino, Peyton. All rights reserved.
//

#ifndef IntNode_hpp
#define IntNode_hpp

class IntNode
{
private:
    int nodeData;
    IntNode * nextPointer;
public:
    //Constructor Section
    IntNode();
    IntNode(int value);
    /*
     Creates an IntNode with a specified value and next node pointer
     */
    IntNode(int value, IntNode * nextNode);
    
    //Method Section
    int getNodeData();
    IntNode * getnextPointer();
    void setNodeData(int value);
    void setnextPointer(IntNode * next);
    
};

#endif /* IntNode_hpp */
