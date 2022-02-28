// Problem: An array is given to you and a value k is given to u and you have to find all the largest element
// it the window of size k 

// eg 1.{12,1,79,90,57,89,56} k =3
// first window of size k 12,1,79 -> 79  
// second window of size k 1,79,90 -> 90 and so on

#include<bits/stdc++.h>
using namespace std;

void maxInWindowOfSizeK(const vector<int>&arr, int k){

    int  n = arr.size();    
    if(k <= 0 && k>=n){
        cout<<"K can't be zero/ negative/ more than array size. "<<endl;
        return;
    }


    // naive approach theta(nk)
    int mx = INT_MIN;
    for(int i=0;i<=n-k;i++){
        mx = arr[i];
        int curr = i;
        cout<<"\n";
        for(int j=0;j<k;j++){
            cout<<arr[curr]<<" ";
            mx = max(arr[curr], mx);
            curr+=1;
        }
        cout<<" : "<<mx<<endl;
    }

    // O(nk)
    mx = INT_MIN;
    
    // first find the largest element among first k elements;

    for(int i=0;i<k;i++){
        mx = max(arr[i], mx);           
    }
    cout<<"\n"<<mx;
    for(int i=1;i<=n-k;i++){

        // if the first element of window is not equal to mx element then simply take maximum among new added
        // element and the previous max element
        if(arr[i-1] != mx){
            mx = max(arr[i+k-1], mx);
        }else{
            mx = INT_MIN;
            int curr = i;
            for(int j=0;j<k;j++){
                mx = max(arr[curr], mx);
                curr++;        
            }            
        }
        cout<<"\n"<<mx<<" ";
    }

}

// efficient sol using deque

void printMax(const vector<int>&arr, const int k){

    // we will use deque so in dq we will store elements(indexes) in such a way that max element index
    // is maintained at the top and we store the elements is decreasing order in dq
    int n = arr.size();
    deque<int>dq;

    // first store the first k elments in dq and the size of dq is atmost k 
    // to store elements we will follow some rules:-
    // we will delete and insert from the end
    // we will insert from the the front

    for(int i=0;i<k;i++){
        while(!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }

    for(int i=k;i<n;i++){
        cout<<arr[dq.front()]<<" ";
        // removing those elements from the dq which are not going to be part of current window or coming window
        // we remove the elements from the front of the stack 
        while(!dq.empty() && dq.front() <= i-k)
            dq.pop_front();

        // now we remove the element from the last we remove the element from the last of dq if it is 
        // smaller than curr element as we want to find the largest element of the window so there is 
        // no need to have smaller elements
        while(!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();
        
        dq.push_back(i);
    }
    cout<<arr[dq.front()]<<" ";
}



int main()
{

    vector<int>arr = {12, 1, 79, 90, 57, 89, 56};

    int k = 3;
    maxInWindowOfSizeK(arr,k);
    cout<<"\n\n";
    printMax(arr, k);

    return 0;
}