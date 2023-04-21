#include "userInterface.h"
#include "header.h"

//---------------------------Staff--------------------------------------

bool wayToImport()
{
    int choice = 1;
    bool enterPressed = false;
    while (!enterPressed)
    {
        system("cls");             // clears the console
        SetConsoleOutputCP(65001); // sets console output to UTF-8 encoding
        cout << "---------------------------------------------" << endl;
        cout << "| " << setw(41) << left << " Please choose way to import:"
             << " |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "| " << setw(20) << left;
        if (choice == 1)
        {
            cout << "➤ Manual";
        }
        else
        {
            cout << "  Manual";
        }
        cout << setw(15) << right << setw(23) << right;
        if (choice == 2)
        {
            cout << "➤ Auto ";
        }
        else
        {
            cout << "  Auto ";
        }
        cout << " |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << endl
             << "Use arrow keys to move, and press enter to select." << endl;
        int key = getch();
        switch (key)
        {
        case 224: // arrow keys
            key = getch();
            if (key == 77 && choice < 2)
            { // right arrow
                choice++;
            }
            else if (key == 75 && choice > 1)
            { // left arrow
                choice--;
            }
            break;
        case 13: // enter key
            enterPressed = true;
            break;
        default:
            break;
        }
    }
    if (choice == 1)
        return true;
    if (choice == 2)
        return false;
}

void createAccount()
{
    user *newList;
    bool isStudent = checkStd();
    bool import = wayToImport();
    system("cls");
    int x = 0, y = 0;
    if (import)
    {
        int cmd;
        user *tmp;
        cout << endl
             << "How many accounts would you like to create: ";
        cin >> cmd;
        for (int i = 0; i < cmd; i++)
        {
            system("cls");

            string username, password;
            gotoxy(x, y);
            cout << setw(10) << ""
                 << "-------------------------------" << endl;
            gotoxy(x, y + 1);
            cout << "Username: |                             |" << endl;
            gotoxy(x, y + 2);
            cout << setw(10) << ""
                 << "-------------------------------" << endl;
            gotoxy(x, y + 3);
            cout << "Password: |                             |" << endl;
            gotoxy(x, y + 4);
            cout << setw(10) << ""
                 << "-------------------------------" << endl;
            gotoxy(x + 12, y + 1);
            cin >> username;
            gotoxy(x + 12, y + 3);
            cin >> password;
            tmp = createUser(username, password);
            tmp->next = newList;
            newList = tmp;
        }
    }
    else
    {
        string fileName;
        gotoxy(x, y);
        cout << setw(20) << ""
             << "-------------------------------" << endl;
        gotoxy(x, y + 1);
        cout << "Source file's name: |                             |" << endl;
        gotoxy(x, y + 2);
        cout << setw(20) << ""
             << "-------------------------------" << endl;
        gotoxy(x + 22, y + 1);
        cin >> fileName;
        newList = inputAccounts(fileName);
    }
    updateList(newList, isStudent);
    deleteUserList(newList);
}

