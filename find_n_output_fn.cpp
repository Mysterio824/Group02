#include "header.h"

//---------additional funcitons-------------

void printBorder(int num, int size)
{
    for (int i = 0; i < size + num * 2 + 2; i++)
        cout << "-";
    cout << endl;
}

Scoreboard *checkInCourse(Student *account, Course *HCourse)
{
    if (!account && !HCourse)
        return nullptr;
    Scoreboard *cur = HCourse->Hscore;
    while (cur && cur->student_id != account->student_id)
        cur = cur->next;
    if (cur) return cur;
    return nullptr;
}

//----------------Student------------------

void printSchedule(Student *account, Course *listOfCourse)
{
    if (!account || !listOfCourse)
    {
        cout << "You aren't allowed to see yet." << endl;
        return;
    }
    system("cls");
    printBorder(7, 18 + 35 + 12 + 25 + 13 + 17 + 11);
    cout << "| " << setw(18) << left << "Course ID"
         << "| " << setw(35) << left << "Course Name"
         << "| " << setw(13) << left << "Class Name"
         << "| " << setw(25) << left << "Teacher"
         << "| " << setw(10) << left << "Credits"
         << "| " << setw(13) << left << "Day of Week"
         << "| " << setw(18) << left << "Session"
         << " |" << endl;
    printBorder(7, 18 + 35 + 12 + 25 + 13 + 17 + 11);
    while (listOfCourse)
    {

        if (checkInCourse(account, listOfCourse))
        {
            cout << "| " << setw(18) << left << listOfCourse->course_id
                 << "| " << setw(35) << left << listOfCourse->course_name
                 << "| " << setw(13) << left << account->className
                 << "| " << setw(25) << left << listOfCourse->teacher_name
                 << "| " << setw(10) << left << listOfCourse->num_credits
                 << "| " << setw(13) << left << listOfCourse->day
                 << "| " << setw(18) << left << listOfCourse->session << " |" << endl;
            printBorder(7, 18 + 35 + 12 + 25 + 13 + 17 + 11);
        }
        listOfCourse = listOfCourse->next;
    }
}

void printStdScoreBoard(Student *account, Course *listOfCourse)
{
    if (!account || !listOfCourse){
        cout << "You aren't allowed to see yet.";
        return;
    }

    system("cls");
    printBorder(9, 18 + 35 + 10 + 11 + 7 + 8 + 20 + 7);
    cout << "| " << setw(18) << left << "Course ID"
         << "| " << setw(35) << left << "Course Name"
         << "| " << setw(10) << left << "Class"
         << "| " << setw(11) << left << "Student ID"
         << "| " << setw(8) << left << "Credits"
         << "| " << setw(7) << left << "Other"
         << "| " << setw(10) << left << "Midterm"
         << "| " << setw(10) << left << "Lasterm"
         << "| " << setw(7) << left << "GPA"
         << " |" << endl;
    printBorder(9, 18 + 35 + 10 + 11 + 7 + 8 + 20 + 7);
    float sum = 0;
    int count = 0;
    while (listOfCourse)
    {
        Scoreboard *cur = checkInCourse(account, listOfCourse);
        if (cur)
        {
            cout << "| " << setw(18) << left << listOfCourse->course_id
                 << "| " << setw(35) << left << listOfCourse->course_name
                 << "| " << setw(10) << left << account->className
                 << "| " << setw(11) << left << account->student_id
                 << "| " << setw(8) << left << listOfCourse->num_credits
                 << "| " << setw(7) << left << cur->other
                 << "| " << setw(10) << left << cur->midterm
                 << "| " << setw(10) << left << cur->finalterm
                 << "| " << setw(7) << left << cur->overallGPA() << " |" << endl;
            printBorder(9, 18 + 35 + 10 + 11 + 7 + 8 + 20 + 7);
            count++;
            sum += cur->overallGPA();
        }
        listOfCourse = listOfCourse->next;
    }
    printBorder(2, 15+ 8);
    cout << "| " << setw(15) << left << "Overall GPA: "
         << " |" << setw(8) << left << sum / float(count) << " |" << endl;
    printBorder(2, 15 + 8);
}

//---------------Staff--------------------

