#include "userInterface.h"
#include "header.h"

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

void updateList (user *list, bool isStudent){
    string fileName;
    if(isStudent)   
        fileName = "listOfStdAcc";
    else 
        fileName = "listOfStfAcc";
    ofstream outputFile(fileName + ".csv");
    if (!outputFile.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }
        while (list){
            outputFile << list -> username << ",";
            outputFile << list -> password << endl;
            list = list -> next;
        }
    cout << "Your password has been changed successfully!" << endl;
    cout << "-Please re-log-in your account- "<< endl;
    outputFile.close();
}

void changePass (user *&account){
    if (!account) return;
    user *list;
    inputAccounts (list, account -> isStudent);
    string newPass;
    cout << "Please enter your new password: ";
    cin >> newPass;
    account -> password = newPass;
    changeInList(list, account);
    updateList(list, account -> isStudent);
    
    //Log in again..
    checkUser(list, account); 
    deleteUserList(list);
}

Class* chooseClass (Class *listClass){
    if(!listClass) return;
    int count = 0;
    Class *mark = listClass;
    cout << "which class would you like to see: " << endl;
    while(listClass){
        cout << ++count <<". " << listClass -> class_name << endl;
        listClass = listClass -> next;
    }
    int command;
    cout << "Your choice: ";
    cin >> command;
    while (command > count){
        cout << "Please enter a again: ";
        cin >> command;
    }
    for (count = 0; count < command; count ++)
        mark = mark -> next;
    return mark;
}

void findStudent (user *&account, Class *listClass){
    if(!listClass || !account) return;
    while (listClass){
        Student *cur = listClass -> Hstudent;
        while (cur || cur -> student_id != account -> username)
            cur = cur -> next;
        if(cur -> student_id == account -> username){
            account -> ref = cur;
            return;
        }
        listClass = listClass -> next;
    }
}

void studentInterface (user *account, Class* listClass, Course *listCourse){
    int command;
    cout << "         Welcome to HCMUS! " <<endl;
        cout << "Here are some of commands you can use: "<< endl;
        cout << "1. Change your password." << endl;
        cout << "2. View your score." << endl;
        cout << "3. View your courses schedule."<< endl;
        cout << "4. Log out." << endl;
        cout << "Enter your option: ";
        cin >> command;
        switch (command){
            case 1:
                changePass(account);
                system ("cls");
                return studentInterface(account, listClass, listCourse);
            case 2:

            case 3:
                system("cls");
                printStdCourse(account -> ref, listCourse);
                cout << endl << "Press 1 to back to menu: ";
                cin >> command;
                while( command != 1){
                    cout << "please press again:";
                    cin >> command;
                }
                return studentInterface(account, listClass, listCourse);
            case 4:
        }
}

void staffInterface (user* account, Class* listClass, Course *listCourse){
    int command = 0;
    cout << "          Welcome to HCMUS! " <<endl;
        cout << "Here are some of commands you can use: "<< endl;
        cout << "1. Change your password." << endl;
        cout << "2. View this semester classes" << endl;
        cout << "3. View the list of classes"<< endl;
        cout << "4. Log out." << endl;
        cout << "Enter your option: ";
        cin >> command;
        switch (command){
            case 1:
                system("cls");
                changePass(account);
                system("cls");
                return staffInterface(account, listClass, listCourse);
            case 2:
                system("cls");
                printAllClass(listClass);
                system("cls");
                return staffInterface(account, listClass, listCourse);
            case 3:
                system("cls");
                printStfClass(chooseClass(listClass));
                system("cls");
                return staffInterface(account, listClass, listCourse);
        }
}

void interFace (user *account, Class* listClass, Course *listCourse){
    if(!account) return;

    if(account -> isStudent){
        findStudent(account, listClass);
        studentInterface(account, listClass, listCourse);
    }
    else
        staffInterface(account, listClass, listCourse);
    
}