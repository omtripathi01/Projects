#include<bits/stdc++.h>
#include "GraphTemplate.h"
using namespace std;

// using bfs
bool detectCycleHelper(const vector<vector<int>>&adjList, vector<bool>&visited, int source){
    vector<int>parent(visited.size());
    visited[source] = true;
    parent[source] = -1;
    queue<int>q;
    q.push(source);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adjList[u]){
            if(!visited[v]){
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }else if(v != parent[u]){
                return true;
            }
        }   
    }

    // queue<pair<int,int>>q; // first -> curr vertex ... second->its parent
    // q.push({source,-1});

    // while(!q.empty()){
    //     pair<int,int>u = q.front();
    //     q.pop();
    //     for(auto v : adjList[u.first]){
    //         if(!visited[v]){
    //             visited[v] = true;
    //             q.push({v, u.first});
    //         }else if(v != u.second && v != u.first){
    //             return true;
    //         }
    //     }
    // }
    return false;
}

// using dfs
bool detectCycleHelper(const vector<vector<int>>&adjList, vector<bool>&visited, int source, int parent){
    visited[source] = true;

    for(auto u : adjList[source]){
        if(!visited[u]){
            return detectCycleHelper(adjList, visited, u, source);
        }else if(u != parent){
            return true;
        }
    }
    return false;
}

bool detectCycle(const vector<vector<int>>&adjList){
    int adliSize = adjList.size(); 
    vector<bool>visited(adliSize, false);
    bool res = false;
    for(int i=0;i<adliSize;i++){
        if(!visited[i]){
            res = detectCycleHelper(adjList, visited, i);
            // res = detectCycleHelper(adjList, visited, i, -1);
        }
    }
    return res;
}

int main()
{

    Graph g;

    vector<vector<int>>adjList1(6);

    g.addEdge(adjList1, 0, 1);
    g.addEdge(adjList1, 1, 2);
    g.addEdge(adjList1, 2, 3);
    g.addEdge(adjList1, 3, 4);
    g.addEdge(adjList1, 4, 5);
    g.addEdge(adjList1, 5, 2);

    vector<vector<int>>adjList2(3);

    g.addEdge(adjList2, 0, 1);
    g.addEdge(adjList2, 1, 2);

    vector<vector<int>>adjList3(2);

    g.addEdge(adjList3, 0, 1);

    vector<vector<int>>adjList4(3);

    g.addEdge(adjList4, 0, 1);
    g.addEdge(adjList4, 1, 2);
    g.addEdge(adjList4, 2, 0);

    vector<vector<int>>adjList5(5);

    g.addEdge(adjList1, 0, 1);
    g.addEdge(adjList1, 1, 2);
    g.addEdge(adjList1, 2, 3);
    g.addEdge(adjList1, 4, 1);
    
    vector<vector<int>>adjList6(5);

    g.addEdge(adjList1, 0, 1);
    g.addEdge(adjList1, 2, 3);
    g.addEdge(adjList1, 3, 4);
    g.addEdge(adjList1, 4, 2);

    

    vector<vector<vector<int>>>testCases = {adjList1, adjList2, adjList3, adjList4, adjList5, adjList6};


    for(auto testCase : testCases){
        g.display(testCase);
        if(detectCycle(testCase))
            cout<<"\nCycle Exist."<<endl;
        else
            cout<<"\nCycle Doesn't Exist."<<endl;

    }



    return 0;
}