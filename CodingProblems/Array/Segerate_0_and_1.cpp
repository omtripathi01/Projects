#include<bits/stdc++.h>
using namespace std;

void segregate01(vector<int>&a){

    if(a.size() == 1) return;
    if(a.size() == 1 && a[0] == 0) return;

    int low = 0;
    int high = a.size()-1;
    while(low<high){
        if(a[low] == 0){
            low++;  
        }else{
            swap(a[low],a[high]);
            high--;
        }
    }
}

int main(){

    vector<int>arr =  {1,0,1,0,0,0,1};
    
    for(int i : arr)
        cout<<i<<" ";
    cout<<"\n";
    
    segregate01(arr);

    for(int i : arr)
        cout<<i<<" ";

    return 0;
}