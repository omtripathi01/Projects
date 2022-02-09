#include<bits/stdc++.h>
#define vec vector<int>
using namespace std;

template<typename T>
void display(vector<T>&v){
    for(T i : v)
        cout<<i<<" ";
    cout<<"\n";
}

int findMissing(vec &a){
    int sum_of_first_n_nos = (a.size()+1)*(a.size()+2)/2; 
    int sum = 0;
    for(int i : a)
        sum+=i;

    return sum_of_first_n_nos-sum;
}
// using above approach we can end up getting overflow error when n is very large  
// using xor so that there will not be any overflow situation
int findMiss(vec &a){

    int n  = a.size()+1;
    int xor_ = 0;
    for(int i=1;i<=n;i++)  // finding xor for n nums
        xor_^=i;
    
    for(auto i : a)        // then doing xor with array element so that common can cancel each other
        xor_^=i;           // A^A = 0
    
    return xor_;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vec a = {5,2,3,4,6,7,8,9};
    display(a);
    cout<<"Missing number from the series is : "<<findMiss(a)<<"\n";

    return 0;
}