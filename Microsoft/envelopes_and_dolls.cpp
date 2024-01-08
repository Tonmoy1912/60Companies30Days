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
        sort(envelopes.begin(),envelopes.end(),com);
        vector<int> arr;
        for(auto &it:envelopes){
            int i=lower_bound(arr.begin(),arr.end(),it[1])-arr.begin();
            if(i<arr.size()){
                arr[i]=it[1];
            }
            else{
                arr.push_back(it[1]);
            }
        }
        return arr.size();
    }
};