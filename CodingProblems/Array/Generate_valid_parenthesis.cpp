// Problem:- we are given an integer that tells how many pair of opening and closing parenthesis are there
// and we have to find out all combinations of valid parenthesis
// eg 1. n=2 ()(), (())
// eg 2. n=3 ()()(), (())(), ()(()), (()()), ((()))
// invalid parethsis is ))))(((( as it is not balanced
// we need to generate all valid balanced parenthesis


#include<bits/stdc++.h>
using namespace std;


void generateParenthesisHelper(int open, int close, string resultSoFar, vector<string>&result){

    if(open == 0 && close == 0){
        // cout<<resultSoFar<<" ";
        result.push_back(resultSoFar);
        return;
    }
    if(open > close)
        return;
    if(open>=0){
        generateParenthesisHelper(open-1, close, resultSoFar+"(", result);
    }
    // if(open <=close){
        generateParenthesisHelper(open, close-1, resultSoFar+")", result);      
    // }


    // if(open > close){
    //     // cout<<"return";
    //     // this is unbalanced condition so simply return
    //     return;
    // }
    // else{
    //     // open <= close
    //     cout<<"\nasdfasddasdfasdf";
    //     resultSoFar.push_back('(');
    //     generateParenthesisHelper(open-1, close, resultSoFar, result);
    //     resultSoFar.pop_back();

    //     resultSoFar.push_back(')');
    //     generateParenthesisHelper(open, close-1, resultSoFar, result);
    //     resultSoFar.pop_back();
    // }

    // else{
    //     resultSoFar.push_back('(');
    //     generateParenthesisHelper(open-1, close, resultSoFar, result);
    //     resultSoFar.pop_back();
    //     resultSoFar.push_back(')');
    //     generateParenthesisHelper(open, close-1, resultSoFar, result);
    //     resultSoFar.pop_back();
    // }

    // if(close>0 && open<=close){
    // }
}

vector<string> generateParenthesis(int n){
    vector<string>result;
    string resultSoFar = "";
    generateParenthesisHelper(n, n, resultSoFar, result);
    return result;
}

bool checkValidParanthesis(string s){

    int count = 0;
    for(char c : s){
        if(c == '(')
            count++;
        else if(c == ')'){
            count--;
            if(count < 0) return false;
        }
    }
    return count == 0;

}


int main()
{
    int n;
    cin>>n;
    vector<string>result = generateParenthesis(n);
    for(auto s : result)
        cout<<s<<" ";

    vector<string>testCases = {"()()",")(","(()))","(((())","))"};
    
    for(string testCase : testCases){
        cout<<"\n"<<testCase<<" : ";
        if(checkValidParanthesis(testCase))
            cout<<"valid";
        else    
            cout<<"invalid";
    }


    return 0;
}