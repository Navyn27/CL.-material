#include <bits/stdc++.h>

using namespace std;

double maximum(double x,double y,double z){
    double maxValue = x;
    if(y > maxValue){
        maxValue = y;
    }
    if(z > maxValue){
        maxValue = z;
    }
    return maxValue;
}
int main(){
    int x = 10;
    int& ref=x;

    ref = 20;
    cout<<"x = "<<x<<endl;
    x = 30;
    cout<<"ref ="<<ref<<endl;
    return 0;
    maximum(31.534,345.5436,23.234);
    return 0;
}