#include "header.h"

void AddSchoolYear(SchoolYear* &Hyear)
{
    string year;
    cout<<"School year: ";  cin>>year;
    
    if (Hyear != nullptr)
    {
        SchoolYear* ptr = Hyear;
        while(ptr != nullptr)
        {
            if (ptr->year == year) 
            {
                cout<<"School year existed! Please try again."<<endl;
                cin>>year;
            }
            else  ptr = ptr->next;
        }

        SchoolYear* newschlyr = new SchoolYear(year);
        newschlyr->next = Hyear;
        Hyear = newschlyr;
    }
    else
        Hyear = new SchoolYear(year);
}

void AddStudentToClass(Class* &Hclass)
{
    if(Hclass == nullptr)
    {
        cout << "Has no class to add student to!";
        return;
    }

    Class* head = Hclass;
    int i = 1;
    while(head != nullptr)
    {
        cout << i << ". ";
        cout << head->class_name << endl;
        i++;
        head = head->next; 
    }
    head = Hclass;

    string input;
    cout << "Which class you want to add student to: "; cin >> input;
    while(head != nullptr)
    {
        if(head->class_name == input)
        {
            string stuId, fName, lName, gder, birth, socialId;
            cout << "Student ID: "; cin >> stuId;
            cout << "First Name: "; cin >> fName;
            cout << "Last Name: "; cin >> lName;
            cout << "Gender: "; cin >> gder;
            cout << "Birth Date:  "; cin >> birth;
            cout << "Social ID: "; cin >> socialId;

            Student* newStudent = new Student(head->class_name, stuId, fName, lName, gder, birth, socialId);

            if(head->Hstudent != nullptr) newStudent->next = head->Hstudent;
            head->Hstudent = newStudent;

            return;
        }
        head = head->next;
    }
    cout << "The class you type in is invalid!" << endl;
    cout << "Type Y/y if you want to try again and other keys to not.";
    cin >> input;

    if(input == "Y" || input == "y") 
        AddStudentToClass(Hclass);
}

//ClassName->Hstudent = ImportStudents(classname_fileName)
//fileName: class_name.csv;
//format: no,id,fname,lname,gender,bday,social_id
Student* ImportStudents(string fileName)//from file straight to class
{
    ifstream file(fileName + ".csv");
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
        string className, student_id, last_name, first_name, gender, birth_date, social_id ;
        getline(ss, className , ',');
        getline(ss, student_id, ',');
        getline(ss, first_name, ',');
        getline(ss, last_name, ',');
        getline(ss, gender, ',');
        getline(ss, birth_date, ',');
        getline(ss, social_id, ',');

        Student* newStudent = new Student(className, student_id, first_name, last_name, gender, birth_date, social_id);
        
        if (Hstudent != nullptr)
        {
            newStudent->next = Hstudent;           
        }
        Hstudent = newStudent;
    }

    file.close();

    return Hstudent;
}

//SchoolYear schyear = import(fileName)
//fileName: year.csv
//format: className1,className2,className3,...
SchoolYear* ImportSchoolYears(string fileName)//wil create 
{
    SchoolYear* Hschyear;

    ifstream inFile(fileName + ".csv");
    if (!inFile.is_open())
    {
        cout<<"failed to open"<<fileName<<".csv"<<endl;
        return nullptr;
    }
    SchoolYear* cur;
    SchoolYear* newyear = new SchoolYear(fileName);
    if (!Hschyear)
        Hschyear = newyear;
    else
    {
        newyear->next = Hschyear;
        Hschyear = newyear;
    }

    string line;
    while(getline(inFile,line))
    {
        stringstream ss(line);
        string className;
        while (getline(ss,className,','))
        {
            Class* newclass = new Class(className);
            newclass->Hstudent = ImportStudents(className);
            if (!Hschyear->Hclass)
                Hschyear->Hclass = newclass;
            else
            {
                newclass->next = Hschyear->Hclass;
                Hschyear->Hclass = newclass;
            }
        }
    }


    return Hschyear;
}
//semester->course = importcourse(course_id)
//fileName: course_ID.csv
//format: courseID, courseName, className, teacherName, credits, capacity, day_of_week, session_time
Course* ImportCourses(string fileName)
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
//fileName: semes01.csv
//format: season,school_year, startDate, endDate
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