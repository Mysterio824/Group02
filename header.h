#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

struct Student{
    string No;
    string student_id;
    string first_name;
    string last_name;
    string gender;
    string birth_date;
    string social_id;

    string className;
    
    Student* next = nullptr;

    Student(string no, string stuId, string fName, string lName, string gder, string birth, string socialId); 
};

struct StudentPtr{
    Student *ref = nullptr;
    StudentPtr *next = nullptr;
};

struct Course{
    string course_id;
    string course_name;
    string class_name;
    string teacher_name;
    string num_credits;
    int capacity = 50;
    string day;
    string session;
    struct Class{
        string class_name;
    
        StudentPtr* Hstudent = nullptr;
    
        Class* next = nullptr;

        struct CoursePtr{
            Course* ref = nullptr;
            float **scores;
            CoursePtr* next = nullptr;
        };
        
        CoursePtr* courses = nullptr;

        Class(string _name);
    };

    struct ClassPtr{
            Course::Class *ref = nullptr;
            ClassPtr* next = nullptr;
    };
    
    ClassPtr* Hclass;//adding later on
    
    Course* next;

    Course(string cID, string cName, string clName, string tName, string nCredit, string capacity, string dei, string ses);
};

struct Semester
{
    //info
    int season;
    string start_date;
    string end_date;
    string school_year;

    //pointers
    Semester* next;
    Course* courses = nullptr;

    //constructors
    void AddCourse();
    Semester(int n, string schoolYear ,string startDate, string endDate);
};

struct SchoolYear
{
    string year;
    Semester *smt = nullptr;
    const int semes_num = 3;
    int semes_count = 0;

    void AddSemester();
    SchoolYear(std::string _year);
    SchoolYear();
};

string getCurrentYear ();

Student* ImportStudent(string className);

void AddStudent(Student* &Hstudent);

void AddClass(Course::Class* &Hclass, string className);

void startProgram (Student* listStudent, Course* listCourse, Course::Class* listClass, SchoolYear thisYear);

Course :: Class* findClass (Student* account, Course::Class *listOfClass);

int findStudentNo (Student *account, Course::Class* myClass);

void printCourse(Student *account, Course::Class *listOfClass);

void printScoreBoard (Student *account, Course::Class *listOfClass);


#endif