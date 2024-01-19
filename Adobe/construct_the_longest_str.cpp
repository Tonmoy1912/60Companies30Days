#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestString(int x, int y, int z) {
        int ans=0;
        if(x==y){
            ans=x+y+z;
        }
        else{
            ans=2*min(x,y)+z+1;
        }
        ans=2*ans;
        return ans;
    }
};