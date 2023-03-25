#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
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

    Student(string no, string stuId, string fName, string lName, string gder, string birth, string socialId); 
};

Student* AddStudent(Student* Hstudent, string className);

struct Class
{
    string class_name;
    
    Student* Hstudent = AddStudent(Hstudent, class_name);
    
    Class* next;

    Class(string _name);

};

Class* AddClass(Class* Hclass, string className);

struct Course{
    string course_id;
    string course_name;
    string class_name;
    string teacher_name;
    string num_credits;
    int capacity = 50;
    string day;
    string session;
    
    Class* Hclass;//adding later on
    
    Course* next;

    Course(string cID, string cName, string clName, string tName, string nCredit, string capacity, string dei, string ses);
};

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