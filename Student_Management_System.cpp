#include <iostream>
#include <fstream>
using namespace std;

ofstream write;
ifstream read;

class Person{
    protected:
        string name;
        int age;
    public:
        virtual void getData() = 0;
        virtual void showData() = 0;
};

class Student : public Person{
    protected:
        int rollNo;
        float marks;
        char grade;
    public:
        void getData(){
            try {
                write.open("student.txt",ios::app);

                cout << "Enter Roll No : ";
                cin>>rollNo;
                write << "RollNo : "<<rollNo<<endl;
                if(cin.fail()){
                    throw "Invalid input for Roll No!";
                }

                cin.ignore();
                cout << "Enter Name of Student : ";
                getline(cin,name);
                write << "Name : "<<name<<endl;
                if(cin.fail()){
                    throw "Invalid input for Name!";
                }

                cout << "Enter Age : ";
                cin>>age;
                write << "Age  : "<<age<<endl;
                if(cin.fail()){
                    throw "Invalid input for Age!";
                }

                cout << "Enter Marks: ";
                cin >> marks;
                write << "Marks : "<<marks<<endl;
                if(cin.fail()){
                    throw "Invalid input for marks!";
                }

                if(marks < 0 || marks > 100){
                    throw "Invalid input for marks!";
                }

                grade = (marks >= 90) ? 'A' : (marks >= 80) ? 'B' : (marks >= 70) ? 'C' : (marks >= 60) ? 'D' : 'F';
                write << "Grade : "<<grade<<endl<<endl;
                write.close();
            }
            catch(const char* message){
                cout << message << endl;
                exit(1);
            }
        }

        void showData(){
            string str;
            read.open("student.txt");
            cout<<"\nStudent History"<<endl;
            while(read.eof()==0){
                getline(read,str);
                cout<<str<<endl;
            }
            read.close();
        }

        void searchByRollNo(int rollNo) {
            string str;
            read.open("student.txt");
            bool found = false;
            while(read.eof()==0){
                getline(read,str);
                if(str.find("RollNo : ") != string::npos) {
                    int foundRollNo = stoi(str.substr(str.find("RollNo : ") + 9));
                    if(foundRollNo == rollNo) {
                        cout << str << endl;
                        for(int i=0; i<3; i++) {
                            getline(read,str);
                            cout << str << endl;
                        }
                        found = true;
                        break;
                    }
                }
            }
            read.close();
            if(!found) {
                cout << "Student with roll number " << rollNo << " not found." << endl;
            }
}
       
};

class Teacher : public Person{
    protected:
        string subject;
    public:
        void getData() {
            try {
                write.open("teacher.txt",ios::app);
                cin.ignore();
                cout << "Enter Teacher Name : ";
                getline(cin,name);
                write << "Teacher Name : "<<name<<endl;
                if (cin.fail()) {
                    throw "Invalid input. Name should be a string.";
                }

                cout << "Enter Teacher Age: ";
                cin >> age;
                write << "Teacher Age  : "<<age<<endl;
                if (cin.fail()) {
                    throw "Invalid input. Age should be a number.";
                }

                cin.ignore();
                cout << "Enter Teacher\'s Subject: ";
                getline(cin,subject);
                write << "Subject Name : "<<subject<<endl<<endl;
                if (cin.fail()) {
                    throw "Invalid input. Subject should be a string.";
                }
                write.close();
        } 
            catch (const char* msg) {
                cerr << "Error: " << msg << endl;
                exit(1);
            }
        }

        void showData() {
            string str;
            read.open("teacher.txt");
            cout<<"\nTeacher History"<<endl;
            while(read.eof()==0){
                getline(read,str);
                cout<<str<<endl;
            }
            read.close();
        }

        void searchByName(string name) {
            string str;
            read.open("teacher.txt");
            bool found = false;
            while(read.eof()==0){
                getline(read,str);
                if(str.find("Teacher Name : ") != string::npos) {
                string foundName = str.substr(str.find("Teacher Name : ") + 15);
                    if(foundName == name) {
                        cout << str << endl;
                        for(int i=0; i<2; i++) {
                            getline(read,str);
                            cout << str << endl;
                        }
                found = true;
                break;
            }
        }
    }
    read.close();
    if(!found) {
        cout << "Teacher with name " << name << " not found." << endl;
    }
}

};

class Course {
    protected:
        string title;
        int duration;
    public:
        virtual void getData() = 0;
        virtual void showData() = 0;
};

class TheoryCourse : public Course {
    protected:
        string textbook;
    public:
        void getData() {
            try {
                cin.ignore();
                write.open("TheoryCourse",ios::app);
                cout << "Enter Title : ";
                getline(cin,title);
                write << "Title : "<<title<<endl;
                if(cin.fail()){
                    throw "Inavalid Title Input!";
                }

                cout << "Enter Duration (in hours) : ";
                cin >> duration;
                write << "Class Duration : "<<duration<<" hours"<<endl;
                if(cin.fail()){
                    throw "Inavalid Duration Input!";
                }

                cin.ignore();
                cout << "Enter Textbook : ";
                getline(cin,textbook);
                write << "Text Book : "<<textbook<<endl<<endl;
                if(cin.fail()){
                    throw "Inavalid Textbook Input!";
                }

                write.close();
            }
            catch (const char* msg) {
                cerr << "Error: " << msg << endl;
                exit(1);
            }
        }
        void showData() {
            string str;
            read.open("TheoryCourse.txt");
            cout<<"\nTheory Course"<<endl;
            while(read.eof()==0){
                getline(read,str);
                cout<<str<<endl;
            }
            read.close();
        }

