#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define M 1000000007

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<ll> arr(n+1);
        arr[1]=1;
        for(int i=1;i<=n;i++){
            if(arr[i]==0){
                continue;
            }
            int start=i+delay;
            int end=i+forget-1;
            end=min(end,n);
            for(int j=start;j<=end;j++){
                arr[j]=(arr[j]+arr[i])%M;
            }
        }
        ll ans=(arr.back()*2)%M;
        int start=n-delay+1;
        for(int i=start;i<n;i++){
            ans=(ans+arr[i])%M;
        }
        return ans;
    }
};