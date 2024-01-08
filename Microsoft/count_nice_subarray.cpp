#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count=0;
        unordered_map<int,int> m;
        m[0]++;
        int ans=0;
        for(auto it:nums){
            if(it%2){
                count++;
            }
            int prev=count-k;
            ans+=m[prev];
            m[count]++;
        }
        return ans;
    }
};