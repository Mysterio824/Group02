#include "userInterface.h"
#include "header.h"

//---------------------------Staff--------------------------------------
void createAccount()
{
    user *newList;
    bool isStudent = false;
    int cmd;
    cout << "---------------------------------------------" << endl;
    cout << "| " << setw(25) << left << "Which type of account you want to create:"
         << " |" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "| " << setw(20) << left << "1. Student" << setw(15) << internal
         << setw(21) << right << "2. Staff "
         << " |" << endl;
    cout << "---------------------------------------------" << endl;
    cout << endl;
    cout << "Enter your choice: ";
    cin >> cmd;
    while (cmd != 1 && cmd != 2)
    {
        cout << endl
             << "Please again: ";
        cin >> cmd;
    }
    if (cmd == 1)
        isStudent = true;
    cout << endl << "---------------------------------------------" << endl;
    cout << "| " << setw(25) << left << "Please choose way to import new accounts:"
         << " |" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "| " << setw(20) << left << "1. Manual" << setw(15) << internal
         << setw(21) << right << "2. Auto "
         << " |" << endl;
    cout << "---------------------------------------------" << endl;
    cout << endl;
    cout << "Enter your choice: ";
    cin >> cmd;
    while (cmd != 1 && cmd != 2)
    {
        cout << endl
             << "Please choose again: ";
        cin >> cmd;
    }
    if (cmd == 1)
    {
        user *tmp;
        cout << endl
             << "How many accounts would you like to create: ";
        cin >> cmd;
        for (int i = 0; i < cmd; i++)
        {
            system("cls");
            string username, password;
            cout << endl
                 << "Please enter the username:";
            cin >> username;
            cout << endl
                 << "Please enter the password:";
            cin >> password;
            tmp = createUser(username, password);
            tmp -> next = newList;
            newList = tmp;
        }
    }
    else {
        string fileName;
        cout << endl << "Please enter the source file: ";
        cin >> fileName;
        newList = inputAccounts(fileName);
    }
    updateList(newList, isStudent);
    deleteUserList(newList);
}

Class *chooseClass(Class *listClass)
{
    if (!listClass)
    {
        cout << "There is no class to choose." << endl;
        return nullptr;
    }
    int count = 0;
    listClass = listClass->next;
    Class *mark = listClass;
    cout << "------------------------" << endl;
    cout << "| " << setw(20) << internal << "List of classes: "
         << " |" << endl;
    cout << "------------------------" << endl;
    while (listClass)
    {
        cout << "| " << ++count << ". " << setw(17) << left << listClass->class_name << " |" << endl;
        listClass = listClass->next;
    }
    cout << "------------------------" << endl;
    int command;
    cout << endl
         << "Please enter the class you would like to see: ";
    cin >> command;
    while (command > count)
    {
        cout << endl
             << "Please enter again: ";
        cin >> command;
    }
    for (count = 0; count < command - 1; count++)
        mark = mark->next;
    return mark;
}

void findStaff(user *&account)
{
    if (!account)
        return;
    staffData *list = importStaff("listStaff");
    staffData *cur = list;
    while (list)
    {
        if (list->staffID == account->username)
        {
            account->profile = createStaff(list->staffID, list->firstName, list->lastName, list->gender, list->birthDate, list->socialID);
            break;
        }
        list = list -> next;
    }
    deleteStaffProfile(cur);
}

void staffInterface(user *account, Class *listClass, Course *listCourse)
{
    system("cls");
    int command = 0;
    cout << setw(3) << right << ""
         << "----------------------------------" << endl;
    cout << setw(5) << right << "| " << setw(15) << right << "Welcome" << setw(15) << left << " to HCMUS!"
         << " |" << endl;
    cout << "------------------------------------------" << endl;
    cout << "| " << setw(25) << left << "Here are some of commands you can use:"
         << " |" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "| " << setw(40) << left << "1. Change your password" << setw(35) << internal
         << setw(30) << left << "2. View the list of students"
         << " |" << endl;
    cout << "| " << setw(72) << right << " |" << endl;
    cout << "| " << setw(40) << left << "3. View the list of a class" << setw(35) << internal
         << setw(30) << left << "4. view your profile"
         << " |" << endl;
    cout << "| " << setw(72) << right << " |" << endl;
    cout << "| " << setw(40) << left << "5. Create new accounts" << setw(35) << internal
         << setw(30) << left << "6. Log out"
         << " |" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Enter your option: ";
    cin >> command;
    while (command < 1 || command > 6){
        cout << endl << "Please enter again: ";
        cin >> command;
    }
    system("cls");
    switch (command)
    {
    case 1:
        changePass(account);
        cout << endl
             << "Login successful!" << endl;
        break;
    case 2:
        printAllClass(listClass);
        break;
    case 3:
        printStfClass(chooseClass(listClass));
        break;
    case 4:
        printProfile(account);
        break;
    case 5:
        createAccount();
        break;
    case 6:
        logOut(account, listClass, listCourse);
    }
    goBackToMenu(account, listClass, listCourse);
}

