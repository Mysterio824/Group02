#include <iostream>
using namespace std;

//---------------------------LOGIN-INFO---------------------------------------------------------------------------------

struct StudentInfo
{
    string student_id;
    string student_password;

    StudentInfo* next;

    StudentInfo (string id, string password)
    {
        student_id = id;
        student_password = password;
        next = NULL;
    }
    /*
    constructor, usage:
        string id, password;    cin>>id>>password;

        Student newstudent = new Student(id, password);

            the result is the same as

        Student newstudent = new Student;
        newstudent->student_id = id;
        newstudent->student_password = password;
        newstudent->next = nullptr;

        *same goes with the AdminInfo*
    */
};

struct AdminInfo
{
    string admin_id;
    string admin_password;

    AdminInfo* next;

    AdminInfo (string id, string password)
    {
        admin_id = id;
        admin_password = password;
        next = NULL;
    }
};

//--------------------------MAIN-STRUCT----------------------------------------------------------------------------------

struct Student
{
    string No;
    string student_id;
    string class_name;
    string first_name;
    string last_name;
    string gender;
    string dob; //day of birth
    
    float other_mark;
    float midterm_mark;
    float final_mark;
    float total_mark;

    Student(string st_id, string f_name, string l_name)
    {
        student_id = st_id;
        first_name = f_name;
        last_name = l_name;
    }
};

struct Class
{
    string class_name;
    Student* students = nullptr;
    Class* next = NULL;

    void AddStudent(Student Student);
};

struct Course
{
    Class* classes = nullptr;
    string course_id;
    string course_name;
    string teacher_name;
    int credit_num;
    int capacity = 50;
    string day_of_week;
    string session_time;

    void AddClass(Class* clss){};
};

struct  Semester
{
    Course* courses = nullptr;
    void AddCourse(Course course);

    string end_date;
    string start_date;
};

struct SchoolYear{
    string year;
    
    Semester* semesters = nullptr;
    void CreateSemester(Semester semes);

    SchoolYear(int n)
    {
        year = n;
    }

};

//-------------------------------FUNCTION-DECLARATION-----------------------------------------------------------------------------

int main(){

    return 0;
}