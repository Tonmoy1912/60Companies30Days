#include<bits/stdc++.h>
using namespace std;

class Solution {
    int com(int i,string &s1,string &s2){
        int n=s2.size();
        for(int j=0;j<n;j++){
            if(s1[i+j]!=s2[j]){
                return 0;
            }
        }
        return 1;
    }
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int sn=s.size();
        int an=a.size();
        int bn=b.size();
        vector<int> arra(sn),arrb(sn);
        for(int i=0;i<=sn-an;i++){
            arra[i]=com(i,s,a);
        }
        for(int i=0;i<=sn-bn;i++){
            arrb[i]=com(i,s,b);
        }
        int count=0;
        vector<int> ans;
        for(int i=0;i<min(k,sn);i++){
            count+=arrb[i];
        }
        for(int i=0;i<sn;i++){
            int l=i-k-1;
            int r=i+k;
            if(l>=0){
                count-=arrb[l];
            }
            if(r<sn){
                count+=arrb[r];
            }
            if(arra[i]&&count>0){
                ans.push_back(i);
            }
        }
        // for(auto it:arra){
        //     cout<<it<<",";
        // }
        // cout<<endl;
        // for(auto it:arrb){
        //     cout<<it<<",";
        // }
        // cout<<endl;
        return ans;
    }
};