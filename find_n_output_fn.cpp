#include "header.h"

//---------additional funcitons-------------
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


void printStdCourse(Student *account, Course *listOfCourse)
{
    if (!account || !listOfCourse)
    {
        cout << "There is nothing to see." << endl;
        return;
    }
    printBorder(7, 12 + 28 + 12 + 25 + 7 + 17 + 11);
    cout << "| " << setw(12) << left << "Course ID"
         << "| " << setw(28) << left << "Course Name"
         << "| " << setw(13) << left << "Class Name"
         << "| " << setw(25) << left << "Teacher"
         << "| " << setw(7) << left << "Credits"
         << "| " << setw(17) << left << "Day of Week"
         << "| " << setw(11) << left << "Session"
         << " |" << endl;
    printBorder(7, 12 + 28 + 12 + 25 + 7 + 17 + 11);
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
            printBorder(7, 12 + 28 + 12 + 25 + 7 + 17 + 11 + 3);
        }
        listOfCourse = listOfCourse->next;
    }
}

void printStdScoreBoard(Student *account, Course *listOfCourse)
{
    if (!account || !listOfCourse)
        return;
    printBorder(10, 11 + 28 + 12 + 12 + 25 + 7 + 10 + 10 + 10 + 8);
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
    printBorder(10, 11 + 28 + 12 + 12 + 25 + 7 + 10 + 10 + 10 + 8);
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
            printBorder(10, 11 + 28 + 12 + 12 + 25 + 7 + 10 + 10 + 10 + 8);
            count++;
            sum += cur->overallGPA();
        }
        listOfCourse = listOfCourse->next;
    }
    cout << "--------------------" << endl;
    cout << "| " << setw(11) << left << "Overall GPA"
         << " |" << sum / float(count) << " |" << endl;
    cout << "--------------------" << endl;
}

//---------------Staff--------------------

Course* printListCourse (Course *listCourse){
    if (!listCourse)
    {
        cout << "There's nothing to see";
        return nullptr;
    }
    Course* mark = listCourse;
    int cnt = 0;
    printBorder(6, 15 + 30 + 20 + 8 + 35 + 10);
    cout << "| " << setw(15) << left << "Index"
         << "| " << setw(20) << left << "Course ID"
         << "| " << setw(30) << left << "Course Name"
         << "| " << setw(8) << left << "Credit"
         << "| " << setw(35) << left << "Teacher"
         << "| " << setw(10) << left << "Capacity"
         << " |" << endl;
    printBorder(6, 15 + 30 + 20 + 8 + 35 + 10);
    while (listCourse)
    {
        cout << "| " << setw(15) << left << ++cnt
             << "| " << setw(20) << left << listCourse -> course_id
             << "| " << setw(30) << left << listCourse -> course_name
             << "| " << setw(8) << left << listCourse -> num_credits
             << "| " << setw(35) << left << listCourse -> teacher_name
             << "| " << setw(10) << left << listCourse -> capacity
             << " |" << endl;
        printBorder(6, 15 + 30 + 20 + 8 + 35 + 10);
        listCourse = listCourse->next;
    }

    int choice;
    do
    {
        cout << endl << "Please enter the index of the Course you want to see (press " << cnt + 1 << " to stop):";
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

void printCourseScoreBoard(Course *HCourse)
{
    if (!HCourse)
    {
        return;
    }
    Scoreboard *cur = HCourse->Hscore;
    printBorder(8, 13 + 30 + 12 + 7 + 10 * 3 + 8);
    cout << "| " << setw(13) << left << "Course ID"
         << "| " << setw(30) << left << "Course Name"
         << "| " << setw(12) << left << "Student ID"
         << "| " << setw(7) << left << "Credits"
         << "| " << setw(10) << left << "Other"
         << "| " << setw(10) << left << "Midterm"
         << "| " << setw(10) << left << "Lasterm"
         << "| " << setw(8) << left << "GPA"
         << " |" << endl;
    printBorder(8, 13 + 30 + 12 + 7 + 10 * 3 + 8);
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
        printBorder(8, 13 + 30 + 12 + 7 + 10 * 3 + 8);
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
    printBorder(6, 12 + 30 + 15 + 7 + 20 + 20);
    cout << "| " << setw(12) << left << "Student ID"
         << "| " << setw(30) << left << "Student Name"
         << "| " << setw(15) << left << "Class Name"
         << "| " << setw(7) << left << "Gender"
         << "| " << setw(20) << left << "Birth Date"
         << "| " << setw(20) << left << "Social ID"
         << " |" << endl;
    printBorder(6, 12 + 30 + 15 + 10 + 20 + 20);
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
        cout << endl << "Please enter the index of the class you want to see (press " << cnt + 1 << " to stop):";
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

void printClassScoreBoard(Class *thisClass, Semester *thisSem) // un finished
{
    if (!thisClass || !(thisSem))
        return;
    system("cls");
    Student *curS = thisClass->Hstudent;
    int num = thisSem -> numOfCourses();
    int size = 0;
    Course *curC = thisSem->Hcourse;
    while(curC){
        size += (curC->course_id).length();
        curC = curC -> next;
    }
    curC = thisSem->Hcourse;
    printBorder(2, 24);
    cout << "| " << setw(12) << left << "Class Name: "
         << "| "
         << setw(12) << left << thisClass->class_name << " |" << endl;
    printBorder(3 + num, size + 12 + 25 + 11);
    cout << "| " << setw(12) << left << "Student ID"
         << "| " << setw(25) << left << "Student Name";
    while (curC)
    {
        cout << "| " << setw((curC->course_id).length()) << left << curC->course_id;
        curC = curC->next;
    }
    cout << "| " << setw(11) << left << "Overall GPA"
         << " |" << endl;
    printBorder(3 + num, size + 12 + 25 + 11);
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
                cout << "| " << setw((curC->course_id).length()) << left << ref->overallGPA();
                sum += ref->overallGPA();
                cnt += 1;
            }
            else
                cout << "| " << setw((curC->course_id).length()) << left << 'x';

            curC = curC->next;
        }
        cout << "| " << setw(11) << left << sum / float(cnt)
             << " |" << endl;
        printBorder(3 + num, size + 12 + 25 + 11);
        curS = curS->next;
    }
}

