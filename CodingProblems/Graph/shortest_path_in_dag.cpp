// Shortest Path in Directed Acyclic Path(DAG)
// a source vertex is given to u and u have to find out shortest path from source to every other vertex
#include<bits/stdc++.h>
#include "GraphTemplate.h"
using namespace std;

void addDirectedEdge(vector<vector<int>>&adjList, vector<vector<int>>&weight , int u, int v, int w){
    weight[u][v] = w;
    adjList[u].push_back(v);
}

void displayWeight(const vector<vector<int>>&weight){
    cout<<"\n======================================\n";
     cout<<"    ";
    for(int i=0;i<weight.size();i++)
        cout<<i<<" ";
    cout<<endl;
    for(int i=0;i<weight.size();i++){
        cout<<i<<" : ";
        for(int j=0;j<weight.size();j++){
            cout<<weight[i][j]<<" "; 
        }
        cout<<endl;
    }
    cout<<"\n======================================\n";    
}

void display(vector<vector<int>>&adjList){
    cout<<"\n======================================\n";
    if(adjList.size() == 0){
        cout<<"Adjacency List is empty."<<endl;
        return;
    }

    for(int i=0;i<adjList.size();i++){
        cout<<i<<" : ";
        for(int j=0;j<adjList[i].size();j++){
            cout<<adjList[i][j]<<(j<adjList[i].size()-1 ? " -> ": "");
        }
        cout<<endl;
    }
    cout<<"\n======================================\n";
}

void shortestPathLengthHelper(const vector<vector<int>>&adjList, const vector<vector<int>>&weight, int source,
                              vector<int>&dist, vector<bool>&visited)
{    
    visited[source] = true;
    for(int v : adjList[source]){
        if(!visited[v]){
            visited[v] = true;
            dist[v] = dist[source] + weight[source][v];
            shortestPathLengthHelper(adjList, weight, v, dist, visited);
        }else{
            dist[v] = min(dist[v], dist[source]+weight[source][v]);
        }
    }
}

void shortestPathLength(const vector<vector<int>>&adjList, const vector<vector<int>>&weight, int source){

    int numOfVertices = adjList.size();
    vector<int>dist(numOfVertices, INT_MAX);
    vector<bool>visited(numOfVertices, false);
    dist[source] = 0;

    shortestPathLengthHelper(adjList, weight, source, dist, visited);

    for(int i =0;i<numOfVertices;i++){
        cout<<i<<" : "<<dist[i]<<endl;
    }
}

int main()
{
    
    vector<vector<int>>adjList(6);
    vector<vector<int>>weight(6,vector<int>(6,0));

    addDirectedEdge(adjList, weight, 0, 1, 2);
    addDirectedEdge(adjList, weight, 0, 4, 1);
    addDirectedEdge(adjList, weight, 1, 2, 3);
    addDirectedEdge(adjList, weight, 2, 3, 6);
    addDirectedEdge(adjList, weight, 5, 3, 1);
    addDirectedEdge(adjList, weight, 4, 5, 4);
    addDirectedEdge(adjList, weight, 4, 2, 2);


    display(adjList);
    displayWeight(weight);

    int source = 0;
    shortestPathLength(adjList, weight, source);

    vector<vector<int>>adjList1(4);
    vector<vector<int>>weight1(4,vector<int>(4,0));

    addDirectedEdge(adjList1, weight1, 0, 1, 1);
    addDirectedEdge(adjList1, weight1, 1, 2, 3);
    addDirectedEdge(adjList1, weight1, 2, 3, 4);
    addDirectedEdge(adjList1, weight1, 1, 3, 2);

    display(adjList1);
    displayWeight(weight1);
    int source1 = 1;
    shortestPathLength(adjList1, weight1, source1);

 
    return 0;
}