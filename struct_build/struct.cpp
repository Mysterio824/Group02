#include <iostream>
using namespace std;

struct StudentInfo
{
    string student_id;
    string student_password;

    StudentInfo* next;
};

struct AdminInfo
{
    string admin_id;
    string admin_password;

    AdminInfo* next;
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

    void AddStudent(Student Student);
};

struct Course
{
    Class* classes = nullptr;
    void AddClass(Class _class);

    string course_id;
    string course_name;
    string teacher_name;
    int credit_num;
    int capacity = 50;
    string day_of_week;
    string session_time;
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