#include<bits/stdc++.h>
using namespace std;

class Solution {
    int isInc(vector<int> &arr,int start,int end){
        int last=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(i>=start&&i<=end){
                continue;
            }
            if(last>=arr[i]){
                return false;
            }
            last=arr[i];
        }
        return true;
    }
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                ans+=isInc(nums,i,j);
            }
        }
        return ans;
    }
};