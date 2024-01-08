#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            arr[i]=i+1;
        }
        int i=0;
        while(arr.size()!=1){
            i+=k-1;
            i%=arr.size();
            arr.erase(arr.begin()+i);
        }   
        return arr[0];
    }
};