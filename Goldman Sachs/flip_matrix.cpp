#include<bits/stdc++.h>
using namespace std;

class Solution {
    int total;
    vector<int> arr;
    int k;
    int m,n;
public:
    Solution(int m, int n) {
        this->m=m;
        this->n=n;
        total=min(1000,m*n);
        for(int i=0;i<total;i++){
            arr.push_back(i);
        }
        srand(time(NULL));
        for(int i=0;i<total;i++){
            int ran=rand()%total;
            swap(arr[i],arr[ran]);
        }
        k=0;
    }
    
    vector<int> flip() {
        int x=arr[k];
        k++;
        int i=x/n;
        int j=x%n;
        return {i,j};
    }
    
    void reset() {
        for(int i=0;i<total;i++){
            int ran=rand()%total;
            swap(arr[i],arr[ran]);
        }
        k=0;
    }
};