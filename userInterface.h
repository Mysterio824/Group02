#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include "logInInterface.h"

//staff's functions
void createAccount();
Class* chooseClass (Class *listClass);
void findStaff(user *&account);
void staffInterface (user* account, SchoolYear *listYear);

//student's functions
void findStudent (user *&account, Class *listClass);
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