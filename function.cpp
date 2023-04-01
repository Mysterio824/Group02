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
void startProgram (Student* &listStudents, Course* &listCourses, Course::Class* &listClasses, SchoolYear &thisYear)
{
    string stuList = "listOfStudents.csv";
    string classList = "listOfClasses.csv";
    string courseList = "listOfCourses.csv";

    listStudents = ImportStudents(stuList);
    listClasses = ImportClasses(classList);
    listCourses = ImportCourses(courseList);
    //import semester
    //import school year
}

Course :: Class* findClass (Student* account, Course::Class *listOfClass){
    if(!listOfClass || !account) return nullptr;
    while (listOfClass){
        if(listOfClass -> class_name == account -> className)
            return listOfClass;
        listOfClass = listOfClass -> next;
    }
    return nullptr;
}

int findStudentNo (Student *account, Course::Class* myClass){
    if(!myClass || !account) return 0;
    int count = 0;
    StudentPtr* curStudent = myClass -> Hstudent;
    while (curStudent && curStudent -> ref != account){
        curStudent = curStudent -> next;
        count ++;
    }
    return count;
}

void printCourse(Student *account, Course::Class *listOfClass){
     cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "| " << setw(12) << left << "Course ID"
        << "| " << setw(35) << left << "Course Name"
        << "| " << setw(20) << left << "Class Name"
        << "| " << setw(25) << left << "Teacher"
        << "| " << setw(5) << left << "Credits"
        << "| " << setw(10) << left << "Max Students"
        << "| " << setw(15) << left << "Day of Week"
        << "| " << setw(11) << left << "Session" << " |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    Course::Class* curClass = findClass(account, listOfClass);
    Course::Class::CoursePtr* curCourse = curClass -> courses;
    while (curCourse){
        cout << "| " << setw(12) << left << curCourse -> ref -> course_id
            << "| " << setw(35) << left << curCourse -> ref -> course_name
            << "| " << setw(20) << left << curClass -> class_name
            << "| " << setw(25) << left << curCourse -> ref -> teacher_name
            << "| " << setw(7) << left << curCourse -> ref -> num_credits
            << "| " << setw(12) << left << curCourse -> ref -> capacity
            << "| " << setw(15) << left << curCourse -> ref -> day
            << "| " << setw(11) << left << curCourse -> ref -> session << " |" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        curCourse = curCourse -> next;
    }
}

void printScoreBoard (Student *account, Course::Class *listOfClass){
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "| " << setw(12) << left << "Course ID"
        << "| " << setw(35) << left << "Course Name"
        << "| " << setw(20) << left << "Class Name"
        << "| " << setw(25) << left << "Student Name"
        << "| " << setw(5) << left << "Credits"
        << "| " << setw(10) << left << "Midterm"
        << "| " << setw(15) << left << "Lasterm"
        << "| " << setw(11) << left << "Overal" << " |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    Course::Class* curClass = findClass(account, listOfClass);
    int No = findStudentNo(account, curClass);
    int n = sizeof(curClass -> courses -> scores[No]);
    while (curClass -> courses){
        for (int i = 0; i < n; i++)
            cout << curClass -> courses ->scores[No][i];
//      cout << "| " << setw(12) << left << curCourse -> ref -> course_id
//             << "| " << setw(35) << left << curCourse -> ref -> course_name
//             << "| " << setw(20) << left << curClass -> class_name
//             << "| " << setw(25) << left << curCourse -> ref -> teacher_name
//             << "| " << setw(7) << left << curCourse -> ref -> num_credits
//             << "| " << setw(12) << left << curCourse -> ref -> capacity
//             << "| " << setw(15) << left << curCourse -> ref -> day
//             << "| " << setw(11) << left << curCourse -> ref -> session << " |" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }
}