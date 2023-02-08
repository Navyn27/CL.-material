#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

struct Student {
    int id;
    string name;
    int age;
    double score;

    void writeData(){
        fstream file("data.csv", file.out | file.app);

        if(!file){
            cout<<"An error occurred"<<endl;
        }
        cout<<"End of file"<<endl;
        file<<endl<<id<<" "<<name<<" "<<age<<" "<<score;
        file.close();
        cout<<"Data recorded successfully!" << endl;
    }
};

void readData(vector <Student> &students, int &class_size);
bool validate(Student stud);
void merge_sort(vector <Student> &students, int l, int r);
void merge_sorted_arrays(vector <Student> &students, int l, int m, int r);
void printer(vector <Student> &students);
void print(Student students);

int main(){

    Student stud1;
    vector<Student> students;
    vector<Student>::iterator it;

    int class_size;
    
    int option;

    Start:

    cout<<"Would you like to read or write? \nEnter 1 for writing and 2 for reading"<<endl;
    cin>>option;

    if(option == 1){
        goto Write;
    }
    else if(option == 2){
        goto Read;
    }
    else{
        cout<<"Invalid option "<<option<<endl;
        goto Start;
    }

    Write:
    
    cout<<"Enter the student's id, name,age, and scores in this order:"<<endl;
    cin>>stud1.id;
    getline(cin,stud1.name);
    cin>>stud1.age>>stud1.score;
    if(validate(stud1)){
        stud1.writeData();
    }
    else{
        cout<<"The student should have a valid id, be aged between 10 and 30, and have a valid score."<<endl;
        goto Start;
    }
    
    exit(1);

    Read:
    readData(students,class_size);
    merge_sort(students,0,class_size);
    printer(students);
    
    return 0;
}

void readData(vector <Student> &students, int &class_size){

    ifstream getData("data.csv");
    string line;
    int count = 0;

    Student stud;

    if(getData){
    while(getData.peek()!=EOF)
        {
            getline(getData,line);
            if(getData.eof()){
                cout<<"End of file"<<endl;
            }
            else{
                getData>>stud.id>>stud.name>>stud.age>>stud.score;
                students.push_back(stud);
                count++;
            }
        }
    }
    class_size= count;
    getData.close();
}   

bool validate(Student stud){
    if(stud.score > 50 || stud.score < 0){
        return false;
    }
    else if(stud.age < 10 || stud.age > 30){
        return false;
    }
    else if(stud.id < 0){
        return false;
    }
    else{
        return true;
    }
}
void merge_sort(vector<Student> &students, int l, int r)
{
  if (l < r)
  {

    int m = (r+l) / 2;
  
    merge_sort(students, l, m);      
    merge_sort(students, m + 1, r);

    merge_sorted_arrays(students, l, m, r);
  }
}
void merge_sorted_arrays(vector <Student> &students, int l, int m, int r)
{

  int left_length = m - l + 1;
  int right_length = r - m;
  
  vector<Student> temp_left;
  vector<Student> temp_right;
  
  int i, j, k;
  
  for (int i = 0; i < left_length; i++){
    temp_left.push_back(students[l + i]);
  }
  
  
  for (int i = 0; i < right_length; i++){
    temp_right.push_back(students[m + 1 + i]);
  }
  for (i=0,j=0,k = l; k <= r; k++)
  {
    if ((i < left_length) &&
        (j >= right_length || temp_left[i].score <= temp_right[j].score))
    {
      students[k] = temp_left[i];
      i++;
    }
    
    else
    {
      students[k] = temp_right[j];
      j++;
    }
  } 
}
void printer(vector<Student> &students){
    int size = students.size();
    int i=0;
    int sum = 0;

    while(i<=size){
        print(students[i]);
        sum += students[i].score;
        i++;
    }
    cout<<"Average score: "<<sum/(size)<<endl;
}
void print(Student student){
    cout<<"Name: "<<student.name<<"\tId: "<<student.id<<"\tScore: "<<student.score<<"\tAge:"<<student.age<<endl;
}