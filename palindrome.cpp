#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string str){
    int a=0;
    int b=str.size()-1;
    
    start:
    if(a>str.size()/2)
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

    if(isPalindrome(sentence))
        cout<<"The input is a palindrome \n";
    else    
        cout<<"The input is not a palindrome \n"; 
    return 0;
}