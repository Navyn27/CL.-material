#include <bits/stdc++.h>

using namespace std;

int stringLength(string str){
    int length = 0;

    while(str[length]){
        length++;
    }
    return length;
}
bool isPalindrome(string str,int length){
    int a=0;
    int b=length-1;
    int c=length;
    
    start:
    if(a>c/2)
        return true;
    if(str[a]==str[b]){
        a++;
        b--;
        goto start; 
    }
    else{
        return false;
    }
}
int main(){

    string sentence = "abagd";
    
    cout<<"Insert the string to test"<<endl;
    cin>>sentence;

    if(isPalindrome(sentence,stringLength(sentence)))
        cout<<"The input is a palindrome \n";
    else    
        cout<<"The input is not a palindrome \n"; 
    return 0;
}