//AlgoExpert
// find sizes of all rivers...rivers can be horizontal and vertical but not diagonal
// 0 --> block
// 1 --> river
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
    cout<<"\n\n";
}
void check(vector<vector<int>>&mat,int i, int j, int &length){
    mat[i][j] = 0;
    length++;
    // traverse in all the directions
    // check for the left cell of the current cell
    if(j-1 >=0 && mat[i][j-1] == 1){
        mat[i][j-1] = 0;
        check(mat, i,j-1, length);
    }
    // check for the right cell of the current cell
    if(j+1 < mat[0].size() && mat[i][j+1] == 1){
        mat[i][j+1] = 0;
        check(mat,i, j+1, length);
    }
    // check for the below cell of the current cell
    if(i+1 < mat.size() && mat[i+1][j] == 1){
        mat[i+1][j] == 0;
        check(mat,i+1,j, length);
    }

    // check for the above cell of the current cell
    if(i-1 >= 0 && mat[i-1][j] == 1){
        mat[i-1][j] = 0;
        check(mat, i-1, j, length);
    }
}

vector<int> riverSizes(vector<vector<int>>&mat){

    vector<int>result;
    // vector<vector<bool>>
    // first approach when we can modify mat matrix

    for(int i=0;i<mat[0].size();i++){
        for(int j=0;j<mat.size();j++){
            int length =0;
            if(mat[i][j] == 1){
                // mat[i][j] = 0;
                // length++;
                check(mat,i, j, length);
                result.push_back(length);
            }
        }
    }
    return result;

}

int main(){

    vector<vector<int>>mat = {{1,0,0,1,0},
                              {1,0,1,0,0},
                              {0,0,1,0,1},
                              {1,0,1,0,1},
                              {1,0,1,1,0}};

    display(mat);
    vector<int>lengths = riverSizes(mat);
    // display(mat);
    if(lengths.size() == 0){
        cout<<"No rivers"<<endl;
    }
    for(int length : lengths){
        cout<<length<<" ";
    }

    return 0;
}