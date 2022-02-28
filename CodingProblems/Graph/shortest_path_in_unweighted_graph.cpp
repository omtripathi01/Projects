// Problem : Find the shortest path in given unweighted graph from source to every other node
// Adj list representation is given

#include<bits/stdc++.h>
#include "GraphTemplate.h"
using namespace std;

void shortestPathHelper(const vector<vector<int>>&adjList, vector<int>&dist, vector<bool>&visited, int source){

    queue<int>q;
    q.push(source);
    visited[source] = true;
    dist[source] = 0; 
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adjList[u]){
            if(!visited[v]){
                dist[v] = dist[u]+1;
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

vector<int> shortestPath(const vector<vector<int>>&adjList, int source){
    vector<int>dist(adjList.size(),INT_MAX);
    vector<bool>visited(adjList.size(),false);
    shortestPathHelper(adjList, dist, visited,source);
    return dist;

}


int main()
{
    Graph g;
    // vector<vector<int>>adjList(4);
    // g.addEdge(adjList, 0, 1);
    // g.addEdge(adjList, 0, 2);
    // g.addEdge(adjList, 1, 2);
    // g.addEdge(adjList, 1, 3);
    // g.addEdge(adjList, 2, 3);
    // // cout<<"\ncheck1";
    // g.display(adjList);
    // // cout<<"\ncheck2";

    vector<vector<int>>adjList(6);

    g.addEdge(adjList, 0, 1);
    g.addEdge(adjList, 0, 2);
    g.addEdge(adjList, 0, 4);
    g.addEdge(adjList, 1, 3);
    g.addEdge(adjList, 2, 4);
    g.addEdge(adjList, 2, 3);
    g.addEdge(adjList, 3, 5);
    g.addEdge(adjList, 4, 5);

    g.display(adjList);

    cout<<"\n";
    int source = 0;
    vector<int>dist = shortestPath(adjList, source);
    for(int i=0;i<dist.size();i++){
        cout<<i<<" : "<<dist[i]<<endl;
    }

    return 0;
}