#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define M 1000000007

int getDiv(int n){
    int i=2;
    // int mask=0;
    int temp=0;
    while(n!=1){
        int count=0;
        while(n%i==0){
            temp=(temp|(1<<i));
            count++;
            n/=i;
            if(count>=2){
                temp=(temp|(1<<31));
            }
        }
        i++;
    }
    temp=(temp|(1<<1));
    return temp;
}

class Solution {
    bool isSatisfy(int n,int mask){
        int t=(n>>31)&1;
        if(t!=0){
            return false;
        }
        for(int i=2;i<31;i++){
            int t1=(n>>i)&1;
            int t2=(mask>>i)&1;
            int t3=t1&t2;
            if(t3){
                return false;
            }
        }
        return true;
    }
    int helper(vector<int> &arr,vector<int> &count,int i,int n,int t,vector<unordered_map<int,int>> &dp){
        if(i>=n){
            return t!=0;
        }
        if(dp[i].count(t)){
            return dp[i][t];
        }
        ll ans=helper(arr,count,i+1,n,t,dp);//not take
        if(isSatisfy(arr[i],t)){
            if(arr[i]==2){
                ll temp=1;
                for(int j=0;j<count[i];j++){
                    temp=(temp*2)%M;
                }
                temp--;
                ans=(ans+((ll)helper(arr,count,i+1,n,t|arr[i],dp)*temp)%M)%M;
            }
            else{
                ans=(ans+((ll)helper(arr,count,i+1,n,t|arr[i],dp)*count[i])%M)%M;
            }
            
        }
        return dp[i][t]=ans;
    }
public:
    int squareFreeSubsets(vector<int>& nums) {
        // int n=nums.size();
        map<int,int> m;
        for(auto it:nums){
            m[it]++;
        }
        vector<int> arr;
        vector<int> count;

        // for(int i=0;i<n;i++){
        //     arr[i]=getDiv(nums[i]);
        // }

        for(auto it:m){
            int mask=getDiv(it.first);
            if((mask>>31)&1!=0){
                continue;
            }
            arr.push_back(mask);
            count.push_back(it.second);
        }
        int n=arr.size();
        vector<unordered_map<int,int>> dp(n);
        return helper(arr,count,0,n,0,dp);
    }
};