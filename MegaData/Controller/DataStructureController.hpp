//
//  DataStructureController.hpp
//  MegaData
//
//  Created by Trevino, Peyton on 2/8/17.
//  Copyright © 2017 Trevino, Peyton. All rights reserved.
//

#ifndef DataStructureController_hpp
#define DataStructureController_hpp

#include "../Model/Node.hpp"
#include "../Model/Array.h"
#include "../Model/List.h"
#include "../Model/Stack.h"
#include "../Model/Queue.h"
#include "../Model/FoodItem.hpp"
#include "../Model/CircularList.h"
#include "../Model/Timer.hpp"
#include "../Model/DoubleList.h"
#include "../Model/BiDirectionalNode.h"
#include "../Model/BinarySearchTree.h"
#include "../Model/BinarySearchTreeNode.h"
#include "../Model/Tree.h"
#include <string>

using namespace std;

class DataStructureController
{
private:
    void testIntArray();
    Node<int> numberNode;
    Node<string> wordNode;
    void testNodes();
    void testListIntro();
    void testListTiming();
    void testFoodQueue();
    void testIntStack();
    void testBinarySearchTreeOperations();
    void testBinarySearchData();
    void testAVLTreeOperations();
    void AVLData();
    
    
    
public:
    DataStructureController();
    void start();
    
};

#endif /* DataStructureController_hpp */
