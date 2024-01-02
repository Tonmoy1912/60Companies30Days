#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    string printMinNumberForPattern(string S){
        // code here 
        int n=S.size();
        string s;
        vector<pair<char,int>> arr;
        int i=0;
        while(i<n){
            char c=S[i];
            int j=i;
            while(j<n&&S[j]==c){
                j++;
            }
            arr.push_back({c,j-i});
            i=j;
        }
        n=arr.size();
        i=0;
        int last=0;
        if(arr[i].first=='I'){
            s.push_back('1');
            last=1;
        }
        while(i<n){
            char c=arr[i].first;
            int t=arr[i].second;
            if(c=='I'){
                for(int k=1;k<t;k++){
                    s.push_back(++last+'0');
                }
            }
            else{
                int temp=last+t+1;
                for(int k=temp;k>last;k--){
                    s.push_back(k+'0');
                }
                last=temp;
            }
            i++;
        }
        if(arr.back().first=='I'){
            s.push_back(++last+'0');
        }
        return s;
    }
};