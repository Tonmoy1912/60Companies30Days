#include<bits/stdc++.h>
using namespace std;

string encode(string src)
{     
  //Your code here 
  string s;
  int n=src.size();
  int i=0;
  while(i<n){
      char c=src[i];
      int j=i;
      while(j<n&&src[j]==c){
          j++;
      }
      int count=j-i;
      s.push_back(c);
    //   if(count==1){
    //       i=j;
    //       continue;
    //   }
      string num=to_string(count);
      for(auto it:num){
          s.push_back(it);
      }
      i=j;
  }
  return s;
} 