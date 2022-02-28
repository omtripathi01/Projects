// Problem1:- Given a matrix of mXn we need to find out no. of ways to reach from source to destination
// Rules: we can only make to moves which are from left to right and from top to bottom and you can move only 1 
// cell at a time
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

// no of ways to reach end start = mat[0][0] and dest = mat[m][n] 

// when no obstacles are there 

int countPaths(vector<vector<int>>&mat){

    int row = mat.size();
    int col = mat[0].size();

    for(int i=0;i<col;i++)
        mat[0][i] = 1;

    for(int i=0;i<row;i++)
        mat[i][0] = 1;

    display(mat);
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++)
            mat[i][j] = mat[i-1][j]+mat[i][j-1];
    }
    display(mat);
    return mat[row-1][col-1];

}

// it's a DP based solution
// countPaths when there are obstacles
int countPaths1(vector<vector<int>>mat){

    int row = mat.size();
    int col = mat[0].size();

    // doing unnecessary work
    // for(int i=0;i<row;i++)
    //     mat[i][0] = (mat[i][0] == -1 ? -1 : 1);
    
    // for(int i=0;i<col;i++)
        // mat[0][i] = (mat[0][i] == -1 ? -1 : 1);

    for(int i=0;i<row;i++)
        if(mat[i][0] == -1){
            mat[i][0] = 0;
            i++;
            while(i<row){
                mat[i][0] = 0;
                i++;
            }
            break;
        }else{
            mat[i][0] = 1;
        }
    
    for(int i=0;i<col;i++)
        if(mat[0][i] == -1){
            mat[0][i] = 0;
            i++;
            while(i<col){
                mat[0][i] = 0;
                i++;
            }
            break;
        }else{
            mat[0][i] = 1;
        }       

    display(mat);

    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){

            if(mat[i][j] == -1){
                mat[i][j] = 0;
            }else{
                mat[i][j] = mat[i-1][j] + mat[i][j-1];
            }

            // if((mat[i-1][j] == -1 && mat[i][j-1] == -1) || mat[i][j] == -1)
            //     continue;
            // else if(mat[i-1][j] == -1)
            //     mat[i][j] = mat[i][j-1];
            // else if(mat[i][j-1] == -1)   
            //     mat[i][j] = mat[i-1][j];
            // else    
            //     mat[i][j] = mat[i-1][j] + mat[i][j-1];

        }
    }

    display(mat);

    return mat[row-1][col-1];
}
/*
// same problem but now rules are changed a bit 
// now instead of moving in just two directions(right and down) u can move in any direction 
// i.e. up , right, left, down the cell
*/

// 1--> Obstacle
// 0--> Allowed
bool isSafe(vector<vector<int>>mat, vector<vector<int>>&visited, int row, int col){
    if(row<mat.size() && col<mat[0].size() && mat[row][col] != 1 && visited[row][col] != 1)
        return true;
    return false;
}
int totalPaths =0;
void countPaths2(vector<vector<int>>mat, vector<vector<int>>visited, int row, int col){

    if(row == mat.size()-1 && col == mat[0].size()-1){
        totalPaths++;
        cout<<"\nPath "<<totalPaths<<" :\n";
        display(visited);
        return;
    }
    visited[row][col] = 1;
    if(isSafe(mat, visited, row, col+1)){              // right movement 
        visited[row][col+1] = 1; 
        countPaths2(mat, visited, row, col+1);
        visited[row][col+1] = 0;
    }
    if(isSafe(mat, visited, row+1, col)){              // down movement
        visited[row+1][col] = 1;
        countPaths2(mat, visited, row+1, col);
        visited[row+1][col] = 0;
    }
    if(isSafe(mat, visited, row, col-1)){              // left movement 
        visited[row][col-1] = 1;
        countPaths2(mat, visited, row, col-1);
        visited[row][col-1] = 0;
    }
    if(isSafe(mat, visited, row-1, col)){              // upwards movement
        visited[row-1][col] = 1;
        countPaths2(mat, visited, row-1, col);
        visited[row-1][col] = 0;
    }
}

int wrapperFunc(vector<vector<int>>mat, vector<vector<int>>visited){
    // totalPaths = 0;
    countPaths2(mat, visited, 0, 0);
    return totalPaths;
}

