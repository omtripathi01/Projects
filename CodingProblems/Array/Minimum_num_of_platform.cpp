// Problem:- We are given with two arrays which represents the arrival and departure of the train
// arv[] and dep[] and ith element of the arrays represents the arrival and departure of ith train
// and we have to find out minimum number of platforms required to give space to each train

// eg. arv[9:00, 09:15, 09:40]
//     dep[9:40, 10:00, 09:50]
// we have to find min num of platforms 
// output is 2 platforms 
#include<bits/stdc++.h>
using namespace std;

template <typename T>
void display(vector<T>a){
    cout<<"\n";
    for(T i : a)
        cout<<i<<" ";
    cout<<"\n";
}
int minPlatform(vector<float>arv, vector<float>dep){

    // int countPlatform = 1; // as atleast we need 1 platform for a train
    // int unoccupiedPlatform = 1;
    // int occupiedPlatform = 0;
    vector<float>platforms;  // it represents if train is at some platform then at what time
                             // it will depart
    platforms.push_back(dep[0]);
    bool updated = true;
    display(platforms);
    for(int i=1;i<arv.size();i++){
        updated = true;
        for(int j=0;j<platforms.size();j++){
            if(platforms[j] <= arv[i]){
                platforms[j] = dep[i];
                updated = false;
                break;
            }
        }
        if(updated){
            platforms.push_back(dep[i]);
        }
        display(platforms);
    }
    return platforms.size();

}

int main()
{
    vector<float>arv = {9.00, 9.15, 9.40, 9.45, 10.00};
    vector<float>dep = {9.40, 10.00, 9.50, 9.50, 10.30};

    cout<<"\nMinimum number of platform required: "<<minPlatform(arv, dep)<<"\n\n";


    return 0;
}