void addInfor(user *account, SchoolYear *thisYear)
{
    system("cls");
    int choice = 1;
    bool enterPressed = false;
    while (!enterPressed)
    {
        system("cls");             // clears the console
        SetConsoleOutputCP(65001); // sets console output to UTF-8 encoding
        cout << setw(14) << right << ""
             << "--------------------------------------------" << endl;
        cout << setw(16) << right << "| " << setw(20) << right << " What do you " << setw(20) << left << "want to add:"
             << " |" << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        cout << "| ";
        if (choice == 1)
        {
            cout << setw(26) << left << "➤ Add new School Year" << setw(15) << internal << "";
        }
        else
        {
            cout << setw(26) << left << " Add new School Year" << setw(13) << internal << "";
        }
        if (choice == 2)
        {
            cout << setw(33) << left << "➤ Add more accounts";
        }
        else
        {
            cout << setw(31) << left << " Add more accounts";
        }
        cout << " |" << endl;
        cout << "| " << setw(72) << right << " |" << endl;
        cout << "| ";
        if (choice == 3)
        {
            cout << setw(34) << left << "➤ Add Student to Class" << setw(7) << internal << "";
        }
        else
        {
            cout << setw(34) << left << " Add Student to Class" << setw(5) << internal << "";
        }
        if (choice == 4)
        {
            cout << setw(33) << left << "➤ Add Student to Course";
        }
        else
        {
            cout << setw(31) << left << " Add Student to Course";
        }
        if (choice == 5)
        {
            cout << setw(34) << left << "➤ Add new Course" << setw(7) << internal << "";
        }
        else
        {
            cout << setw(34) << left << " Add new Course" << setw(5) << internal << "";
        }
        if (choice == 6)
        {
            cout << setw(33) << left << "➤ Add new Semeter";
        }
        else
        {
            cout << setw(31) << left << " Add new Semester";
        }
        cout << " |" << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        cout << endl
             << "Use arrow keys to move, and press enter to select." << endl;
        int key = getch();
        switch (key)
        {
        case 224: // arrow keys
            key = getch();
            if (key == 77 && choice < 6)
            { // right arrow
                choice++;
            }
            else if (key == 75 && choice > 1)
            { // left arrow
                choice--;
            }
            else if (key == 80 && choice < 4)
            { // down arrow
                choice += 2;
            }
            else if (key == 72 && choice > 3)
            { // up arrow
                choice -= 2;
            }
            break;
        case 13: // enter key
            enterPressed = true;
            break;
        default:
            break;
        }
    }
    // perform action based on selected choice
    system("cls");
    switch (choice)
    {
    case 1:
        AddSchoolYear(thisYear);
        break;
    case 2:
        createAccount();
        break;
    case 3:
        Class* thisClass = printListClass(thisYear ->Hclass);
        AddStudentToClass(thisClass);
        break;
    case 4:
        Course* thisCourse = printListCourse(thisYear->Hsemester->Hcourse);
        AddStudentToCourse(thisCourse);
        break;
    case 5:
        AddCourseToSemester(thisYear -> Hsemester);
        break;
    case 6:
        AddSemesterToSchoolYear(thisYear);
        break;
    }
}

void findStaff(user *&account)
{
    if (!account || account->profile)
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
        list = list->next;
    }
    deleteStaffProfile(cur);
}

void choseClassToView(Class *hClass, Semester *thisSem)
{
    int choice = 1;
    bool enterPressed = false;
    while (!enterPressed)
    {
        system("cls");             // clears the console
        SetConsoleOutputCP(65001); // sets console output to UTF-8 encoding
        cout << "---------------------------------------------" << endl;
        cout << "| " << setw(41) << left << " What do you want to see:"
             << " |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "| " << setw(20) << left;
        if (choice == 1)
        {
            cout << "➤ Information of students";
        }
        else
        {
            cout << "  Information of students";
        }
        cout << setw(15) << right << setw(23) << right;
        if (choice == 2)
        {
            cout << "➤ Score board ";
        }
        else
        {
            cout << "  core board ";
        }
        cout << " |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << endl
             << "Use arrow keys to move, and press enter to select." << endl;
        int key = getch();
        switch (key)
        {
        case 224: // arrow keys
            key = getch();
            if (key == 77 && choice < 2)
            { // right arrow
                choice++;
            }
            else if (key == 75 && choice > 1)
            { // left arrow
                choice--;
            }
            break;
        case 13: // enter key
            enterPressed = true;
            break;
        default:
            break;
        }
    }
    if (choice == 1)
        return printClassScoreBoard(hClass, thisSem);
    if (choice == 2)
        return printOneClass(hClass);
}

