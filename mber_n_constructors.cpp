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

Semester::Semester(string ssn, string schoolYear ,string startDate, string endDate)
{
    season = ssn;
    school_year = schoolYear;
    start_date = startDate;
    end_date = endDate;

    Hcourse = nullptr;
    next = nullptr;   
}

Scoreboard::Scoreboard(string stdnt_id)
{
    student_id = stdnt_id;
    midterm = 0;
    finalterm = 0;
    other = 0;

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
    Hclass = nullptr;
    next = nullptr;
}
