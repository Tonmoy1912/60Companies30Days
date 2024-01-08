#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mid=(n-1)/2;
        int val=nums[mid];
        int ans=0;
        for(auto it:nums){
            ans+=abs(it-val);
        }
        return ans;
    }
};