#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    long long sumScores(string s) {
        int n=s.size();
        vector<int> Z(n);
        int left=0,right=0;
        for(int i=1;i<n;i++){
            if(i>right){
                left=right=i;
                while(right<n&&s[right]==s[right-left]){
                    right++;
                }
                Z[i]=right-left;
                right--;
            }
            else{
                if(Z[i-left]<right-i+1){
                    Z[i]=Z[i-left];
                }
                else{
                    left=i;
                    while(right<n&&s[right]==s[right-left]){
                        right++;
                    }
                    Z[i]=right-left;
                    right--;
                }
            }
        }
        Z[0]=n;
        ll ans=0;
        for(auto &it:Z){
            ans+=it;
        }
        return ans;
    }
};