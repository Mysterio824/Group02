#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include "header.h"
#include "logInInterface.h"

//staff's functions
bool wayToImport();
void createAccount();
bool chooseCourseOrClass();
void addInfor(user *account, SchoolYear *thisYear);
void findStaff(user *&account);
void chooseToAddCourse(Course *&Hcourse);
void chooseToViewClass(Class *hClass, SchoolYear *thisYear);
void viewForStaff (user* account, SchoolYear *thisYear);
void staffInterface (user* account, SchoolYear *listYear);

//student's functions
void findStudent (user *&account, Class *listClass);
void viewCourseForStudent(user *account, Course* Hcourse, bool valid);
void studentInterface (user *account, SchoolYear *thisYear, int valid);

//public's functions
void interFace (user *account, SchoolYear *listYear);
Semester* chooseSem(SchoolYear *thisYear);
void goBackToMenu (user* account, SchoolYear *listYear);
void logOut(user *&account, SchoolYear *&listYear);
void changeInList (user *list, user *account);
void reWriteUserList(user *list, bool isStudent);
void reWriteStaffList(Staff* listStaff);
void updateUserList (user *list, bool isStudent);
void updateStaffList (Staff* listStaff);
void changePass (user *&account);


#endif