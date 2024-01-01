#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<pair<int,string>> arr;
        for(auto &it:access_times){
            arr.push_back({stoi(it[1]),it[0]});
        }
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int i=0,j=0;
        unordered_map<string,int> m;
        unordered_set<string> s;
        while(i<n){
            int temp=arr[i].first+100;
            while(j<n&&arr[j].first<temp){
                m[arr[j].second]++;
                if(m[arr[j].second]>=3){
                    s.insert(arr[j].second);
                }
                j++;
            }
            m[arr[i].second]--;
            i++;
        }
        vector<string> ans;
        for(auto &it:s){
            ans.push_back(it);
        }
        return ans;
    }
};