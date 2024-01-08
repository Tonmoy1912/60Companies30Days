#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        if(n<=1){
            return ;
        }
        vector<int> arr(n);
        sort(nums.begin(),nums.end());
        int i=n-1,j=1;
        while(i>=0){
            arr[j]=nums[i];
            i--;
            j+=2;
            if(j>=n){
                j=0;
            }
        }
        nums=arr;
    }
};