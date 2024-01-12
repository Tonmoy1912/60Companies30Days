#include<bits/stdc++.h>
using namespace std;

class Solution {
public:


    int helper(string &s,int i,int n,int m,vector<int> &dp,set<string> &dic){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=helper(s,i+1,n,m,dp,dic)+1;//not take
        int l=min(n-i,m);
        for(int j=1;j<=l;j++){
            string str=s.substr(i,j);
            if(dic.count(str)!=0){
                ans=min(ans,helper(s,i+j,n,m,dp,dic));
            }
        }
        return dp[i]=ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        int n=s.size();
        vector<int> dp(n,-1);
        set<string> dic;
        int m=0;
        for(auto it:dictionary){
            dic.insert(it);
            m=max(m,(int)it.size());
        }
        return helper(s,0,n,m,dp,dic);
        // return 0;
    }
};