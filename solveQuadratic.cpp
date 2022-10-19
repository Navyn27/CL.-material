#include <bits/stdc++.h>

using namespace std;

int main(){
    int a;
    int b;
    int c;

    cout<<"Insert a: ";
    cin>>a;
    cout<<"Insert b: ";
    cin>>b;
    cout<<"Insert c: ";
    cin>>c;

    cout<<"x1: "<< ((0-b) + sqrt(pow(b,2)-(4*a*c)))/(2*a) <<endl;
    cout<<"x2: "<< ((0-b) - sqrt(pow(b,2)-(4*a*c)))/(2*a) <<endl;

}