#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCollisions(string directions) {
        stack<char> s;
        int count=0;
        for(auto &it:directions){
            if(it=='R'){
                if(!s.empty()&&s.top()=='S'){
                    s.pop();
                }
                s.push('R');
            }
            else if(it=='S'){
                if(!s.empty()&&s.top()=='S'){
                    s.pop();
                }
                count+=s.size();
                while(!s.empty()){
                    s.pop();
                }
                s.push('S');
            }
            else{
                if(!s.empty()&&s.top()=='S'){
                    count++;
                    // s.pop();
                    continue;
                }
                else if(s.empty()){
                    continue;
                }
                else if(!s.empty()&&s.top()=='R'){
                    count+=2;
                    s.pop();

                }
                count+=s.size();
                while(!s.empty()){
                    s.pop();
                }
                s.push('S');
            }
        }
        return count;
    }
};