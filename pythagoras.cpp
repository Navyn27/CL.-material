#include<bits/stdc++.h>

using namespace std;

int main(){

    int a;
    float b;
    for(a=1;a<=100;a++){
       if(a==4){
        continue;
       }
       else{
       if(a%2==0){
          b=pow((a/2),2)-1;
       }
       else{
          b = pow(a,2)/2-0.5;
       }
       if(b<=100 && b!=0){
        cout<<"a: "<<a<<" b: "<<b<<endl;
       }
       else
          continue;
       }
    }
         
    return 0;
}