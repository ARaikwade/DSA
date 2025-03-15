/******************************************************************************

Graph implementation using adjecency list.



*******************************************************************************/
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Graph
{
private:
    unordered_map<string, unordered_set<string> > adjList;


public:

    //O(1)
    bool addVertex(string vertex)
    {
        if(adjList.count(vertex) == 0)
        {
            adjList[vertex];
            return true;
        }
        return false;
    }
    
    //O(1)
    bool addEdge(string vertex1, string vertex2)
    {
        if((adjList.count(vertex1)) != 0 && (adjList.count(vertex2) != 0))
        {
            adjList.at(vertex1).insert(vertex2);
            adjList.at(vertex2).insert(vertex1);
            return true;
        }
        return false;
    }
    
    //O[v]
    bool removeVertex(string vertex)
    {
        if(adjList.count(vertex) != 0)
        {
            for(auto temp : adjList.at(vertex))
            {
                adjList.at(temp).erase(vertex);
            }
            adjList.erase(vertex);
            return true;
        }
        return false;
    }
    
    //O[1]
    bool removeEdge(string vertex1, string vertex2)
    {
        if(adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0)
        {
            adjList.at(vertex1).erase(vertex2);
            adjList.at(vertex2).erase(vertex1);
            return true;
        }
        return false;
    }
    
    void printGraph()
    {
        for(auto ver : adjList)
        {
            cout << ver.first << " : [ ";
            for(auto edg : adjList.at(ver.first))
            {
                cout << edg << ",";
            }
            cout << "]" << endl;
        }
    }
};



int main()
{
    Graph g;
    
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    
    
    g.addEdge("A", "B");
    g.addEdge("A", "C");
    g.addEdge("B", "C");
    
    
    //g.printGraph();
    
    g.removeEdge("A", "B");
    
    
    g.removeVertex("B");
    
    g.printGraph();
    

    return 0;
}