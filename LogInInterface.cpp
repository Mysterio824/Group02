#include "logInInterface.h"

user *logIn()
{
    user *account = new user;
    int check;
    bool isStudent = false;

    cout << setw(3) << right << ""
         << "----------------------------------" << endl;
    cout << setw(5) << right << "| " << setw(18) << right << "Welcome" << setw(12) << left << " "
         << " |" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "| " << setw(25) << left << "Choose whether you are student or staff"
         << " |" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "| " << setw(20) << left << "1. Student" << setw(15) << internal
         << setw(19) << right << "2. Staff "
         << " |" << endl;
    cout << "-------------------------------------------" << endl;
    cout << endl;
    cout << "Enter your choice: ";
    cin >> check;
    while (check != 1 && check != 2)
    {
        cout << endl
             << "Please re-choose whether you are student or staff: ";
        cin >> check;
    }
    if (check == 1)
        isStudent = true;

    user *listAcc; // list of data user's accounts
    importAccounts(listAcc, isStudent);

    system("cls");
    checkUser(listAcc, account);
    account->isStudent = isStudent;
    deleteUserList(listAcc);
    return account;
}

void importAccounts(user *&list, bool isStudent)
{ // upload the data of users
    list = nullptr;
    string fileName;
    if (isStudent)
        fileName = "listOfStdAcc";
    else
        fileName = "listOfStfAcc";
    ifstream file1(fileName + ".csv");
    if (!file1.is_open())
    {
        cout << "Error opening file" << endl;
        return;
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
        newUser -> next = list;
        list = newUser;
    }
    file1.close();
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
        newUser -> next = list;
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

void checkUser(user *list, user *&account)
{ // check if username and password are correct
    if (!list)
        return; 
    string inputUsername, inputPassword;
    cout << "Please enter your username: ";
    cin >> inputUsername;
    cout << endl;
    cout << "Please enter your password: ";
    cin >> inputPassword;
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
    cout << endl
         << "Wrong username or password!" << endl << endl;
    return checkUser(list, account);
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

staffData *importStaff(string fileName)
{
    staffData *list = nullptr;
    ifstream file1(fileName + ".csv");
    if (!file1.is_open())
    {
        cout << "Error opening file" << endl;
        return nullptr;
    }
    staffData *newUser;
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
        addToList(list, newUser);
    }
    file1.close();
    return list;
}

staffData *createStaff(string staffID, string firstName, string lastName, string gender, string birthDate, string socialID)
{
    staffData *newStaff = new staffData;
    newStaff->staffID = staffID;
    newStaff->firstName = firstName;
    newStaff->lastName = lastName;
    newStaff->gender = gender;
    newStaff->birthDate = birthDate;
    newStaff->socialID = socialID;
    newStaff->next = nullptr;
    return newStaff;
}

void addToList(staffData *&head, staffData *newUser)
{
    if (head == nullptr)
    {
        head = newUser;
    }
    else
    {
        staffData *currentNode = head;
        while (currentNode->next != nullptr)
        {
            currentNode = currentNode->next;
        }
        currentNode->next = newUser;
    }
}

string staffData::fullName(){
    string fullName = lastName + " " + firstName;
    return fullName;
}

void deleteStaffProfile(staffData *&list)
{
    if (!list)
        return;
    staffData *cur = list;
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
    if (!account || !(account -> profile)){
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
    staffData *ref = account->profile;
    cout << "| " << setw(12) << left << ref->staffID
         << "| " << setw(10) << left << ref->firstName
         << "| " << setw(17) << left << ref->lastName
         << "| " << setw(25) << left << ref->fullName()
         << "| " << setw(10) << left << ref->gender
         << "| " << setw(15) << left << ref->birthDate
         << "| " << setw(20) << left << ref->socialID
         << " |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl;
}