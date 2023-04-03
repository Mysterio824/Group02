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

float Scoreboard::overallGPA()
{
    float GPA = (midterm * 0.3 + final * 0.5 + other * 0.2) / 2.5;
    return GPA;
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

void printStdCourse(Student *account, Course *listOfCourse)
{
    if (!account && !listOfCourse)
        return;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "| " << setw(12) << left << "Course ID"
         << "| " << setw(35) << left << "Course Name"
         << "| " << setw(20) << left << "Class Name"
         << "| " << setw(25) << left << "Teacher"
         << "| " << setw(5) << left << "Credits"
         << "| " << setw(10) << left << "Max Students"
         << "| " << setw(15) << left << "Day of Week"
         << "| " << setw(11) << left << "Session"
         << " |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    while (listOfCourse)
    {
        if (checkInCourse(account, listOfCourse))
        {
            cout << "| " << setw(12) << left << listOfCourse->course_id
                 << "| " << setw(35) << left << listOfCourse->course_name
                 << "| " << setw(20) << left << account->className
                 << "| " << setw(25) << left << listOfCourse->teacher_name
                 << "| " << setw(7) << left << listOfCourse->num_credits
                 << "| " << setw(12) << left << listOfCourse->capacity
                 << "| " << setw(15) << left << listOfCourse->day
                 << "| " << setw(11) << left << listOfCourse->session << " |" << endl;
            cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        }
        listOfCourse = listOfCourse->next;
    }
}

void printStdScoreBoard(Student *account, Course *listOfCourse)
{
    if (!account && !listOfCourse)
        return;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "| " << setw(12) << left << "Course ID"
         << "| " << setw(35) << left << "Course Name"
         << "| " << setw(20) << left << "Class Name"
         << "| " << setw(25) << left << "Student Name"
         << "| " << setw(5) << left << "Credits"
         << "| " << setw(10) << left << "Other"
         << "| " << setw(10) << left << "Midterm"
         << "| " << setw(15) << left << "Lasterm"
         << "| " << setw(11) << left << "GPA"
         << " |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    float sum = 0;
    int count = 0;
    while (listOfCourse)
    {
        Scoreboard *cur = checkInCourse(account, listOfCourse);
        if (cur)
        {
            cout << "| " << setw(12) << left << listOfCourse->course_id
                 << "| " << setw(35) << left << listOfCourse->course_name
                 << "| " << setw(20) << left << account->className
                 << "| " << setw(25) << left << account->last_name
                 << "| " << setw(7) << left << listOfCourse->num_credits
                 << "| " << setw(15) << left << cur->other
                 << "| " << setw(15) << left << cur->midterm
                 << "| " << setw(15) << left << cur->final
                 << "| " << setw(11) << left << cur->overallGPA() << " |" << endl;
            cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            count++;
            sum += cur->overallGPA();
        }
        listOfCourse = listOfCourse->next;
    }
    cout << "--------------" << endl;
    cout << "| " << setw(12) << left << "OverallGPA"
         << " |" << endl;
    cout << "--------------" << endl;
    cout << sum / count << endl;
    cout << "--------------" << endl;
}

void printStfScoreBoard(Course *HCourse)
{
    if (!HCourse)
        return;
    Scoreboard *cur = HCourse->Hscore;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "| " << setw(12) << left << "Course ID"
         << "| " << setw(35) << left << "Course Name"
         << "| " << setw(25) << left << "Student ID"
         << "| " << setw(5) << left << "Credits"
         << "| " << setw(10) << left << "Other"
         << "| " << setw(10) << left << "Midterm"
         << "| " << setw(15) << left << "Lasterm"
         << "| " << setw(11) << left << "GPA"
         << " |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    while (cur)
    {
        cout << "| " << setw(12) << left << HCourse->course_id
             << "| " << setw(35) << left << HCourse->course_name
             << "| " << setw(25) << left << cur->student_id
             << "| " << setw(7) << left << HCourse->num_credits
             << "| " << setw(15) << left << cur->other
             << "| " << setw(15) << left << cur->midterm
             << "| " << setw(15) << left << cur->final
             << "| " << setw(11) << left << cur->overallGPA() << " |" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }
}

void printStfClass(Class *hClass)
{
    if (!hClass)
        return;
    Student *cur = hClass->Hstudent;
    cout << "----------------------" << endl;
    cout << "| " << setw(12) << left << "Class Name: " << " | " 
         << hClass -> class_name << " |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "| " << setw(12) << left << "Student ID"
         << "| " << setw(40) << left << "Student Name"
         << "| " << setw(25) << left << "Gender"
         << "| " << setw(15) << left << "Birth Date"
         << "| " << setw(20) << left << "Social ID"
         << " |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    while (cur)
    {
        cout << "| " << setw(12) << left << cur->student_id
             << "| " << setw(40) << left << cur->first_name + " " + cur->last_name
             << "| " << setw(25) << left << cur->gender
             << "| " << setw(15) << left << cur->birth_date
             << "| " << setw(20) << left << cur->social_id
             << " |" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

        cur = cur->next;
    }
}

void printAllClass(Class *listOfClass)
{
    if (!listOfClass)
        return;

    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "| " << setw(12) << left << "Student ID"
         << "| " << setw(40) << left << "Student Name"
         << "| " << setw(25) << left << "Class Name" 
         << "| " << setw(25) << left << "Gender"
         << "| " << setw(15) << left << "Birth Date"
         << "| " << setw(20) << left << "Social ID"
         << " |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    while (listOfClass)
    {
        Student *cur = listOfClass->Hstudent;
        while (cur)
        {
            cout << "| " << setw(12) << left << cur->student_id
                 << "| " << setw(40) << left << cur->first_name + " " + cur->last_name
                 << "| " << setw(25) << left << listOfClass -> class_name
                 << "| " << setw(25) << left << cur->gender
                 << "| " << setw(15) << left << cur->birth_date
                 << "| " << setw(20) << left << cur->social_id
                 << " |" << endl;
            cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

            cur = cur->next;
        }
        listOfClass = listOfClass->next;
    }
}