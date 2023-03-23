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
    void AddStudent(string fileName);
    
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
    Semester **smt = new Semester*[3];
    std::string year;
    SchoolYear(std::string _year)
    {
        year = _year;
        for (int i = 0; i < 3; i ++)
           smt[i] -> year = _year;
    }
};

void addStudentToList(Student *&head, Student *newStudent);
Student* createStudent(string No, string student_id, string first_name, string last_name, string gender, string birth_date, string social_id);

#endif