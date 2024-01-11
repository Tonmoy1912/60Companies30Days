#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int maxi=0;
        int cur=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            cur+=i*nums[i];
        }
        maxi=cur;
        for(int i=n-1;i>=0;i--){
            maxi=max(maxi,cur);
            cur-=(n-1)*nums[i];
            cur+=(sum-nums[i]);
        }
        return maxi;
    }
};