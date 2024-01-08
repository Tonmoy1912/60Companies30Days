#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s){
    int i=0,j=s.size()-1;
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;j--;
    }
    return true;
}

class Solution {
    void helper(string &s,string &s1,string &s2,int i,int n,int &ans){
        if(i>=n){
            if(isPalindrome(s1)&&isPalindrome(s2)){
                ans=max(ans,(int)(s1.size()*s2.size()));
            }
            return ;
        }
        s1.push_back(s[i]);
        helper(s,s1,s2,i+1,n,ans);
        s1.pop_back();
        s2.push_back(s[i]);
        helper(s,s1,s2,i+1,n,ans);
        s2.pop_back();
        helper(s,s1,s2,i+1,n,ans);
    }
public:
    int maxProduct(string s) {
        string s1,s2;
        int ans=0;
        helper(s,s1,s2,0,s.size(),ans);
        return ans;
    }
};