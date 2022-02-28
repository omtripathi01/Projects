// Problem: Depth First Search

#include<bits/stdc++.h>
#include "GraphTemplate.h"
using namespace std;

void recDFS(const vector<vector<int>>&adjList, vector<bool>&visited, int source){

    visited[source] = true;
    cout<<source<<" ";
    for(int u : adjList[source]){
        if(!visited[u])
            recDFS(adjList, visited, u);
    }
}

void DFS(const vector<vector<int>>&adjList, vector<bool>&visited, int source){

    queue<int>q;
    q.push(source);
    visited[source] = true;

    while(!q.empty()){
        int ele = q.front();
        q.pop();
        cout<<ele<<" ";
        for(int u : adjList[source]){
            if(!visited[u]){
                visited[u] = true;
                q.push(u);
            }
        }
    }
}


// this will help in handling disconnected graph
void dfsDis(const vector<vector<int>>&adjList){
    
    int numVertices = adjList.size();
    vector<bool>visited(numVertices, false);

    for(int i=0;i<numVertices;i++){
        if(!visited[i]){
            // recDFS(adjList, visited, i);
            DFS(adjList, visited, i);
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
    dfsDis(adjList);

    return 0;
}