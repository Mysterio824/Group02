#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include "logInInterface.h"

void changeInList (user *list, user *account);

void updateList (user *list);

void changePass (user *&account);

void interFace (user *account);

#endif