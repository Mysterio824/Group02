#include <iostream>
using namespace std;

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


struct Student
{
    string student_id;
    string full_name;
    
    float other_mark;
    float midterm_mark;
    float final_mark;
    float total_mark;

    Student(string _id, string _name)
    {
        student_id = _id;
        full_name = _name;
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

//----------------------------------------------------------------------------------

int main(){

    return 0;
}