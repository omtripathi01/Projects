// check whether the second array is subsequence of first array or not
// subsequence means that elements of second array should be present in the same order in first array 
// it is not necessary that they are adjacent 

#include<bits/stdc++.h>
using namespace std;

void check(vector<int>&a1, vector<int>&a2){
    int i=0,j=0;
    while(i<a1.size() && j<a2.size()){
        if(a1[i] == a2[j]){
            i++;
            j++;
        }else{
            i++;
        }
    }
    if(j == a2.size()){
        cout<<"Is a subsequence"<<endl;
    }else{
        cout<<"Not a subsequence"<<endl;
    }

}

int main(){

    vector<int>arr1 = {5,1,22,25,6,-1,8,10};
    vector<int>arr2 = {1,6,-1,10,11};

    check(arr1,arr2);


  



    return 0;
}