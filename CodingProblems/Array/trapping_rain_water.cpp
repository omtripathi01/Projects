// Problem:- Trapping Rain Water 
// A array will be given to you which has heights of tower and you have to find out how much water can be trapped
// between those towers 
// eg. {2,3,0,2,1,5,2,5} // 6 units of water
// 

#include<bits/stdc++.h>
using namespace std;
// O(n) t.c. and O(n) s.c.
// Approach:-
// 1. We will first compute the lmax and rmax and store them in an array lmax[] and rmax[]
// 2. then we will find out the min of lmax[i] and rmax[i] and store them at new vector res[i]
// 3. then we will subtract heights[i] from res[i] and update res[i]
// 4. then simply add all elements of res and that will be our final result
template <typename T>
void display(vector<T>a){
    cout<<"\n";
    for(T i : a)
        cout<<i<<" ";
    cout<<"\n";
}


int trappingRainWater(vector<int>heights){

    int water = 0;
    int n = heights.size();
    vector<int>lmax(n);
    vector<int>rmax(n);
    int j = n-2;
    lmax[0] = heights[0];
    rmax[n-1] = heights[n-1];

    // for computing lmax traverse from left to right and keep on tracking max
    for(int i=1;i<n;i++){
        lmax[i] = max(lmax[i-1], heights[i]);
    }
    
    // for computing rmax traverse from right to left and keep on tracking max
    for(int j=n-2; j>=0;j--){
        rmax[j] = max(rmax[j+1], heights[j]);
    }

    // for(int i=1;i<n-1;i++){
    //     lmax[i] = max(lmax[i-1], heights[i]);
    //     rmax[j] = max(rmax[j+1], heights[j]);
    //     j--;
    // }
    display(lmax);
    display(rmax);


// no need to use this one more temp array
    // vector<int>res(n);
    // for(int i=0;i<n;i++)
    //     res[i] = min(lmax[i], rmax[i]);
    // display(res);
    // for(int i=0;i<n;i++){
    //     res[i] -= heights[i];
    // }
    // display(res);
    // for(auto i : res)
    //     water+=i;


    for(int i=0;i<n;i++){
        water += min(lmax[i], rmax[i])-heights[i]; 
    }


    return water;
}

// try to solve it using one extra vector instead of using two 
// try to optimize it more
int trappingRainWater1(const vector<int>&h){
    int n  = h.size();
    if(n<=1) return 0;

    int water = 0;
    vector<int>lmax(n);
    



}


int main()
{
    vector<int>heights = {2,3,1,2,4,2,3};//{2,3,0,2,1,5,2,5};
    cout<<"\nRain water that can be trapped: "<<trappingRainWater(heights)<<" units\n";

    return 0;
}