void viewForStaff(user *account, SchoolYear *listYear)
{
    system("cls");
    if (!account || !listYear)
    {
        cout << "There's nothing to see!";
        return;
    }
    int choice = 1;
    bool enterPressed = false;
    while (!enterPressed)
    {
        system("cls");             // clears the console
        SetConsoleOutputCP(65001); // sets console output to UTF-8 encoding
        cout << setw(2) << right << ""
             << "------------------------------------------------------------------" << endl;
        cout << setw(4) << right << "| " << setw(9) << right << "  Welcome" << setw(11) << left << " to HCMUS!"
             << " |";
        cout << setw(25) << left << "  Here are some of commands you can use:"
             << " |" << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        cout << "| ";
        if (choice == 1)
        {
            cout << setw(26) << left << "➤ View list of Students" << setw(15) << internal << "";
        }
        else
        {
            cout << setw(26) << left << " View list of Students" << setw(13) << internal << "";
        }
        if (choice == 2)
        {
            cout << setw(33) << left << "➤ View the list of Classes";
        }
        else
        {
            cout << setw(31) << left << " View the list of Classes";
        }
        cout << " |" << endl;
        cout << "| " << setw(72) << right << " |" << endl;
        cout << "| ";
        if (choice == 3)
        {
            cout << setw(34) << left << "➤ View list of Courses" << setw(7) << internal << "";
        }
        else
        {
            cout << setw(34) << left << " View list of Courses" << setw(5) << internal << "";
        }
        if (choice == 4)
        {
            cout << setw(33) << left << "➤ View your profile";
        }
        else
        {
            cout << setw(31) << left << " View your profile";
        }
        cout << " |" << endl;
        cout << "| " << setw(72) << right << " |" << endl;
        cout << "| ";
        if (choice == 5)
        {
            cout << setw(34) << left << "➤ View this year Semesters" << setw(7) << internal << "";
        }
        else
        {
            cout << setw(34) << left << " View this year Semesters" << setw(5) << internal << "";
        }
        if (choice == 6)
        {
            cout << setw(33) << left << "➤ View list of Years";
        }
        else
        {
            cout << setw(31) << left << " View list of Years";
        }
        cout << " |" << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        cout << endl
             << "Use arrow keys to move, and press enter to select." << endl;
        int key = getch();
        switch (key)
        {
        case 224: // arrow keys
            key = getch();
            if (key == 77 && choice < 6)
            { // right arrow
                choice++;
            }
            else if (key == 75 && choice > 1)
            { // left arrow
                choice--;
            }
            else if (key == 80 && choice < 4)
            { // down arrow
                choice += 2;
            }
            else if (key == 72 && choice > 3)
            { // up arrow
                choice -= 2;
            }
            break;
        case 13: // enter key
            enterPressed = true;
            break;
        default:
            break;
        }
    }
    system("cls");
    switch (choice)
    {
    case 1:
        printAllClass(listYear->Hclass);
        break;
    case 2:
        choseClassToView(printListClass(listYear->Hclass), listYear->Hsemester);
        break;
    case 3:
        printCourseScoreBoard(printListCourse(listYear->Hsemester->Hcourse));
        break;
    case 4:
        printProfile(account);
        break;
    case 5:
        addInfor(account, listYear);
        break;
    case 6:
        logOut(account, listYear);
    }
    goBackToMenu(account, listYear);
}