Course* printListCourse (Course *listOfCourse){
    if (!listOfCourse)
    {
        cout << "There's nothing to see";
        return nullptr;
    }
    system("cls");
    Course* mark = listOfCourse;
    int cnt = 0;
    printBorder(7, 18 + 35 + 12 + 25 + 13 + 17 + 11);
    cout << "| " << setw(18) << left << "Course ID"
         << "| " << setw(35) << left << "Course Name"
         << "| " << setw(13) << left << "Class Name"
         << "| " << setw(25) << left << "Teacher"
         << "| " << setw(10) << left << "Credits"
         << "| " << setw(13) << left << "Day of Week"
         << "| " << setw(18) << left << "Session"
         << " |" << endl;
    printBorder(7, 18 + 35 + 12 + 25 + 13 + 17 + 11);
    while (listOfCourse)
    {
        
            cout << "| " << setw(18) << left << listOfCourse->course_id
                 << "| " << setw(35) << left << listOfCourse->course_name
                 << "| " << setw(13) << left << listOfCourse->class_name
                 << "| " << setw(25) << left << listOfCourse->teacher_name
                 << "| " << setw(10) << left << listOfCourse->num_credits
                 << "| " << setw(13) << left << listOfCourse->day
                 << "| " << setw(18) << left << listOfCourse->session << " |" << endl;
            printBorder(7, 18 + 35 + 12 + 25 + 13 + 17 + 11);
        listOfCourse = listOfCourse->next;
        cnt++;
    }

    int choice;
    do
    {
        cout << endl << "Please enter the index of the Course you want to see (press 0 to stop): ";
        cin >> choice;
    } while (choice > cnt || choice < 0);
    if (choice == 0)
    {
        return nullptr;
    }
    for (cnt = 1; cnt < choice; cnt++)
        mark = mark->next;
    return mark;
}

void printCourseScoreBoard(Course *HCourse)
{
    if (!HCourse)
    {
        return;
    }
    system("cls");
    Scoreboard *cur = HCourse->Hscore;
    printBorder(8, 18 + 35 + 12 + 10 + 10 * 3 + 8);
    cout << "| " << setw(18) << left << "Course ID"
         << "| " << setw(35) << left << "Course Name"
         << "| " << setw(12) << left << "Student ID"
         << "| " << setw(10) << left << "Credits"
         << "| " << setw(10) << left << "Other"
         << "| " << setw(10) << left << "Midterm"
         << "| " << setw(10) << left << "Lasterm"
         << "| " << setw(8) << left << "GPA"
         << " |" << endl;
    printBorder(8, 18 + 35 + 12 + 10 + 10 * 3 + 8);
    while (cur)
    {
        cout << "| " << setw(18) << left << HCourse->course_id
             << "| " << setw(35) << left << HCourse->course_name
             << "| " << setw(12) << left << cur->student_id
             << "| " << setw(10) << left << HCourse->num_credits
             << "| " << setw(10) << left << cur->other
             << "| " << setw(10) << left << cur->midterm
             << "| " << setw(10) << left << cur->finalterm
             << "| " << setw(8) << left << cur->overallGPA()
             << " |" << endl;
        printBorder(8, 18 + 35 + 12 + 10 + 10 * 3 + 8);
        cur = cur->next;
    }
}

