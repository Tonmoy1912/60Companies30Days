#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    #define ll long long
    #define M 1000000007
    
    ll helper(vector<int> &nums,int i,int k,int n,int m,vector<vector<ll>> &dp){
        if(k==m){
            return 1;
        }
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        ll ans=0;
        
        for(int j=0;j<n;j++){
            // if(i==j||((k&(1<<j))>0)){
            //     continue;
            // }
            if((k&(1<<j))==0){
                if((nums[i]%nums[j]==0)||(nums[j]%nums[i]==0)){
                    k=(k^(1<<j));
                    ans=(ans+helper(nums,j,k,n,m,dp))%M;
                    k=(k^(1<<j));
                }
            }
        }
        return dp[i][k]=ans;
        
    }
    
    int specialPerm(vector<int>& nums) {
        int n=nums.size();
        int m=(1<<n)-1;
        vector<vector<ll>> dp(n,vector<ll> (m+1,-1));
        // return helper(nums,0,0,n,m,dp);
        ll ans=0;
        for(int i=0;i<n;i++){
            ans=(ans+helper(nums,i,1<<i,n,m,dp))%M;
        }
        return ans;
    }
};