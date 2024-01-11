#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> prev(n,-1);
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        prev[i]=j;
                    }
                }
            }
        }
        int i=max_element(dp.begin(),dp.end())-dp.begin();
        vector<int> ans;
        ans.push_back(nums[i]);
        while(prev[i]!=-1){
            i=prev[i];
            ans.push_back(nums[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};