void printOneClass(Class *hClass)
{
    if (!hClass)
        return;
    system("cls");
    Student *cur = hClass->Hstudent;
    printBorder(2, 24);
    cout << "| " << setw(12) << left << "Class Name: "
         << "| "
         << setw(12) << hClass->class_name << " |" << endl;
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
        return;
    }
    system("cls");
    printBorder(6, 12 + 30 + 15 + 7 + 20 + 20);
    cout << "| " << setw(12) << left << "Student ID"
         << "| " << setw(30) << left << "Student Name"
         << "| " << setw(15) << left << "Class Name"
         << "| " << setw(7) << left << "Gender"
         << "| " << setw(20) << left << "Birth Date"
         << "| " << setw(20) << left << "Social ID"
         << " |" << endl;
    printBorder(6, 12 + 30 + 15 + 7 + 20 + 20);
    while (listOfClass)
    {
        Student *cur = listOfClass->Hstudent;
        while (cur)
        {
            cout << "| " << setw(12) << left << cur->student_id
                 << "| " << setw(30) << left << cur->fullName()
                 << "| " << setw(15) << left << listOfClass->class_name
                 << "| " << setw(7) << left << cur->gender
                 << "| " << setw(20) << left << cur->birth_date
                 << "| " << setw(20) << left << cur->social_id
                 << " |" << endl;
            printBorder(6, 12 + 30 + 15 + 7 + 20 + 20);

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
    system("cls");
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
        cout << endl << "Please enter the index of the class you want to see (press 0 to stop): ";
        cin >> choice;
    } while (choice > cnt || choice < 0);
    if (choice == 0)
    {
        return nullptr;
    }
    for (cnt = 1; cnt < choice; cnt++)
        mark = mark->next;
    return mark;
}

void printClassScoreBoard(Class *thisClass, Semester *thisSem) // un finished
{
    if (!thisClass || !(thisSem))
        return;
    system("cls");
    Student *curS = thisClass->Hstudent;
    Course *curC = thisSem->Hcourse;
    printBorder(2, 24);
    cout << "| " << setw(12) << left << "Class Name: "
         << "| "
         << setw(12) << left << thisClass->class_name << " |" << endl;
    printBorder(5, 8 + 35 + 12 + 25 + 13);
    cout << "| " << setw(12) << left << "Student ID"
         << "| " << setw(25) << left << "Student Name"
         << "| " << setw(35) << left << "Course Name"
         << "| " << setw(8) << left << "GPA"
         << "| " << setw(13) << left << "Overall GPA"
         << " |" << endl;
    printBorder(5, 8 + 35 + 12 + 25 + 13);
    int cnt;
    float sum;
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
                cout << "| " << setw(35) << left << curC->course_name
                     << "| " << setw(8) << left << ref -> overallGPA();
                sum += ref->overallGPA();
                cnt += 1;
                curC = curC->next;
                break;
            }
            curC = curC->next;
        }
        if(cnt == 0){
            cout << "| " << setw(35) << left << ""
                 << "| " << setw(8) << left << ""
                 << "| " << setw(13) << left << ""
                 << " |" << endl;
        }
        while (curC)
        {
            ref = checkInCourse(curS, curC);
            if (ref)
            {
                cout << "| " << setw(13) << left << ""
                     << " |" << endl
                     << "| " << setw(12) << left << ""
                     << "| " << setw(25) << left << "";
                cout << "| " << setw(35) << left << curC->course_name
                     << "| " << setw(8) << left << ref -> overallGPA();

                sum += ref->overallGPA();
                cnt += 1;
            }
            curC = curC->next;
        }
        if(cnt != 0){
            cout << "| " << setw(13) << left << sum / float(cnt)
                 << " |" << endl;
        }
        printBorder(5, 8 + 35 + 12 + 25 + 13);
        curS = curS->next;
    }
}

string displayyears ()
{
    vector<string> years;
    string getyear = "";
    fstream ifs("input/yearlist.csv", ios::in);
    if (!ifs.is_open())
    {
        cout << "Failed to open input/yearlist.csv" << endl;
        return getyear;
    }
    string line;
    while (getline(ifs, line))
    {
        stringstream ss(line);
        string tmp;
        while (getline(ss,tmp,','))
            years.push_back(tmp);
    }
        int cnt = 0;
    printBorder(2, 15 + 30);
    cout << "| " << setw(15) << left << "Index"
         << "| " << setw(30) << left << "Year"
         << " |" << endl;
    printBorder(2, 15 + 30);
    for (int i = 0; i < years.size(); i++)
    {
        cout << "| " << setw(15) << left << ++cnt
             << "| " << setw(30) << left << years[i]
             << " |" << endl;
        printBorder(2, 15 + 30);
    }
    ifs.close();
    int choice;
    do{
        cout << endl << "Please enter the index of year you like to see (press 0 to stop): ";
        cin >> choice;
    } while (choice > cnt || choice < 0);
    if (choice != 0)
        getyear = years[choice - 1];
    years.empty();
    return getyear;
}
