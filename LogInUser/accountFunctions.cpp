#include "accountData.h"

void inputAccounts (user *&list){ //upload the data of users
    list = nullptr;
    ifstream file1("listOfAccounts.csv");
    if (!file1.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }
    string line;
    while (getline(file1, line)){
        stringstream ss(line);
        string username, password, role;
        getline(ss, username, ',');
        getline(ss, password, ',');
        getline(ss, role, ',');
        user* newUser = createUser(username, password, role);
        addToList(list, newUser);
    }
    file1.close();
}


user* createUser(string username, string password, string role){ 
    user* newUser = new user;
    newUser->username = username;
    newUser->password = password;
    newUser->role = role;
    newUser->next = nullptr;
    return newUser;
}

void addToList(user *&head, user *newUser){
    if (head == nullptr) {
        head = newUser;
    } else {
        user *currentNode = head;
        while (currentNode->next != nullptr) {
            currentNode = currentNode->next;
        }
        currentNode->next = newUser;
    }
}

void checkUser (user *list, user *&account){ //check if username and password are correct
    if (!list) return;
    string inputUsername, inputPassword;
    cout << "Please enter your username: ";
    cin >> inputUsername;
    cout << "Please enter your password: ";
    cin >> inputPassword;

    while (list -> next){ 
        if (inputUsername == list -> username  && inputPassword == list -> password){
            cout << "Login successful!" << endl;
            account = new user;
            account = list;
            account -> next = nullptr;
            return;
        }
        if (inputUsername == list -> username){
            cout << "Wrong username or password!" << endl;
            return checkUser (list, account);
        }
        list = list -> next;
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

user* logIn (user *&account){ 
    user *list; //list of data user's accounts
    inputAccounts(list);
    checkUser (list, account);
    deleteUserList (list);
    return account;
}

