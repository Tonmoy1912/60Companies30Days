#include<bits/stdc++.h>
using namespace std;

class Solution {
    void getS(unordered_set<int> &s,int mask){
        for(int i=0;i<15;i++){
            if((mask>>i)&1){
                s.insert(i);
            }
        }
    }
    void bfs(int node,vector<int> &vis,vector<vector<int>> &adj){
        // int cur=node;
        int n=vis.size();
        queue<int> q;
        q.push(node);
        vis[node]=1;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(int i=0;i<n;i++){
                if(adj[cur][i]==1&&!vis[i]){
                    q.push(i);
                    vis[i]=1;
                }
            }
        }
    }
    bool connected(vector<vector<int>> &adj,unordered_set<int> &s){
        int count=0;
        vector<int> vis(adj.size());
        for(auto &it:s){
            if(!vis[it]){
                if(count==1){
                    return false;
                }
                bfs(it,vis,adj);
                count++;
            }    
        }
        return true;
    }
    int helper(vector<vector<int>> &edges,int mask,int n){
        unordered_set<int> s;
        getS(s,mask);
        vector<vector<int>> adj(n,vector<int> (n,100));
        for(auto &it:edges){
            if(s.count(it[0])==1&&s.count(it[1])==1){
                adj[it[0]][it[1]]=1;
                adj[it[1]][it[0]]=1;
            }
        }
        for(int i=0;i<n;i++){
            adj[i][i]=0;
        }
        if(!connected(adj,s)){
            return -1;
        }
        int maxi=1;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(adj[i][k]!=100&&adj[k][j]!=100){
                        adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                        maxi=max(maxi,adj[i][j]);
                    }
                }
            }
        }
        return maxi;
    }
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        for(auto &it:edges){
            it[0]--;
            it[1]--;
        }
        int mask=(1<<n)-1;
        vector<int> ans(n-1);
        for(int i=1;i<=mask;i++){
            if(__builtin_popcount(i)<=1){
                continue;
            }
            int d=helper(edges,i,n);
            if(d==-1){
                continue;
            }
            ans[d-1]++;
        }
        return ans;
    }
};