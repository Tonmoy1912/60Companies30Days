#include<bits/stdc++.h>
using namespace std;

bool contains(string s1,string s2){
    int n=s1.size();
    int m=s2.size();
    vector<int> kmp(m);
    int j=0,i=1;
    while(i<m){
        if(s2[j]==s2[i]){
            j++;
            kmp[i]=j;
            i++;
        }
        else if(j==0){
            kmp[i]=0;
            i++;
        }
        else{
            j=kmp[j-1];
        }
    }
    j=0;i=0;
    while(i<n){
        if(s2[j]==s1[i]){
            j++;
            // kmp[i]=j;
            i++;
        }
        else if(j==0){
            // kmp[i]=0;
            i++;
        }
        else{
            j=kmp[j-1];
        }
        if(j>=m){
            return true;
        }
    }
    return false;
}

int main(){
    cout<<contains("TOnmoy biswas"," bis")<<endl;
    return 0;
}