void staffInterface(user *account, SchoolYear *listYear)
{
    system("cls");
    int choice = 1;
    bool enterPressed = false;
    while (!enterPressed)
    {
        system("cls");             // clears the console
        SetConsoleOutputCP(65001); // sets console output to UTF-8 encoding
        cout << setw(2) << right << ""
             << "------------------------------------------------------------------" << endl;
        cout << setw(4) << right << "| " << setw(9) << right << "  Welcome" << setw(11) << left << " to HCMUS!"
             << " |";
        cout << setw(25) << left << "  Here are some of commands you can use:"
             << " |" << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        cout << "| ";
        if (choice == 1)
        {
            cout << setw(26) << left << "➤ Change your password" << setw(15) << internal << "";
        }
        else
        {
            cout << setw(26) << left << " Change your password" << setw(13) << internal << "";
        }
        if (choice == 2)
        {
            cout << setw(33) << left << "➤ View system's information";
        }
        else
        {
            cout << setw(31) << left << " View system's information";
        }
        cout << " |" << endl;
        cout << "| " << setw(72) << right << " |" << endl;
        cout << "| ";
        if (choice == 3)
        {
            cout << setw(34) << left << "➤ Add things to system" << setw(7) << internal << "";
        }
        else
        {
            cout << setw(34) << left << " Add things to system" << setw(5) << internal << "";
        }
        if (choice == 4)
        {
            cout << setw(33) << left << "➤ Log out";
        }
        else
        {
            cout << setw(31) << left << " Log out";
        }
        cout << " |" << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        cout << endl
             << "Use arrow keys to move, and press enter to select." << endl;
        int key = getch();
        switch (key)
        {
        case 224: // arrow keys
            key = getch();
            if (key == 77 && choice < 4)
            { // right arrow
                choice++;
            }
            else if (key == 75 && choice > 1)
            { // left arrow
                choice--;
            }
            else if (key == 80 && choice < 3)
            { // down arrow
                choice += 2;
            }
            else if (key == 72 && choice > 2)
            { // up arrow
                choice -= 2;
            }
            break;
        case 13: // enter key
            enterPressed = true;
            break;
        default:
            break;
        }
    }
    // perform action based on selected choice
    system("cls");
    switch (choice)
    {
    case 1:
        changePass(account);
        cout << "Login successful!" << endl;
        break;
    case 2:
        viewForStaff(account, listYear);
        break;
    case 3:
        addInfor(account, listYear);
        break;
    case 4:
        logOut(account, listYear);
    }
    goBackToMenu(account, listYear);
}

//---------------------------student--------------------------------------
void findStudent(user *&account, Class *listClass)
{
    if (!listClass || !account || account->ref)
        return;
    while (listClass)
    {
        Student *cur = listClass->Hstudent;
        while (cur)
        {
            if (cur->student_id == account->username)
            {
                account->ref = cur;
                return;
            }
            cur = cur->next;
        }
        listClass = listClass->next;
    }
}

void studentInterface(user *account, SchoolYear *listYear)
{
    int choice = 1;
    bool enterPressed = false;
    while (!enterPressed)
    {
        system("cls");             // clears the console
        SetConsoleOutputCP(65001); // sets console output to UTF-8 encoding
        cout << setw(2) << right << ""
             << "------------------------------------------------------------------" << endl;
        cout << setw(4) << right << "| " << setw(9) << right << "  Welcome" << setw(11) << left << " to HCMUS!"
             << " |";
        cout << setw(25) << left << "  Here are some of commands you can use:"
             << " |" << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        cout << "| ";
        if (choice == 1)
        {
            cout << setw(39) << left << "➤ Change your password" << setw(9) << internal << "";
        }
        else
        {
            cout << setw(39) << left << " Change your password" << setw(7) << internal << "";
        }
        if (choice == 2)
        {
            cout << setw(26) << left << "➤ View your profile ";
        }
        else
        {
            cout << setw(24) << left << " View your profile ";
        }
        cout << " |" << endl;
        cout << "| " << setw(72) << right << " |" << endl;
        cout << "| ";
        if (choice == 3)
        {
            cout << setw(39) << left << "➤ View course's information" << setw(9) << internal << "";
        }
        else
        {
            cout << setw(39) << left << " View course's information" << setw(7) << internal << "";
        }
        if (choice == 4)
        {
            cout << setw(26) << left << "➤ Log out";
        }
        else
        {
            cout << setw(24) << left << " Log out";
        }
        cout << " |" << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        cout << endl
             << "Use arrow keys to move, and press enter to select." << endl;
        int key = getch();
        switch (key)
        {
        case 224: // arrow keys
            key = getch();
            if (key == 77 && choice < 4)
            { // right arrow
                choice++;
            }
            else if (key == 75 && choice > 1)
            { // left arrow
                choice--;
            }
            else if (key == 80 && choice < 3)
            { // down arrow
                choice += 2;
            }
            else if (key == 72 && choice > 2)
            { // up arrow
                choice -= 2;
            }
            break;
        case 13: // enter key
            enterPressed = true;
            break;
        default:
            break;
        }
    }
    system("cls");
    switch (choice)
    {
    case 1:
        changePass(account);
        cout << "Login successful!" << endl;
        break;
    case 3:
        printStdCourse(account->ref, listYear->Hsemester->Hcourse);
        break;
    case 4:
        printProfile(account);
        break;
    case 6:
        logOut(account, listYear);
    }
    goBackToMenu(account, listYear);
}

