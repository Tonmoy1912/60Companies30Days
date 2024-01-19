#include<bits/stdc++.h>
using namespace std;

class Solution {
    int Dijkstra(vector<vector<pair<int,int>>> &adj,int n,int source,int destination){
        vector<int> dis(n,1000000);
        dis[source]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,source});
        while(!pq.empty()){
            pair<int,int> temp=pq.top();
            pq.pop();
            int node=temp.second;
            int d=temp.first;
            if(d>dis[node]){
                continue;
            }
            for(auto &it:adj[node]){
                int newDis=dis[node]+it.second;
                if(newDis<dis[it.first]){
                    dis[it.first]=newDis;
                    pq.push({newDis,it.first});
                }
            }
        }
        return dis[destination];
    }
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        set<pair<int,int>> s;
        s.insert({start[0],start[1]});
        s.insert({target[0],target[1]});
        for(auto &it:specialRoads){
            s.insert({it[0],it[1]});
            s.insert({it[2],it[3]});
        }
        vector<pair<int,int>> arr;
        map<pair<int,int>,int> m;
        int count=0;
        for(auto &it:s){
            arr.push_back(it);
            m[it]=count;
            count++;
        }
        vector<vector<pair<int,int>>> adj(count);
        for(int i=0;i<count;i++){
            for(int j=i+1;j<count;j++){
                int dis=abs(arr[i].first-arr[j].first)+abs(arr[i].second-arr[j].second);
                int x=m[arr[i]];
                int y=m[arr[j]];
                adj[x].push_back({y,dis});
                adj[y].push_back({x,dis});
            }
        }
        for(auto &it:specialRoads){
            int x=m[{it[0],it[1]}];
            int y=m[{it[2],it[3]}];
            adj[x].push_back({y,it[4]});
        }
        int ans=Dijkstra(adj,count,m[{start[0],start[1]}],m[{target[0],target[1]}]);
        return ans;
    }
};