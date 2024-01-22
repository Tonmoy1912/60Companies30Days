#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define M 1000000007

class Solution {
    ll powMod(ll b,ll e){
        if(e==0){
            return 1;
        }
        if(e%2){
            return (powMod(b,e-1)*b)%M;
        }
        ll ans=powMod((b*b)%M,e/2);
        return ans;
    }
public:
    int minNonZeroProduct(int p) {
        ll largest=(((ll)1)<<p)-1;
        // ll ans=(largest*(largest-1))%M;
        // ans=(ans*(largest/2))%M;
        ll n=largest/2;
        ll ans=largest%M;
        // for(int i=0;i<n;i++){
        //     ans=(ans*(largest-1))%M;
        // }
        ll temp=powMod((largest-1)%M,n);
        return (ans*temp)%M;
    }
};