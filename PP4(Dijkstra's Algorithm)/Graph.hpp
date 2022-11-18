#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <map>
#include <unordered_map>
using namespace std;

class GraphBase : public GraphBase 
{
    Graph();
    ~Graph();
    virtual void addVertex(string label);
    virtual void removeVertex(string label);
    virtual void addEdge(string label1, string label2, unsigned long weight);
    virtual void removeEdge(string label1, string label2);
    virtual unsigned long shortestPath(string startLabel, string endLabel, vector<string> &path);
}

#endif