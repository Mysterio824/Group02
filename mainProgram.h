#ifndef MAINPROGRAM_H
#define MAINPROGRAM_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#pragma once
using namespace std;

struct Student
{
    string No;
    string student_id;
    string first_name;
    string last_name;
    string gender;
    string birth_date;
    string social_id;
    
    Student* next = nullptr;

    Student(string no, string id, string f_name, string l_name, string gndr, string b_date, string so_id)
    {
        No = no;
        student_id = id;
        first_name = f_name;
        last_name = l_name;
        gender = gndr;
        birth_date = b_date;
        social_id = so_id;
    }
};

struct Class
{
    string class_name;
    Class(string _name)
    {
        class_name = _name;
    }
    
    Student* students = nullptr;
    void AddStudent(string fileName);
    
    Class* next = nullptr;
};

struct Course{
    string course_id;
    string course_name;
    
    Class* classes = nullptr;
    void AddClass();
    
    Course* next = nullptr;
};

struct Semester
{
    int season;
    string school_year;
    string start_date;
    string end_date;
    Semester(int n, string year, string startDate, string endDate);
    
    Course* courses = nullptr;
    void AddCourse();
};

struct SchoolYear
{
    Semester **smt = new Semester*[3];
    string year;
    SchoolYear(string _year);
};

void addStudentToList(Student *&head, Student *newStudent);
//Student* createStudent(string No, string student_id, string first_name, string last_name, string gender, string birth_date, string social_id);

void createSemester(SchoolYear schul_yr);




































#endif