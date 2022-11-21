/*  Names: Ali-Sarosh Bangash (U01170226), Faiz Alam (U31663839), Sumit Jadhav (U89612131)
*   Description: To make an implementation of Dijkstra's Algorithm with provided functions from 
*   GraphBase header file, and our own file (Graph.cpp and Graph.hpp)
*/

#include "Graph.hpp"
#include <iostream>

void checkLabel(string labelName) 
{
    if (labelName.empty()) 
    {
        throw("Invalid input is passed through\n");
    }
}

Graph::~Graph() 
{
    for(auto& v : vertices) 
    {
        delete v;
    }
    for(auto& e : edges)
    {
        delete e;
    }
    vertices.clear();
    edges.clear();
}

void Graph::addVertex(string label) 
{
    checkLabel(label);
    Vertex* v = new Vertex;
    v->visited = false;
    v->cost = INT_MAX;
    v->label = label;
    v->SP = {""};
    vertices.push_back(v);
}

void Graph::removeVertex(string label) {
    checkLabel(label);

    deque<Vertex*>::iterator v;
    for (v = vertices.begin(); v != vertices.end(); v++) {
        if ((*v)->label == label) {
            vertices.erase(v);
        }
    }
    deque<Edge*>::iterator e;
    for (e =  edges.begin(); e!= edges.end(); e++) {
        if (((*e)->cur == label) || (*e)->adj == label) {
            edges.erase(e);
        }
    }
}


void Graph::addEdge(string label1, string label2, unsigned long weight) 
{
    checkLabel(label1);
    checkLabel(label2);

    Edge *edge1 = new Edge(label1, label2, weight);
    Edge *edge2 = new Edge(label2, label1, weight);

    edges.push_back(edge1);
    edges.push_back(edge2);
}

void Graph::removeEdge(string label1, string label2) 
{
    checkLabel(label1);
    checkLabel(label2);
    deque<Edge*>::iterator edgeIterator;
    for (edgeIterator = edges.begin(); edgeIterator != edges.end(); ++edgeIterator) 
    {
        if ((*edgeIterator)->cur == label1) {
            if ((*edgeIterator)->adj == label2) {
                edges.erase(edgeIterator);
            }
        }
    }
}

void Graph::findMinIndex(string& e) {
    int inx = 0;
    deque<Vertex*>::iterator v;
    for (v = vertices.begin(); v != vertices.end(); v++) {
        if ((*v)->label == e) {
            min_index = inx;
        }
        else {
            inx++;
        }
    }
}

void Graph::findMinDist(string sLabel) {
    deque<Edge*>::iterator i;
    for (i = edges.begin(); i != edges.end(); i++) {
        if ((*i)->cur == min_elem) {
            for (deque<Vertex*>::iterator j = vertices.begin(); j != vertices.end(); j++) {
                if (((*i)->adj == (*j)->label)) {
                    if ((vertices.at(min_index)->cost + (*i)->weight < (*j)->cost) && (*j)->visited == false) {     // if new min distance found and not visited,
                        (*j)->cost = vertices.at(min_index)->cost + (*i)->weight;       // set min distance

                        if (min_elem == sLabel) {
                            (*j) -> SP.clear();
                            (*j) -> SP.push_back(sLabel);
                        }
                        else if (min_elem != sLabel) {
                            (*j) -> SP.clear();
                            (*j) -> SP = vertices.at(min_index)->SP;
                            (*j) -> SP.push_back(vertices.at(min_index)->label);
                        }
                        Path.push(make_pair((*j)->cost, (*j)->label));
                    }
                }
            }
        }
    }
}

void Graph::optimalPath(string endLabel, vector<string> &path) {
    deque<Vertex*>::iterator v;

    for (v = vertices.begin(); v != vertices.end(); v++) {
        if (endLabel == (*v)->label) {
            shortest_dist = (*v) -> cost;
            (*v)->SP.push_back(endLabel);
            path = (*v)->SP;
        }
    }
}

void Graph::clearPath() {
    deque<Vertex*>::iterator i;
    for (i = vertices.begin(); i != vertices.end(); i++) {
        (*i)->visited = false;
        (*i)->cost = INT_MAX;
        (*i)->SP = {""};
    }
}

unsigned long Graph::shortestPath(string startLabel, string endLabel, vector<string> &path) 
{
    checkLabel(startLabel);
    checkLabel(endLabel);

    //start path
    deque <Vertex*>::iterator v;
    for (v = vertices.begin(); v != vertices.end(); v++) {
        if ((*v)->label == startLabel) {
            (*v)->SP.clear();
            (*v)->cost = 0;
            (*v)->SP.push_back(startLabel);
        }
    }
    Path.push(make_pair(0, startLabel));

    //path
    while (!Path.empty()) {
        min_elem = Path.top().second;
        Path.pop();
        findMinIndex(min_elem);
        findMinDist(startLabel);
        vertices.at(min_index)->visited = true; // vertex at min_index has been visited
    }

    optimalPath(endLabel, path);

    clearPath();

    return shortest_dist;
}