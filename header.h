#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#pragma once

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

struct studentPtr{
    Student *ref = nullptr;
    studentPtr *next = nullptr;
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
    
        studentPtr* Hstudent = nullptr;
    
        Class* next = nullptr;

        struct CoursePtr{
        Course* myCourse = nullptr;
        float **scores;
        CoursePtr* next = nullptr;
        };

        Course** myCourses = nullptr;

        Class(string _name);

    };
    Class** Hclass;//adding later on
    
    Course* next;

    Course(string cID, string cName, string clName, string tName, string nCredit, string capacity, string dei, string ses);
};




Student* ImportStudent(Student* Hstudent, string className);
void AddStudent(Student* &Hstudent);

void AddClass(Course::Class* &Hclass, string className);

struct Semester
{
    int season;
    string start_date;
    string end_date;
    string school_year;
   
    Course* courses = nullptr;
    void AddCourse();

    Semester();
    Semester(int n, string schoolYear ,string startDate, string endDate);
};

struct SchoolYear
{
    Semester *smt = new Semester[3];
    string year;
    SchoolYear(std::string _year)
    {
        year = _year;
        for (int i = 0; i < 3; i ++)
           smt[i].school_year = _year;
    }
};









#endif