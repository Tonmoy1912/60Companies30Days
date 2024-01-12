#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<string> split(string str,char delimiter){
        vector<string> ans;
        string temp="";
        int i=0,n=str.size();
        while(i<n){
            if(str[i]==delimiter){
                ans.push_back(temp);
                temp="";
            }
            else{
                temp.push_back(str[i]);
            }
            i++;
        }
        ans.push_back(temp);
        return ans;
    }
public:
    bool isValidSerialization(string preorder) {
        // if(preorder.size()==1){
        //     return preorder=="#";
        // }
        vector<string> arr=split(preorder,',');
        if(arr.size()==1){
            return arr[0]=="#";
        }
        if(arr.size()==2){
            return false;
        }
        int n=arr.size();
        if(arr[n-1]!="#"||arr[n-2]!="#"){
            return false;
        }
        int count=0;
        for(int i=0;i<n-1;i++){
            if(arr[i]!="#"){
                count++;
            }
            else{
                count--;
            }
            if(count<0){
                return false;
            }
        }
        return true;
    }
};