#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <vector>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13
#define ESC 27

using namespace std;

//------------------------Struct--------------------------
struct Student{
    //info
    string student_id;
    string first_name;
    string last_name;
    string gender;
    string birth_date;
    string social_id;

    string className;
    //pointer
    Student* next;

    string fullName();
    Student(string class_name, string stuId, string fName, string lName, string gder, string birth, string socialId);
};

struct Class{
    //info
    string class_name;
    //pointers
    Student* Hstudent;
    Class* next;

    int capacity();

    Class(string _name);
};

struct Staff
{
    string staffID;
    string firstName;
    string lastName;
    string gender;
    string birthDate;
    string socialID;
    Staff *next = nullptr;

    string fullName();
};

struct user
{
    string username; // ID
    string password;
    bool isStudent;
    Student *ref = nullptr;
    Staff *profile = nullptr;
    user *next;
};
//---------------------------------------------------------------------
struct Scoreboard{
    //info
    string student_id, full_name;
    float midterm, finalterm, other;
    //pointer
    Scoreboard* next = nullptr;
    Scoreboard(string stdnt_id);
    float overallGPA();
};

struct Course{
    //info
    string course_id;
    string course_name;
    string class_name;
    string teacher_name;
    string num_credits;
    int capacity = 50;
    string day;
    string session;
    
    //pointer
    Scoreboard* Hscore = nullptr;
    Course* next;

    Course(string cID, string cName, string clName, string tName, string nCredit, string capa, string dei, string ses);
};

struct Semester
{
    //info
    string season;
    string start_date;
    string end_date;
    string school_year;

    //pointers
    Semester* next;
    Course* Hcourse;

    //constructors
    Semester(string ssn, string schoolYear ,string startDate, string endDate);
    int numOfCourses();
};

struct SchoolYear
{
    //info
    string year;
    int semes_count = 0;
    const int semes_num = 3;
    //pointer
    Class* Hclass;
    Semester *Hsemester;
    SchoolYear* next = nullptr;

    SchoolYear(string _year);
};
/* 
Stuct visualization---------------------------------------------------
SchoolYear
{
    string year;
    int semes_count = 0;
    const int semes_num = 3;

    SchoolYear* next;--------->
    Class* Hclass {

        string class_name;

        Class* next;--------->
        Student* Hstudent {
            
            string student_id;
            string first_name;
            string last_name;
            string gender;
            string birth_date;
            string social_id;
            string className;

            Student* next;--------->
        }
        
    }
    Semester *Hsemester {

        string season;
        string start_date;
        string end_date;
        string school_year;

        Semester* next;--------->
        Course* Hcourse {

            string course_id;
            string course_name;
            string class_name;
            string teacher_name;
            string num_credits;
            int capacity = 50;
            string day;
            string session;

            Course* next;--------->
            Scoreboard* Hscore {
                string student_id;
                float midterm, finalterm, other;

                Scoreboard* next;--------->
            }
        }
    }
}
 */
//--------------------------Function----------------------------------

//Functions to import from file
Student* ImportStudents(string fileName);//fileName = class_name
Semester* ImportSemesters(string fileName);
Course* ImportCourses(string fileName);
SchoolYear* ImportSchoolYears(string fileName);
Scoreboard* ImportScoreboard(Course* Hcourse);

//Functions to remove manually
void RemoveStudentFromClass(SchoolYear* &thisyear);
void RemoveStudentFromCourse(SchoolYear* &thisyear);
void RemoveCourseFromSemester(SchoolYear* &thisyear);

//Functions to add manually
void AddSchoolYear(SchoolYear* &Hyear);
void AddClasstoSchoolYear(SchoolYear* &Hschoolyear);
void AddSemesterToSchoolYear(SchoolYear* &Hschoolyear);
void AddCourseToSemester(Semester* &Hsemester);
void AddStudentToClass(Class* &Hclass);
void AddStudentToCourse(Course* &Hcourse);

//Functions to find in list
Scoreboard* checkInCourse (Student *account, Course *HCourse);
Semester* checkcurrentsemester(SchoolYear *thisyear);

//Function to print out on console screen for STUDENTS
void printStdCourse(Student *account,Course *listOfCourse);
void printStdScoreBoard (Student *account, Class *listOfClass);

//Function to print out on console screen for STAFF
Course* printListCourse (Course *listCourse);
void printCourseScoreBoard(Course *HCourse);
void printOneClass(Class *HClass);
void printAllClass(Class *listOfClass);
Class* printListClass (Class *listClass);
void printClassScoreBoard (Class *thisClass, Semester *thisSem);
SchoolYear* printListYear(SchoolYear *listYear);

//Export funtions
void exportStudents (Class *listClass);
void exportScoreBoard (Course *list);
void exportClass (Class *list);
void exportCourse(Course *list);
void exportSchoolYear (SchoolYear *list);

//Other functions
string getCurrentYear ();
void startProgram(SchoolYear* &thisyear);
void SaveChosenYear(SchoolYear* thisyear);
void MemmoryRelease(SchoolYear* &thisyear);
void printBorder(int num, int size);
void UpdateCourseInfo(Course* &Hcourse);//at input_fn.cpp
void UpdateStudentResult(Course* &Hcourse);//at input_fn.cpp
string displayyears (); //at find_n_output_fn.cpp
void switchyear(SchoolYear* &thisyear); //at main_fn.cpp
bool isInRange(string curr, string start, string end);
#endif