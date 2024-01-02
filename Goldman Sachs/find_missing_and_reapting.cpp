#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        int sum=0;
        for(int i=1;i<=n;i++){
            sum^=arr[i-1];
            sum^=i;
        }
        int k=0;
        while(k<31&&(((sum>>k)&1)==0)){
            k++;
        }
        int p=0,q=0;
        for(int i=1;i<=n;i++){
            if((arr[i-1]>>k)&1==1){
                p^=arr[i-1];
            }
            else{
                q^=arr[i-1];
            }
            if((i>>k)&1==1){
                p^=i;
            }
            else{
                q^=i;
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(arr[i]==p){
                count++;
            }
        }
        if(count==0){
            return {q,p};
        }
        return {p,q};
    }
};