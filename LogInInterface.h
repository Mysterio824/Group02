#ifndef LOGININTERFACE_H
#define LOGININTERFACE_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#pragma once
using namespace std;

struct user {
    string username; //ID
    string password;
    bool isStudent;
    // Student *ref = nullptr;
    user* next;
};

void inputAccounts (user *&listAcc, bool isStudent);

user* createUser(string username, string password);

void addToList(user *&head, user *newUser);

void checkUser (user *list, user *&account);

void deleteUserList(user *&list);

user* logIn();


#endif

//How to use
/*
    user *account; //user's account
    logIn(account);
*/