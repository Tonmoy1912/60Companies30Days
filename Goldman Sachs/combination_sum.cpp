#include<bits/stdc++.h>
using namespace std;

class Solution {
    void helper(vector<vector<int>> &ans,vector<int> &temp,int k,int n,int last){
        if(n<0){
            return ;
        }
        if(k==0){
            if(n==0){
                ans.push_back(temp);
            }
            else{
                return ;
            }
        }
        for(int i=last-1;i>=1;i--){
            temp.push_back(i);
            helper(ans,temp,k-1,n-i,i);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(ans,temp,k,n,10);
        return ans;
    }
};