#include<bits/stdc++.h>
using namespace std;

bool com(vector<int> &a,vector<int> &b){
    if(a[0]<b[0]){
        return true;
    }
    else if(a[0]>b[0]){
        return false;
    }
    return a[1]>=b[1];
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        sort(envelopes.begin(),envelopes.end(),com);
        vector<int> arr;
        for(int i=0;i<n;i++){
            int j=lower_bound(arr.begin(),arr.end(),envelopes[i][1])-arr.begin();
            if(j==arr.size()){
                arr.push_back(envelopes[i][1]);
            }
            else{
                arr[j]=envelopes[i][1];
            }
        }
        return arr.size();
    }
};