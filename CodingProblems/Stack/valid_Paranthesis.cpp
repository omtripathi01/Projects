// Problem: A string will be given to you and it consists of only these 6 characters = {}[]()
// and you have to figure it out whether the given string consists of valid parenthesis
// Now what is valid parenthesis
// valid parenthesis the bracket will opens last should be closed first
// {[()]} // correct
// {[()}] // incorrect
#include<bits/stdc++.h>
using namespace std;

bool valid(string check){

    stack<char>st;
    st.push(check[0]);

    for(int i=1;i<check.length();i++){

        char c = (check[i] == '}') ? '{' : (check[i] == ']') ? '[' : (check[i] == ')') ? '(' :'#';
        if(c != '#'){
            if(!st.empty() && st.top() == c){
                st.pop();
                continue;
            }else{
                return false;
            }
        } 
        st.push(check[i]);
    }
    if(!st.empty())
        return false;
    return true;
}

// writing the code in much cleaner way

bool isMatching(char open, char closing){

    return ((open == '{' && closing == '}') || 
            (open == '[' && closing == ']') || 
            (open == '(' && closing == ')'));
}

bool isOpen(char ch){
    return ((ch == '{') || (ch == '[') || (ch == '('));
}

bool isBalanced(string str){

    stack<char>s;
    
    for( char ch : str){
        if(isOpen(ch)){
            s.push(ch);
        }else if(!s.empty() && isMatching(s.top(), ch)){
            s.pop();
        }else{
            return false;
        }
    }
    // write it like this
    // if(!s.empty()) return false;
    // return true;

    return s.empty();

}

bool checkValid(string s){

    int count = 0;
    for(char c : s){        
        if(c == '{' || c == '[' || c == '(')
            count++;
        else{
            count--;
            if(count < 0)
                return false;
        }
    }
        return count == 0;

    // int countCircular = 0, countSquare = 0, countCurly = 0; 
    //     if(c == '{')
    //         countCurly++;
    //     else if(c == '[')
    //         countSquare++;
    //     else if(c == '(')
    //         countCircular++;
    //     else{
    //         if(c == '}')
    //             countCurly--;
    //         else if(c == ']')
    //             countSquare--;
    //         else if(c == ')')
    //             countCircular--;
            
    //         if(countCircular < 0 || countCurly < 0 || countSquare < 0)
    //             return false;
    //     }
    // }
    // return (countCircular == 0 && countCurly == 0 && countSquare == 0);
}

int main()
{
    vector<string>testCase = {"{[()]}",
                              "{}()[]",
                              "[{}]()",
                              "[(]}]",
                              "()[]{}{",
                              "[][][]]",
                              "((((",
                              "{}))))",
                              "))))",
                              "(([]"};

    for(int i=0;i<testCase.size();i++){
        cout<<"\n";
        cout<<testCase[i]<<" -> "<<(isBalanced(testCase[i]) == true ? " valid " : " invalid ")<<endl;
        cout<<testCase[i]<<" -> "<<(checkValid(testCase[i]) == true ? " valid " : " invalid ")<<endl;
        cout<<"\n";
    }

    return 0;
}