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

string Student::fullName()
{
    string fullName = last_name + " " + first_name;
    return fullName;
}

int Class::capacity()
{
    int count = 0;
    Student *cur = Hstudent;
    while (cur)
    {
        cur = cur->next;
        count += 1;
    }
    return count;
}

int Semester::numOfCourses()
{
    int cnt = 0;
    Course *cur = Hcourse;
    while (cur)
    {
        cur = cur->next;
        cnt += 1;
    }
    return cnt;
}

void printBorder(int num, int size)
{
    for (int i = 0; i < size + num * 2 + 1; i++)
        cout << "-";
    cout << endl;
}

//----------------Student------------------
float Scoreboard::overallGPA()
{
    float GPA = (midterm * 0.3 + finalterm * 0.5 + other * 0.2) / 2.5;
    return GPA;
}

void printStdCourse(Student *account, Course *listOfCourse)
{
    if (!account || !listOfCourse)
    {
        cout << "There is nothing to see." << endl;
        return;
    }
    printBorder(5, 12 + 28 + 12 + 25 + 7 + 17 + 11);
    cout << "| " << setw(12) << left << "Course ID"
         << "| " << setw(28) << left << "Course Name"
         << "| " << setw(13) << left << "Class Name"
         << "| " << setw(25) << left << "Teacher"
         << "| " << setw(7) << left << "Credits"
         << "| " << setw(17) << left << "Day of Week"
         << "| " << setw(11) << left << "Session"
         << " |" << endl;
    printBorder(5, 12 + 28 + 12 + 25 + 7 + 17 + 11);
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
            printBorder(5, 12 + 28 + 12 + 25 + 7 + 17 + 11);
        }
        listOfCourse = listOfCourse->next;
    }
}

void printStdScoreBoard(Student *account, Course *listOfCourse)
{
    if (!account || !listOfCourse)
        return;
    printBorder(9, 11 + 28 + 12 + 12 + 25 + 7 + 10 + 10 + 10 + 8);
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
    printBorder(9, 11 + 28 + 12 + 12 + 25 + 7 + 10 + 10 + 10 + 8);
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
            printBorder(9, 11 + 28 + 12 + 12 + 25 + 7 + 10 + 10 + 10 + 8);
            count++;
            sum += cur->overallGPA();
        }
        listOfCourse = listOfCourse->next;
    }
    cout << "--------------------" << endl;
    cout << "| " << setw(11) << left << "Overall GPA"
         << " |" << sum / count << " |" << endl;
    cout << "--------------------" << endl;
}

//---------------Staff--------------------
void printStfScoreBoard(Course *HCourse)
{
    if (!HCourse)
    {
        cout << "There is no score board to see." << endl;
        return;
    }
    Scoreboard *cur = HCourse->Hscore;
    printBorder(7, 13 + 30 + 12 + 7 + 10 * 3 + 8);
    cout << "| " << setw(13) << left << "Course ID"
         << "| " << setw(30) << left << "Course Name"
         << "| " << setw(12) << left << "Student ID"
         << "| " << setw(7) << left << "Credits"
         << "| " << setw(10) << left << "Other"
         << "| " << setw(10) << left << "Midterm"
         << "| " << setw(10) << left << "Lasterm"
         << "| " << setw(8) << left << "GPA"
         << " |" << endl;
    printBorder(7, 13 + 30 + 12 + 7 + 10 * 3 + 8);
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
        printBorder(7, 13 + 30 + 12 + 7 + 10 * 3 + 8);
        cur = cur->next;
    }
}

void printStfClass(Class *hClass)
{
    if (!hClass)
        return;

    Student *cur = hClass->Hstudent;
    printBorder(1, 12);
    cout << "| " << setw(12) << left << "Class Name: "
         << " | "
         << hClass->class_name << " |" << endl;
    printBorder(7, 12 + 17 + 10 + 25 + 10 + 15 + 20);
    cout << "| " << setw(12) << left << "Student ID"
         << "| " << setw(17) << left << "First Name"
         << "| " << setw(10) << left << "last Name"
         << "| " << setw(25) << left << "Full Name"
         << "| " << setw(10) << left << "Gender"
         << "| " << setw(15) << left << "Birth Date"
         << "| " << setw(20) << left << "Social ID"
         << " |" << endl;
    printBorder(7, 12 + 17 + 10 + 25 + 10 + 15 + 20);

    while (cur)
    {
        string fullName = cur->first_name + " " + cur->last_name;
        cout << "| " << setw(12) << left << cur->student_id
             << "| " << setw(17) << left << cur->first_name
             << "| " << setw(10) << left << cur->last_name
             << "| " << setw(25) << left << cur->fullName()
             << "| " << setw(10) << left << cur->gender
             << "| " << setw(15) << left << cur->birth_date
             << "| " << setw(20) << left << cur->social_id
             << " |" << endl;
        printBorder(7, 12 + 17 + 10 + 25 + 10 + 15 + 20);
        cur = cur->next;
    }
}

