#include<bits/stdc++.h>
using namespace std;


bool com(pair<string,int> &a,pair<string,int> &b){
        if(a.second>b.second){
            return true;
        }
        else if(a.second<b.second){
            return false;
        }
        return a.first<=b.first;
    }
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        for(auto &it:words){
            m[it]++;
        }
        vector<pair<string,int>> arr;
        for(auto &it:m){
            arr.push_back(it);
        }
        sort(arr.begin(),arr.end(),com);
        vector<string> ans;
        for(int i=0;i<k;i++){
            ans.push_back(arr[i].first);
        }
        return ans;
    }
};