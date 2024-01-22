#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximizeSquareHoleArea(int N, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int h=1;
        int i=0;
        int n=hBars.size();
        while(i<n){
            int j=i+1;
            while(j<n&&hBars[j-1]==hBars[j]-1){
                j++;
            }
            h=max(h,j-i+1);
            i=j;
        }
        int v=1;
        i=0;
        n=vBars.size();
        while(i<n){
            int j=i+1;
            while(j<n&&vBars[j-1]==vBars[j]-1){
                j++;
            }
            v=max(v,j-i+1);
            i=j;
        }
        int ans=min(v,h);
        return ans*ans;
    }
};