#ifndef ACCOUNTDATA_H
#define ACCOUNTDATA_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct user {
    string username;
    string password;
    string role;
    string ID;
    user* next;
};

void inputAccounts (user *&listStaff);

user* createUser(string username, string password, string role, string ID);

void addToList(user *&head, user *newUser);

void checkUser (user *list, user *&account);

void deleteUserList(user *&list);

void logIn(user *&account);


#endif

//How to use
/*
    user *account; //user's account
    logIn(account);
*/