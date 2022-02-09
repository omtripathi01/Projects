// Problem--> Given a sorted array in which elements may repaeat and we have to find out the 
//            index of first and last occurence of the given num.

// eg:- arr =  {1,2,2,3,4,5,5,5,6}
// 2 --> first_occurence = 1 and last_occurence = 2
// 5 --> first_occurence = 5 and last_occurence = 7

#include<bits/stdc++.h>
#include<algorithm> // for lower_bound and upper_bound
using namespace std;

template <typename T>
void display(vector<T>&a){
    for(T i : a){
        cout<<i<<" ";
    }
    cout<<"\n";
}
// we can do linear search for element and then we can get its first and last occurence
// O(n)
void findFirstAndLast(vector<int>&a, int find){

    int first_occurence = -1;
    int last_occurence = -1;

    for(int i=0;i<a.size();i++){
        if(a[i] == find){
            first_occurence = last_occurence = i++;
            while(i<a.size() && a[i] == find)
                    i++;
            // if(a[i-1] == find)
            if(i==a.size() ||  a[i-1] == find)
                last_occurence = i-1;
            break;             
        }
    }
    cout<<"Element: "<<find<<"\nfirst occurence : "<<first_occurence
                     <<"\nlast occurence: "<<last_occurence;
}

// We can solve this in O(logn) t.c. as we can use the fact the array given to us is sorted
// so for serching the element we can use binary search 

void findFirstAndLast1(vector<int>&a, int find){

    int low = 0;
    int high = a.size()-1;
    int idx = -1;
    int first_occurence =-1, last_occurence = -1;
    while(low<=high){        
        int mid  = low + (high-low)/2;

        if(a[mid] == find){
            idx = mid;
            break;
        }
        else if(a[mid] < find){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    
    if(idx == -1){
        cout<<"Element not found"<<endl;
        return;
    }
    int i;
    i = first_occurence = last_occurence = idx;
    i--;
    while(i>0 && a[i] == find)
        i--;
    first_occurence = i+1;
    idx++;
    while(idx<a.size() && a[idx] == find)
        idx++;
    last_occurence = idx-1;
    cout<<"\nElement: "<<find<<"\nfirst occurence : "<<first_occurence
                     <<"\nlast occurence: "<<last_occurence;

}
// another approach
// going to use binary search to find first and last occurence separately 

int firstOccurence(vector<int>&a, int find){

    int n = a.size()-1;
    int low = 0;
    int high = n;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(a[mid] == find){
            // if we find the element then arise 
            // whether this is the first occurece... if it is then return it to check it simply do
            // check the left section as we are finding the first occurence so we will check in
            // the left section
            if(mid != 0 && a[mid-1] != find)
                return mid;
            // if it is not the first occurence then we will simply again do search in left 
            // section
            high = mid-1;
        }else if(a[mid] < find){
            low = mid+1;
        }else{
            high = mid-1;
        }
    } 
    return -1;


}
int lastOccurence(vector<int>&a, int find){
    int n = a.size()-1;
    int low = 0;
    int high = n;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(a[mid] == find){
            // if we find the element then arise some ques
            // whether this is the lat occurece... if it is then return.. it to check it simply do
            // check the right section as we are finding the last occurence so we will check in
            // the right section
            if(mid != n+1 && a[mid+1] != find)
                return mid;
            // if it is not the last occurence then we will simply again do search in right 
            // section
            low = mid+1;
        }else if(a[mid] < find){
            low = mid+1;
        }else{
            high = mid-1;
        }
    } 
    return -1;

}
void findFirstAndLast2(vector<int>&a, int find){

    int first_occurence = firstOccurence(a, find);
    if(first_occurence == -1){
        cout<<"\nElement not found";
        return;
    }
    int last_occurence = lastOccurence(a,find);
    cout<<"\nElement: "<<find<<"\nfirst occurence : "<<first_occurence
                     <<"\nlast occurence: "<<last_occurence;
}
// in case of java/c++  there are two functions which we can use to find first and last occurence
// we can use lower_bound and upper_bound 

// using built in function
// never use this approach
// void firstAndLastOccurence(vector<int>&a , int find){

//     // it is not an ideal sol because there are unwanted corner cases which we have to handle

//     vector<int>::iterator firstOccurence = lower_bound(a.begin(), a.end(), find);
//     vector<int>::iterator lastOccurence = upper_bound(a.begin(), a.end(), find);

//     cout<<(firstOccurence-a.begin())<<" "<<(lastOccurence-a.begin()-1);

// }


// wherever there is while loop in the func then we can make it a recursive solution

int recFirstOccurene(vector<int>&a, int find, int start, int end){

    // base condition
    if(start > end)
        return -1;

    // recursive calls 
    int mid = start + (end-start)/2;
    int idx = -1;
    if(a[mid] == find){
        idx = mid;
        if(a[mid-1] != find)
            return idx;
        idx = recFirstOccurene(a, find, start, mid-1);
    }else if(a[mid] > find){
        idx = recFirstOccurene(a, find, start, mid-1);
    }else{
        idx = recFirstOccurene(a, find, mid+1, end);
    }
    return idx;

}

int recLastOccurene(vector<int>&a, int find, int start, int end){

    // base condition
    if(start > end)
        return -1;

    // recursive calls 
    int mid = start + (end-start)/2;
    int idx = -1;
    if(a[mid] == find){
        idx = mid;
        if(a[mid+1] != find)
            return idx;
        idx = recLastOccurene(a, find, mid+1, end);
    }else if(a[mid] > find){
        idx = recLastOccurene(a, find, start, mid-1);
    }else{
        idx = recLastOccurene(a, find, mid+1, end);
    }
    return idx;

}

void findFirstAndLastOccurence(vector<int>&a, int find){

    int first_Occurence = recFirstOccurene(a, find, 0, a.size()-1);
    int last_Occurene = -1;
    if(first_Occurence != -1)
        last_Occurene = recLastOccurene(a, find, 0 , a.size()-1);

    cout<<"\nElement: "<<find<<"\nfirst occurence : "<<first_Occurence
                     <<"\nlast occurence: "<<last_Occurene;


}
int main()
{

    vector<int>a = {1,2,2,3,4,5,5,5,6};
    display(a);
    int find ;
    cin>>find;
    cout<<"\n";
    findFirstAndLast(a, find);
    cout<<"\n";
    findFirstAndLast1(a, find);
    cout<<"\n";
    findFirstAndLast2(a, find);
    cout<<"\n";
    // firstAndLastOccurence(a, find);
    findFirstAndLastOccurence(a, find);

    return 0;
}