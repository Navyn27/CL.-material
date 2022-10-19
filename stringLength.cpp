#include <bits/stdc++.h>

using namespace std;

int stringLength(string str){
    int length = 0;

    while(str[length]){
        length++;
    }
    return length;
}
int main(){
    string str;

    cout<<"Enter a text:"<<endl;
    cin>>str;

    cout<<stringLength(str)<<endl;
    return 0;
}