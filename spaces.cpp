#include<bits/stdc++.h>

using namespace std;

int main(){

    string str;
    int spaceCount;

    cout<<"Input the string to analyze:"<<endl;
    getline(cin,str);

    for(int i=0;i<str.size();i++){
        if(str[i]==' '){
            spaceCount++;
        }    
        else{
            continue;
        }
    }

    cout<<"The received text contains "<<spaceCount<<" spaces"<<endl;

    return 0;
}