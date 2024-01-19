#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> m;
        for(auto &it:matches){
            m[it[0]];
            m[it[1]]++;
        }
        vector<vector<int>> ans(2);
        for(auto &it:m){
            if(it.second==0){
                ans[0].push_back(it.first);
            }
            else if(it.second==1){
                ans[1].push_back(it.first);
            }
        }
        return  ans;
    }
};