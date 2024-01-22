#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        int m=arr1.size();
        int n=arr2.size();
        int l=0,r=0;
        int count=0;
        int ans=0;
        for(int i=0;i<m;i++){
            int targetl=arr1[i]-d;
            int targetr=arr1[i]+d;
            while(r<n&&arr2[r]<=targetr){
                count++;
                r++;
            }
            while(l<n&&arr2[l]<targetl){
                count--;
                l++;
            }
            if(count==0){
                ans++;
            }
        }
        return ans;
    }
};