#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> arr;
        vector<vector<int>> ans;
        for(auto &it:buildings){
            arr.push_back({it[0],-it[2]});
            arr.push_back({it[1],it[2]});
        }
        sort(arr.begin(),arr.end());
        multiset<int,greater<int>> s;
        int h=0;
        int n=arr.size();
        s.insert(0);
        for(int i=0;i<n;i++){
            if(arr[i].second<0){
                s.insert(abs(arr[i].second));
            }
            else{
                auto it=s.find(arr[i].second);
                s.erase(it);
            }
            int e=*s.begin();
            if(h!=e){
                h=e;
                ans.push_back({arr[i].first,h});
            }
        }
        return ans;
    }
};