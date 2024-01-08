#include<bits/stdc++.h>
using namespace std;

int get_val(vector<vector<int>> &img,int i,int j,int m,int n){
    int il=max(0,i-1);
    int jl=max(0,j-1);
    int ih=min(i+1,m-1);
    int jh=min(j+1,n-1);
    int sum=0;
    int count=0;
    for(int ik=il;ik<=ih;ik++){
        for(int jk=jl;jk<=jh;jk++){
            sum+=img[ik][jk];
            count++;
        }
    }
    return sum/count;
}

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m=img.size();
        int n=img[0].size();
        vector<vector<int>> ans(m,vector<int> (n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=get_val(img,i,j,m,n);
            }
        }
        return ans;
    }
};