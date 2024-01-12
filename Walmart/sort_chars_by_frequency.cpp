#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(auto it:s){
            m[it]++;
        }
        vector<pair<int,char>> arr;
        for(auto &it:m){
            arr.push_back({it.second,it.first});
        }
        sort(arr.begin(),arr.end(),greater<pair<int,char>>());
        string ans;
        for(auto &it:arr){
            for(int i=0;i<it.first;i++){
                ans.push_back(it.second);
            }
        }
        return ans;
    }
};