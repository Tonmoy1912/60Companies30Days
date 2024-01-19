#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<ll> arr;
        ll sum=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            sum+=abs(s[i]-t[i]);
            arr.push_back(sum);
        }
        int ans=upper_bound(arr.begin(),arr.end(),maxCost)-arr.begin();
        for(int i=0;i<n;i++){
            int len=upper_bound(arr.begin(),arr.end(),arr[i]+maxCost)-arr.begin()-i-1;
            ans=max(ans,len);
        }
        return ans;
    }
};