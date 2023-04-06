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

    ofstream outFile("input/schoolyear/" + year + ".csv");
    if (!outFile.is_open()) 
    {
        cout<<"Couldn't save school year to database!"<<endl;
        outFile.close();
    }
}

void AddClasstoSchoolYear(SchoolYear* &Hschoolyear)
{
    string year;
    while (true)
    {
        cout<<"Select a school year to insert new class: "; cin>>year;
        
        ifstream inFile("input/schoolyear/" + year + ".csv");
        if (inFile.is_open() == false)
        {
            inFile.close();
            cout<<"No database found of "<<year<<".csv"<<endl;
            cout<<"Retry? (Y/N): "; cin>>year;
            if (year == "Y" || year == "y")
                continue;
            else return;
        }
        else
        {
            inFile.close();
            break;
        }
    }
    string className;
    cout<<"New class name: "; cin>>className;
    ofstream outFile("input/schoolyear/" + year + ".csv");
    outFile<<className<<", ";


}

void AddSemesterToSchoolYear(SchoolYear* &Hschoolyear)
{
    if(Hschoolyear == nullptr)
    {
        cout << "There is no school year to add semester!" << endl;
        return;
    }
    cout << "They are available school years: " << endl;
    SchoolYear* Hyear = Hschoolyear;
    while (Hyear != nullptr)
    {
        cout << '.' << Hyear->year << endl;
        Hyear = Hyear->next;
    }
    Hyear = Hschoolyear;
    
}
//voif AddCourseToSemester

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

            ofstream outFile("input/classes/" + input +".csv");
            if (!outFile.is_open())
            {
                cout<<"No database found of "<< input << ".csv"<<endl;
                outFile.close();
            }
            outFile<<"\n"<<stuId<<", "<<fName<<", "<<lName<<", "<<gder<<", "<<birth<<", "<<socialId<<", ";

            Student* newStudent = new Student(head->class_name, stuId, fName, lName, gder, birth, socialId);

            if(head->Hstudent != nullptr) newStudent->next = head->Hstudent;
            head->Hstudent = newStudent;
            outFile.close();
            delete head;
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

void AddStudentToCourse(Course* &Hcourse)//change course name to course id
{
    if(Hcourse == nullptr)
    {
        cout << "There's no course for you to add a student to!"<<endl;
        return;
    }
    cout << "There are courses available: " << endl;
    Course* tmpCourse = Hcourse;
    while (tmpCourse != nullptr)
    {
        cout << '.' << tmpCourse->course_id << endl;
        tmpCourse = tmpCourse->next;
    }
    tmpCourse = Hcourse;    

    string input;
    cout << "Name of course you want to add student to: "; cin >> input;  
    while (true)
    {      
        tmpCourse = Hcourse;
        if(tmpCourse->course_id == input) break;
        tmpCourse = tmpCourse->next;
        if(tmpCourse == nullptr)
        {
            cout << "The course you typed in was invalid!" <<endl;
            cout << "Do you want to try again ? (Y/y for yes and others for no): "; cin >> input;
            if(input != "Y" && input != "y")
            {
                cout << "You added no student!" <<endl;
                return;
            }
            else
                cout << "Try again! Name of course?: "; cin >> input;
        }
    }
    //course_id input acquired
    ofstream outFile("input/scoreboard/" + input + ".csv");
    if (!outFile.is_open())
    {
        cout<<"Course data not found."<<endl;
        cout<<"Proceed without saving to database."<<endl;
    }
    cout << "ID of the student you want to add to course: "; cin >> input;
    Scoreboard* tmpStu = tmpCourse->Hscore;
    while (true)
    {
        if(tmpStu->student_id == input)
        {
            cout << "The student is already in the course." <<endl;
            cout << "Do you want to add a different student? (Y/y for yes - others for no): "; cin >> input;
            if(input != "Y" && input != "y")
            {
                cout << "You added no student!" << endl;
                break;
            }
            else
            {
                cout << "Type another ID: "; cin >> input;
                tmpStu = tmpCourse->Hscore;
            }
        }
        else
        {
            tmpStu = tmpStu->next;
            if(tmpStu == nullptr)
            {
                tmpStu = new Scoreboard(input);
                tmpStu->next = tmpCourse->Hscore;
                tmpCourse->Hscore = tmpStu;
                cout << "You added this Student ID: " << input << "to " << tmpCourse->course_name << endl;
                break;
            }
        }
    }
    outFile.close();
}

