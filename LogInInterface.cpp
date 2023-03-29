#include "logInInterface.h"

user* logIn (){ 
    user* account = new user;
    int check;
    bool isStudent = false;

    cout << "               Welcome!" << endl;
    cout << "Choose whether you are student or staff: 1. Student   2. Staff" << endl;
    cout << "Your choice: ";
    cin >> check;
    while (check > 2 || check < 1){
        cout << "Please choose whether you are student or staff: 1. Student   2. Staff" << endl;
        cout << "Your choice: ";
        cin >> check;
    }
    if(check = 1) isStudent = true;

    user *listAcc; //list of data user's accounts
    inputAccounts(listAcc, isStudent);
    
    checkUser (listAcc, account); 
    account -> isStudent = isStudent; 
    deleteUserList (listAcc);
    return account;
}

void inputAccounts (user *&list, bool isStudent){ //upload the data of users
    list = nullptr;
    string fileName;
    if(isStudent)   
        fileName = "listOfStdAcc";
    else 
        fileName = "listOfStfAcc";
    ifstream file1(fileName + ".csv");
    if (!file1.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }
    string line;
    while (getline(file1, line)){
        stringstream ss(line);
        string username, password;
        getline(ss, username, ',');
        getline(ss, password, ',');
        user* newUser = createUser(username, password);
        addToList(list, newUser);
    }
    file1.close();
    user *cur = list;
}


user* createUser(string username, string password){ 
    user* newUser = new user;
    newUser -> username = username;
    newUser -> password = password;
    newUser -> next = nullptr;
    return newUser;
}

void addToList(user *&head, user *newUser){
    if (head == nullptr) {
        head = newUser;
    } else {
        user *currentNode = head;
        while (currentNode -> next != nullptr) {
            currentNode = currentNode->next;
        }
        currentNode -> next = newUser;
    }
}

void checkUser (user *list, user *&account){ //check if username and password are correct
    if (!list) return;
    string inputUsername, inputPassword;
    cout << "Please enter your username: ";
    cin >> inputUsername;
    cout << "Please enter your password: ";
    cin >> inputPassword;
    user *cur = list;
    while (cur -> next){ 
        if (inputUsername == cur -> username  && inputPassword == cur -> password){
            system ("cls");
            account -> username = cur -> username;
            account -> password = cur -> password;
            return;
        }
        if (inputUsername == cur -> username){
            cout << "Wrong username or password!" << endl;
            return checkUser (list, account);
        }
        cur = cur -> next;
    }
    cout << "Wrong username or password!" << endl;
    return checkUser (list, account);
}

void deleteUserList(user *&list){
    if (!list) return;
    user* cur = list;
    while (list -> next){
        list = list ->next;
        delete cur;
        cur = list;
    }
    delete list;
    delete cur;
}


