//A program to calculate the hypotenuse of a trianlge provided with the base and height

#include <bits/stdc++.h>

using namespace std;

int main(){
    int a;
    int b;

    cout<<"Insert a:"<<endl;
    cin>>a;
    
    cout<<"Insert b:"<<endl;
    cin>>b;

    cout<<"The hypotenuse is: "<<sqrt(pow(a,2)+pow(b,2))<<endl;

    return 0;
}