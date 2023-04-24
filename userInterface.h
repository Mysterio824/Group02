#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include "header.h"
#include "logInInterface.h"

//staff's functions
bool wayToImport();
void createAccount();
void addInfor(user *account, SchoolYear *thisYear);
Semester* chooseSem(SchoolYear *thisYear);
void findStaff(user *&account);
void chooseToViewClass(Class *hClass, Semester *thisSem);
void viewForStaff (user* account, SchoolYear *thisYear);
void staffInterface (user* account, SchoolYear *listYear);

//student's functions
void findStudent (user *&account, Class *listClass);
void viewCourseForStudent(user *account, Course* Hcourse);
void studentInterface (user *account, SchoolYear *thisYear);

//public's functions
void interFace (user *account, SchoolYear *listYear);
void goBackToMenu (user* account, SchoolYear *listYear);
void logOut(user *&account, SchoolYear *&listYear);
void changeInList (user *list, user *account);
void reWriteList(user *list, bool isStudent);
void updateList (user *list, bool isStudent);
void changePass (user *&account);


#endif