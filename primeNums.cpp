#include <bits/stdc++.h>
using namespace std;
 int main(){
    
    int a;
    float product = 2;

    for(a=3;a<=100;a++){
        for(int b=2;b<a;b++){
            if(a%b==0){
                break;
            }
            else if(b+1==a){
                product *= a;
            }
            else{
                continue;
            }
        }
    }

    cout<<product<<endl;
    return 0;
 }