#include "header.h"

void AddSchoolYear(SchoolYear &schoolyear)
{
    string year;
    cout<<"School year: ";  cin>>year;
    
    if (schoolyear.list)
    {
        SchoolYear* ptr = schoolyear.list;
        while(ptr)
            if (ptr->year == year) {
                cout<<"School year existed! Please try again."<<endl;
                cin>>year;
            }
            else
                ptr = ptr->next;
        //no identical schoolyear found
        SchoolYear* newschlyr = new SchoolYear(year);
        newschlyr->next = schoolyear.list;
        schoolyear.list = newschlyr;
    }
    else
        schoolyear.list = new SchoolYear(year);
}

void AddStudent(Course::Class* myClass)//manually add
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
    
    if(myClass->Hstudent == nullptr)
    {
        myClass->Hstudent = new StudentPtr;
        myClass->Hstudent->ref = newStudent;
    }
    else
    {
        StudentPtr* tmp = myClass->Hstudent;
        myClass->Hstudent = new StudentPtr;
        myClass->Hstudent->ref = newStudent;
        myClass->Hstudent->next = tmp;
    }
}

void AddCLass(Course* myCourse, string className)//manually add
{
    Course::Class* newClass = new Course::Class(className);
    if (myCourse->Hclass == nullptr)
    {
        myCourse->Hclass = new Course::ClassPtr;
        myCourse->Hclass->ref = newClass;
    }
    else
    {   
        Course::ClassPtr* tmp = myCourse->Hclass;
        myCourse->Hclass = new Course::ClassPtr;
        myCourse->Hclass->ref = newClass;
        myCourse->Hclass->next = tmp;
    }
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
        
        if (!Hstudent)
            Hstudent = newStudent;
        else
        {
            newStudent->next = Hstudent;
            Hstudent = newStudent;
        }
    }

    file.close();

    return Hstudent;
}

Course::Class* ImportClasses(string fileName)//from file
{
    ifstream file(fileName);
    if(!file.is_open())
    {
        cout << "Cannot open " << fileName << endl;
        return nullptr;
    }

    Course::Class* Hclass = nullptr;

    string line;

    while (getline(file, line)) //Reading file to input classes
    {
        stringstream ss(line);
        string className;
        getline(ss, className , ',');
        
        Course::Class* newClass = new Course::Class(className);

        if(Hclass != nullptr)
        {
            Course::Class* tmp = Hclass;
            newClass->next = tmp;
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
            Course* tmp = Hcourse;
            newCourse->next = Hcourse;
        }
        Hcourse = newCourse;
    }

    file.close();

    return Hcourse;
}