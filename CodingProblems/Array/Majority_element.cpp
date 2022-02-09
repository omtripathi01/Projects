// Problem:- We have to find out the element which is occuring more that n/2 times in an array 
// where n is the number of elements
// eg. {1,2,2,2,4,5} there is no majority element as 2 occurs only three times not more than 3 times
// eg. {2,3,4,5,5,5,5,5} 5 is majority element 
// return -1 if majority element is not present
#include<bits/stdc++.h>
using namespace std;

// t.c. O(n) s.c. O(n)
int findMajorityElement(const vector<int>&a){

    map<int,int>mp;
    for(auto i : a)
        mp[i]++;
    int n = a.size();
    for(auto i : mp){
        if(i.second > n/2)
            return i.first;
    }
    return -1;
}

// Boyer-Moore Majority Voting Algorithm
// this algo works on the fact that from given elements/candidates only on element occurs
// more than n/2 times
// in array there can be only one majority element

// O(n) time comp  and O(1) space comp

int findMajorityElement1(vector<int>&a){

    if(a.size() == 0)return -1;
    int majElement = a[0] , count =1;

    for(int i=1;i<a.size();i++){
        if(a[i] == majElement)
            count++;
        else    
            count--;
        if(count == 0){
            majElement = a[i];
            count = 1;
        }
    }

    // confirming that the element which we found is actually a majElement

    count = 0;
    for(int i=0;i<a.size();i++){
        if(majElement == a[i])
            count++;
    }
    if(count > a.size()/2)
        return majElement;
    return -1;
}

int main()
{

    vector<int>v = {1,2,1,2,2,2,3,2};
    int res = findMajorityElement(v);
    cout<<(res == -1 ? "No majority Element": to_string(res))<<endl;
    res = findMajorityElement1(v);
    cout<<(res == -1 ? "No majority Element": to_string(res))<<endl;

    return 0;
}