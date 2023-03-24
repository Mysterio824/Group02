#include "mainProgram.h"

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

Class::Class(string _name)
{
    class_name = _name;
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
}
//--------------------------------------------------

//---------------Function----------------------------
void Course::AddStudent(string fileName)
{
    ifstream file(fileName);
    if(!file.is_open())
    {
        std::cout << "Cannot open " << fileName << std::endl;
        return;
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
        
        //Add students to a singly linked list
        if (students == nullptr) 
        {
            students = newStudent;
            stu = students;
        } 
        else 
        {
            stu->next = newStudent;
            stu = stu->next;
        }
    }

    file.close();
}

void Class::AddStudent(string fileName)
{
    ifstream file(fileName);
    if(!file.is_open())
    {
        std::cout << "Cannot open " << fileName << std::endl;
        return;
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
        
        //Add students to a singly linked list
        if (students == nullptr) 
        {
            students = newStudent;
            stu = students;
        } 
        else 
        {
            stu->next = newStudent;
            stu = stu->next;
        }
    }

    file.close();
}

void Semester::AddCourse()
{
    string cID, cName, clName, tName, nCredit, capa, dei, ses;
    cout << "What is the id of the course? ";
    cin >> cID;
    cout << "What is the name of the course? ";
    cin >> cName;
    cout << "What is the name of the class? ";
    cin >> clName;
    cout << "Who will teach this course? ";
    cin >> tName;
    cout << "The number of credits in this course? ";
    cin >> nCredit;
    cout << "Maximum student in this course? ";
    cin >> capa;
    cout << "Which day of week this course take? ";
    cin >> dei;
    cout << "And what session in the day? ";
    cin >> ses;

    Course* course = new Course(cID, cName, clName, tName, nCredit, capa, dei, ses);
    Course* tmp;

    if(courses == nullptr)
    {
        courses = course;
        tmp = courses;
    }
    else
    {
        tmp->next = course;
        tmp = tmp->next;
    }
}