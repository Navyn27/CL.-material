#include <bits/stdc++.h>

using namespace std;

int main(){
    
    string secretWord;
    string returnString;

    string animals[10] = {"elephant","lion","tiger","buffalo","cobra","hare","warthog","zebra","hyena","parrot"};
    string foods[10] = {"chips","burger","broccoli","steak","sambusa","sausage","hotdog","rice","pizza","meat" };
    string brands[10] = {"dell","apple","hp","gucci","hyundai","ferrari","nike","intel","mustang","rolex"};
    string companies[10] = {"mcdonalds","subway","nike","apple","ibm","tesla","rwandair","amazon","google","meta"};
    string peopleNames[10] = {"john","francine","maxwell","donald","joe","ivan","edward","anabelle","elon","billie"};

    int choice;    
    int ran;
    int secretSize;
    char guess;
    char decision;

    cout<<"\t WORD GUESSING GAME"<<endl;
    cout<<"\t      WELCOME"<<endl;;
    restart:
    cout<<"\n Choose the category of words from which to guess: \n";
    cout<<"\t 1. animals\n\t 2. foods \n\t 3. brands \n\t 4. companies\n\t 5. peopleNames\n\n";
    cin>>choice;

    if(choice>5 || choice<1){
        cout<<"Invalid input, insert a number between 1 and 5\n"<<endl; 
    }
    else{
        srand(time(0));
        ran = rand()%10 + 1;
        if(choice == 1){
            secretWord = animals[ran];
        }
        else if(choice == 2){
            secretWord = foods[ran];
        }
        else if(choice == 3){
            secretWord = brands[ran];
        }
        else if(choice == 4){
            secretWord = companies[ran];
        }
        else{
            secretWord = peopleNames[ran];
        }
    }

    secretSize = secretWord.size();
    int a = secretSize;

    while(a){
        returnString += "_";
        a--;
    }
    cout<<"The secret word is:\t"<<returnString<<endl;

    cout<<"Guess a letter that is in the secret word\n";
    startGuessing:
    cin>>guess;

    for(a=0;a<secretSize;a++){
        if(secretWord[a]==guess){
            returnString[a]=guess;
        }
        else{
            continue;
        }
    }

    cout<<"\t\t => Your guess is:\t"<<returnString<<endl;

    for(a=0;a<secretSize;a++){
        if(returnString[a]=='_'){
            goto startGuessing;
        }
        else{
            continue;
        }
    }

    cout<<"+==============================================================+"<<endl;
    cout<<"+==============================================================+"<<endl;
    cout<<"+==============CONGRATULATIONS, YOU MADE IT====================+"<<endl;
    cout<<"+===============The secret word was '"<<returnString<<"'======================+"<<endl;
    cout<<"+===============================================================+"<<endl;

    cout<<"\n\n Do you want to play again?"<<endl;
    cout<<"Enter 'y' for yes and 'n' for no"<<endl;
    cin>>decision;

    if(decision=='y'){
        cout<<"\t\t\t.....Restarting....."<<endl;
        returnString="";
        goto restart;
    }
    else{
        cout<<"\t\t\tGlad you played\n\t\t\t.....Closing....."<<endl;
    }
    return 0;
}