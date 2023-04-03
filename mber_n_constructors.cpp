#include "header.h"

//------------Constructor------------------------
Student::Student(string class_name, string stuId, string fName, string lName, string gder, string birth, string socialId)
{
    className = class_name;
    student_id = stuId;
    first_name = fName;
    last_name = lName;
    gender = gder;
    birth_date = birth;
    social_id = socialId;

    next = nullptr;
}

Class::Class(string _name)
{
    class_name = _name;
    Hstudent = nullptr;
    next = nullptr;
}

Semester::Semester(int n, string schoolYear ,string startDate, string endDate)
{
    season = n;
    school_year = schoolYear;
    start_date = startDate;
    end_date = endDate;

    Hcourse = nullptr;
    next = nullptr;   
}

Scoreboard::Scoreboard(string stdnt_id, float _mid, float _final, float _other)
{
    student_id = stdnt_id;
    midterm = _mid;
    finalterm = _final;
    other = _other;

    next = nullptr;
}

Course::Course(string cID, string cName, string clName, string tName, string nCredit, string capa, string dei, string ses)
{
    course_id = cID;
    course_name = cName;
    class_name = clName;
    teacher_name = tName;
    num_credits = nCredit;
    capacity = stoi(capa);
    day = dei;
    session = ses;

    next = nullptr;
}

SchoolYear::SchoolYear(std::string _year)
{
        year = _year;
        Hsemester = nullptr;
        next = nullptr;
}

//---------------------Member Function----------------------------
void Semester::AddCourse()
{
    string cID, cName, clName, tName, nCredit, capa, dei, ses;
    cout << "Course ID: ";
    cin >> cID; //string
    cout << "Course name: ";
    cin >> cName; //string
    cout << "Class name: ";
    cin >> clName; //string
    cout << "Teacher name: ";
    getline(cin, tName); //string with spaces
    cout << "Number of credits: ";
    cin >> nCredit; //
    cout << "Number of Students:  ";
    cin >> capa; //
    cout << "Day of week: ";
    cin >> dei;
    cout << "Session time: ";
    cin >> ses;

    Course* newCourse = new Course(cID, cName, clName, tName, nCredit, capa, dei, ses);
    
    if(Hcourse != nullptr)
    {
        newCourse->next = Hcourse;
    }
    Hcourse = newCourse;
}

void SchoolYear::AddSemester()
{
    semes_count++;
    if (semes_count > semes_num)
    {
        cout<<"Number of semesters exceeded!"<<endl;
        semes_count--;
        return;
    }
    
    int seasn;
    string schoolYear, startDate, endDate;

    cout<<"Season: "; cin>>seasn;
    Semester* smtptr = Hsemester;
    for (int i = 0; i < 3 && smtptr; i++)
    {
        if (smtptr->season == seasn)
        {
            cout<<"This season is currently have a semester scheduled!"<<endl;
            cout<<"Please choose another season, or input -1 to cancel: "; cin>>seasn;
            if (seasn == -1)
                return;
            i = 0;
        }
        else
            smtptr = smtptr->next;
    }
    cout<<"School year: "; cin>>schoolYear;
    cout<<"Start date: "; cin>>startDate;
    cout<<"End date: "; cin>>endDate;

    delete smtptr;

    Semester* newsemes = new Semester(seasn, schoolYear, startDate, endDate);
    if (Hsemester)
       newsemes->next = Hsemester;   
    Hsemester = newsemes;
    cout<<"Semester added successfully!"<<endl;
}