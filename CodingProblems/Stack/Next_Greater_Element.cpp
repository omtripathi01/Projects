// Problem: Array will be given to you and you have to find out the next greater element for each index
// eg. 1 {4,5,2,8,6,7}
//       5,8,8,-1,7,-1 

// if there is no greater element on the right of some element then print -1 

#include<bits/stdc++.h>
using namespace std;

void display(vector<int>arr){
    cout<<"\n";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<(arr[i+1] >= 0 && i<arr.size() ?"  " : " ");
    }
    cout<<"\n";
}

// t.c. O(n^2) s.c. O(1)
vector<int> NextGreaterElement(const vector<int>&arr){
    vector<int>res;
    for(int i=0;i<arr.size();i++){
        // bool flag = true;
        for(int j=i+1;j<arr.size();j++){
            if(arr[j] > arr[i]){
                // flag = false;
                res.push_back(arr[j]);
                break;
            }
        }
        // if(flag){
        //     res.push_back(-1);
        // }
        if(res.size() == i){
            res.push_back(-1);
        }
    }
    return res;
}

// tc O(n)  sc O(n)
// traversing from right to left
vector<int> nextGreaterElement(const vector<int>&arr){

    int n = arr.size();
    vector<int>res(n,-1);
    stack<int>st;
    st.push(arr[n-1]);
    res[n-1] = -1;

    for(int i = n-2; i>=0; i--){

        if(st.top() > arr[i]){
            res[i] = st.top();
        }
        else{
            st.pop();
            while(!st.empty()){
                if(st.top() > arr[i]){
                    res[i] = st.top();
                    break;
                }
                st.pop();
            }
        }
        st.push(arr[i]);
    }
    return res;
}

// traversing from left to right 

// approcah is we check whether the top of stack is less than the current element then it means that the
// next greater element for the element on the top of stack is current element then print that element 
// and we keep on popping elements from the stack till the stack is not empty or till we get top elements 
// smaller than current element

void nextGreaterElement1(const vector<int>&arr){

    stack<int>s;
    s.push(arr[0]);

    for(int i=1;i<arr.size();i++){
        while(!s.empty() && s.top() < arr[i]){
            cout<<s.top()<<" -> "<<arr[i]<<endl;
            s.pop();
        }
        s.push(arr[i]);
    }

    // for remaining elements who have no greater element on right
    while(!s.empty()){
        cout<<s.top()<<" -> -1"<<endl;
        s.pop();
    }
}

int main()
{

    vector<int>arr = {4, 5, 2, 8, 6, 7};
    display(arr);

    vector<int>res = NextGreaterElement(arr);
    display(res);

    vector<int>res1 = nextGreaterElement(arr);
    display(res1);

    nextGreaterElement1(arr);



    return 0;
}