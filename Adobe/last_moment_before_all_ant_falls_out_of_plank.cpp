#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxi;
        if(left.size()){
            maxi=*max_element(left.begin(),left.end());
        }
        else{
            maxi=0;
        }
        int mini;//=*min_element(right.begin(),right.end());
        if(right.size()){
            mini=*min_element(right.begin(),right.end());
        }
        else{
            mini=n;
        }
        return max(maxi,n-mini);
    }
};