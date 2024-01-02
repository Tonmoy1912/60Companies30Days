#include<bits/stdc++.h>
using namespace std;

class DataStream {
    int value,k;
    int count;
public:
    DataStream(int value, int k):value(value),k(k),count(0) {

    }
    
    bool consec(int num) {
        if(num==value){
            count++;
        }
        else{
            count=0;
        }
        count=min(count,k);
        return count==k;
    }
};

