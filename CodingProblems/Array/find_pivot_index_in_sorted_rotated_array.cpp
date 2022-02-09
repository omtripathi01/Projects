#include<bits/stdc++.h>
#define vec vector<int>
using namespace std;
// O(n)
int findPivot(vec &a){
    bool increasing = false;
    if(a[0]<a[1]) increasing = true;
    int pivot  = -1;
    for(int i=2;i<a.size();i++){
        if(increasing){
            if(a[i-1]<a[i])
                continue;
            else{
                pivot = a[i];
                break;
            }               
        }else{
            if(a[i-1]>a[i])
                continue;
            else{
                pivot = a[i];
                break;
            } 
        }
    }
    return pivot;

}
// finding the local minima i.e. find the element whose left and right are larger than it
// O(n)
int findPivot1(vec &a){

    int n = a.size();
    int pivot = -1;
    for(int i=1;i<n-1;i++){
        if(a[i]<a[i+1] && a[i-1]>a[i]){
            pivot = a[i];
            break;
        }
    }
    return pivot;

}
// so whenever the question is given to u and it is said that the array is sorted then always 
// remember that there is going to be O(logn) sol i.e. we have to do binary search in it    

// O(logn) sol
int findPivotHelper(vec &a, int start, int end){
    // condition when there is no pivot in the given array
    if(start >= end){ 
        return -1;
    }

    int mid = start + (end-start)/2; // it is same as (start+end)/2 but what we use .. can handle
                                     // overflow condition suppose start and end = 10^9 then 
                                     // overflow will be there that is mid cannot hold such large
                                     // value so we use this to play safe

    // base ==> Is middle value the Pivot?
    if(start < mid && a[mid-1] > a[mid]){
        return mid;
    }
    if(mid < end && a[mid] > a[mid+1]){
        return mid+1;
    }

    // recursive
    if(a[start] < a[mid]){
        // first section is sorted 
        // pivot is in second section        
        return findPivotHelper(a, mid+1, end);
    }
    else{
        // second section is sorted 
        // pivot is in first section
        return findPivotHelper(a, start, mid-1);
    }
    
}
int findPivot2(vec &a){
    int res = findPivotHelper(a, 0, a.size()-1);
    if(res == -1)
        return -1;
    return a[res];
}



int main(){

    vec a = {2,1,5,4,3};  //{3,4,5,1,2};

    cout<<"Pivot is : "<<findPivot(a)<<" "<<findPivot1(a)<<" "<<findPivot2(a);


    return 0;
}