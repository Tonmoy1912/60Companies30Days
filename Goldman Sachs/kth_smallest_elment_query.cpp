#include<bits/stdc++.h>
using namespace std;

class Com{
    int n;
    public:
    Com(int n){
        this->n=n;
    }
    bool operator()(pair<string,pair<int,int>> &s1,pair<string,pair<int,int>> &s2){
        char str1=s1.first[n],str2=s2.first[n];
        if(str1<str2){
            return true;
        }
        else if(str1>str2){
            return false;
        }
        return s1.second.second<=s2.second.second;
    }
};

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<pair<string,pair<int,int>>> arr;
        int n=nums.size();
        // ans.resize(n);
        int l=nums[0].size();
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],{i,i}});
        }
        vector<pair<int,pair<int,int>>> q;
        n=queries.size();
        for(int i=0;i<n;i++){
            q.push_back({queries[i][1],{queries[i][0],i}});
        }
        ans.resize(n);
        sort(q.begin(),q.end());
        int i=0;
        int last=1;
        while(i<n){
            int t=q[i].first;
            int j=i;
            // sort(arr.begin(),arr.end(),Com(l-t));
            while(last<=t){
                sort(arr.begin(),arr.end(),Com(l-last));
                int m=arr.size();
                for(int k=0;k<m;k++){
                    arr[k].second.second=k;
                }
                last++;
            }
            while(j<n&&q[j].first==t){
                pair<int,pair<int,int>> it=q[j];
                int x=it.second.first;
                // ans.push_back(arr[x-1].second);
                ans[it.second.second]=arr[x-1].second.first;
                j++;
            }
            i=j;
        }
        return ans;
    }
};