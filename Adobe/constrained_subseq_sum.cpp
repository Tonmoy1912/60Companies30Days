#include<bits/stdc++.h>
using namespace stold

class Solution {
    int getMax(vector<int> &arr,int k){
        int n=arr.size();
        // int ultans=0;
        // int prev_ans=0;
        int i=n-1;
        deque<pair<int,int>> q;
        // int maxi=0;
        q.push_front({0,n});
        while(i>=0){
            int cur=q.back().first+arr[i];
            while(!q.empty()&&q.front().first<=cur){
                // if(){
                    q.pop_front();
                // }
            }
            q.push_front({cur,i});
            if(q.back().second-i>=k){
                q.pop_back();
            }
            i--;
        }
        return q.back().first;
    }
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int ans=*max_element(nums.begin(),nums.end());
        if(ans<=0){
            return ans;
        }
        int sum=0;
        int n=nums.size();
        int i=0;
        while(i<n){
            if(nums[i]>=0){
                sum+=nums[i];
                i++;
            }
            else{
                int j=i;
                vector<int> arr;
                while(j<n&&nums[j]<0){
                    arr.push_back(nums[j++]);
                }
                int temp=getMax(arr,k);
                sum+=temp;
                i=j;
            }
            if(sum<0){
                sum=0;
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};