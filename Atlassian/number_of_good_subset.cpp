#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define M 1000000007

class Solution {
    ll powMod(ll b,ll e){
        if(e==0){
            return 1;
        }
        if(e%2){
            return (powMod(b,e-1)*b)%M;
        }
        ll ans=powMod((b*b)%M,e/2);
        return ans;
    }
    int getHash(int n){
        if(n==1){
            return 2;
        }
        int hash=0;
        int cur=n;
        int i=2;
        while(i<=cur){
            if(cur%i==0){
                int count=0;
                while(cur%i==0){
                    count++;
                    cur/=i;
                }
                if(count>1){
                    return -1;
                }
                else{
                    hash=(hash|(1<<i));
                }
            }
            i++;
        }
        return hash;
    }
    ll helper(vector<pair<int,int>> &arr,int i,int hash,int n,vector<unordered_map<int,ll>> &dp){
        if(i>=n){
            // return 1;
            if(hash==0||hash==2){
                return 0;
            }
            else{
                return 1;
            }
        }
        if(dp[i].count(hash)){
            return dp[i][hash];
        }
        ll ans=0;
        if((hash&arr[i].first)){
            ans=helper(arr,i+1,hash,n,dp);
        }
        else{
            ans=helper(arr,i+1,hash,n,dp);
            ll temp=helper(arr,i+1,hash|arr[i].first,n,dp);
            if(arr[i].first==2){
                temp=(temp*(powMod(2,arr[i].second)-1))%M;
                ans=(ans+temp)%M;
            }
            else{
                temp=(temp*arr[i].second)%M;
                ans=(ans+temp)%M;
            }
            // ans=(ans+temp)%M;
        }
        return dp[i][hash]=ans;
    }
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        map<int,int> m;
        for(auto &it:nums){
            m[it]++;
        }
        vector<pair<int,int>> arr;
        for(auto &it:m){
            int hash=getHash(it.first);
            if(hash!=-1){
                arr.push_back({hash,it.second});
            }
        }
        // if(m.size()==0||(m.size()==1&&m.count(0)==1)){}
        int n=arr.size();
        vector<unordered_map<int,ll>> dp(n);
        // for(auto &it:arr){
        //     cout<<it.first<<"-"<<it.second<<endl;
        // }
        return helper(arr,0,0,n,dp);
    }
};