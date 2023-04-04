#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include "logInInterface.h"

void changeInList (user *list, user *account);

void updateList (user *list, bool isStudent);

void changePass (user *&account);

Class* chooseClass (Class *listClass);

void findStudent (user *&account, Class *listClass);

void studentInterface (user *account, Class* listClass, Course *listCourse);

void staffInterface (user* account, Class* listClass, Course *listCourse);

void interFace (user *account, Class* listClass, Course *listCourse);

void goBackToMenu (user* account,  Class* listClass, Course *listCourse);

#endif