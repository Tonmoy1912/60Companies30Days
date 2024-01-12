#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        map<int,int> m;
        for(auto &it:ages){
            m[it]++;
        }
        vector<pair<int,int>> arr;
        for(auto &it:m){
            arr.push_back(it);
        }
        reverse(arr.begin(),arr.end());
        int ans=0;
        int sum=0;
        int n=arr.size();
        int i=0,j=0;
        vector<int> test;
        while(i<n){
            int temp=0.5*arr[i].first+7;
            if(j>i){
                sum-=arr[i].second;
            }
            if(j<i){
                j=i;
            }
            while(j<n&&temp<arr[j].first){
                if(i!=j){
                    sum+=arr[j].second;
                }
                j++;
            }
            ans+=sum*arr[i].second;
            // test.push_back(sum*arr[i].second);
            if(temp<arr[i].first){
                ans+=(arr[i].second-1)*arr[i].second;
            }
            // test.back()+=(arr[i].second-1)*arr[i].second;
            i++;
        }
        // for(auto it:test){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        return ans;
    }
};