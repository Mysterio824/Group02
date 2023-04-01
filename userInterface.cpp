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

void findStudent (Student *listStudent, user* account){
    if(!listStudent || !account) return;
    while (listStudent){
        if(listStudent -> student_id == account -> username){
            account -> ref = listStudent;
            return;
        }
        listStudent = listStudent -> next;
    }
}

void studentInterface (user *account, Student* listStudent, Course::Class* listClass, Course *listCourse){
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
                return studentInterface(account, listStudent, listClass, listCourse);
            case 2:

            case 3:
                system("cls");
                printCourse(account -> ref, listClass);
                cout << endl << "Press 1 to back to menu: ";
                cin >> command;
                while( command != 1){
                    cout << "please press again:";
                    cin >> command;
                }
                return staffInterface(account, listStudent, listClass, listCourse);
            case 4:
        }
}

void staffInterface (user* account, Student* listStudent, Course::Class* listClass, Course *listCourse){
    int command = 0;
    cout << "          Welcome to HCMUS! " <<endl;
        cout << "Here are some of commands you can use: "<< endl;
        cout << "1. Change your password." << endl;
        cout << "2. View this semester classes." << endl;
        cout << "3. View the list of the students."<< endl;
        cout << "4. Log out." << endl;
        cout << "Enter your option: ";
        cin >> command;
        switch (command){
            case 1:
                changePass(account);
                system("cls");
                return staffInterface(account, listStudent, listClass, listCourse);
            
        }
}

void interFace (user *account, Student* listStudent, Course::Class* listClass, Course *listCourse){
    if(!account) return;

    if(account -> isStudent){
        findStudent(listStudent, account);
        studentInterface(account, listStudent, listClass, listCourse);
    }
    else
        staffInterface(account, listStudent, listClass, listCourse);
    
}