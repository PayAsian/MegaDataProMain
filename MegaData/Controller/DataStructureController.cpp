//
//  DataStructureController.cpp
//  MegaData
//
//  Created by Trevino, Peyton on 2/8/17.
//  Copyright © 2017 Trevino, Peyton. All rights reserved.
//

#include "DataStructureController.hpp"
#include <iostream>
#include "../Model/IntNodeArray.hpp"
using namespace std;

DataStructureController :: DataStructureController()
{
    wordNode = Node<string>("derpy mcderpface");
    numberNode = Node<int>();
}

void DataStructureController:: testNodes()
{
    cout << "" << endl;
    cout << wordNode.getNodeData() << endl;
    cout << "" << endl;
    cout << numberNode.getNodeData() << endl;
    
}

void DataStructureController :: start()
{
    cout << "Starting the project" << endl;
    
    cout << "Switching to the array testing" << endl;
    testIntArray();
    cout << "Finished testing" << endl;
}

void DataStructureController :: testIntArray()
{
    cout << "Testing the array" << endl;
    
    IntNodeArray temp = IntNodeArray(3);
    
    for(int index = 0; index < 3; index++)
    {
        cout << temp.getFromIndex(index) << " is at spot " << index << endl;
    }
    
    cout << "Tesing input" << endl;
    
    for(int index = 0; index < temp.getSize(); index++)
    {
        temp.setAtIndex(index, index);
    }
    
    for(int index = 0; index < 3; index++)
    {
        cout << temp.getFromIndex(index) << " is at spot " << index << endl;
    }
}
    void DataStructureController :: testListIntro()
    {
        List<int> sample;
        sample.addFront(2);
        sample.addEnd(3);
        sample.addFront(1);
        
        for(int index = 0; index < sample.getSize(); index++ )
        {
            cout << sample.getFromIndex(index) << endl;
            cout << sample.remove(1) << endl;
        }
        
        cout << "Size should read 3 and is " << sample.getSize() << endl;
    }
    
    void DataStructureController :: testListTiming()
    {
        DoubleList<int> timingList;
        Timer totalTimer;
        for(int index = 0; index < 10000; index++)
        {
            timingList.add(rand());
        }
        Timer doubleTimer;
        long slowTime [1000];
        long fastTime [1000];
        double averageSlow = 0.00, averageFast = 0.00;
        
        for(int index = 0; index < 1000; index++)
        {
            int randomIndex = rand() % 10000;
            doubleTimer.startTimer();
            timingList.getFromIndex(randomIndex);
            doubleTimer.stopTimer();
            slowTime[index] = doubleTimer.getExecutionTimeInMicroseconds();
            doubleTimer.resetTimer();
            
            doubleTimer.startTimer();
            timingList.getFromIndexFast(randomIndex);
            doubleTimer.stopTimer();
            fastTime[index] = doubleTimer.getExecutionTimeInMicroseconds();
            doubleTimer.resetTimer();
            
            averageSlow += slowTime[index];
            averageFast += fastTime[index];
        }
        
        averageSlow = averageSlow/1000.00;
        averageFast = averageFast/1000.00;
        totalTimer.stopTimer();
        
        cout << "The average speed for the getFromIndex method was: " << averageSlow << " microseconds. " << endl;
        cout << "The average speed forthe getFromIndexFas method was:" << averageFast << " microseconds." << endl;
        
        cout << "A time savings?? of: " << averageSlow - averageFast << " microseconds. " << endl;
        
        totalTimer.displayTimerInformation();
            
    }
    
    void DataStructureController :: testFoodQueue()
    {
        Queue<FoodItem> tastyFood;
        FoodItem szechwan("spicy chinese dish");
        
        tastyFood.enqueue(szechwan);
        FoodItem boring;
        
        FoodItem removed = tastyFood.dequeue();
        cout << "The item removed from the queue was: " << removed.getFoodName() << " and should be: " << endl;
    }
    
    void DataStructureController :: testIntStack()
    {
        Stack<int> numberStack;
        numberStack.add(2315);
        numberStack.push(32);
        int testValue = numberStack.pop();
        cout << "Test value is " << testValue << " and should be 32 " << endl;
    }
    

