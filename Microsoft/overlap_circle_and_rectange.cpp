#include<bits/stdc++.h>
using namespace std;

bool check(int Cx,int Cy,int Px,int Py,int r2){
    return (pow(Cx-Px,2)+pow(Cy-Py,2))<=r2;
}

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int r2=pow(radius,2);
        for(int i=x1;i<=x2;i++){
            if(check(xCenter,yCenter,i,y1,r2)||check(xCenter,yCenter,i,y2,r2)){
                return true;
            }
        }
        for(int i=y1;i<=y2;i++){
            if(check(xCenter,yCenter,x1,i,r2)||check(xCenter,yCenter,x2,i,r2)){
                return true;
            }
        }
        if((xCenter>=x1)&&(xCenter<=x2)&&(yCenter>=y1)&&(yCenter<=y2)){
            return true;
        }
        return false;
    }
};