void printAllClass(Class *listOfClass)
{
    if (!listOfClass)
    {
        cout << "There is no class to see." << endl;
        return;
    }
    printBorder(5, 12 + 30 + 15 + 10 + 20 + 20);
    cout << "| " << setw(12) << left << "Student ID"
         << "| " << setw(30) << left << "Student Name"
         << "| " << setw(15) << left << "Class Name"
         << "| " << setw(10) << left << "Gender"
         << "| " << setw(20) << left << "Birth Date"
         << "| " << setw(20) << left << "Social ID"
         << " |" << endl;
    printBorder(5, 12 + 30 + 15 + 10 + 20 + 20);
    while (listOfClass)
    {
        Student *cur = listOfClass->Hstudent;
        while (cur)
        {
            cout << "| " << setw(12) << left << cur->student_id
                 << "| " << setw(30) << left << cur->fullName()
                 << "| " << setw(15) << left << listOfClass->class_name
                 << "| " << setw(10) << left << cur->gender
                 << "| " << setw(20) << left << cur->birth_date
                 << "| " << setw(20) << left << cur->social_id
                 << " |" << endl;
            printBorder(5, 12 + 30 + 15 + 10 + 20 + 20);

            cur = cur->next;
        }
        listOfClass = listOfClass->next;
    }
}

Class *printListClass(Class *listClass)
{
    if (!listClass)
    {
        cout << "There's no class to see";
        return nullptr;
    }
    Class *mark = listClass;
    int cnt = 0;
    printBorder(3, 15 + 30 + 10);
    cout << "| " << setw(15) << left << "Index"
         << "| " << setw(30) << left << "Class Name"
         << "| " << setw(10) << left << "Capacity"
         << " |" << endl;
    printBorder(3, 15 + 30 + 10);
    while (listClass)
    {
        cout << "| " << setw(15) << left << ++cnt
             << "| " << setw(30) << left << listClass->class_name
             << "| " << setw(10) << left << listClass->capacity()
             << " |" << endl;
        printBorder(3, 15 + 30 + 10);
        listClass = listClass->next;
    }

    int choice;
    do
    {
        cout << "Please enter the index of the class you want to see(press " << cnt + 1 << " to stop):";
        cin >> choice;
    } while (choice > cnt + 1 || choice < 1);
    if (choice == cnt + 1)
    {
        return nullptr;
    }
    for (cnt = 1; cnt < choice; cnt++)
        mark = mark->next;
    return mark;
}

void printClassScoreBoard(Class *thisClass, Semester *thisSem)
{
    if (!thisClass || !(thisSem))
        return;
    Student *curS = thisClass->Hstudent;
    int size = thisSem->numOfCourses();
    Course *curC = thisSem->Hcourse;
    printBorder(1, 12);
    cout << "| " << setw(12) << left << "Class Name: "
         << " | "
         << thisClass->class_name << " |" << endl;
    printBorder(3 + size, size * 28 + 12 + 25 + 10);
    cout << "| " << setw(12) << left << "Student ID"
         << "| " << setw(25) << left << "Student Name";
    while (curC)
    {
        cout << "| " << setw(28) << left << curC->course_name;
        curC = curC->next;
    }
    cout << "| " << setw(10) << left << "Overall GPA"
         << " |" << endl;
    printBorder(3 + size, size * 28 + 12 + 25 + 10);
    int cnt, sum;
    Scoreboard *ref;
    while (curS)
    {
        curC = thisSem->Hcourse;
        sum = cnt = 0;
        cout << "| " << setw(12) << left << curS->student_id
             << "| " << setw(25) << left << curS->fullName();
        while (curC)
        {
            ref = checkInCourse(curS, curC);
            if (ref)
            {
                cout << "| " << setw(28) << internal << ref->overallGPA();
                sum += ref->overallGPA();
                cnt += 1;
            }
            else
                cout << "| " << setw(28) << internal << 'x';
            cout << "| " << setw(10) << left << sum / cnt
                 << " |" << endl;
            printBorder(3 + size, size * 28 + 12 + 25 + 10);
            curC = curC->next;
        }
        curS = curS->next;
    }
}
