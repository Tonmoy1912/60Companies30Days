#include<bits/stdc++.h>
using namespace std;

class Solution {
    int helper(vector<int> &nums1,vector<int> &nums2,int i,int j,int m,int n,vector<vector<int>> &dp,int &ans){
        if(i>=m||j>=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        helper(nums1,nums2,i+1,j,m,n,dp,ans);
        helper(nums1,nums2,i,j+1,m,n,dp,ans);
        dp[i][j]=0;
        if(nums1[i]==nums2[j]){
            dp[i][j]=helper(nums1,nums2,i+1,j+1,m,n,dp,ans)+1;
            ans=max(ans,dp[i][j]);
        }
        return dp[i][j];
    }
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        int ans=0;
        helper(nums1,nums2,0,0,m,n,dp,ans);
        return ans;
    }
};