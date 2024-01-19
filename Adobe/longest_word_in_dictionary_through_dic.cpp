#include<bits/stdc++.h>
using namespace std;

bool com(string &a,string &b){
    if(a.size()<b.size()){
        return true;
    }
    else if(a.size()>b.size()){
        return false;
    }
    return a>b;
}

class Solution {
    bool satisfy(string &str,vector<vector<int>> &arr){
        int n=str.size();
        int j=0;
        for(int i=0;i<n;i++){
            if(arr[j][str[i]-'a']==-1){
                return false;
            }
            else{
                j=arr[j][str[i]-'a'];
            }
        }
        return true;
    }
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int n=s.size();
        vector<vector<int>> arr(n+1);
        vector<int> temp(26,-1);
        for(int i=n;i>=1;i--){
            arr[i]=temp;
            temp[s[i-1]-'a']=i;
        }
        arr[0]=temp;
        sort(dictionary.begin(),dictionary.end(),com);
        int l=dictionary.size();
        int ans=-1;
        for(int i=0;i<l;i++){
            string &str=dictionary[i];
            if(satisfy(str,arr)){
                ans=i;
            }
        }
        if(ans==-1){
            return "";
        }
        return dictionary[ans];
    }
};