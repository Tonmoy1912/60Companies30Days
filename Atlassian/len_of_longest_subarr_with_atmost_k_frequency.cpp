#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        int n=arr.size();
        int j=0;
        int ans=1;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
            // if(m[arr[i]]>k){
            //     while(m[arr[i]]>k){
            //         m
            //     }
            // }
            while(j<n&&m[arr[i]]>k){
                m[arr[j]]--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};