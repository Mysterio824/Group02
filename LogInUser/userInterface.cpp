#include "userInterface.h"

void changeInList (user *list, user *account){
    if(!list) return;
    while (list -> next){
        if( account -> username == list -> username){
        list -> password = account -> password;
        return;
        }
        list = list -> next;
    }
}

void updateList (user *list){
    ofstream outputFile;
    outputFile.open("listOfAccounts.csv");
    if (!outputFile.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }
        while (list){
            outputFile << list -> username << ",";
            outputFile << list -> password << ",";
            outputFile << list -> role << endl;
            list = list -> next;
        }
    outputFile.close();
}

void changePass (user *&account){
    if (!account) return;
    user *list;
    inputAccounts (list);
    string newPass;
    cout << "Please enter your new password: ";
    cin >> newPass;
    account -> password = newPass;
    changeInList(list, account);
    updateList(list);
    cout << "Your password has been changed successfully!" << endl;
    cout << "-Please re-log-in your account- "<< endl;
    checkUser(list, account);
    deleteUserList(list);
}

void interFace (user *account){
    if(!account) return;
    int command;
    if(account -> role == "student"){
        cout << "  Welcome to HCMUS school! " <<endl;
        cout << "Here are some of commands you can use: "<< endl;
        cout << "1. Change your password." << endl;
        cout << "2. View your score." << endl;
        cout << "3. View your courses schedule."<< endl;
        cout << "Enter the command you want to do: ";
        cin >> command;
        switch (command){
            case 1:
                changePass(account);
                system ("cls");
                return interFace(account);
        }
    }
    if(account -> role == "staff"){
        cout << "  Welcome to HCMUS school! " <<endl;
        cout << "Here are some of commands you can use: "<< endl;
        cout << "1. Change your password." << endl;
        cout << "2. View this semester classes." << endl;
        cout << "3. View the list of the students."<< endl;
        cout << "Enter the command you want to do: ";
        cin >> command;
    }
}