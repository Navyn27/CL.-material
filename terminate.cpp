#include <iostream>

using namespace std;

int main(){

    int n;
    int sum;
    int average;
    int input;
    int count = 0;

    cout<<"Enter n: ";
    cin>>n;
    if(n>0){
      count = n;
      while(n){
        start:
        cout<<"Enter Number "<<count-n + 1<<":"<<endl;;
        cin>>input;
        if(input>0){
            if(input == 1){
                goto terminate;
            }
            sum += input;
        }
        else{
            cout<<"Negative numbers are not allowed"<<endl;;
            goto start; 
        }
        n--;
      }
    }
    else{
        goto terminate;
    }
    terminate:
        cout<<"Sum is:"<<sum<<endl;
        cout<<"Average is:"<<sum/count;

    return 0;
}