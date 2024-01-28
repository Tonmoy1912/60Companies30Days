#include<bits/stdc++.h>
using namespace std;

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:

    int leftFunc(MountainArray &mountainArr,int l,int r,int target){
        int low=l,high=r;
        while(low<=high){
            int mid=(low+high)/2;
            int temp=mountainArr.get(mid);
            if(temp<target){
                low=mid+1;
            }
            else if(temp>target){
                high=mid-1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }

    int rightFunc(MountainArray &mountainArr,int l,int r,int target){
        int low=l,high=r;
        while(low<=high){
            int mid=(low+high)/2;
            int temp=mountainArr.get(mid);
            if(temp>target){
                low=mid+1;
            }
            else if(temp<target){
                high=mid-1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int pivot=0;
        int n=mountainArr.length();
        int low=0,high=n-1;
        int l=mountainArr.get(0);
        int r=mountainArr.get(n-1);
        int lr;
        while(low<=high){
            int mid=(low+high)/2;
            int temp=mountainArr.get(mid);
            if(mid==0||mid==n-1){
                pivot=mid;
                lr=temp;
            }
            
            if(mid>0&&mountainArr.get(mid-1)>temp){
                high=mid-1;
            }
            else if(mid<n-1&&mountainArr.get(mid+1)>temp){
                low=mid+1;
            }
            else{
                pivot=mid;
                lr=temp;
                break;
            }
        }
        if((target<min(l,r)||target>lr)){
            return -1;
        }
        int index=leftFunc(mountainArr,0,pivot,target);
        if(index==-1){
            index=rightFunc(mountainArr,pivot,n-1,target);
        }
        return index;
    }
};