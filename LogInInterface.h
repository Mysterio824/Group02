#ifndef LOGININTERFACE_H
#define LOGININTERFACE_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
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
    staffData *profile = nullptr;
    Student *ref = nullptr;
    user *next;
};

//user functions
user* logIn();
void importAccounts(user *&listAcc, bool isStudent);
user* inputAccounts (string fileName);
user* createUser(string username, string password);
void checkUser(user *list, user *&account);
void deleteUserList(user *&list);

//staff profile functions
staffData* importStaff(string fileName);
staffData* createStaff(string staffID, string firstName, string lastName, string gender, string birthDate, string socialID);
void addToList(staffData *&head, staffData *newUser);
void deleteStaffProfile (staffData *&list);
void printProfile(user *account);

#endif

// How to use
/*
    user *account; //user's account
    logIn(account);
*/