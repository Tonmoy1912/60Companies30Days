#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define M 1000000007

class Solution {
    int helper(int cur,int end,int k,vector<unordered_map<int,ll>> &dp){
        if(k==0){
            return cur==end;
        }
        if(dp[k].count(cur)){
            return dp[k][cur];
        }
        if(abs(end-cur)>k){
            return dp[k][cur]=0;
        }
        ll ans=helper(cur-1,end,k-1,dp);
        ans=(ans+helper(cur+1,end,k-1,dp))%M;
        return dp[k][cur]=ans;
    }
public:
    int numberOfWays(int startPos, int endPos, int k) {
        vector<unordered_map<int,ll>> dp(k+1);
        return helper(startPos,endPos,k,dp);
    }
};