// Topological sorting in useful in situations when we want to resolve dependencies between the graphs
// it can be applied on acyclic graphs i.e. on the graphs that don't have cycles

// Kahn's Algorithm

// Steps:-
// Create a indegree array
// Do BFS traversal starting from nodes whose indegree is 0


#include<bits/stdc++.h>
#include "GraphTemplate.h"
using namespace std;

// using bfs approach
void topologicalSortOfGraphHelper(const vector<vector<int>>&adjList, vector<int>&indegree){

    queue<int>q;
    for(int i=0;i<indegree.size();i++){
        if(indegree[i] == 0)
            q.push(i);
    }
    while(!q.empty()){

        int u = q.front();
        q.pop();
        cout<<u<<" ";
        for(int v : adjList[u]){
            indegree[v]--;
            if(indegree[v] == 0)
                q.push(v);
        }
    }
}
void topologicalSortOfGraph(const vector<vector<int>>&adjList){

    int numOfVertices = adjList.size();
    vector<int>indegree(numOfVertices,0);

    for(int i=0;i<numOfVertices;i++){
        for(int j=0;j<adjList[i].size();j++)
            indegree[adjList[i][j]]++;
    }
    // for(int i : indegree)
    //     cout<<i<<" ";
    topologicalSortOfGraphHelper(adjList, indegree);
}

// using dfs

void topologicalSortHelper(const vector<vector<int>>&adjList, vector<bool>&visited, stack<int>&st, int source){

    visited[source] = true;
    for(auto v : adjList[source]){
        if(!visited[v])
            topologicalSortHelper(adjList, visited, st, v);
    }
    st.push(source);
}
void topologicalSort(const vector<vector<int>>&adjList){

    int numOfVertices = adjList.size();
    vector<bool>visited(numOfVertices, false);
    stack<int>st;

    for(int i=0;i<numOfVertices;i++){
        if(!visited[i]){
            topologicalSortHelper(adjList, visited, st, i);
        }
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}
int main()
{
    Graph* g = new Graph(true);

    vector<vector<int>>adjList1(3);

    g->addEdge(adjList1, 0, 1);
    g->addEdge(adjList1, 0, 2);

    vector<vector<int>>adjList2(5);

    g->addEdge(adjList2, 0, 2);
    g->addEdge(adjList2, 0, 3);
    g->addEdge(adjList2, 1, 3);
    g->addEdge(adjList2, 1, 4);

    vector<vector<int>>adjList3(6);

    g->addEdge(adjList3, 0, 1);
    g->addEdge(adjList3, 0, 2);
    g->addEdge(adjList3, 1, 3);
    g->addEdge(adjList3, 2, 3);
    g->addEdge(adjList3, 3, 4);
    g->addEdge(adjList3, 3, 5);

    vector<vector<int>>adjList4(5);

    g->addEdge(adjList4, 0, 2);
    g->addEdge(adjList4, 0, 3);
    g->addEdge(adjList4, 3, 2);
    g->addEdge(adjList4, 1, 3);
    g->addEdge(adjList4, 1, 4);

    vector<vector<vector<int>>>testCases = {adjList1, adjList2, adjList3, adjList4};

    for(auto testCase : testCases){
        g->display(testCase);
        cout<<"\nTopological Sorting Of graph is : ";
        cout<<"\n";
        topologicalSortOfGraph(testCase);
        cout<<"\n";
        topologicalSort(testCase);
    }

    // g->display(adjList2);
    // cout<<"\nTopological Sorting Of graph is : ";
    // topologicalSortOfGraph(adjList2);
    return 0;
}