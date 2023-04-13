#include "header.h"

string getCurrentYear()
{
    string year;
    int tmp;
    time_t t = time(nullptr);
    tm *const pTInfo = localtime(&t);
    tmp = 1900 + pTInfo->tm_year;
    year = to_string(tmp);
    return year;
}

Scoreboard *checkInCourse(Student *account, Course *HCourse)
{
    if (!account && !HCourse)
        return nullptr;
    Scoreboard *cur = HCourse->Hscore;
    while (cur && cur->student_id != account->student_id)
        cur = cur->next;
    if (cur->student_id == account->student_id)
        return cur;
    return nullptr;
}

string Student::fullName(){
    string fullName = last_name + " " + first_name;
    return fullName;
}

//----------------Student------------------
float Scoreboard::overallGPA()
{
    float GPA = (midterm * 0.3 + finalterm * 0.5 + other * 0.2) / 2.5;
    return GPA;
}

void printStdCourse(Student *account, Course *listOfCourse)
{
    if (!account || !listOfCourse){
        cout << "There is nothing to see." << endl;
        return;
    }
    cout << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "| " << setw(12) << left << "Course ID"
         << "| " << setw(28) << left << "Course Name"
         << "| " << setw(13) << left << "Class Name"
         << "| " << setw(25) << left << "Teacher"
         << "| " << setw(7) << left << "Credits"
         << "| " << setw(17) << left << "Day of Week"
         << "| " << setw(11) << left << "Session"
         << " |" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
    while (listOfCourse)
    {
        if (checkInCourse(account, listOfCourse))
        {
            cout << "| " << setw(12) << left << listOfCourse->course_id
                 << "| " << setw(28) << left << listOfCourse->course_name
                 << "| " << setw(13) << left << account->className
                 << "| " << setw(25) << left << listOfCourse->teacher_name
                 << "| " << setw(7) << left << listOfCourse->num_credits
                 << "| " << setw(17) << left << listOfCourse->day
                 << "| " << setw(11) << left << listOfCourse->session << " |" << endl;
            cout << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
        }
        listOfCourse = listOfCourse->next;
    }
}

void printStdScoreBoard(Student *account, Course *listOfCourse)
{
    if (!account || !listOfCourse)
        return;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "| " << setw(11) << left << "Course ID"
         << "| " << setw(28) << left << "Course Name"
         << "| " << setw(12) << left << "Class Name"
         << "| " << setw(12) << left << "Student ID"
         << "| " << setw(25) << left << "Student Name"
         << "| " << setw(7) << left << "Credits"
         << "| " << setw(10) << left << "Other"
         << "| " << setw(10) << left << "Midterm"
         << "| " << setw(10) << left << "Lasterm"
         << "| " << setw(8) << left << "GPA"
         << " |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    float sum = 0;
    int count = 0;
    while (listOfCourse)
    {
        Scoreboard *cur = checkInCourse(account, listOfCourse);
        if (cur)
        {
            cout << "| " << setw(11) << left << listOfCourse->course_id
                 << "| " << setw(28) << left << listOfCourse->course_name
                 << "| " << setw(12) << left << account->className
                 << "| " << setw(12) << left << account->student_id
                 << "| " << setw(25) << left << account->fullName()
                 << "| " << setw(7) << left << listOfCourse->num_credits
                 << "| " << setw(10) << left << cur->other
                 << "| " << setw(10) << left << cur->midterm
                 << "| " << setw(10) << left << cur->finalterm
                 << "| " << setw(8) << left << cur->overallGPA() << " |" << endl;
            cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            count++;
            sum += cur->overallGPA();
        }
        listOfCourse = listOfCourse->next;
    }
    cout << "--------------------" << endl;
    cout << "| " << setw(11) << left << "Overall GPA"
         << " |" << sum/count << " |" << endl;
    cout << "--------------------" << endl;
}


//---------------Staff--------------------
void printStfScoreBoard(Course *HCourse)
{
    if (!HCourse){
        cout << "There is no score board to see." << endl;
        return;
    }
    Scoreboard *cur = HCourse->Hscore;
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "| " << setw(13) << left << "Course ID"
         << "| " << setw(30) << left << "Course Name"
         << "| " << setw(12) << left << "Student ID"
         << "| " << setw(7) << left << "Credits"
         << "| " << setw(10) << left << "Other"
         << "| " << setw(10) << left << "Midterm"
         << "| " << setw(10) << left << "Lasterm"
         << "| " << setw(8) << left << "GPA"
         << " |" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    while (cur)
    {
        cout << "| " << setw(13) << left << HCourse->course_id
             << "| " << setw(30) << left << HCourse->course_name
             << "| " << setw(12) << left << cur->student_id
             << "| " << setw(7) << left << HCourse->num_credits
             << "| " << setw(10) << left << cur->other
             << "| " << setw(10) << left << cur->midterm
             << "| " << setw(10) << left << cur->finalterm
             << "| " << setw(8) << left << cur->overallGPA() << " |" << endl;
        cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    }
}

void printStfClass(Class *hClass)
{
    if (!hClass) return;

    Student *cur = hClass->Hstudent;
    cout << "-----------------------------" << endl;
    cout << "| " << setw(12) << left << "Class Name: "
         << " | "
         << hClass->class_name << " |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "| " << setw(12) << left << "Student ID"
         << "| " << setw(17) << left << "First Name"
         << "| " << setw(10) << left << "last Name"
         << "| " << setw(25) << left << "Full Name"
         << "| " << setw(10) << left << "Gender"
         << "| " << setw(15) << left << "Birth Date"
         << "| " << setw(20) << left << "Social ID"
         << " |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl;
    
    while (cur)
    {
        string fullName = cur->first_name + " " + cur->last_name;
        cout << "| " << setw(12) << left << cur->student_id
             << "| " << setw(17) << left << cur -> first_name
             << "| " << setw(10) << left << cur -> last_name
             << "| " << setw(25) << left << cur->fullName()
             << "| " << setw(10) << left << cur->gender
             << "| " << setw(15) << left << cur->birth_date
             << "| " << setw(20) << left << cur->social_id
             << " |" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl;

        cur = cur->next;
    }
}

void printAllClass(Class *listOfClass)
{
    if (!listOfClass){
        cout << "There is no class to see." << endl;
        return;
    }
    cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "| " << setw(12) << left << "Student ID"
         << "| " << setw(30) << left << "Student Name"
         << "| " << setw(15) << left << "Class Name" 
         << "| " << setw(10) << left << "Gender"
         << "| " << setw(20) << left << "Birth Date"
         << "| " << setw(20) << left << "Social ID"
         << " |" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
    while (listOfClass)
    {
        Student *cur = listOfClass->Hstudent;
        while (cur)
        {
            cout << "| " << setw(12) << left << cur->student_id
                 << "| " << setw(30) << left << cur -> fullName()
                 << "| " << setw(15) << left << listOfClass -> class_name
                 << "| " << setw(10) << left << cur->gender
                 << "| " << setw(20) << left << cur->birth_date
                 << "| " << setw(20) << left << cur->social_id
                 << " |" << endl;
            cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;

            cur = cur->next;
        }
        listOfClass = listOfClass->next;
    }
}

