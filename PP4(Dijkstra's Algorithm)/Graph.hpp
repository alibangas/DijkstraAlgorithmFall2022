/*  Names: Ali-Sarosh Bangash (U01170226), Faiz Alam (U31663839), Sumit Jadhav (U89612131)
*   Description: To make an implementation of Dijkstra's Algorithm with provided functions from 
*   GraphBase header file, and our own file (Graph.cpp and Graph.hpp)
*/

#ifndef GRAPH_H
#define GRAPH_H

#include "GraphBase.hpp"
#include <vector>
#include <string>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <deque>
#include <algorithm>
#include <climits>
using namespace std;

class Vertex 
{
    public:
        int cost;
        bool visited;
        vector<string> SP; 
        string label;

        friend class Graph;
        Vertex() {label = "";}
        
};

class Edge
{
    public:
        string cur;
        int weight;
        string adj;
        friend class Graph;

        Edge() { cur = ""; weight = 0; adj = ""; }

        Edge(string curr, string adjc, int in_weight) {
            cur = curr;
            adj = adjc;
            weight = in_weight;
        }
        ~Edge(){}
};


class Graph : public GraphBase 
{
    public:
        deque<Vertex*> vertices;
        deque<Edge*> edges;
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> Path;
        Graph(){};
        ~Graph();
        virtual void addVertex(string label) override;
        virtual void removeVertex(string label) override;
        virtual void addEdge(string label1, string label2, unsigned long weight) override;
        virtual void removeEdge(string label1, string label2) override;
        virtual unsigned long shortestPath(string startLabel, string endLabel, vector<string> &path) override;
        void findMinIndex(string& e);
        void findMinDist(string sLabel);
        string min_elem = "";
        int min_index = 0;
        void optimalPath(string endLabel, vector<string>& path);
        void clearPath();
        int shortest_dist = 0;
};

#endif