#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool left(set<int>&s){
        for(int i=2;i<=5;i++){
            if(s.count(i)){
                return false;
            }
        }
        return true;
    }
    bool right(set<int>&s){
        for(int i=6;i<=9;i++){
            if(s.count(i)){
                return false;
            }
        }
        return true;
    }
    bool middle(set<int>&s){
        for(int i=4;i<=7;i++){
            if(s.count(i)){
                return false;
            }
        }
        return true;
    }
    int getGroup(set<int> &s){
        bool l=left(s);
        bool r=right(s);
        bool m=middle(s);
        if(l&&r){
            return 2;
        }
        else if(m||l||r){
            return 1;
        }
        return 0;
    }
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,set<int>> m;
        for(auto &it:reservedSeats){
            m[it[0]].insert(it[1]);
        }
        int ans=0;
        ans+=(n-m.size())*2;
        for(auto &it:m){
            ans+=getGroup(it.second);
        }
        return ans;
    }
};