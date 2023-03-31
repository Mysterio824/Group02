#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include "logInInterface.h"

void changeInList (user *list, user *account);

void updateList (user *list, bool isStudent);

void changePass (user *&account);

void findStudent (Student *listStudent, user* account);

void studentInterface (user *account, Student* listStudent, Course::Class* listClass, Course *listCourse);

void staffInterface (user* account, Student* listStudent, Course::Class* listClass, Course *listCourse);

void interFace (user *account, Student* listStudent, Course::Class* listClass, Course *listCourse);
#endif