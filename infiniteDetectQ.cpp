#include <iostream>

using namespace std;

int main(){
    int n;
    string str;
    
    enterStr:

    cout<<"Enter string:";
    cin>>str;

    n = str.size();
    
    while(n>0){
        if(str[n-1] == 'q'){
            exit(1);
        }
        n--;
    }

    goto enterStr;
    return 0;
}