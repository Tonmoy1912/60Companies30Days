#include<bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
    bool check(ll div1,ll div2,ll l,ll count1,ll count2,ll mid){
        ll m=mid/div1;
        ll n=mid/div2;
        ll com=mid/l;
        m-=com;
        n-=com;
        mid-=com;
        mid=mid-m-n;
        count1=max((ll)0,count1-n);
        count2=max((ll)0,count2-m);
        return mid>=(count1+count2);
    }
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        ll low=2,high=1e15;
        ll l=lcm((ll)divisor1,(ll)divisor2);
        while(low<=high){
            ll mid=(low+high)/2;
           bool t= check(divisor1,divisor2,l,uniqueCnt1,uniqueCnt2,mid);
           if(t){
               high=mid-1;
           }
           else{
               low=mid+1;
           }
        }
        return low;
    }
};