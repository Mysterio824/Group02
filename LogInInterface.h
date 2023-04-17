#ifndef LOGININTERFACE_H
#define LOGININTERFACE_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include "header.h"

using namespace std;

struct staffData
{
    string staffID;
    string firstName;
    string lastName;
    string gender;
    string birthDate;
    string socialID;
    staffData *next = nullptr;

    string fullName();
};

struct user
{
    string username; // ID
    string password;
    bool isStudent;
    Student *ref;
    staffData *profile = nullptr;
    user *next;
};

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
staffData* importStaff(string fileName);
staffData* createStaff(string staffID, string firstName, string lastName, string gender, string birthDate, string socialID);
void deleteStaffProfile (staffData *&list);
void printProfile(user *account);

#endif

// How to use
/*
    user *account = logIn(); //user's account
*/