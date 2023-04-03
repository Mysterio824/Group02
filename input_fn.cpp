#include "header.h"

void AddSchoolYear(SchoolYear* &schoolyear)
{
    string year;
    cout<<"School year: ";  cin>>year;
    
    if (schoolyear)
    {
        SchoolYear* ptr = schoolyear;
        while(ptr != nullptr)
        {
            if (ptr->year == year) 
            {
                cout<<"School year existed! Please try again."<<endl;
                cin>>year;
            }
            else  ptr = ptr->next;
        }

        //no identical schoolyear found
        delete ptr;
        SchoolYear* newschlyr = new SchoolYear(year);
        newschlyr->next = schoolyear;
        schoolyear = newschlyr;
    }
    else
        schoolyear = new SchoolYear(year);
}

void AddStudent(Class* &myClass)//manually add
{
    string no, student_id, last_name, first_name, gender, birth_date, social_id ;

    cout<<"No: ";           cin>>no;
    cout<<"Student ID: ";   cin>>student_id;
    cout<<"Last name: ";    cin>>last_name;
    cout<<"First name: ";   cin>>first_name;
    cout<<"Gender: ";       cin>>gender;
    cout<<"Birth date: ";   cin>>birth_date;
    cout<<"Social ID: ";    cin>>social_id;

    Student* newStudent = new Student(no, student_id, first_name, last_name, gender, birth_date, social_id);
    newStudent -> className = myClass -> class_name;
    
    if(myClass->Hstudent != nullptr)
    {
        newStudent->next = myClass->Hstudent;
    }
    myClass->Hstudent = newStudent;
}

void AddCLass(Course* &myCourse)//manually add
{
    string className;
    cout << "Name of class you want to add to course: ";
    cin >> className;
    Class* newClass = new Class(className);

    if(myCourse->Hclass != nullptr) newClass->next = myCourse->Hclass;
    myCourse->Hclass = newClass;
}

Student* ImportStudents(string fileName)//from file
{
    ifstream file(fileName);
    if(!file.is_open())
    {
        cout << "Cannot open " << fileName << endl;
        return nullptr;
    }

    Student* Hstudent = nullptr;
    
    string line;

    while (getline(file, line)) //Reading file to input students
    {
        stringstream ss(line);
        string no, student_id, last_name, first_name, gender, birth_date, social_id ;
        getline(ss, no , ',');
        getline(ss, student_id, ',');
        getline(ss, first_name, ',');
        getline(ss, last_name, ',');
        getline(ss, gender, ',');
        getline(ss, birth_date, ',');
        getline(ss, social_id, ',');

        Student* newStudent = new Student(no, student_id, first_name, last_name, gender, birth_date, social_id);
        
        if (Hstudent != nullptr)
        {
            newStudent->next = Hstudent;           
        }
        Hstudent = newStudent;
    }

    file.close();

    return Hstudent;
}

Class* ImportClasses(string fileName)//from file
{
    ifstream file(fileName);
    if(!file.is_open())
    {
        cout << "Cannot open " << fileName << endl;
        return nullptr;
    }

    Class* Hclass = nullptr;

    string line;

    while (getline(file, line)) //Reading file to input classes
    {
        stringstream ss(line);
        string className;
        getline(ss, className , ',');
        
        Class* newClass = new Class(className);

        if (Hclass != nullptr)
        {
            newClass->next = Hclass;           
        }
        Hclass = newClass;
    }

    file.close();

    return Hclass;
}

Course* ImportCourses(string fileName)// from file
{
    ifstream file(fileName);
    if(!file.is_open())
    {
        cout << "Cannot open " << fileName << endl;
        return nullptr;
    }

    Course* Hcourse = nullptr;

    string line;

    while (getline(file, line)) //Reading file to input courses
    {
        stringstream ss(line);
        string cID, cName, clName, tName, nCredit, capacity, dei, ses;
        getline(ss, cID , ',');
        getline(ss, cName , ',');
        getline(ss, clName, ',');
        getline(ss, tName , ',');
        getline(ss, nCredit , ',');
        getline(ss, capacity, ',');
        getline(ss, dei , ',');
        getline(ss, ses , ',');
        
        Course* newCourse= new Course(cID, cName, clName, tName, nCredit, capacity, dei, ses);

        if(Hcourse != nullptr)
        {
            newCourse->next = Hcourse;
        }
        Hcourse = newCourse;
    }

    file.close();

    return Hcourse;
}

Semester* ImportSemesters(string fileName)
{
    ifstream file(fileName);
    if(!file.is_open())
    {
        cout << "Cannot open " << fileName << endl;
        return nullptr;
    }

    Semester* Hsemester = nullptr;

    string line;

    while (getline(file, line)) //Reading file to input semesters
    {
        stringstream ss(line);
        string season, schoolYear , startDate, endDate;
        getline(ss, season, ',');
        getline(ss, schoolYear, ',');
        getline(ss, startDate, ',');
        getline(ss, endDate, ',');
        
        Semester* newSemester= new Semester(stoi(season), schoolYear, startDate, endDate);

        if(Hsemester != nullptr)
        {
            newSemester->next = Hsemester;
        }
        Hsemester = newSemester;
    }

    file.close();

    return Hsemester;
}

SchoolYear* ImportSchoolYears(string fileName)
{
    ifstream file(fileName);
    if(!file.is_open())
    {
        cout << "Cannot open " << fileName << endl;
        return nullptr;
    }

    SchoolYear* HschoolYear = nullptr;

    string line;

    while (getline(file, line)) //Reading file to input years
    {
        stringstream ss(line);
        string schoolYear;
        getline(ss, schoolYear, ',');
        
        SchoolYear* newSchoolYear= new SchoolYear(schoolYear);

        if(HschoolYear != nullptr)
        {
            newSchoolYear->next = newSchoolYear;
        }
        HschoolYear= newSchoolYear;
    }

    file.close();

    return HschoolYear;
}