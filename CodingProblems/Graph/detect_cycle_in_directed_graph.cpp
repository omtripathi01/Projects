#include<bits/stdc++.h>
#include "GraphTemplate.h"
using namespace std;    

// using dfs (we will use the concept of back edge and maintain a recursion call stack to check whether there is 
// back edge or not)

bool detectCycleHelper(const vector<vector<int>>&adjList, int source, vector<bool>&visited, vector<bool>&recSt){

    visited[source] = true;
    recSt[source] = true;

    for(auto u : adjList[source]){
        if(!visited[u] && detectCycleHelper(adjList, u, visited, recSt)){
            return true;
        }else if(recSt[u]){
            return true;
        }
    }
    recSt[source] = false;
    return false;
}

bool detectCycle(const vector<vector<int>>&adjList){

    int numOfVertices = adjList.size();
    vector<bool>visited(numOfVertices, false);
    vector<bool>recSt(numOfVertices, false);   // recursion call stack

    bool flag = false;
    for(int i=0;i<numOfVertices;i++){
        if(!visited[i] && !flag){
            flag = detectCycleHelper(adjList, i, visited, recSt); 
        }
    }
    return flag;
}

int main()
{
    Graph g1(true),g2(true),g3(true),g4(true),g5(true);

    vector<vector<int>>adjList1(6);

    g1.addEdge(adjList1, 0, 1);
    g1.addEdge(adjList1, 2, 1);
    g1.addEdge(adjList1, 2, 3);
    g1.addEdge(adjList1, 3, 4);
    g1.addEdge(adjList1, 4, 5);
    g1.addEdge(adjList1, 5, 3);

    vector<vector<int>>adjList2(4);

    g2.addEdge(adjList1, 0, 1);
    g2.addEdge(adjList1, 1, 2);
    g2.addEdge(adjList1, 2, 3);
    g2.addEdge(adjList1, 3, 1);

    vector<vector<int>>adjList3(4);
    g3.addEdge(adjList1, 0, 1);
    g3.addEdge(adjList1, 2, 1);
    g3.addEdge(adjList1, 2, 3);
    g3.addEdge(adjList1, 1, 3);


    vector<vector<int>>adjList4(6);

    g4.addEdge(adjList1, 0, 1);
    g4.addEdge(adjList1, 1, 2);
    g4.addEdge(adjList1, 2, 3);
    g4.addEdge(adjList1, 3, 4);
    g4.addEdge(adjList1, 4, 5);
    g4.addEdge(adjList1, 5, 3);
    g4.addEdge(adjList1, 5, 2);

    vector<vector<int>>adjList5(3);

    g5.addEdge(adjList1, 0, 1);
    g5.addEdge(adjList1, 2, 1);

    g1.display(adjList1);    

    // vector<vector<vector<int>>>testCases = {adjList1, adjList2, adjList3, adjList4, adjList5};

    // vector<Graph>graphs = {g1,g2,g3,g4,g5};

    // for(int i=0;i<graphs.size();i++){
    //     graphs[i].display(testCases[i]);
    //     if(detectCycle(testCases[i]))
    //         cout<<"\nCYCLE EXIST."<<endl;
    //     else
    //         cout<<"\nCYCLE DOESN'T EXIST."<<endl;        
    // }

    // for(auto testCase : testCases){
    //     g.display(testCase);
    //     if(detectCycle(testCase))
    //         cout<<"\nCYCLE EXIST."<<endl;
    //     else
    //         cout<<"\nCYCLE DOESN'T EXIST."<<endl;
    // }
    return 0;
}