        void searchByTitle(string courseTitle) {
            string str;
            bool found = false;
            read.open("TheoryCourse.txt");
            cout << "\nSearch Results for \"" << courseTitle << "\":" << endl;
            while(read.eof()==0){
                getline(read,str);
                if (str.find("Title : " + courseTitle) != string::npos) {
                    found = true;
                    cout << str << endl;
                    for (int i = 0; i < 2; i++) {
                        getline(read, str);
                        cout << str << endl;
                    }
                }
            }
            read.close();
            if (!found) {
                cout << "No results found for \"" << courseTitle << "\"." << endl;
            }
}
};

class LabCourse : public Course {
    protected:
        string lab;
    public:
        void getData() {
            try {
            write.open("labCourse.txt",ios::app);

            cout << "Enter Title : ";
            cin.ignore();
            getline(cin,title);
            write << "Title : "<<title<<endl;
            if(cin.fail()){
                throw "Inavalid Title Input!";
            }

            cout << "Enter Duration (in hours): ";
            cin >> duration;
            write << "Class Duration : "<<duration<<" hours"<<endl;
            if(cin.fail()){
                throw "Inavalid Duration Input!";
            }

            cin.ignore();
            cout << "Enter Lab : ";
            getline(cin,lab);
            write << "Lab  : "<<lab<<endl<<endl;
            if(cin.fail()){
                throw "Invalid Textbook Input!";
            }
            write.close();
        }
        catch (const char* msg) {
                cerr << "Error: " << msg << endl;
                exit(1);
        }
    }

        void showData() {
            string str;
            read.open("labCourse.txt");
            cout<<"\nLab Course"<<endl;
            while(read.eof()==0){
                getline(read,str);
                cout<<str<<endl;
            }
            read.close();
        }

        void searchByTitle(string courseTitle) {
            string str;
            bool found = false;
            read.open("labCourse.txt");
                cout << "\nSearch Results for \"" << courseTitle << "\":" << endl;
                while(read.eof()==0){
                    getline(read,str);
                    if (str.find("Title : " + courseTitle) != string::npos) {
                    found = true;
                    cout << str << endl;
                    for (int i = 0; i < 2; i++) {
                        getline(read, str);
                        cout << str << endl;
                    }
                }
            }
            read.close();
            if (!found) {
                cout << "No results found for \"" << courseTitle << "\"." << endl;
        }
    }

};

class Department : public Student , public Teacher , public LabCourse , public TheoryCourse{
    public:
        void inputTeacherDetails(){
            Teacher::getData();
        }

        void showTeacherDetails(){
            Teacher::showData();
        }

        void SearchTeacher(){
            string tName;
            cout<<"Enter Teacher Name : ";
            cin.ignore();
            getline(cin,tName);
            Teacher::searchByName(tName);
        }

        void inputStudentDetails(){
            Student::getData();
        }

        void showStudentDetails(){
            Student::showData();
        }

        void SearchStudentDeatils(){
            int roll;
            cout<<"Enter Roll No (integer) : ";
            cin>>roll;
            Student::searchByRollNo(roll);
        }

        void inputTheoryCourse(){
            TheoryCourse::getData();
        }

        void showTheoryCourse(){
            TheoryCourse::showData();
        }

        void SearchTheoryDetails(){
            string theoryTitle;
            cout<<"Enter Course Title : ";
            cin.ignore();
            getline(cin,theoryTitle);
            TheoryCourse::searchByTitle(theoryTitle);
        }

        void inputLabCourse(){
            LabCourse::getData();
        }

        void showLabCourse(){
            LabCourse::showData();
        }

        void SearchLabDetails(){
            string LabTitle;
            cout<<"Enter Course Title : ";
            cin.ignore();
            getline(cin,LabTitle);
            LabCourse::searchByTitle(LabTitle);
        }
};

int main(){
        Department info;
        int choice;
        char ans;

     do{
        cout<<"\nSTUDENT MANAGEMENT SYSTEM\n"<<endl;
        cout<<"1  : Add Student Info"<<endl
            <<"2  : Show Student Info"<<endl
            <<"3  : Search Student Info"<<endl
            <<"4  : Add Teacher Info"<<endl
            <<"5  : Show Teacher Info"<<endl
            <<"6  : Search Teacher Info"<<endl
            <<"7  : Add Theory Course"<<endl
            <<"8  : Show Theory Course"<<endl
            <<"9  : Search Theory Course"<<endl
            <<"10 : Add Lab Course"<<endl
            <<"11 : Show Lab Course"<<endl
            <<"12 : Search Lab Course\n"<<endl;  

        cout<<"Enter Choice : ";
        cin>>choice;
        
        switch(choice){
            case 1:
            info.inputStudentDetails();
            break;

            case 2:
            info.showStudentDetails();
            break;

            case 3:
            info.SearchStudentDeatils();
            break;

            case 4:
            info.inputTeacherDetails();
            break;

            case 5:
            info.showTeacherDetails();
            break;

            case 6:
            info.SearchTeacher();
            break;

            case 7:
            info.inputTheoryCourse();
            break;

            case 8:
            info.showTheoryCourse();
            break;

            case 9:
            info.SearchTheoryDetails();
            break;

            case 10:
            info.inputLabCourse();
            break;

            case 11:
            info.showLabCourse();
            break;

            case 12:
            info.SearchLabDetails();
            break;

            default:
            cout << "Invalid Input!"<<endl;
        }

        cout << "\nDO YOU WANT TO RUN PROGRAM AGAIN (Y/N) : ";
        cin>>ans;

        if(ans == 'N' || ans == 'n'){
            cout<<"\nProgram Closed"<<endl;
        } 
    }
    while(ans=='Y' || ans=='y');
}