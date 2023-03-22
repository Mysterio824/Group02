#include <iostream>
#include<fstream>

struct Student
{
    std::string No;
    std::string student_id;
    std::string first_name;
    std::string last_name;
    std::string gender;
    std::string birth_date;
    std::string social_id;
    
    Student* next = nullptr;
};

struct Class
{
    std::string class_name;
    Class(std::string _name)
    {
        class_name = _name;
    }
    
    Student* students = nullptr;
    void AddStudent(char fileName[]);
    
    Class* next = nullptr;
};

struct Course{
    std::string course_id;
    std::string course_name;
    
    Class* classes = nullptr;
    void AddClass();
    
    Course* next = nullptr;
};

struct Semester
{
    int season;
    std::string start_date;
    std::string end_date;
    Semester(int n, std::string startDate, std::string endDate)
    {
        season = n;
        start_date = startDate;
        end_date = endDate;
    }
    std::string year;
    
    Course* courses = nullptr;
    void AddCourse();
};

struct SchoolYear
{
    std::string year;
    
};

void Course::AddClass()
{
    int n;
    std::cout << "How many classes you want to add? ";
    std::cin >> n;
    
    std::string className;
    Class* newClass;
    for(int i = 1; i <= n; i++)
    {
        std::cout << i << ". Class? ";
        std::cin >> className;
        
        newClass = new Class(className);
        
        if(classes == nullptr) classes = newClass;
        else classes->next = newClass;
        
        newClass = newClass->next;
    }
}

void Class::AddStudent(char fileName[])
{
    std::fstream in;
    in.open(fileName);
    if(!in.is_open())
    {
        std::cout << "Cannot open " << fileName << std::endl;
        return;
    }
    
    Student* stu;
    while(in.eof() == false)
    {
        stu = new Student;
        in >> stu->No >> stu->student_id >> stu->first_name >> stu->last_name >> stu->gender >> stu->birth_date >> stu->social_id;
    
        if(students == nullptr) students = stu;
        else  students->next = stu;
        
        stu = stu->next;
    }
    
    in.close();
}