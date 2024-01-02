#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();
        vector<vector<int>> arr(m,vector<int> (n,-1));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]){
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int z=q.front().second;
            q.pop();
            if(i<0||i>=m||j<0||j>=n){
                continue;
            }
            if(arr[i][j]!=-1){
                continue;
            }
            arr[i][j]=z;
            q.push({{i,j-1},z+1});
            q.push({{i,j+1},z+1});
            q.push({{i-1,j},z+1});
            q.push({{i+1,j},z+1});
        }
        return arr;
    }
};