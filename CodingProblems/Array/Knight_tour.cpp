// Problem:- Knight Tour Problem in this we are given knight and we have to move that knight in such a manner
// so that we can traverse the whole board

#include<bits/stdc++.h>
using namespace std;

void display(vector<vector<int>>mat){        
    cout<<endl;
    cout<<"    ";
    for(int i=0;i<mat[0].size();i++){
        cout<<i<<"   ";
    }
    cout<<endl;

    for(int row=0;row<mat.size();row++){
        cout<<row<<"   ";
        for(int col=0;col<mat[0].size();col++){
            cout<<mat[row][col]<<(((mat[row][col+1]>9 || mat[row][col+1] <0) && col<mat[0].size())?"  ":"   ");
        }
        cout<<endl;
    }

    cout<<"\n";
}

# define POSSIBLE_MOVES 8
vector<int>xMoves = {2, 1, -1, -2, -2, -1, 1, 2};
vector<int>yMoves = {1, 2, 2, 1, -1, -2, -2 ,-1};

static int num = 1;

bool isSafe(vector<vector<int>>board, int x, int y){
    if(x>= board.size() || y>=board[0].size() || x<0 || y<0 || board[x][y] != 0)
        return false;
    return true;
}
bool knightTourHelper(vector<vector<int>>&board, int n, int x, int y, int count){

    if(count >= n*n){
        // cout<<"true";
        // display(board);
        return true;
    }
    if(isSafe(board, x, y)){
        board[x][y] = count;
        for(int moves = 0; moves<POSSIBLE_MOVES; moves++){
            int nextX,nextY;
            nextX = x+xMoves[moves];
            nextY = y+yMoves[moves];
            if(knightTourHelper(board, n, nextX, nextY, count+1)){
                return true;
            }
        }
        board[x][y] = 0;
    }
    return false;

}

void knightTour(int n){
    vector<vector<int>>board(n, vector<int>(n,0));
    int count = 1;
    if(knightTourHelper(board, n, 0, 0, count)){
        display(board);
        return;
    }
}
int main()
{
    // vector<vector<int>>board;
    int n;
    cin>>n;
    knightTour(n);
    return 0;
}