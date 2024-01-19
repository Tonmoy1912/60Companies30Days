#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<pair<int,pair<int,int>>> arr;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                arr.push_back({abs(rCenter-i)+abs(cCenter-j),{i,j}});
            }
        }
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        for(auto it:arr){
            ans.push_back({it.second.first,it.second.second});
        }
        return ans;
    }
};