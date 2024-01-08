#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n=original.size();
        vector<vector<ll>> dis(26,vector<ll> (26,LONG_LONG_MAX));
        for(int i=0;i<26;i++){
            dis[i][i]=0;
        }
        for(int i=0;i<n;i++){
            dis[original[i]-'a'][changed[i]-'a']=min(dis[original[i]-'a'][changed[i]-'a'],(ll)cost[i]);
        }
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(dis[i][k]!=LONG_LONG_MAX && dis[k][j]!=LONG_LONG_MAX){
                        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                    }
                }
            }
        }
        ll ans=0;
        n=source.size();
        for(int i=0;i<n;i++){
            ll d=dis[source[i]-'a'][target[i]-'a'];
            if(d!=LONG_LONG_MAX){
                ans+=d;
            }
            else{
                return -1;
            }
        }
        return ans;
    }
};