//---------------------------student--------------------------------------
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
    system("cls");
    int command;
    cout << setw(3) << right << ""
         << "----------------------------------" << endl;
    cout << setw(5) << right << "| " << setw(15) << right << "Welcome" << setw(15) << left << " to HCMUS!"
         << " |" << endl;
    cout << "------------------------------------------" << endl;
    cout << "| " << setw(25) << left << "Here are some of commands you can use:"
         << " |" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "| " << setw(40) << left << "1. Change your password" << setw(35) << internal
         << setw(30) << left << "2. View your score"
         << " |" << endl;
    cout << "| " << setw(72) << right << " |" << endl;
    cout << "| " << setw(40) << left << "3. View your course's schedule" << setw(35) << internal
         << setw(30) << left << "4. View your profile"
         << " |" << endl;
    cout << "| " << setw(72) << right << " |" << endl;
    cout << "| " << setw(40) << left << "5. View..." << setw(35) << internal
         << setw(30) << left << "6. Log out"
         << " |" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Enter your option: ";
    cin >> command;
    while (command < 1 || command > 6){
        cout << endl << "Please enter again: ";
        cin >> command;
    }
    system("cls");
    switch (command)
    {
    case 1:
        changePass(account);
        cout << endl
             << "Login successful!" << endl;
        break;
    case 3:
        printStdCourse(account->ref, listCourse);
        break;
    case 4:
        printProfile(account);
        break;
    case 6:
        logOut(account, listClass, listCourse);
    }
    goBackToMenu(account, listClass, listCourse);
}

//---------------------------Public--------------------------------------
void interFace(user *account, Class *listClass, Course *listCourse)
{
    // if (!account || !listClass || !listCourse)
    //     return;
    if (!account)
        return;

    if (account->isStudent)
    {
        findStudent(account, listClass);
        studentInterface(account, listClass, listCourse);
        return;
    }
    findStaff(account);
    staffInterface(account, listClass, listCourse);
}

void goBackToMenu(user *account, Class *listClass, Course *listCourse)
{
    int command;
    do
    {
        cout << endl << endl
             << "Press 1 to go back to main menu: ";
        cin >> command;
    } while (command != 1);
    if (account->isStudent)
        return studentInterface(account, listClass, listCourse);
    return staffInterface(account, listClass, listCourse);
}

void logOut(user *&account, Class *listClass, Course *listCourse)
{
    int command;
    cout << "------------------------------" << endl;
    cout << "| " << setw(26) << left << "  Do you want to log out:"
         << " |" << endl;
    cout << "------------------------------" << endl;
    cout << "| " << setw(20) << left << "1. Yes" << setw(20) << internal
         << setw(6) << left << "2. No"
         << " |" << endl;

    cout << "------------------------------" << endl;
    cout << "Enter your choice: ";
    cin >> command;
    while (command != 1 && command != 2)
    {
        cout << endl
             << "Please enter again: ";
        cin >> command;
    }
    if (command == 1)
    {
        system("cls");
        account = nullptr;
        account = logIn();
    }
    if (account->isStudent)
        return studentInterface(account, listClass, listCourse);
    return staffInterface(account, listClass, listCourse);
}

void changeInList(user *list, user *account)
{
    if (!list)
        return;
    while (list)
    {
        if (account->username == list->username)
        {
            list->password = account->password;
            return;
        }
        list = list->next;
    }
}

void reWriteList(user *list, bool isStudent)
{
    if(!list) return;
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
    cout << endl << "Your data have been added successful!";
    outputFile.close();
}

void updateList(user *newList, bool isStudent){
    if(!newList) return;
    string fileName;
    if (isStudent)
        fileName = "listOfStdAcc";
    else
        fileName = "listOfStfAcc";
    ofstream outputFile(fileName + ".csv", ios::app);
    if (!outputFile.is_open())
    {
        cout << "Error opening file" << endl;
        return;
    }
    while (newList)
    {
        outputFile << newList->username << ",";
        outputFile << newList->password << endl;
        newList = newList->next;
    }
    cout << endl << "Your data have been added successful!";
    outputFile.close();
}

void changePass(user *&account)
{
    if (!account)
        return;
    user *list;
    importAccounts(list, account->isStudent);
    string newPass;
    cout << "Please enter your new password: ";
    cin >> newPass;
    account->password = newPass;
    changeInList(list, account);
    reWriteList(list, account->isStudent);
    cout << endl
         << "Your password has been changed successfully!" << endl;
    cout << endl
         << "-Please re-log-in your account- " << endl;
    // Log in again..
    system("cls");
    cout << "Please re-login to your account" << endl
         << endl;
    checkUser(list, account);
    deleteUserList(list);
}