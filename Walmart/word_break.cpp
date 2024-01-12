#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int helper(string &s,int i,int n,vector<string> &wordDict,vector<int> &dp){
        if(i>=n){
            return true;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int limit=min(n,i+20);
        string temp="";
        for(int j=i;j<limit;j++){
            temp.push_back(s[j]);
            int ind=lower_bound(wordDict.begin(),wordDict.end(),temp)-wordDict.begin();
            if(ind>=wordDict.size()){
                // continue;
                break;
            }
            if(wordDict[ind]==temp){
                if(helper(s,j+1,n,wordDict,dp)){
                    dp[i]=true;
                    return true;
                }
            }
        }
        return dp[i]=false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        sort(wordDict.begin(),wordDict.end());
        int n=s.size();
        // vector<vector<int>> dp(n,vector<int> (n,-1));
        vector<int> dp(n,-1);
        return helper(s,0,n,wordDict,dp);
    }
};