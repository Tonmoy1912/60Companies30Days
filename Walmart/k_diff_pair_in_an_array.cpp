#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int,int> m;
        for(auto it:nums){
            m[it]++;
        }
        int ans=0;
        if(k==0){
            for(auto &it:m){
                if(it.second>1){
                    ans++;
                }
            }
        }
        else{
            for(auto &it:m){
                int target=it.first+k;
                ans+=m.count(target);
            }
        }
        return ans;
    }
};