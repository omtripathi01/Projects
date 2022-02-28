// Problem: Breadth First Search (unweighted undirected graph)
// Suppose a graph is given to you which represents your friends from social network .. root of the graph 
// represents you and the level below it represents your friends and below it represents there friends
// you have to find out all the friends reachable from you may be through intermediates
//      0
//  1       2
//      3       4
// output: 0 1 2 3 4

// we can say in bfs we search element which are at distance 1 then at distance 2 and so on


#include<bits/stdc++.h>
#include "GraphTemplate.h"
using namespace std;

// if graph is disconnected then this function alone will not work
void bfs(const vector<vector<int>>&adjList, vector<bool>&visited, int source){

    queue<int>q;
    q.push(source);
    visited[source] = true;

    while(!q.empty()){

        int v = q.front();
        // visited[v] = true;
        cout<<v<<" ";
        q.pop();
        for(int u : adjList[v]){
            if(!visited[u]){
                visited[u] = true;
                q.push(u);
            }
        }
    }
}
// this will help in handling disconnected graph
void bfsDis(const vector<vector<int>>&adjList){
    
    int numVertices = adjList.size();
    vector<bool>visited(numVertices, false);

    for(int i=0;i<numVertices;i++){
        if(!visited[i]){
            bfs(adjList, visited, i);
            cout<<endl;
        }
    }
}


int main()
{
    Graph g;
    // vector<vector<int>>adjList(8);
    // vector<vector<int>>adjList(6);
    // g.addEdge(adjList, 0, 1);
    // g.addEdge(adjList, 1, 3);
    // g.addEdge(adjList, 3, 5);

    // g.addEdge(adjList, 0, 2);
    // g.addEdge(adjList, 2, 4);
    // g.addEdge(adjList, 4, 5);

    // g.addEdge(adjList, 0, 5);

    // g.addEdge(adjList, 6, 7);

    // vector<vector<int>>adjList(4);

    // g.addEdge(adjList, 0, 1);
    // g.addEdge(adjList, 0, 2);
    // g.addEdge(adjList, 1, 2);
    // g.addEdge(adjList, 1, 2);
    // g.addEdge(adjList, 1, 3);


    vector<vector<int>>adjList(7);

    g.addEdge(adjList, 0, 1);
    g.addEdge(adjList, 0, 4);
    g.addEdge(adjList, 1, 2);
    g.addEdge(adjList, 2, 3);
    g.addEdge(adjList, 4, 5);
    g.addEdge(adjList, 4, 6);
    g.addEdge(adjList, 5, 6);



    g.display(adjList);
    bfsDis(adjList);

    return 0;
}