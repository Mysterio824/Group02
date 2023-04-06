#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include "logInInterface.h"

//staff's functions
void createAccount();
Class* chooseClass (Class *listClass);
void findStaff(user *&account);
void staffInterface (user* account, Class* listClass, Course *listCourse);

//student's functions
void findStudent (user *&account, Class *listClass);
void studentInterface (user *account, Class* listClass, Course *listCourse);

//public's functions
void interFace (user *account, Class* listClass, Course *listCourse);
void goBackToMenu (user* account,  Class* listClass, Course *listCourse);
void logOut(user *&account, Class *listClass, Course *listCourse);
void changeInList (user *list, user *account);
void updateList (user *list, bool isStudent);
void changePass (user *&account);


#endif