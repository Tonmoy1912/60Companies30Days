#include<bits/stdc++.h>
using namespace std;

class Solution {
    // bool bridge;
    // void setBridge(vector<vector<int>> &grid,int i,int j,int m,int n){
    //     if(i>0&&i<m-1&&grid[i-1][j]==1&&grid[i+1][j]==1){
    //         // return true;
    //         bridge=true;
    //     }
    //     if(j>0&&j<n-1&&grid[i][j-1]==1&&grid[i][j+1]==1){
    //         // return true;
    //         bridge=true;
    //     }
    //     // return false;
    // }
    void bfs(int i,int j,int m,int n,vector<vector<int>> &grid,vector<vector<int>> &vis,vector<int> &arr){
        queue<pair<int,int>> q;
        vis[i][j]=1;
        q.push({i,j});
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            // setBridge(grid,i,j,m,n);
            q.pop();
            int count=0;
            // bool t=false;
            if(i-1>=0&& grid[i-1][j]==1){
                // t=true;
                count++;
                if(!vis[i-1][j]){
                    vis[i-1][j]=1;
                    q.push({i-1,j});
                }
            }
            if(i+1<m&& grid[i+1][j]==1){
                // t=true;
                count++;
                if(!vis[i+1][j]){
                    vis[i+1][j]=1;
                    q.push({i+1,j});
                }
            }
            if(j-1>=0&& grid[i][j-1]==1){
                // t=true;
                count++;
                if(!vis[i][j-1]){
                    vis[i][j-1]=1;
                    q.push({i,j-1});
                }
            }
            if(j+1<n&& grid[i][j+1]==1){
                // t=true;
                count++;
                if(!vis[i][j+1]){
                    vis[i][j+1]=1;
                    q.push({i,j+1});
                }
            }
            // arr.push_back(count);
        }
    }

    int getIsland(vector<vector<int>> &grid,vector<int> &arr){
        // bridge=false;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int> (n));
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]&&grid[i][j]==1){
                    if(count==1){
                        return 2;
                    }
                    bfs(i,j,m,n,grid,vis,arr);
                    count++;
                }
            }
        }
        return count;
    }
public:
    int minDays(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> arr;
        int count=getIsland(grid,arr);
        // for(auto it:arr){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        if(count!=1){
            return 0;
        }
        if(arr.size()==1){
            return 1;
        }
        else if(arr.size()==2){
            return 2;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    int count=getIsland(grid,arr);
                    grid[i][j]=1;
                    if(count!=1){
                        return 1;
                    }
                }
            }
        }
        return 2;
    }
};