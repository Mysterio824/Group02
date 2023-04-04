#include "userInterface.h"
#include "header.h"

void changeInList(user *list, user *account)
{
    if (!list)
        return;
    while (list->next)
    {
        if (account->username == list->username)
        {
            list->password = account->password;
            return;
        }
        list = list->next;
    }
}

void updateList(user *list, bool isStudent)
{
    string fileName;
    if (isStudent)
        fileName = "listOfStdAcc";
    else
        fileName = "listOfStfAcc";
    ofstream outputFile(fileName + ".csv");
    if (!outputFile.is_open())
    {
        cout << "Error opening file" << endl;
        return;
    }
    while (list)
    {
        outputFile << list->username << ",";
        outputFile << list->password << endl;
        list = list->next;
    }
    cout << "Your password has been changed successfully!" << endl;
    cout << "-Please re-log-in your account- " << endl;
    outputFile.close();
}

void changePass(user *&account)
{
    if (!account)
        return;
    user *list;
    inputAccounts(list, account->isStudent);
    string newPass;
    cout << "Please enter your new password: ";
    cin >> newPass;
    account->password = newPass;
    changeInList(list, account);
    updateList(list, account->isStudent);

    // Log in again..
    system ("cls");
    cout << "Please re-login to your account" << endl << endl;
    checkUser(list, account);
    deleteUserList(list);
}

Class *chooseClass(Class *listClass)
{
    if (!listClass)
    {
        cout << "There is no class to choose." << endl;
        return nullptr;
    }
    int count = 0;
    Class *mark = listClass;
    cout << "which class would you like to see: " << endl;
    while (listClass)
    {
        cout << ++count << ". " << listClass->class_name << endl;
        listClass = listClass->next;
    }
    int command;
    cout << "Your choice: ";
    cin >> command;
    while (command > count)
    {
        cout << "Please enter a again: ";
        cin >> command;
    }
    for (count = 0; count < command; count++)
        mark = mark->next;
    return mark;
}

void findStudent(user *&account, Class *listClass)
{
    if (!listClass || !account)
        return;
    while (listClass)
    {
        Student *cur = listClass->Hstudent;
        while (cur || cur->student_id != account->username)
            cur = cur->next;
        if (cur->student_id == account->username)
        {
            account->ref = cur;
            return;
        }
        listClass = listClass->next;
    }
}

void studentInterface(user *account, Class *listClass, Course *listCourse)
{
    int command;
    cout << setw(3) << right << "" << "----------------------------------" << endl;
    cout << setw(5)<< right << "| " << setw(15) << right << "Welcome" << setw(15) << left << " to HCMUS!" << " |" <<endl;
    cout << "------------------------------------------" << endl;   
    cout << "| " << setw(25) << left << "Here are some of commands you can use:" << " |" <<endl;
    cout << "--------------------------------------------------------------------------" << endl;    
    cout << "| " << setw(40) << left << "1. Change your password" << setw(35) << internal
         << setw(30) << left << "2. View your score" << " |" << endl;
    cout << "| " << setw(72) << right << " |"  << endl;
    cout << "| " << setw(40) << left << "3. View your course's schedule" << setw(35) << internal
         << setw(30) << left << "4. Log out" << " |" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Enter your option: ";
    cin >> command;
    switch (command)
    {
    case 1:
        system ("cls");
        changePass(account);
        goBackToMenu(account, listClass, listCourse);
    case 3:
        system("cls");
        printStdCourse(account->ref, listCourse);
        cout << endl
             << "Press 1 to back to menu: ";
        cin >> command;
        while (command != 1)
        {
            cout << "please press again:";
            cin >> command;
        }
        goBackToMenu(account, listClass, listCourse);
        // case 4:
    }
}

void staffInterface(user *account, Class *listClass, Course *listCourse)
{
    int command = 0;
    cout << setw(3) << right << "" << "----------------------------------" << endl;
    cout << setw(5)<< right << "| " << setw(15) << right << "Welcome" << setw(15) << left << " to HCMUS!" << " |" <<endl;
    cout << "------------------------------------------" << endl;   
    cout << "| " << setw(25) << left << "Here are some of commands you can use:" << " |" <<endl;
    cout << "--------------------------------------------------------------------------" << endl;    
    cout << "| " << setw(40) << left << "1. Change your password" << setw(35) << internal
         << setw(30) << left << "2. View the list of students" << " |" << endl;
    cout << "| " << setw(72) << right << " |"  << endl;
    cout << "| " << setw(40) << left << "3. View the list of a class" << setw(35) << internal
         << setw(30) << left << "4. Log out" << " |" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Enter your option: ";
    cin >> command;
    switch (command)
    {
    case 1:
        system("cls");
        changePass(account);
        goBackToMenu(account, listClass, listCourse);
    case 2:
        system("cls");
        printAllClass(listClass);
        goBackToMenu(account, listClass, listCourse);
    case 3:
        system("cls");
        printStfClass(chooseClass(listClass));
        goBackToMenu(account, listClass, listCourse);
    }
}

void interFace(user *account, Class *listClass, Course *listCourse)
{
    if (!account)
        return;

    if (account->isStudent)
    {
        findStudent(account, listClass);
        studentInterface(account, listClass, listCourse);
    }
    else
        staffInterface(account, listClass, listCourse);
}

void goBackToMenu(user *account, Class *listClass, Course *listCourse)
{
    int command;
    do
    {
        cout << endl
             << "Press 1 to go back to main menu: ";
        cin >> command;
    } while (command != 1);
    system("cls");
    if (account->isStudent)
        return studentInterface(account, listClass, listCourse);
    return staffInterface(account, listClass, listCourse);
}