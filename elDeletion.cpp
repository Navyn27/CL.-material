#include <bits/stdc++.h>

using namespace std;

int main(){

    int scores[]={52,78,75,68,88,63,75,90,78};
    int delId = 3;
    int length =9;
    
    for(int a=delId;a<length-1;a++){
        scores[delId] = scores[delId+1];
    }
    for(int a=0;a<20;a++){
        cout<<scores[a]<<endl;
    }
    return 0;
}