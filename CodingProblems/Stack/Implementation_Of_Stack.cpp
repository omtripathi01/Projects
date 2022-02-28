// Stack (LIFO last in first out DS)

#include<bits/stdc++.h>
using namespace std;
// Implenting Stack using vector
template <class T>
class Stack{

    int sze;
    int tp;
    vector<T>data;
    public:
        Stack():
        sze(0),tp(0)
        {}

    void push(T data);
    void pop();
    T top();

    int size();
    bool empty();

};

template <class T>
void Stack<T> :: push(T d){
    data.push_back(d);
    tp = sze++;
}

template <class T>
void Stack<T> :: pop(){
    if(sze <= 0){
        cout<<"Stack is empty."<<endl;
        return;
    }
    data.pop_back();
    sze--;
    tp--;
}

template <class T>
T Stack<T> :: top(){
    if(sze == 0){
        cout<<"Stack is empty."<<endl;
        return -1;
    }
    return data[tp];
}

template <class T>
int Stack<T> :: size(){
    return sze;
}

template <class T>
bool Stack<T> :: empty(){
    return sze == 0;
}

int main()
{

    Stack<char>st;
    st.push('A');
    st.push('B');
    st.push('C');
    st.push('D');

    while(!st.empty()){
        cout<<st.top()<<"\n";
        st.pop();
    }


    
    return 0;
}