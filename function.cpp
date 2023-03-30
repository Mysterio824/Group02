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
        for (int i = 0; i < 3; i ++)
           smt[i].school_year = _year;
}

//---------------Function----------------------------
Student* ImportStudent( string fileName)//from file
{
    Student *Hstudent;
    ifstream file(fileName + ".csv");
    if(!file.is_open())
    {
        cout << "Cannot open " << fileName << endl;
        return nullptr;
    }
    
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
        
        //applying Stack's LIFO principle
        if (Hstudent == nullptr) 
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

void AddStudent(Student* &Hstudent, Course::Class* myClass)//manually add
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

    if (!Hstudent)
        Hstudent = newStudent;
    else
    {
        newStudent->next = Hstudent;
        Hstudent = newStudent;
    }
}

//creates another textfile containing class names
//work in progress...
void AddCLass(Course::Class* &Hclass, string className)
{
    Course::Class* pclass;
    Course::Class* newclass = new Course::Class(className);
    if (!Hclass)
    {
        Hclass = newclass;
        pclass = Hclass;
    }
    else
    {
        pclass->next = newclass;
        pclass = pclass->next;
    }
}
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

    Course* newcourse = new Course(cID, cName, clName, tName, nCredit, capa, dei, ses);
    Course* tmp;
    if(!courses)
    {
        courses = newcourse;
        tmp = courses;
    }
    else
    {
        tmp->next = newcourse;
        tmp = tmp->next;
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
    listStudent = ImportStudent("listOfStudent");
    //import class
    //import course
    //import school year
    //import semester
}