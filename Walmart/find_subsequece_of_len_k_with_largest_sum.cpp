#include<bits/stdc++.h>
using namespace std;

bool com(pair<int,int> &a,pair<int,int> &b){
    return a.second<b.second;
}

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        vector<pair<int,int>> arr;
        for(int i=0;i<k;i++){
            arr.push_back(pq.top());
            pq.pop();
        }
        sort(arr.begin(),arr.end(),com);
        vector<int> ans;
        for(auto it:arr){
            ans.push_back(it.first);
        }
        return ans;
    }
};