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
    string day_of_week;
    string session_time;
    int credit_num;
    int capacity;

    Course* next;

    Course(string id, string name, string teacher, string dow, string ssn_time, int cred_num, int cap)
    {
        course_id = id;
        course_name = name;
        teacher_name = teacher;
        day_of_week = dow;
        session_time = ssn_time;

        credit_num = cred_num;
        capacity = cap;

        next = nullptr;
    }
    void AddClass(Class* clss){};
};

struct Semester
{
    Course* courses = nullptr;

    string end_date;
    string start_date;

    void AddCourse(Course* courses);
};

struct SchoolYear{
    string year;
    
    Semester semestrs[3];

    SchoolYear(int n)
    {
        year = n;
    }

};

//-------------------------------FUNCTION-DECLARATION-----------------------------------------------------------------------------

SchoolYear* createSchoolYear() {
    int n;
    cout<<"Create new school year: "; cin>>n;
    SchoolYear* newschoolyear = new SchoolYear(n);

    
    return newschoolyear;
}

void Semester::AddCourse(Course* courses)
{
    string id, name, teacher, dow, ssn_time;
    int cred_num, cap;

    cout<<"Course ID: ";                cin>>id;
    cout<<"Course name: ";              cin>>name;
    cout<<"Course's teacher name: ";    cin>>teacher;
    cout<<"Sessions: ";                 cin>>ssn_time;
    cout<<"Days of week: ";             cin>>dow;
    
    cout<<"Credit number: ";            cin>>cred_num;
    cout<<"Capacity: ";                 cin>>cap;

    Course* newcourse = new Course(id,name,teacher,ssn_time,dow,cred_num,cap);
    
    Course* curr = courses;
    if(!courses)
    {
        courses = newcourse;
        curr = courses;
    }
    else
    {
        curr->next = newcourse;
        curr = curr->next;
        
    }
}