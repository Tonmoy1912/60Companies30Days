#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll getHash(vector<int> &needs,int l){
    ll ans=0;
    for(int i=0;i<l;i++){
        ans=ans*100+needs[i];
    }
    return ans;
}

vector<int> getNeeds(ll hash,int l){
    vector<int> arr;
    for(int i=0;i<l;i++){
        arr.push_back(hash%100);
        hash/=100;
    }
    reverse(arr.begin(),arr.end());
    return arr;
}

bool check(vector<int> &needs,vector<int> &special,int l){
    for(int i=0;i<l;i++){
        if(needs[i]<special[i]){
            return false;
        }
    }
    return true;
}

class Solution {
    int helper(vector<int> &price,ll hash,vector<vector<int>> &special,int i,int l,int n,vector<unordered_map<ll,int>> &dp){
        if(hash==0){
            return 0;
        }
        if(dp[i].count(hash)){
            return dp[i][hash];
        }
        if(i>=n){
            // return 10000;
            int ans=0;
            vector<int> needs=getNeeds(hash,l);
            for(int j=0;j<l;j++){
                ans+=needs[j]*price[j];
            }
            return dp[i][hash]=ans;
        }
        
        int ans1=helper(price,hash,special,i+1,l,n,dp);
        int ans2=10000;
        vector<int> needs=getNeeds(hash,l);
        if(check(needs,special[i],l)){
            for(int k=0;k<l;k++){
                needs[k]-=special[i][k];
            }
            ans2=helper(price,getHash(needs,l),special,i,l,n,dp)+special[i][l];
            // for(int k=0;k<l;k++){
            //     needs[k]+=special[i][k];
            // }
        }
        // int j=0;
        // while(j<l){
        //     if(needs[j]>0){
        //         break;
        //     }
        //     j++;
        // }
        // needs[j]--;
        // int ans3=helper(price,getHash(needs,l),special,i,l,n,dp)+price[j];
        return dp[i][hash]=min({ans1,ans2});
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n=special.size();
        int l=price.size();
        ll hash=getHash(needs,l);
        vector<unordered_map<ll,int>> dp(n+1);
        return helper(price,hash,special,0,l,n,dp);
    }
};