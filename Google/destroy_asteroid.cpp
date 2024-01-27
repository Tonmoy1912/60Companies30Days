#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define M 1000000007

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& arr) {
        sort(arr.begin(),arr.end());
        ll m=mass;
        for(auto &it:arr){
            if(it>m){
                return false;
            }
            else{
                m+=it;
            }
        }
        return true;
    }
};