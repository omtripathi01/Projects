// Problem:- We are a given a grid or table with charaters in each cell and we will be given a word and we
// have to find out whether that word is present in the grid or not.
// We can search horizontally and vertically as well as horizontally and vertically both (L shape) 
// eg. 0 1 2 3
//   0 A B C E
//   1 S F C S
//   2 A D D D
// find "SEE" and "ABFD" it present in the word grid then return true otherwise return false
// constraints can move only in horizontal and vertical directions
// valid cases :- If word is present upside down 
//                If word is present in step format 
//                If word is present invert in horizontal manner ef  EES  
// invalid cases :- Word should not be in diagonal manner               


#include<bits/stdc++.h>
using namespace std;

template <typename T>
void display(vector<vector<T>>grid){
    cout<<"  ";
    for(int i=0;i<grid[0].size();i++)
        cout<<i<<" ";
    cout<<"\n";
    for(int i=0;i<grid.size();i++){
        cout<<i<<" ";
        for(int j=0;j<grid[0].size();j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }
}

// Improvement in the solution
// space complexity is O(mn)
// we can achieve space complexity as O(1)
// instead of creating a visited matrix to mark visited what we can do is we can make the modification 
// in wordGrid matrix itself ...so what we can do is we can simply replace the currently visited 
// element with any other character such as '.'
// and then when we backtrack then we replace it with the same char
#define POSSIBLE_MOVES 4
vector<int>xMoves = {0, 1, 0, -1};
vector<int>yMoves = {1, 0, -1, 0};
bool isSafe(vector<vector<char>>&wordGrid, string st, int index, int x, int y, vector<vector<bool>>&visited){
    int row = wordGrid.size();
    int col = wordGrid[0].size();
    if(x<0 || y<0 || x>=row || y>=col || visited[x][y] || wordGrid[x][y] != st[index])
        return false;
    return true;
}
bool findWordHelper(vector<vector<char>>&wordGrid, string st, int index, int x, int y, vector<vector<bool>>&visited){

    if(index >= st.length()){
        return true;
    }

    if(isSafe(wordGrid, st, index, x, y, visited)){
        // if we don't want to use visisted or we want to save space
        // char ch = wordGrid[x][y];
        // wordGrid[x][y] = '.';

        visited[x][y] = true;
        int nextX,nextY;
        for(int i=0;i<POSSIBLE_MOVES;i++){
            nextX = x+xMoves[i];
            nextY = y+yMoves[i];
            if(findWordHelper(wordGrid, st, index+1, nextX, nextY, visited)){
                return true;
            }
        }
        // wordGrid[x][y] = ch;
        visited[x][y] = false;
    }
    return false;
}


void findWord(vector<vector<char>>wordGrid, string st){

    
    
    vector<vector<bool>>visited(wordGrid.size(), vector<bool>(wordGrid[0].size(),false));
    int startIndex = 0;
    int row = wordGrid.size();
    int col = wordGrid[0].size();
    bool wordFound = false;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(st[0] == wordGrid[i][j] && findWordHelper(wordGrid, st, startIndex, i, j, visited)){
                cout<<"\n=======================word found=======================\n";
                display(visited);
                wordFound = true;
                break;
            }
        }
    }
    if(!wordFound)
        cout<<"\n=======================word not found=======================\n";



}
int main()
{
    int row = 3, col = 4;
    vector<vector<char>>wordGrid = {{'A','B','C','E'},
                                    {'S','F','C','S'},
                                    {'A','D','D','D'}};

    string input;
    getline(cin>>ws,input);
    cout<<"\n";
    display(wordGrid);
    cout<<"\n";

    findWord(wordGrid, input);


    return 0;
}