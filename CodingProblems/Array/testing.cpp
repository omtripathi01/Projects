#include<bits/stdc++.h>
using namespace std;
int main()
{

    // int n =10;
    // int a;
    // while(cin.peek() == '\n'){
    //     cin>>a;
    //     // cout<<a<<" ";
    // }
    int n;
    cin>>n;
    // int e;
    // vector<int>a(n,-1);
    // for(int i=0;i<n;i++){
    //     cin>>a[i];
    // }
    // for()


    // int xor_=0;
    // for(int i=1;i<=n;i++)
    //     xor_^=i;
    // vector<int>check(n+1,0);
    vector<int>arr;
    while(true){
        int a;
        cin>>a;
        arr.push_back(a);
        if(cin.peek()=='\n')
            break;
        // cout<<a<<" ";
        // check[a] = 1;
        // xor_^=a;
    }
    // cout<<xor_<<"endl";
    // if(xor_ == 0)
    //     cout<<"yes";
    // else    
    //     cout<<"no";
    // cout<<"\n";
    // for(auto i : check)
    //     cout<<i<<" ";
    // bool flag = true;
    // for(int i=1;i<=n;i++){
    //     if(check[i] == 1){
    //         continue;
    //     }
    //     else{
    //         flag = false;
    //         cout<<"no";
    //         break;
    //     }
    // }
    // if(flag)
    // cout<<"yes";
    cout<<arr.size();
    if(arr.size() == n)
        cout<<"yes";
    else    
        cout<<"no";

    return 0;
}
