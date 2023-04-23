#ifndef LOGININTERFACE_H
#define LOGININTERFACE_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include "header.h"

using namespace std;

//user functions
user* logIn();
user* importAccounts(bool isStudent);
user* inputAccounts (string fileName);
user* createUser(string username, string password);
void checkUser(user *list, user *&account);
void deleteUserList(user *&list);
void gotoxy(int x, int y);
bool checkStd();
void drawBox(int x, int y, int width, int height, string title) ;

//staff profile functions
Staff* importStaff(string fileName);
Staff* createStaff(string staffID, string firstName, string lastName, string gender, string birthDate, string socialID);
void deleteStaffProfile (Staff *&list);
void printProfile(user *account);

#endif

// How to use
/*
    user *account = logIn(); //user's account
*/