// doing same thing but little bit advance manner

// by defining moves in such manner we can solve problems with greater ease and if there are more
// moves such we as to move diagonally then we can simply define them and the chances of error will be less

void display(vector<vector<bool>>mat){        
    cout<<endl;
    cout<<"  ";
    for(int i=0;i<mat[0].size();i++){
        cout<<i<<" ";
    }
    cout<<endl;

    for(int row=0;row<mat.size();row++){
        cout<<row<<"  ";
        for(int col=0;col<mat[0].size();col++){
            cout<<mat[row][col]<<" ";
        }
        cout<<endl;
    }

    cout<<"\n";
}
//=============================================================================================//

#define POSSIBLE_MOVES 4
vector<int> xMoves = {-1, 0, 1, 0};
vector<int> yMoves = {0, 1, 0, -1};


bool isSafe1(const vector<vector<int>>&mat, vector<vector<bool>>&visited,
            int x, int y, int row, int col){
    
    if(x<0 || y<0 || x>= row || y>=col || visited[x][y] || mat[x][y])
        return false;
    return true;
}

void countPathAllDirectionHelper(const vector<vector<int>>&mat, vector<vector<bool>>&visited,
                                  int x, int y, int row, int col, int &result){
    //base condition
    if(x == row-1 && y == col-1){
        visited[x][y] = true;
        result++;
        cout<<"\nPath "<<result<<" :\n";
        display(visited);
        return ;
    }

    // the destination has not reached yet

    if(isSafe1(mat, visited, x, y, row, col)){
        visited[x][y] = true;
        
        // 4 Directions
        int nextx,nexty;
        for(int i = 0 ; i < POSSIBLE_MOVES ; i++){
            nextx = x+xMoves[i];
            nexty = y+yMoves[i];
            countPathAllDirectionHelper(mat, visited, nextx, nexty, row, col, result);
        }
        // countPathAllDirectionHelper(mat, visited, x+1, y, row, col, result);
        // countPathAllDirectionHelper(mat, visited, x, y-1, row, col, result);
        // countPathAllDirectionHelper(mat, visited, x-1, y, row, col, result);
        // countPathAllDirectionHelper(mat, visited, x, y+1, row, col, result);

        visited[x][y] = false;
    }
}


int countPathAllDirection(const vector<vector<int>>&mat){

    int row = mat.size();
    if(row == 0)
        return 0;
    int col = mat[0].size();

    vector<vector<bool>>visited(row, vector<bool>(col, false));    
    int result = 0;

    countPathAllDirectionHelper(mat, visited, 0, 0, row, col, result);

    return result;

}


int main()
{
    // int row = 4, col=5;
    // vector<vector<int>>matrix(row, vector<int>(col,0));
    // cout<<"No. of ways to reach end when no obstacles are there : "<<countPaths(matrix)<<"\n";


    // vector<vector<int>>matrix1(row, vector<int>(col, 0));
    // // Obstacle    --> -1
    // // No Obstacle -->  0
    // matrix1[1][2] = -1;
    // matrix1[2][1] = -1;
    // matrix1[2][3] = -1;
    // matrix1[0][3] = -1;
    // // matrix1[3][0] = -1;
    // // matrix1[2][4] = -1;
    
    // cout<<"\n\n";
    // display(matrix1);

    // int num_Paths = countPaths1(matrix1);
    // cout<<"\n\nNo. of paths when obstracles are there : "<<(num_Paths == -1?"we cannot reach end" : to_string(num_Paths));


    vector<vector<int>>matrix2 = {{0,1,1,1,1},
                                  {0,0,0,0,0},
                                  {0,0,0,1,0},
                                  {1,1,1,1,0},
                                  {1,1,1,1,0}};
    vector<vector<int>>visited(matrix2.size(), vector<int>(matrix2[0].size(), 0));
    
    cout<<"\n\n";
    display(matrix2);

    // cout<<"\nTotal num of paths when we can make all around movement : "<<wrapperFunc(matrix2, visited)<<"\n\n";
  

    cout<<"\nTotal num of paths when we can make all around movement : "<<countPathAllDirection(matrix2)<<"\n\n";

    return 0;
}