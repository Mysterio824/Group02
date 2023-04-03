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