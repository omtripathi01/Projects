// Problem:- You are given with the NXN board and there are N queens you have to place N quuens such that
// no queen attack each other mean they are at safe position

#include<bits/stdc++.h>
using namespace std;

template <typename T>
void display(vector<vector<T>>grid){
    cout<<"  ";
    for(int i=0;i<grid.size();i++)
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
// placing queens row wise 

bool isSafe(vector<vector<int>>grid, int row, int col){

    // check col
    for(int i=0;i<row;i++){
        if(grid[i][col] == 1)
            return false;
    }
    // check diagonal
    // left diagonal
    int i=1,j=1;  
    while(row-i >=0 && col-j >=0){
        if(grid[row-i][col-j] == 1)
            return false;
        i++;j++;
    }

    // right diagonal
    i=1;j=1;
    while(row-i >=0 && col+j < grid.size()){
        if(grid[row-i][col+j] == 1)
            return false;
        i++;
        j++;
    }
    return true;
}
// there is no need to pass col as parameter because it is of no use
void placeNQueens(vector<vector<int>>&board, int n, int row, int col){

    if(row >= n){
        cout<<"\n\n";
        display(board);
        return;
    }
    for(int i=0;i<n;i++){
        // board[row][i] = 1;
        if(isSafe(board, row, i)){
            board[row][i] = 1;
            placeNQueens(board, n, row+1, 0);
            board[row][i] = 0;
        }
        // board[row][i] = 0;
    }
}

// placing queens col wise

bool isSafe1(vector<vector<bool>>board, int row, int col, int n){
    
    // check horizontal row as we are placing queens column wise
    for(int c=0; c<col;c++){
        if(board[row][c]){
            return false;
        }
    }

    // check for vertically downward and upward diagonals
    for(int r=row-1,c=col-1; r>=0 && c>=0; r--,c--){
        if(board[r][c])
            return false;
    }

    for(int r=row+1,c=col-1; r<n && c>=0; r++,c--){
        if(board[r][c])
            return false;
    }

    return true;
}
bool NQueenHelper(vector<vector<bool>>&board, int col, int n){

    if(col >= n)
        return true;

    for(int row = 0; row<n; row++){
        if(isSafe1(board, row, col, n)){
            board[row][col] = true;
            if(NQueenHelper(board, col+1, n))
                return true;
            board[row][col] = false;
        }
    }
    return false;
}

void NQueen(int n){
    vector<vector<bool>>board(n, vector<bool>(n, false));
    if(NQueenHelper(board, 0, n)){
        cout<<"Solution Exists: \n";
        display(board);
    }else{
        cout<<"Solution does not exist\n";
    }
}


int main()
{
    int n;
    cin>>n;

    vector<vector<int>>matrix(n,vector<int>(n, 0));
    display(matrix);
    cout<<"\n\n==================================\n";
    placeNQueens(matrix, n, 0, 0);
    // display(matrix);
    cout<<"\n\n==================================\n";
    NQueen(n);

    return 0;
}