#include "mainProgram.h"

Semester::Semester(int n, string year, string startDate, string endDate)
    {
        season = n;
        school_year = year;
        start_date = startDate;
        end_date = endDate;
    }

SchoolYear::SchoolYear(string _year)
    {   year = _year;   }

void Course::AddClass()
{
    int n; 
    cout << "How many classes you want to add? ";
    cin >> n;
    
    string className;
    Class* newClass;
    for(int i = 1; i <= n; i++)
    {
        cout << i << ". Class? ";
        cin >> className;
        
        newClass = new Class(className);
        
        if(classes == nullptr) classes = newClass;
        else classes->next = newClass;
        
        newClass = newClass->next;
    }
}

void Class::AddStudent(string fileName)
{
    ifstream file(fileName);
    if(!file.is_open())
    {
        cout << "Cannot open " << fileName << endl;
        return;
    }
    
    Student* stu;
    string line;
    while (getline(file, line)){
        stringstream ss(line);
        string no, student_id, last_name, first_name, gender, birth_date, social_id ;
        getline(ss, no , ',');
        getline(ss, student_id, ',');
        getline(ss, first_name, ',');
        getline(ss, last_name, ',');
        getline(ss, gender, ',');
        getline(ss, birth_date, ',');
        getline(ss, social_id, ',');
        Student *newStudent = new Student(no, student_id, first_name, last_name, gender, birth_date, social_id);
        addStudentToList (stu, newStudent);
    }
    file.close();

    students = stu;
}
/* Student* createStudent(string No, string student_id, string first_name, string last_name, string gender, string birth_date, string social_id){ 
    Student* newStudent = new Student;
    newStudent -> No = No;
    newStudent -> student_id = student_id;
    newStudent -> first_name = first_name;
    newStudent -> last_name = last_name;
    newStudent -> gender = gender;
    newStudent -> birth_date = birth_date;
    newStudent -> social_id = social_id;
    newStudent -> next = nullptr;
    return newStudent;
} */

void addStudentToList(Student *&head, Student *newStudent){
    if (head == nullptr)
    {
        head = newStudent;
    }
    else
    {
        newStudent->next = head;
        head = newStudent;
    }
}
