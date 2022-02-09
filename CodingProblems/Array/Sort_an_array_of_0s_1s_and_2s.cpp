#include<bits/stdc++.h>
using namespace std;

// for testing 
// void sort012(int a[], int n){
//     if(n==1) return;
//     if(n==2 && a[0] == 0) return;

//     int end = n-1;
//     int begin = 0;
//     for(int i=0;i<n;i++){
//         cout<<"i = "<<i<<" : ";
//         for(int j=0;j<n;j++)
//             cout<<a[j]<<" ";
//         cout<<"===>";
        
//         if(a[i] == 0){
//         for(int j=0;j<n;j++)
//             cout<<a[j]<<" ";
//             continue;
//         }
//         else if(a[i] == 2){
//             while(end>i && a[end] == 2)
//                 end--;
//             if(end == i){
//                 for(int j=0;j<n;j++)
//                     cout<<a[j]<<" ";
//                 cout<<"\n";
//                 break;
//             }
//             swap(a[i], a[end]);
//             // end--;
//         }
//         else{
//             begin = i+1;
//             bool flag = true;  // flag true means there are no more 0's after current i
//             while(begin<n && a[begin] != 0){
//                 begin++;
//                 // flag == false;
//             }
//             if(begin == n){
//                 for(int j=0;j<n;j++)
//                     cout<<a[j]<<" ";
//                 cout<<"\n";
//                 continue;
//             }
//             // if(flag==false)
//                 swap(a[i], a[begin]);
//         }

//         // cout<<"i = "<<i<<" : ";
//         for(int i=0;i<n;i++)
//             cout<<a[i]<<" ";
//         cout<<"\n";
//     }

// }

//tle
// void sort012(int a[], int n){
//     if(n==1) return;
//     if(n==2 && a[0] == 0) return;

//     int end = n-1;
//     int begin = 0;
//     for(int i=0;i<n;i++){        
//         if(a[i] == 0)
//             continue;
//         else if(a[i] == 2){
//             while(end>i && a[end] == 2)
//                 end--;
//             if(end == i){
//                 break;
//             }
//             swap(a[i], a[end]);
//             // end--;
//         }
//         else{
//             begin = i+1;
//             while(begin<n && a[begin] != 0){
//                 begin++;
//             }
//             if(begin == n){
//                 continue;
//             }
//                 swap(a[i], a[begin]);
//         }
//     }
// }

void sort012(int a[], int n)
{
    int lo = 0;
    int hi = n - 1;
    int mid = 0;

    // Iterate till all the elements
    // are sorted
    while (mid <= hi) {
        switch (a[mid]) {

        // If the element is 0
        case 0:
            swap(a[lo++], a[mid++]);
            break;

        // If the element is 1 .
        case 1:
            mid++;
            break;

        // If the element is 2
        case 2:
            swap(a[mid], a[hi--]);
            break;
        }
    }
}



int main(){

    int arr[] = {1,0,1,0,1};//{2,2,1,1,0} ;//{2,0,2,0};// {1,1,2,1,1,2}; //{1,0,2,1,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
    sort012(arr, n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    


    return 0;
}