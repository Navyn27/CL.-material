#include <bits/stdc++.h>

using namespace std;

int main(){

    string str;
    int spaceCount;

    cout<<"Enter a string:"<<endl;
    getline(cin,str);

    for(int i=0;i<str.size();i++){
        if(str[i]==' '){
            spaceCount++;
        }
        else{
            continue;
        }
    }

    cout<<"The Number of characters without spaces: "<<str.size()-spaceCount<<endl;
    cout<<"The Number of characters with spaces: "<<str.size()<<endl;
    cout<<"The Number of Words: "<<spaceCount+1<<endl;
    
    return 0;
}