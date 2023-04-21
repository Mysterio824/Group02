#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include "logInInterface.h"
#include "header.h"

//staff's functions
bool wayToImport();
void createAccount();
void addInfor(user *account, SchoolYear *thisYear);
void findStaff(user *&account);
void choseClassToView(Class *hClass, Semester *thisSem);
void viewForStaff (user* account, SchoolYear *thisYear);
void staffInterface (user* account, SchoolYear *listYear);

//student's functions
void findStudent (user *&account, Class *listClass);
void viewForStudent (user* account, SchoolYear *thisYear);
void studentInterface (user *account, SchoolYear *listYear);

//public's functions
void interFace (user *account, SchoolYear *listYear);
void goBackToMenu (user* account, SchoolYear *listYear);
void logOut(user *&account, SchoolYear *listYear);
void changeInList (user *list, user *account);
void reWriteList(user *list, bool isStudent);
void updateList (user *list, bool isStudent);
void changePass (user *&account);


#endif