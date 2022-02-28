// Problem:- We are given with a num and we have to find out all possible strings coding that can be form by 
// those numbers
// eg 1. num = 123
// 
#include<bits/stdc++.h>
using namespace std;

// map<string,int>mp is faster than map<int,string>mp

map<char,string>keypadMapping = {{'2',"abc"},
                                 {'3',"def"},
                                 {'4',"ghi"},
                                 {'5',"jkl"},
                                 {'6',"mno"},
                                 {'7',"pqrs"},
                                 {'8',"tuv"},
                                 {'9',"wxyz"},
                                             };

void generateAllPossibleStrings(string num){

    int n = keypadMapping[num[num.length()-1]].length();
    vector<string>vec;
    for(int i=0;i<n;i++){
        string s(1,keypadMapping[num[n-1]][i]);
        vec.push_back(s);
    }
    
    for(int i=num.length()-2;i>=0;i--){
        vector<string>temp1;
        for(int j=0;j<keypadMapping[num[i]].length();j++){
            vector<string>temp = vec;
            for(int k=0;k<temp.size();k++){
                string s(1,keypadMapping[num[i]][j]);
                temp[k] = s.append(temp[k]); 
            }
            for(auto s : temp)
                temp1.push_back(s);
        }
        vec = temp1;
    }
    sort(vec.begin(), vec.end());
    for(auto i : vec)
        cout<<i<<" ";
    cout<<"\n"<<vec.size();

}

vector<string>keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void generatePossibleCombinationsHelper(string &number, int index, string &resultSoFar, vector<string>&result){

    if(index >= number.size()){
        result.push_back(resultSoFar);
        return;
    }

    int digit = number[index] - '0'; // as values stored at are "123" so to convert char to int we do - '0' 
    string possibleMoves = keypad[digit];
    for(int i=0; i<possibleMoves.length();i++){

        resultSoFar.push_back(possibleMoves[i]);
        generatePossibleCombinationsHelper(number, index+1, resultSoFar, result);
        // backtracking
        resultSoFar.pop_back();

    }

}


vector<string> generatePossibleCombinations(string number){
    vector<string>result;
    string resultSoFar = "";
    generatePossibleCombinationsHelper(number, 0, resultSoFar, result);
    return result;
}



int main()
{
    generateAllPossibleStrings("234");
    cout<<"\n\n";
    vector<string>res = generatePossibleCombinations("234");

    for(auto s : res)   
        cout<<s<<" ";

    return 0;
}