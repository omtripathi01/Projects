#include<bits/stdc++.h>
using namespace std;
int main(){

    int a =10;
    // results of left and right shift are always integer and they are always performed on integers
    cout<<(a<<1)<<endl;  //left shift by 1 mean multiply the num a by 2  a*2
    cout<<(a>>1)<<endl;  //right shift by 1 mean divide the num a by 2

    cout<<(a<<3)<<endl; // left shift by 3(or n) means multiply the num a by 2^3  so res = a*2^3
    cout<<(a>>3)<<endl; // right shift by 3(or n) means divide the num a by 2^3  so res = a/2^3



    return 0;
}