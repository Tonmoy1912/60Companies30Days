#include<bits/stdc++.h>
using namespace std;

bool com(string &s1,string &s2){
    return s1.size()>s2.size();
}

bool contains(string &s1,string &s2){
    int n=s1.size();
    int m=s2.size();
    int i=m-1;
    int j=n-1;
    while(i>=0){
        if(s2[i]!=s1[j]){
            return false;
        }
        i--;
        j--;
    }
    return true;
}

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),com);
        int n=words.size();
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            arr[i]=i;
        }
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(contains(words[j],words[i])){
                    arr[i]=j;
                    break;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(arr[i]==i){
                ans+=words[i].size()+1;
            }
        }
        return ans;
    }
};