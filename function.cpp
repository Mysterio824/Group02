#include "header.h"

//------------Constructor------------------------
Student::Student(string no, string stuId, string fName, string lName, string gder, string birth, string socialId)
{
    No = no;
    student_id = stuId;
    first_name = fName;
    last_name = lName;
    gender = gder;
    birth_date = birth;
    social_id = socialId;
}

Course::Class::Class(string _name)
{
    class_name = _name;
    next = nullptr;
}

Semester::Semester(int n, string schoolYear ,string startDate, string endDate)
{
    season = n;
    school_year = schoolYear;
    start_date = startDate;
    end_date = endDate;

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
    
    if(courses != nullptr)
    {
        Course* tmp = courses;
        newCourse->next = tmp;
    }
    courses = newCourse;
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
    Semester* smtptr = smt;
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

    Semester* newsemes = new Semester(seasn, schoolYear, startDate, endDate);
    if (!smt)
    {
        smt = newsemes;
        smtptr = smt;
    }
    else
    {
       smtptr->next = newsemes;
       smtptr = newsemes;
    }
    cout<<"Semester added successfully!"<<endl;
}

//---------------Function----------------------------
StudentPtr* ImportStudent(string fileName)//from file
{
    ifstream file(fileName + ".csv");
    if(!file.is_open())
    {
        cout << "Cannot open " << fileName << endl;
        return nullptr;
    }

    StudentPtr* Hstudent = nullptr;
    
    string line;
    Student* stu;

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
        
        if(Hstudent == nullptr)
        {
            Hstudent = new StudentPtr;
            Hstudent->ref = newStudent;
        }
        else
        {
            StudentPtr* tmp = Hstudent;
            Hstudent = new StudentPtr;
            Hstudent->ref = newStudent;
            Hstudent->next = tmp;
        }
    }

    file.close();

    return Hstudent;
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

//creates another textfile containing class names

void AddCLass(Course* myCourse, string className)
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

string getCurrentYear (){
    string year;
    int tmp;
    time_t t = time(nullptr);
    tm *const pTInfo = localtime(&t);
    tmp=1900 + pTInfo->tm_year;
    year = to_string(tmp);
    return year;
}

//start the program (import all the data)
void startProgram (Student* listStudent, Course* listCourse, Course::Class* listClass, SchoolYear thisYear){
    //import students
    //import class
    //import course
    //import school year
    //import semester
}