#include<bits/stdc++.h>
using namespace std;

class KthLargest {
    // priority_queue<int> maxPrioriy;
    priority_queue<int,vector<int>,greater<int>> minPriority;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        // int i=0;
        this->k=k;
        int n=nums.size();
        sort(nums.begin(),nums.end(),greater<int>());
        for(int i=0;i<k&&i<n;i++){
            minPriority.push(nums[i]);
        }
    }
    
    int add(int val) {
        if(minPriority.size()<k){
            minPriority.push(val);
        }
        else if(val>minPriority.top()){
            minPriority.push(val);
        }
        if(minPriority.size()>k){
            minPriority.pop();
        }
        return minPriority.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */