// Problem :- This is same as Generate_valid_parenthesis
// In this we are given with a value N and we have to generate all the possible combinations of bits of size of N
// eg 1. N = 2 
// 00 01 10 11 


#include<bits/stdc++.h>
using namespace std;

void generateAllBinaryCombo(int n, string stringSoFar){

    // base condition 
    if(stringSoFar.length() == n){
        cout<<stringSoFar<<"\n";
        return;
    }

    generateAllBinaryCombo(n, stringSoFar+"1");
    generateAllBinaryCombo(n, stringSoFar+"0");

}


int main()
{
 
    int n;
    cin>>n;
    generateAllBinaryCombo(n, "");
 
 
    return 0;
}