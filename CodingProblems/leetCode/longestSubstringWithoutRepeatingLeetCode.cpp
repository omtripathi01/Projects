// https://leetcode.com/problems/longest-substring-without-repeating-characters/discuss/2602888/JavaororQueueororfaster-89.17ororspace-97.55ororeasy-to-understand-codeororExplanation
#include<bits/stdc++.h>
using namespace std;

void generateSubstrings(string &str, int index ,string subStr){

    if(index == str.length()-1) return;
    cout<<endl;


}
// O(n^2)
int lengthOfLongestSubstring(string s) {
    
    if(s == ""){
        return 0;
    }
    unordered_set<char>us;
    int res = 1;
    int count = 0;
    for(int i=0;i<s.length();i++){        
        for(int j=i;j<s.length();j++){            
            if(us.find(s[j]) == us.end()){
                us.insert(s[j]);
                count++;
            }else{
                break;
            }
        }
        res = max(count, res);
        us.clear();
        count = 0;
    }
    return res;   
}

//O(n)
int lenOfLongestSubstring(string str){
	int n = str.length(); 
	int res = 0;
	vector<int> prev(256,-1);
	int i=0;
	for (int j = 0; j < n; j++){
	    i=max(i,prev[str[j]]+1);
	    int maxEnd=j-i+1;
	    res=max(res,maxEnd);
	    prev[str[j]]=j;
	} 
	return res; 
}
int main(){

    string s = "abc";
    // generateSubstrings(s,0, "");

    string test1 = "abcabcbb";
    string test2 = "bbbbbb";
    string test3 = "pwwkew";
    string test4 = "";
    string test5 = " ";
    string test6 = "au";
    string test7 = "dvdf";
    vector<string>testCases = {test1, test2 ,test3, test4, test5, test6, test7};
    cout<<"========================================================"<<endl;
    for(string testCase : testCases){    
        cout<<"length of longest substring in (\""<<testCase<<"\") : "<<lenOfLongestSubstring(testCase)<<endl;
    }
    cout<<"========================================================"<<endl;
   
}
