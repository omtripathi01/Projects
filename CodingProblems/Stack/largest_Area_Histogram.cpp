// Problem: Largest Area in Histogram 
// A array is given to you which consists of heights of bars and width of each bar is 1 unit and you have
// Calculate the largest area of the rectangle

// arr = {6,2,5,4,5,1,6}

#include<bits/stdc++.h>
using namespace std;

void display(vector<int>arr){
    cout<<"\n";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<(arr[i+1] >= 0 && i<arr.size() ?"  " : " ");
    }
    cout<<"\n";
}

// navive method
// we will consider each bar as smallest bar and we will go on left of it and find all the consecutive bars
// which are larger than or equal to the current bar and same thing we will do on the right side of the bar

// O(n^2)
int getMaxArea(const vector<int>&arr){

    int mxArea = 0;

    for(int i=0;i<arr.size();i++){

        int currBar = arr[i];
        for(int j = i-1;j>=0;j--){
            if(arr[j] >= arr[i])
                currBar += arr[i];
            else    
                break; 
        }
        for(int j = i+1;j<arr.size();j++){
            if(arr[j] >= arr[i])
                currBar += arr[i];
            else    
                break; 
        }
        mxArea = max(mxArea, currBar);
    }

    return mxArea;

}

// better Solution O(n)
// find previous smaller and next smaller elements


// in previous smaller if perv smaller doesn't exist then use -1 to represent it
vector<int> previousSmaller(const vector<int>&arr){
    vector<int>res;
    res.push_back(-1);
    stack<int>st;
    st.push(arr[0]);

    for(int i = 1; i<arr.size();i++){
        if(!st.empty() && arr[i] < st.top()){
            st.pop();
            while(!st.empty() && arr[i] < st.top()){
                st.pop();        
            }
        }else if(!st.empty()){
            res.push_back(st.top());
        }
        st.push(arr[i]);
        if(res.size() == i)
            res.push_back(-1);
    }
    return res;
    
}

// in next smaller if next smaller doesn't exist then use size of arr to represent it

vector<int> nextSmaller(const vector<int>&arr){

    int n = arr.size();
    vector<int>res(n, -1);
    stack<int>st;
    st.push(arr[n-1]);

    for(int i=n-2; i>=0; i--){
        if(arr[i] > st.top()){
            res[i] = st.top();
            st.pop();
        }else if(!st.empty()){
            st.pop();
            while(!st.empty() && arr[i] > st.top())
                st.pop();
        }
        st.push(arr[i]);
    }
    return res;
}

// better sol 
// tc -> O(n)  sc O(4n)  as we are using 2 stacks and 2 arrays to store the next and prev smaller

int getMaxArea1(const vector<int>&arr){

    int n = arr.size();
    int res=0;
    int ps[n],ns[n];
    
    stack <int> s;
    s.push(0);
    for(int i=0;i<n;i++){
        while(s.empty()==false && arr[s.top()]>=arr[i])
            s.pop();
        int pse=s.empty()?-1:s.top();
        ps[i]=pse;
        s.push(i);
    }
    
    while(s.empty()==false){
        s.pop();
    }
    
    s.push(n-1);
    for(int i=n-1;i>0;i--){
        while(s.empty()==false && arr[s.top()]>=arr[i])
            s.pop();
        int nse=s.empty()?n:s.top();
        ns[i]=nse;
        s.push(i);
    }
    
    for(int i=0;i<n;i++){
        int curr=arr[i];
        curr+=(i-ps[i]-1)*arr[i];
        curr+=(ns[i]-i-1)*arr[i];
        res=max(res,curr);
    }
    return res;
    
 
}

// effecienct sol

int getMaxArea2(const vector<int>&arr){

    int n = arr.size();
    stack<int>s;
    int res = 0;
    int curr = 0;
    for(int i=0;i<n; i++){
        while(s.empty() == false && arr[s.top()] >= arr[i]){

            int tp = s.top();
            s.pop();
            curr = arr[tp] * (s.empty() ? i:(i-s.top()-1));
            res = max(res, curr);
        }
        s.push(i);
    }
        // process the remaing elements of stack
        // now stack contains those elements which do not have any next smaller element

        while(s.empty() == false){
            int tp = s.top();
            s.pop();
            curr = arr[tp] * (s.empty() ? n : (n-s.top()-1));
            res = max(res, curr);
        }
    return res;
}

int maxArea(const vector<int>&arr){

    if(arr.size() == 0)
        return 0;
    if(arr.size() == 1)
        return arr[0];

    // stack is storing indexes of elements 
    // we are storing bars in increasing heights in stack
    // means the top of the stack is the highest bar among all the bars below it 
    stack<int>s;
    int maxAr = 0, currAr = 0, topElement;
    int i =0;
    while(i<arr.size()){

        if(s.empty() || arr[s.top()] <= arr[i]){
            s.push(i);
            i++;
        }else{
            topElement = s.top();
            s.pop();
            if(s.empty()){
                currAr = arr[topElement]*i;
            }else{
                currAr = arr[topElement] * (i - 1 - s.top());
            }
        }
        maxAr = max(maxAr, currAr);
    }
    // we are left with those bars which are highest or we don't find any larger bar than them
    while(!s.empty()){
        topElement = s.top(); s.pop();
        if(s.empty()){
            currAr = arr[topElement]*i;
        }else{
            currAr = arr[topElement]*(i-1-s.top());
        }
        maxAr = max(maxAr, currAr);
    }
    return maxAr;
}



int main()
{

    // vector<int>barHeights = {6,2,5,4,1,5,6};
    // cout<<"Mx Area of Histogram: "<<getMaxArea(barHeights);

    vector<int>arr = {6,2,5,4,5,1,6};//{4,2,1,5,3,6,7};
    display(arr);

    cout<<getMaxArea1(arr)<<" "<<getMaxArea2(arr)<<" "<<maxArea(arr);

    return 0;
}

// next question similar to it is sliding window maximum