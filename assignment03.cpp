#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void recordStudent(int id,string name,int age,double stud_score);

class Student{
    private:
        int id;
        string name;
        int age;
        double score;

        bool validate(int stud_id, int stud_age, double stud_score){
            if((stud_age >=10 || stud_age <=30)&&(stud_id >=0)&&(stud_score <= 50 && stud_score >= 0)){
                return true;
            }
            return false;
        }

    public:
        Student *head;
        Student *next;
        
        Student(int stud_id, string stud_name, int stud_age, double stud_score, bool newStud){
            if(validate(stud_id,stud_age,stud_score) && newStud){
                id = stud_id;
                name = stud_name;
                age = stud_age;
                score = stud_score;
                next = NULL;
                head = NULL;
                recordStudent(id,name,age,stud_score);
            }
            else{
                id = stud_id;
                name = stud_name;
                age = stud_age;
                score = stud_score;
                next = NULL;
                head = NULL;
            }
        }
        double getScore(){
            return score;
        }
        void setScore(int newScore){
            score = newScore;
        }
        void insertStudNext(Student *studToAdd){
            Student *temp = next;
            next = studToAdd;
            studToAdd->next = temp;
        }
        void callStudent(){
            cout<<"id: "<<id<<" names:"<<name<<" age:"<<age<<" score:"<<score<<endl;
        }
};

void readStudents(vector<Student> & students);
int listSize(Student *headObj);
void appendStudent(Student *head,Student *toAdd, int position);
void merge_sort(vector<Student> &students, int l, int r);
void merge_sorted_arrays(vector <Student> &students, int l, int m, int r);
void printer(vector<Student> &students);
void print(Student student);

int main(){
    int option;
    int id, age;
    string name;
    double score;

    vector<Student> students;

    // Student *stud = new Student(5,"Annand",20,45,true);
    // stud->head = stud;
    
    start:
    
    cout<<"Enter option\n1. For reading data\n2. For writing data"<<endl;
    cin>>option;

    if(option==1){
        goto read_data;
    }
    else if(option==2){
        goto write_data;
    }
    else{
        cout<<"Invalid option"<<endl;
        goto start;
    }

    read_data:
    readStudents(students);
    cout<<students.size()<<" Data rows recorded."<<endl;
    merge_sort(students,0,students.size()-1);
    printer(students);
    exit(1);

    write_data:

    cout<<"Enter the student's data in zhe following order:\n1. Student's id 2. Student's name 3. Student's age 4. Student's score"<<endl;  
    cin>>id>>name>>age>>score;

    Student *newStud = new Student(id,name,age,score,true);
    // appendStudent(stud,newStud,2);

    return 0;

}

int listSize(Student *headObj){
    int count = 0;
    
    while(headObj){
        headObj = headObj->next;
        count++;
    }

    return count;
}

void recordStudent(int id, string name, int age, double score){
        fstream file("data.csv", file.out | file.app);

        if(!file){
            cout<<"An error occurred"<<endl;
        }
        file<<endl<<id<<" "<<name<<" "<<age<<" "<<score;
        file.close();
        cout<<"Data recorded successfully!" << endl;            
}

void appendStudent(Student *head,Student *toAdd, int position){
    int count = 0;
    while(head){
        count++;
        if(count == position-1){
            head->insertStudNext(toAdd);
            break;
        }
        head = head->next;
    }
}

void readStudents(vector<Student> &students){
    ifstream getData("data.csv");
    string line;

    int count = 0;

    int id;
    string name;
    int age;
    double score;

    if(getData){
        while(getData.peek()!=EOF)
        {
            getline(getData,line);
            if(getData.eof()){
                cout<<"End of file"<<endl;
            }
            else{
                getData>>id>>name>>age>>score;
                Student *stud = new Student(id, name, age, score,false);
                students.push_back(*stud);
                count++;
            }
        }   
    }
    getData.close();
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
        (j >= right_length || temp_left[i].getScore() <= temp_right[j].getScore()))
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
    double sum = 0;

    while(i<size){
        print(students[i]);
        sum += students[i].getScore();
        i++;
    }
    cout<<"Average score: "<<sum/(size)<<endl;
}

void print(Student student){
    student.callStudent();
}