#include "Graph.hpp"

void checkLabel(string labelName) 
{
    if (labelName.empty()) 
    {
        throw("Invalid input is passed through\n");
    }
}

void GraphBase::addVertex(string label) 
{
    checkLabel(label);

}

/*
void GraphBase::removeVertex(string label) 
{
    
}

void GraphBase::addEdge(string label1, string label2, unsigned long weight) 
{

}

void GraphBase::removeEdge(string label1, string label2) 
{

}

unsigned long GraphBase::shortestPath(string startLabel, string endLabel, vector<string> &path) 
{

}
*/


int main () 
{
    vector<string> vertices1 = { "1", "2", "3", "4", "5", "6" };
    vector<tuple<string, string, unsigned long>> edges1 = { {"1", "2", 7}, {"1", "3", 9}, {"1", "6", 14}, 
    {"2", "3", 10}, {"2", "4", 15}, {"3", "4", 11}, {"3", "6", 2}, {"4", "5", 6}, {"5", "6", 9} };
    for (const auto label : vertices1) g.addVertex(label);
    /*
    for (const auto &tuple : edges1) g.addEdge(std::get<0>(tuple), get<1>(tuple), get<2>(tuple));
    g.shortestPath("1", "5", path); // == 20
    g.shortestPath("1", "5", path); // = { "1", "3", "6", "5" }
    */
}