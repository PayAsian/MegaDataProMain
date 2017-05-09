//
//  Graph.hpp
//  MegaData
//
//  Created by Trevino, Peyton on 5/9/17.
//  Copyright © 2017 Trevino, Peyton. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#include <set>
#include <queue>
#include <assert.h>

using namespace std;
template<class Type>
class Graph
{
private:
    static const int MAXIMUM = 20;
    bool adjacencyMatrix [MAXIMUM][MAXIMUM];
    int vertexCount;
    void depthFirstTraversal(Graph<Type> graph, int vertex, bool markedVertices[]);
    
public:
    Graph();
    ~Graph();
    
    void addVertex(const Type& value);
    void addEdge(int source, int target);
    void removeEdge(int source, int target);
    Type& operator[] (int vertex);
    Type operator [] (int vertex) const;
    int size() const;
    bool areConnected(int source, int target) const;
    std::set<int> neighbors(int vertex) const;
    void depthFirstTraversal(Graph<Type> graph, int vertex);
    void breadthFirstTraversal(Graph<Type> graph, int vertex);
};

#endif /* Graph_h */