//---------------------------Public--------------------------------------
void interFace(user *account, SchoolYear *listYear)
{
    if (!account || !listYear)
        return;

    if (account->isStudent)
    {
        findStudent(account, listYear->Hclass);
        studentInterface(account, listYear);
        return;
    }
    findStaff(account);
    staffInterface(account, listYear);
}

void goBackToMenu(user *account, SchoolYear *listYear)
{
    int command;
    do
    {
        cout << endl
             << endl
             << "Press 1 to go back to main menu: ";
        cin >> command;
    } while (command != 1);
    if (account->isStudent)
        return studentInterface(account, listYear);
    return staffInterface(account, listYear);
}

void logOut(user *&account, SchoolYear *listYear)
{
    int choice = 1;
    bool enterPressed = false;
    while (!enterPressed)
    {
        system("cls");             // clears the console
        SetConsoleOutputCP(65001); // sets console output to UTF-8 encoding
        cout << "---------------------------------------------" << endl;
        cout << "| " << setw(41) << left << " Do you want to log out:"
             << " |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "| " << setw(20) << left;
        if (choice == 1)
        {
            cout << "➤ Yes";
        }
        else
        {
            cout << "  Yes";
        }
        cout << setw(15) << right << setw(23) << right;
        if (choice == 2)
        {
            cout << "➤ No ";
        }
        else
        {
            cout << "  No ";
        }
        cout << " |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << endl
             << "Use arrow keys to move, and press enter to select." << endl;
        int key = getch();
        switch (key)
        {
        case 224: // arrow keys
            key = getch();
            if (key == 77 && choice < 2)
            { // right arrow
                choice++;
            }
            else if (key == 75 && choice > 1)
            { // left arrow
                choice--;
            }
            break;
        case 13: // enter key
            enterPressed = true;
            break;
        default:
            break;
        }
    }
    if (choice == 1)
    {
        system("cls");
        account->ref = nullptr;
        account->profile = nullptr;
        account = nullptr;
        account = logIn();
        return interFace(account, listYear);
    }
    if (choice == 2)
        return interFace(account, listYear);
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
    if (!list)
        return;
    string fileName;
    if (isStudent)
        fileName = "listOfStdAcc";
    else
        fileName = "listOfStfAcc";
    ofstream outputFile("input/accounts/" + fileName + ".csv");
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
    cout << endl
         << "Your data have been added successful!";
    outputFile.close();
}

void updateList(user *newList, bool isStudent)
{
    if (!newList)
        return;
    string fileName;
    if (isStudent)
        fileName = "listOfStdAcc";
    else
        fileName = "listOfStfAcc";
    ofstream outputFile("input/accounts/" + fileName + ".csv", ios::app);
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
    cout << endl
         << "Your data have been added successful!";
    outputFile.close();
}

void changePass(user *&account)
{
    if (!account)
        return;
    user *list = importAccounts(account->isStudent);
    string newPass;
    cout << "Please enter your new password: ";
    cin >> newPass;
    account->password = newPass;
    changeInList(list, account);
    reWriteList(list, account->isStudent);
    system("cls");
    // Log in again..
    cout << "Please re-login to your account" << endl;
    checkUser(list, account);
    deleteUserList(list);
}