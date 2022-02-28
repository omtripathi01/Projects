// Problem :- given a array of ranges and you have to merge the overlapping ranges into one and then print
// them

// Problem : min no of intervals to be removed so that the remaining ranges are non overlapping 

#include<bits/stdc++.h>
using namespace std;

// for sorting vp in descending order
bool comparator(pair<int,int>&a, pair<int,int>&b){

    if(a.first == b.first){
        if(a.second >= b.second)
            return true;
    }else if(a.first > b.first)
        return true;
    return false;

    // return a.first < b.second;
}

vector<pair<int,int>> mergerIntervals(vector<pair<int,int>>&vp){

    sort(vp.begin(), vp.end());
    vector<pair<int,int>>res;
    // res.push_back(vp[0]);
    int l = vp[0].first;
    int r = vp[0].second;

    for(int i=1;i<vp.size();i++){

        if(r>=vp[i].first){
        //    r = r>vp[i].second ? r : vp[i].second; 
            r = max(r, vp[i].second);
        }else{
            res.push_back(make_pair(l,r));
            l = vp[i].first;
            r = vp[i].second;
        }
    }
    res.push_back(make_pair(l,r));
    return res;
}

class Interval{
    public:
        int start ,end;
};

bool comp(const Interval &a, const Interval &b){
    if(a.start >= b.start){
        return false;
    }
    return true;
    // return a.start < b.start;
}

vector<Interval> mergerInterval(vector<Interval>&intervals){

    sort(intervals.begin(), intervals.end(), comp);

    vector<Interval>res;
    // int l = intervals[0].start;
    // int r = intervals[0].end;
    // for(int i=1;i<intervals.size();i++){
    //     if(r >= intervals[i].start){
    //         r = max(intervals[i].end, r);
    //     }else{
    //         res.push_back({l,r});
    //         l = intervals[i].start;
    //         r = intervals[i].end;
    //     }
    // }
    // res.push_back({l,r});

    // another clear code approach
    // using vector as stack
    res.push_back(intervals[0]);

    for(int i=1;i<intervals.size();i++){
        if(res.back().end < intervals[i].start){
            // no overlapping between intervals eg. [1,2] [3,5]
            res.push_back(intervals[i]);
        }else{
            // there is overlapping eg. [1,3] [3,6]  or [1,5] [3,4]
            res.back().end = max(res.back().end, intervals[i].end);
        }
    }

    return res;
}



int main()
{

    vector<pair<int,int>>vp = { {6,8}, {1,9}, {2,4}, {4,7} };//{{9,10},{8,14},{3,4},{6,7},{9,11}};//{{2,4},{1,2},{2,3},{4,5}};

    for(auto i : vp){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<"\n\n";
    // sort(vp.begin(), vp.end());

    // for(auto i : vp){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }

    vector<pair<int,int>>res = mergerIntervals(vp);

    for(auto i : res){
        cout<<i.first<<" "<<i.second<<endl;
    }  
    cout<<"\n";  
    vector<Interval>intervals = { {6,8}, {1,9}, {2,4}, {4,7} };//{{9,10},{8,14},{3,4},{6,7},{9,11}};//{{2,4},{1,2},{2,3},{4,5}};

    for(auto i : intervals){
        cout<<i.start<<" "<<i.end<<endl;
    }  
    cout<<"\n\n";
    vector<Interval>res1 = mergerInterval(intervals);

    for(auto i : res1){
        cout<<i.start<<" "<<i.end<<endl;
    }  

    return 0;
}