#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

//------------------------Struct--------------------------
struct Student{
    string No;
    string student_id;
    string first_name;
    string last_name;
    string gender;
    string birth_date;
    string social_id;

    string className;

    Student* next;

    Student(string no, string stuId, string fName, string lName, string gder, string birth, string socialId); 
};

struct StudentPtr{
    Student* ref = nullptr;
    StudentPtr* next = nullptr;
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
    
    ClassPtr* Hclass = nullptr;
    
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

    int semes_count = 0;
    const int semes_num = 3;
    Semester *smt = nullptr;
    
    SchoolYear* next;

    void AddSemester();
    SchoolYear(string _year);
};

//--------------------------Function----------------------------------

//Functions to import from file
Student* ImportStudents(string fileName);
Course::Class* ImportClasses(string fileName);
Course* ImportCourses(string fileName);
Semester* ImportSemesters(string fileName);
SchoolYear* ImportSchoolYears(string fileName);

//Functions to add manually
void AddSchoolYear(SchoolYear &schoolyear);
void AddStudent(Course::Class* &myClass);
void AddClass(Course* &myCourse, string className);

//Functions to find in list
Course :: Class* findClass (Student* account, Course::Class *listOfClass);
int findStudentNo (Student *account, Course::Class* myClass);

//Function to print out on console screen
void printCourse(Student *account, Course::Class *listOfClass);
void printCourse(Student *account, Course::Class *listOfClass);
void printScoreBoard (Student *account, Course::Class *listOfClass);

//Other functions
string getCurrentYear ();
void startProgram (Student* &listStudents, Course* &listCourses, Course::Class* &listClasses, SchoolYear* &listSchoolYears, Semester* &listSemesters);

#endif