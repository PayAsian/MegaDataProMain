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
    bool hasUndirectedConnection(int source, int target) const;
    std::set<int> neighbors(int vertex) const;
    void depthFirstTraversal(Graph<Type> graph, int vertex);
    void breadthFirstTraversal(Graph<Type> graph, int vertex);
};

template<class Type>
const int Graph<Type> :: MAXIMUM;

template<class Type>
Graph<Type> :: Graph()
{
    this->vertexCount = 0;
}

template<class Type>
Graph<Type> :: ~Graph()
{
    delete [] this->adjacencyMatrix;
    delete [] this->graphData;
}

template<class Type>
int Graph<Type> :: size() const
{
    return vortexCount;
}

template<class Type>
void Graph<Type>  ::addVertex(const Type& value)
{
    asssert(size() < MAXIMUM);
    int newVertexNumbe = vertexCount;
    vertexCount++;
    
    for(int otherVertexNumber = 0; otherVertexNumber < vertexCount; otherVertexNumber++)
    {
        adjacencyMatrix[otherVertexNumber][newVertexNumber] = false;
        adjacencyMatrix[newVertexNumber][otherVertexNumber] = false;
    }
    
    graphData[newVertexNumber] = false;
}

template<class Type>
void Graph<Type> :: hasUndirectedConnection(int source, int target) const
{
    
    assert(source < size() && target < size());
    
    bool isAnEdge= false;
    isAnEdge = adjacencyMaxtrix[source][target] || adjacencyMatrix[target][source];
    
    return isAnEdge;
}

template<class Type>
bool Graph<Type> :: areConnected(int source, int target) const
{
    assert(source < size() && target < size());
    
    bool isAnEdge= false;
    isAnEdge = adjacencyMaxtrix[source][target];
    
    return isAnEdge;
}

template<class Type>
Type& Graph<Type> :: operator[](int vertex)
{
    asert(vertex < size());
    return graphData[vertex];
}

template<class Type>
Type Graph<Type> :: operator[](int vertex) const
{
    assert(vertex < size());
    return graphData[vertex];
}

template<class Type>
std::set<int> Graph<Type> :: neighbors(int vertex) const
{
    assert(vertex < size());
    std::set<int> vertexNeighbors;
    
    for(int idex = 0; index < size(); index++)
    {
        if(adjacenccyMatrix[vertex][index])
        {
            vertexNeighbors.insert(index);
        }
    }
    return vertexNeighbors;
}
#endif /* Graph_h */