//fileName: class_name.csv;
//format: id,fname,lname,gender,bday,social_id
Student* ImportStudents(string fileName)//from inFile straight to class
{
    ifstream inFile("input/classes/"+fileName + ".csv");
    if(!inFile.is_open())
    {
        cout << "Cannot open " << fileName << endl;
        return nullptr;
    }

    Student* Hstudent = nullptr;
    Student* pstd;
    
    string line;

    while (getline(inFile, line)) //Reading inFile to input students
    {
        stringstream ss(line);
        string student_id, last_name, first_name, gender, birth_date, social_id ;
        getline(ss, student_id, ',');
        getline(ss, first_name, ',');
        getline(ss, last_name, ',');
        getline(ss, gender, ',');
        getline(ss, birth_date, ',');
        getline(ss, social_id, ',');

        Student* newStudent = new Student(fileName, student_id, first_name, last_name, gender, birth_date, social_id);
        
        if (!Hstudent)
        {
            Hstudent = newStudent;
            pstd = Hstudent;
        }
        else
        {
            pstd->next = newStudent;
            pstd = newStudent;
        }
    }

    inFile.close();
    cout<<">classes/"<<fileName<<".csv loaded"<<endl;
    return Hstudent;
}

//fileName: year.csv
//format: className1,className2,className3,...
SchoolYear* ImportSchoolYears(string fileName)
{
    SchoolYear* Hschyear;
    //creates newSchoolyear
    ifstream inFile("input/schoolyear/"+fileName + ".csv");
    if (!inFile.is_open())
    {
        cout<<"failed to open"<<fileName<<".csv"<<endl;
        return nullptr;
    }
    SchoolYear* newyear = new SchoolYear(fileName);
    if (!Hschyear)
        Hschyear = newyear;
    else
    {
        newyear->next = Hschyear;
        Hschyear = newyear;
    }
    //add class to schoolyear
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
            {
                Hschyear->Hclass = newclass;
            }
            else
            {
                newclass->next = Hschyear->Hclass;
                Hschyear->Hclass = newclass;
            }
        }
    }
    
    inFile.close();
    cout<<">schoolyear/"<<fileName<<".csv loaded"<<endl;
    return Hschyear;
}

//fileName: semester[...].csv
//format: courseID, courseName, className, teacherName, credits, capacity, day_of_week, session_time
Course* ImportCourses(string fileName)//semester#
{
    ifstream inFile("input/courses/"+ fileName +".csv");
    if(!inFile.is_open())
    {
        cout << "Cannot open " << fileName << endl;
        return nullptr;
    }

    Course* Hcourse = nullptr;

    string line;

    while (getline(inFile, line)) //Reading inFile to input courses
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

        if(!Hcourse)
            Hcourse = newCourse;
        else
        {
            newCourse->next = Hcourse;
            Hcourse = newCourse;
        }
    }

    inFile.close();
    cout<<">courses/"<<fileName<<".csv loaded."<<endl;

    return Hcourse;
}
//fileName: year.csv
//format: season,school_year, startDate, endDate
//semesName = "semester"+semester->season, e.g semester01, semester02
///season = 01, 02, 03
Semester* ImportSemesters(string fileName)//fileName = currentyear
{
    ifstream inFile("input/semesters/" + fileName + ".csv");
    if(!inFile.is_open())
    {
        cout << "Cannot open " << fileName +".csv" << endl;
        return nullptr;
    }

    Semester* Hsemester = nullptr;
    Semester* psemes;
    string line;
    while (getline(inFile,line))
    {
        stringstream ss(line);
        string season, begin, end;
        getline(ss,season,',');
        getline(ss,begin,',');
        getline(ss,end,',');

        Semester* newsemester = new Semester(season, fileName, begin, end);
        if (!Hsemester)
        {
            Hsemester = newsemester;
            psemes = Hsemester;
        }
        else
        {
            psemes->next = newsemester;
            psemes = newsemester;
        }
    }

    /* psemes = Hsemester;
    string semesterN;
    while(psemes)
    {
        semesterN = "semester"+psemes->season;
        psemes->Hcourse = ImportCourses(semesterN);
        psemes = psemes->next;
    } */
    inFile.close();
    cout<<">semesters/"<<fileName<<".csv loaded."<<endl;

    return Hsemester;
}