SchoolYear* printListYear(SchoolYear *listYear){
    if (!listYear)
    {
        cout << "There's no class to see";
        return nullptr;
    }
    SchoolYear *mark = listYear;
    int cnt = 0;
    printBorder(2, 15 + 30);
    cout << "| " << setw(15) << left << "Index"
         << "| " << setw(30) << left << "year"
         << " |" << endl;
    printBorder(2, 15 + 30);
    while (listYear)
    {
        cout << "| " << setw(15) << left << ++cnt
             << "| " << setw(30) << left << listYear -> year
             << " |" << endl;
        printBorder(2, 15 + 30);
        listYear = listYear->next;
    }

    int choice;
    do
    {
        cout << endl << "Please enter the index of the class you want to see (press " << cnt + 1 << " to stop):";
        cin >> choice;
    } while (choice > cnt + 1 || choice < 1);

    if (choice == cnt + 1)
        return nullptr;
    
    for (cnt = 1; cnt < choice; cnt++)
        mark = mark->next;

    return mark;
}
string displayyears ()
{
    vector<string> years;
    fstream ifs("input/yearlist.txt", ios::in);
    if (!ifs.is_open())
    {
        cout << "Failed to open input/yearlist.txt" << endl;
        return;
    }
    string tmp;
    while (getline(ifs, tmp))
            years.push_back(tmp);

    for (int i = 0; i < years.size(); i++)
    {
        cout<< "| " << setw(20) << left<<"Year list"<< "|"<<endl;
        cout<< "|---------------------|"<<endl;
        cout <<"| " << setw(20) << years[i] << "|" <<endl;
    }
    cout<< " --------------------- "<<endl;
    ifs.close();

    string getyear;
    cout << "Year input required: ";
    while(cin>>getyear)
    {
        for (int i = 0; i < years.size(); i++)
            if (getyear == years[i])
            {
                years.empty();
                return getyear;
            }

        cout<<"Invalid year, retry? (Y/N) "; cin>>getyear;
        if (getyear == "N" || getyear == "n")
        {
            years.empty();
            return "";
        }
    }
}