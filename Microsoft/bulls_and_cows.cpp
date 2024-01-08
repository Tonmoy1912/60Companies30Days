#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int n=secret.size();
        vector<int> s(10),g(10);
        int count=0;
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]){
                count++;
            }
            else{
                s[secret[i]-'0']++;
                g[guess[i]-'0']++;
            }
        }
        int count2=0;
        for(int i=0;i<10;i++){
            count2+=min(g[i],s[i]);
        }
        return (to_string(count)+"A"+to_string(count2)+"B");
    }
};