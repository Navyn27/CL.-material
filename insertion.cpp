#include <bits/stdc++.h>
#include <array>

using namespace std;

int main(){
    array<int,9>scores={52,78,75,68,88,63,75,90,78};
    int length = scores.size();
    int item=10;
    int k=9;
    int j=length-1;

    int a = 0;

    while(j>=k){
        scores[j+1] = scores[j];
        j-=1;
    }
    scores[k] = item;
    for(int a=0;a<10;a++){
        cout<<scores[a]<<endl;
    }
    return 0;
}