#include<bits/stdc++.h>

using namespace std;

string reverseStr(string str){
    string revStr = "";
    for(int i=str.size()-1;i>=0;i--){
         revStr += str[i];
    }
    return revStr;
}
int main(){

   string str;

   cout<<"Enter text to reverse:"<<endl;
   getline(cin,str);
   cout<<reverseStr(str);

   return 0;
}
