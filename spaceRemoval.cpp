#include <bits/stdc++.h>

using namespace std;

string removeSpace(string str){
    
    string newString ="";

    for(int a = 0;a<str.size();a++){
        if(str[a]!=' '){
            newString+=str[a];
        }
        else{
            continue;
        }
    }

    return newString;
}
int main(){
    string str;

    cout<<"Insert string:"<<endl;
    getline(cin,str);

    cout<<removeSpace(str)<<endl;

    return 0;
}