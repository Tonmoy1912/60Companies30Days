#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define M 1000000007

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        ll n=nums.size();
        ll sum=0;
        ll i=1;
        while(i<n){
            ll temp=sum+i*(nums[i]-nums[i-1]);
            if(temp>k){
                break;
            }
            sum=temp;
            i++;
        }
        // ll e=k/i;
        sum=0;
        for(int j=0;j<i;j++){
            // nums[j]+=e;
            sum+=nums[i-1]-nums[j];
            nums[j]=nums[i-1];
        }
        ll e=k-sum;
        // i=0;
        int t=0;
        for(int j=0;j<e;j++){
            // nums[j]++;
            nums[t]++;
            t++;
            t=t%i;
        }
        ll ans=1;
        for(int i=0;i<n;i++){
            ans=(ans*nums[i])%M;
        }
        return ans;
    }
};