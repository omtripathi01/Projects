// Adjacency Matrix
// Adjacency List (using jagged arrays/vectors) 

#include<bits/stdc++.h>
using namespace std;


class Graph{

    private: 

        int numVertices;
        vector<vector<bool>> adjMat;
        bool isdirectedGraph = false;

    public:
        
        Graph(bool directedGraphStatus = false):isdirectedGraph(directedGraphStatus),numVertices(0)
        {}

        Graph(int numVertices,bool directedGraphStatus = false){
            this->isdirectedGraph = directedGraphStatus;
            this->numVertices = numVertices;
            adjMat = vector<vector<bool>>(numVertices, vector<bool>(numVertices, false));  
        }

        void addEdge(int u, int v);
        void addEdge(vector<vector<int>>&adjList, int u, int v);
        
        void removeEdge(int u, int v);
        void removeEdge(vector<vector<int>>&adjList, int u, int v);

        void display();
        void display(vector<vector<int>>&adjList);

};

void Graph :: addEdge(int u, int v){

    adjMat[u][v] = true;
    if(!isdirectedGraph)
        adjMat[v][u] = true;
    
}
void Graph :: addEdge(vector<vector<int>>&adjList, int u, int v){

    adjList[u].push_back(v);
    if(!isdirectedGraph)
        adjList[v].push_back(u);

}
void Graph :: removeEdge(int u, int v){

    adjMat[u][v] = false;
    if(!isdirectedGraph)
        adjMat[v][u] = false;
    
}
void Graph :: removeEdge(vector<vector<int>>&adjList, int u, int v){
    vector<int>temp;
    for(int vertix : adjList[u]){
        if(vertix != v)
            temp.push_back(vertix);
    }
    adjList[u] = temp;
    temp.clear();
    if(!isdirectedGraph){
        for(int vertix : adjList[v]){
            if(vertix != u)
                temp.push_back(vertix);
        }       
    }
    adjList[v] = temp;
    temp.clear();
}

void Graph :: display(){

    cout<<"\n======================================\n";
    if(adjMat.size() == 0){
        cout<<"Adjacency Matrix is empty."<<endl;
        return;
    }
    cout<<"    ";
    for(int i=0;i<adjMat.size();i++)
        cout<<i<<" ";
    cout<<endl;
    for(int i=0;i<adjMat.size();i++){
        cout<<i<<" : ";
        for(int j=0;j<adjMat.size();j++){
            cout<<adjMat[i][j]<<" "; 
        }
        cout<<endl;
    }
    cout<<"\n======================================\n";
    
    
}
void Graph :: display(vector<vector<int>>&adjList){
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

int main()
{

    // Adjacency Matrix
    // Graph g1(5,true); //directecd graph
    Graph g1(5);
    g1.addEdge(0,1);
    g1.addEdge(0,2);
    g1.addEdge(1,2);
    g1.addEdge(2,3);
    g1.addEdge(3,4);
    cout<<"\n\nAdjacency Matrix:";
    g1.display();


    // Adjacency List
    // Graph g2(true); // directed graph
    Graph g2;
    vector<vector<int>>adjList(5);
    g2.addEdge(adjList, 0, 1);
    g2.addEdge(adjList, 0, 2);
    g2.addEdge(adjList, 1, 2);
    g2.addEdge(adjList, 2, 3);
    g2.addEdge(adjList, 3, 4);

    cout<<"Adjacency List:";
    g2.display(adjList);


    return 0;
}