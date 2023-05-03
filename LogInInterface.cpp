#include "logInInterface.h"

user *logIn()
{
    user *account = new user;
    bool isStudent = checkStd();

    user *listAcc = importAccounts(isStudent); // list of data user's accounts

    system("cls");
    checkUser(listAcc, account);
    account->isStudent = isStudent;

    deleteUserList(listAcc);
    return account;
}

bool checkStd(){
    int choice = 1;
    bool enterPressed = false;
    while (!enterPressed) {
        system("cls"); // clears the console
        SetConsoleOutputCP(65001); // sets console output to UTF-8 encoding
        cout << "---------------------------------------------" << endl;
        cout << "| " << setw(23) << right << " Choose student" << setw(18) << left << " or staff:"
             << " |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "| " << setw(19) << left;
        if (choice == 1) {
            cout << "➤ Student";
        } 
        else {
            cout << " Student";
        }
        cout << setw(13) << internal << "" << setw(11) << left;
        if (choice == 2) {
            cout << "➤ Staff ";
        } 
        else {
            cout << " Staff ";
        }
        cout << " |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << endl << "Use arrow keys to move, and press enter to select." << endl;
        int key = getch();
        switch (key) {
            case 224: // arrow keys
                key = getch();
                if (key == 77 && choice < 2) { // right arrow
                    choice++;
                } else if (key == 75 && choice > 1) { // left arrow
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

user* importAccounts(bool isStudent)
{ // upload the data of users
    user* list = nullptr;
    string fileName;
    if (isStudent)
        fileName = "listOfStdAcc";
    else
        fileName = "listOfStfAcc";
    ifstream file1("input/accounts/"+ fileName + ".csv");
    if (!file1.is_open())
    {
        cout << "Error opening file" << endl;
        return nullptr;
    }
    string line;
    user *newUser;
    while (getline(file1, line))
    {
        stringstream ss(line);
        string username, password;
        getline(ss, username, ',');
        getline(ss, password, ',');
        newUser = createUser(username, password);
        newUser->next = list;
        list = newUser;
    }
    file1.close();

    return list;
}

user *inputAccounts(string fileName)
{ // upload the data of users
    user *list = nullptr;
    ifstream file1(fileName + ".csv");
    if (!file1.is_open())
    {
        cout << "Error opening file" << endl;
        return nullptr;
    }
    string line;
    user *newUser;
    while (getline(file1, line))
    {
        stringstream ss(line);
        string username, password;
        getline(ss, username, ',');
        getline(ss, password, ',');
        newUser = createUser(username, password);
        newUser->next = list;
        list = newUser;
    }
    file1.close();
    return list;
}

user *createUser(string username, string password)
{
    user *newUser = new user;
    newUser->username = username;
    newUser->password = password;
    newUser->next = nullptr;
    return newUser;
}


void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void checkUser(user *list, user *&account)
{
    if (!list)
        return;

    string inputUsername, inputPassword;
    int x = 0, y = 0; // Starting position of the box

    do {
        // Draw the box and get the username and password from the user
        system("cls");
        gotoxy(x, y);
        cout << setw(10)<< ""<< "-------------------------------" << endl;
        gotoxy(x, y+1);
        cout << "Username: |                             |" << endl;
        gotoxy(x, y+2);
        cout << setw(10)<< ""<< "-------------------------------" << endl;
        gotoxy(x, y+3);
        cout << "Password: |                             |" << endl;
        gotoxy(x, y+4);
        cout << setw(10)<< ""<< "-------------------------------" << endl;
        gotoxy(x+12, y+1);
        cin >> inputUsername;
        gotoxy(x+12, y+3);
        cin >> inputPassword;

        // Check if the username and password are correct
        user *cur = list;
        while (cur)
        {
            if (inputUsername == cur->username && inputPassword == cur->password)
            {
                system("cls");
                account->username = cur->username;
                account->password = cur->password;
                return;
            }
            if (inputUsername == cur->username)
                break;
            cur = cur->next;
        }

        // Display an error message if the username or password is incorrect
        gotoxy(x, y+6);
        cout << "Wrong username or password! Press any key to try again..." << endl;
        getch();
    } while (true);
}

void deleteUserList(user *&list)
{
    if (!list)
        return;
    user *cur = list;
    while (list->next)
    {
        list = list->next;
        delete cur;
        cur = list;
    }
    delete list;
    delete cur;
}

Staff *importStaff(string fileName)
{
    Staff *list = nullptr;
    ifstream file1("input/academicStaff/" + fileName + ".csv");
    if (!file1.is_open())
    {
        cout << "Error opening file" << endl;
        return nullptr;
    }
    Staff *newUser;
    string line;
    while (getline(file1, line))
    {
        stringstream ss(line);
        string staffID, firstName, lastName, gender, birthDate, socialID;
        getline(ss, staffID, ',');
        getline(ss, firstName, ',');
        getline(ss, lastName, ',');
        getline(ss, gender, ',');
        getline(ss, birthDate, ',');
        getline(ss, socialID, ',');
        newUser = createStaff(staffID, firstName, lastName, gender, birthDate, socialID);
        newUser->next = list;
        list = newUser;
    }
    file1.close();

    return list;
}

Staff *createStaff(string staffID, string firstName, string lastName, string gender, string birthDate, string socialID)
{
    Staff *newStaff = new Staff;
    newStaff->staffID = staffID;
    newStaff->firstName = firstName;
    newStaff->lastName = lastName;
    newStaff->gender = gender;
    newStaff->birthDate = birthDate;
    newStaff->socialID = socialID;
    newStaff->next = nullptr;
    return newStaff;
}

void deleteStaffProfile(Staff *&list)
{
    if (!list)
        return;
    Staff *cur = list;
    while (list->next)
    {
        list = list->next;
        delete cur;
        cur = list;
    }
    delete list;
    delete cur;
}


void printProfile(user *account)
{
    if (!account || (!(account->profile) && !(account -> ref)))
    {
        cout << "There's nothing to see!";
        return;
    }
    cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "| " << setw(12) << left << "Your ID"
         << "| " << setw(10) << left << "Last Name"
         << "| " << setw(17) << left << "First Name"
         << "| " << setw(25) << left << "Full Name"
         << "| " << setw(10) << left << "Gender"
         << "| " << setw(15) << left << "Birth Date"
         << "| " << setw(20) << left << "Social ID"
         << " |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl;
    if (account->isStudent)
    {
        Student *ref = account->ref;
        cout << "| " << setw(12) << left << ref->student_id
             << "| " << setw(10) << left << ref->last_name
             << "| " << setw(17) << left << ref->first_name
             << "| " << setw(25) << left << ref->fullName()
             << "| " << setw(10) << left << ref->gender
             << "| " << setw(15) << left << ref->birth_date
             << "| " << setw(20) << left << ref->social_id
             << " |" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl;
        return;
    }
    Staff *ref = account->profile;
    cout << "| " << setw(12) << left << ref->staffID
         << "| " << setw(10) << left << ref->lastName
         << "| " << setw(17) << left << ref->firstName
         << "| " << setw(25) << left << ref->fullName()
         << "| " << setw(10) << left << ref->gender
         << "| " << setw(15) << left << ref->birthDate
         << "| " << setw(20) << left << ref->socialID
         << " |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl;
}
