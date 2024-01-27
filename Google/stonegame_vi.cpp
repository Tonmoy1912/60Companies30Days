#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        vector<vector<int>> arr;
        int n=aliceValues.size();
        // int m=bobValues.size();
        for(int i=0;i<n;i++){
            arr.push_back({aliceValues[i]+bobValues[i],aliceValues[i],bobValues[i]});
        }
        sort(arr.begin(),arr.end(),greater<vector<int>>());
        int sum=0;
        for(int i=0;i<n;i++){
            if(i%2){
                sum-=arr[i][2];
            }
            else{
                sum+=arr[i][1];
            }
        }
        if(sum>0){
            return 1;
        }
        else if(sum<0){
            return -1;
        }
        return sum;
    }
};