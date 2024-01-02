#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void helper(string &digits,int i,int n,vector<string> &arr,vector<string> &ans,string &temp){
        if(i>=n){
            ans.push_back(temp);
            return ;
        }
        int t=digits[i]-'2';
        for(int j=0;j<arr[t].size();j++){
            temp.push_back(arr[t][j]);
            helper(digits,i+1,n,arr,ans,temp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        vector<string> arr={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        int n=digits.size();
        string temp;
        helper(digits,0,n,arr,ans,temp);
        return ans;
    }
};