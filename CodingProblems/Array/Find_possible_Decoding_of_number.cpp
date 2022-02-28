// Problem:- a num will be given to u and u have to find out all possible decodings


#include<bits/stdc++.h>
using namespace std;

vector<char>decoding(27);

void generateAllDecodingsHelper(string &num, int index, string resultSoFar, vector<string>&result){

    if(index>=num.length()){
        // cout<<resultSoFar<<" ";
        result.push_back(resultSoFar);
        return;
    }
    
    int i = num[index]-'0';
    string s(1,decoding[i]);
    generateAllDecodingsHelper(num, index+1, resultSoFar+s, result);

    if(index<num.length()-1){
        int i = stoi(num.substr(index,2));
        string s(1,decoding[i]);
        generateAllDecodingsHelper(num, index+2, resultSoFar+s, result);
    }
}

vector<string> generateAllDecodings(string &num){

    vector<string>result;
    generateAllDecodingsHelper(num, 0, "", result);
    return result;
}

int main()
{

    decoding[0] = '#';
    for(int i = 1;i<=26;i++){
        decoding[i] = char(i+64);
    }
    for(int i=1;i<=26;i++)
        cout<<i<<" ";
    cout<<"\n";
    for(int i=1;i<=26;i++)
        cout<<decoding[i]<<(i<10?" ":"  ");

    string num = "122";
    cout<<"\n";

    vector<string> res = generateAllDecodings(num);

    return 0;
}