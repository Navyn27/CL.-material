//Write a program to tell whether an input character is a digit or not

#include <bits/stdc++.h>

using namespace std;

int main(){

    char str;
    cout<<"Enter the character to test: "<<endl;
    cin>>str;

    for(int i=0;i<1;i++){
        if(isdigit(str)){
            cout<<"The input is a digit"<<endl;
        }
        else{
            cout<<"The input is not a digit"<<endl;
        }
    }

    return 0;
}