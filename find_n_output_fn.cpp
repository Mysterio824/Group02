#include "header.h"

string getCurrentYear (){
    string year;
    int tmp;
    time_t t = time(nullptr);
    tm *const pTInfo = localtime(&t);
    tmp=1900 + pTInfo->tm_year;
    year = to_string(tmp);
    return year;
}

Course :: Class* findClass (Student* account, Course::Class *listOfClass){
    if(!listOfClass || !account) return nullptr;
    while (listOfClass){
        if(listOfClass -> class_name == account -> className)
            return listOfClass;
        listOfClass = listOfClass -> next;
    }
    return nullptr;
}

int findStudentNo (Student *account, Course::Class* myClass){
    if(!myClass || !account) return 0;
    int count = 0;
    StudentPtr* curStudent = myClass -> Hstudent;
    while (curStudent && curStudent -> ref != account){
        curStudent = curStudent -> next;
        count ++;
    }
    return count;
}

void printCourse(Student *account, Course::Class *listOfClass){
     cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "| " << setw(12) << left << "Course ID"
        << "| " << setw(35) << left << "Course Name"
        << "| " << setw(20) << left << "Class Name"
        << "| " << setw(25) << left << "Teacher"
        << "| " << setw(5) << left << "Credits"
        << "| " << setw(10) << left << "Max Students"
        << "| " << setw(15) << left << "Day of Week"
        << "| " << setw(11) << left << "Session" << " |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    Course::Class* curClass = findClass(account, listOfClass);
    Course::Class::CoursePtr* curCourse = curClass -> courses;
    while (curCourse){
        cout << "| " << setw(12) << left << curCourse -> ref -> course_id
            << "| " << setw(35) << left << curCourse -> ref -> course_name
            << "| " << setw(20) << left << curClass -> class_name
            << "| " << setw(25) << left << curCourse -> ref -> teacher_name
            << "| " << setw(7) << left << curCourse -> ref -> num_credits
            << "| " << setw(12) << left << curCourse -> ref -> capacity
            << "| " << setw(15) << left << curCourse -> ref -> day
            << "| " << setw(11) << left << curCourse -> ref -> session << " |" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        curCourse = curCourse -> next;
    }
}

void printScoreBoard (Student *account, Course::Class *listOfClass){
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "| " << setw(12) << left << "Course ID"
        << "| " << setw(35) << left << "Course Name"
        << "| " << setw(20) << left << "Class Name"
        << "| " << setw(25) << left << "Student Name"
        << "| " << setw(5) << left << "Credits"
        << "| " << setw(10) << left << "Midterm"
        << "| " << setw(15) << left << "Lasterm"
        << "| " << setw(11) << left << "Overal" << " |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    Course::Class* curClass = findClass(account, listOfClass);
    int No = findStudentNo(account, curClass);
    int n = sizeof(curClass -> courses -> scores[No]);
    while (curClass -> courses){
        for (int i = 0; i < n; i++)
            cout << curClass -> courses ->scores[No][i];
//      cout << "| " << setw(12) << left << curCourse -> ref -> course_id
//             << "| " << setw(35) << left << curCourse -> ref -> course_name
//             << "| " << setw(20) << left << curClass -> class_name
//             << "| " << setw(25) << left << curCourse -> ref -> teacher_name
//             << "| " << setw(7) << left << curCourse -> ref -> num_credits
//             << "| " << setw(12) << left << curCourse -> ref -> capacity
//             << "| " << setw(15) << left << curCourse -> ref -> day
//             << "| " << setw(11) << left << curCourse -> ref -> session << " |" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }
}