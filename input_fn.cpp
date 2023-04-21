#include "header.h"

void AddSchoolYear(SchoolYear* &Hyear)
{
    string input;
    cout<<"School year: ";  cin>>input;
    
    if (Hyear != nullptr)
    {
        SchoolYear* ptr = Hyear;
        cout << "Here are available schoo-years: " << endl;
        while(ptr != nullptr)
        {
            cout << "+" << ptr->year << endl;
            ptr = ptr->next;
        }
        ptr = Hyear;
        while(ptr != nullptr)
        {
            if (ptr->year == input) 
            {
                cout<<"School year existed!"<<endl;
                cout << "Do you want to try again? (Y/y for yes - other keys for no): "; cin >> input;
                if(input != "y" && input != "Y")
                {
                    cout << "You chose not to add any school-year!" << endl;
                    system("pause");
                    return;
                }
                else
                {
                    cout << "Try another year: "; cin >> input;
                    ptr = Hyear;
                }
            }
            else ptr = ptr->next;
        }

        SchoolYear* newschlyr = new SchoolYear(input);
        newschlyr->next = Hyear;
        Hyear = newschlyr;
    }
    else Hyear = new SchoolYear(input);

    cout << "You added the shool-year: " << input << endl;
    system("pause"); 
}

void AddClasstoSchoolYear(SchoolYear* &Hschoolyear)
{
    if(Hschoolyear == nullptr)
    {
        cout << "There is no school year to add semester!" << endl;
        return;
    }
    cout << "Here are available school years: " << endl;
    SchoolYear* tmpYear = Hschoolyear;
    while (tmpYear != nullptr)
    {
        cout << '+' << tmpYear->year << endl;
        tmpYear = tmpYear->next;
    }
    tmpYear = Hschoolyear;
    string input;
    cout << "Which year you want to add class? : "; cin >> input;
    while (true)
    {
        if(input == tmpYear->year) break;
        tmpYear = tmpYear->next;
        if(tmpYear == nullptr)
        {
            cout << "The year you want is invalid!" <<endl;
            cout << "Do you want to try again? (Y/y for yes - other keys for no): "; cin >> input;
            if(input != "Y" && input != "y")
            {
                cout << "You chose not to add class." << endl;
                system("pause");
                return;
            }
            else
            {
                cout << "Try another year: "; cin >> input;
                tmpYear = Hschoolyear;
            }
        }
    }
    Class* tmpClass = tmpYear->Hclass;
    cout << "Here are classes in this year: " << endl;
    while (tmpClass != nullptr)
    {
        cout << '.' << tmpClass->class_name << endl;
        tmpClass = tmpClass->next;
    }
    tmpClass = tmpYear->Hclass;
    string className;
    cout << "Name of class you want to add: ";  cin >> className;
    while (tmpClass != nullptr)
    {
        if(tmpClass->class_name == className)
        {
            cout << "This class is already in the school year." << endl;
            cout << "Do you want to try again? (Y/y for yes - others for no): "; cin >> input;
            if(input != "Y" && input != "y")
            {
                cout << "You added no class to the school year!" << endl;
                system("pause");
                return;
            }
            else
            {
                cout << "Try another class: "; cin >> className;
                tmpClass = tmpYear->Hclass;
            }
        }
        else tmpClass = tmpClass->next;
    }     
    tmpClass= new Class(className);
    tmpClass->next = tmpYear->Hclass;
    tmpYear->Hclass = tmpClass;
    cout << "You added class " << className << "to the school-year of " << tmpYear->year;
    system("pause");
}

void AddSemesterToSchoolYear(SchoolYear* &Hschoolyear)
{
    if(Hschoolyear == nullptr)
    {
        cout << "There is no school year to add semester!" << endl;
        return;
    }
    cout << "Here are available school years: " << endl;
    SchoolYear* tmpYear = Hschoolyear;
    while (tmpYear != nullptr)
    {
        cout << '+' << tmpYear->year << endl;
        tmpYear = tmpYear->next;
    }
    tmpYear = Hschoolyear;
    string input;
    cout << "Which year you want to add semester? : "; cin >> input;
    while (true)
    {
        if(input == tmpYear->year) break;
        tmpYear = tmpYear->next;
        if(tmpYear == nullptr)
        {
            cout << "The year you want is invalid!" <<endl;
            cout << "Do you want to try again? (Y/y for yes - other keys for no): "; cin >> input;
            if(input != "Y" && input != "y")
            {
                cout << "You chose not to add semester." << endl;
                system("pause");
                return;
            }
            else
            {
                cout << "Try another year: "; cin >> input;
                tmpYear = Hschoolyear;
            }
        }
    }
    Semester* tmpSemes = tmpYear->Hsemester;
    cout << "Sesons have been already in this year: " << endl;
    while (tmpSemes != nullptr)
    {
        cout << '.' << tmpSemes->season << endl;
        tmpSemes = tmpSemes->next;
    }
    tmpSemes = tmpYear->Hsemester;
    string season, startDate, endDate;
    cout << "The season of this semester(1, 2, 3)? : ";  cin >> season;
    while (tmpSemes != nullptr)
    {
        if(tmpSemes->season == season)
        {
            cout << "This season is already in the school year." << endl;
            cout << "Do you want to try again? (Y/y for yes - others for no): "; cin >> input;
            if(input != "Y" && input != "y")
            {
                cout << "You added no semester to the school year!" << endl;
                system("pause");
                return;
            }
            else
            {
                cout << "Try another season (1, 2, 3): "; cin >> season;
                tmpSemes = tmpYear->Hsemester;
            }
        }
        else tmpSemes = tmpSemes->next;
    }     
    cout << "The start date of this semester? : "; cin >> startDate;
    cout << "The end date of this semester? : "; cin >> endDate;
 
    tmpSemes = new Semester(season, tmpYear->year, startDate, endDate);
    tmpSemes->next = tmpYear->Hsemester;
    tmpYear->Hsemester = tmpSemes;
    cout << "You added a semester season " << season << "to the school year of " << tmpYear->year;
    system("pause");
}

void AddCourseToSemester(Semester* &Hsemester)
{
    if(Hsemester == nullptr)
    {
        cout << "There is no semester to add course!" << endl;
        return;
    }
    cout << "Here are available semesters: " << endl;
    Semester* tmpSemes = Hsemester;
    while (tmpSemes != nullptr)
    {
        cout << '+' << "season: " << tmpSemes->season << endl;
        tmpSemes = tmpSemes->next;
    }
    tmpSemes = Hsemester;
    string input;
    cout << "Which season you want to add course? : "; cin >> input;
    while (true)
    {
        if(input == tmpSemes->season) break;
        tmpSemes = tmpSemes->next;
        if(tmpSemes == nullptr)
        {
            cout << "The season you want is invalid!" <<endl;
            cout << "Do you want to try again? (Y/y for yes - other keys for no): "; cin >> input;
            if(input != "Y" && input != "y")
            {
                cout << "You chose not to add course." << endl;
                system("pause");
                return;
            }
            else
            {
                cout << "Try another season: "; cin >> input;
                tmpSemes = Hsemester;
            }
        }
    }
    Course* tmpCourse = tmpSemes->Hcourse;
    cout << "Courses in this semester: " << endl;
    while (tmpCourse != nullptr)
    {
        cout << '.' << tmpCourse->course_id << endl;
        tmpCourse = tmpCourse->next;
    }
    tmpCourse = tmpSemes->Hcourse;

    string cID, cName, clName, tName, nCredit, capacity, dei, ses;
    cout << "ID of the course: ";  cin >> cID;
    while (tmpCourse != nullptr)
    {
        if(tmpCourse->course_id == cID)
        {
            cout << "This course ID is already in the semester." << endl;
            cout << "Do you want to try again? (Y/y for yes - others for no): "; cin >> input;
            if(input != "Y" && input != "y")
            {
                cout << "You added no course to the semester!" << endl;
                system("pause");
                return;
            }
            else
            {
                cout << "Try another course ID: "; cin >> cID;
                tmpCourse = tmpSemes->Hcourse;
            }
        }
        else tmpCourse = tmpCourse->next;
    }     
    cout << "Name of the course: "; cin >> cName;
    cout << "The class name is: "; cin >> clName;
    cout << "Who will teach this course?: ";  cin >> tName;
    cout << "The number of credits: "; cin >> nCredit;
    cout << "Capacity: "; cin >> capacity;
    cout << "This course will be taught in which day of week?: ";  cin >> dei;
    cout << "And what session?: "; cin >> ses;
 
    tmpCourse = new Course(cID, cName, clName, tName, nCredit, capacity, dei, ses);
    tmpCourse->next = tmpSemes->Hcourse;
    tmpSemes->Hcourse = tmpCourse;
    cout << "You added a course with ID " << cID << "to the semester season " << tmpSemes->season << ", year " << tmpSemes->school_year;
    system("pause");
}

void AddStudentToClass(Class* &Hclass)
{
    if(Hclass == nullptr)
    {
        cout << "There is no class to add student";
        return;
    }
    cout << "Here are available classes in this school year:" << endl;
    Class* tmpClass = Hclass;
    while (tmpClass != nullptr)
    {
        cout << '+' << tmpClass->class_name << endl;
        tmpClass = tmpClass->next;
    }
    tmpClass = Hclass;
    string input;
    cout << "Which class you want to add student: "; cin >> input;
    while (true)
    {
        if(input == tmpClass->class_name) break;
        tmpClass = tmpClass->next;
        if(tmpClass == nullptr)
        {
            cout << "The class you want is invalid!" << endl;
            cout << "Do you want to try again? (Y/y for yes - other keys for no): "; cin >> input;
            if(input != "Y" && input != "y")
            {
                cout << "You chose not to add any student." << endl;
                system("pause");
                return;
            }
            else
            {
                cout << "Try again with another class: "; cin >> input;
                tmpClass = Hclass;
            }
        }
    }
    Student* tmpStu = tmpClass->Hstudent;
    cout << "Student's IDs is currently in this class: " << endl;
    while (tmpStu != nullptr)
    {
        cout << '.' << tmpStu->student_id << endl;
        tmpStu = tmpStu->next;
    }
    tmpStu = tmpClass->Hstudent;

    string stuId, fName, lName, gder, birth, socialId;
    cout << "Student ID: "; cin >> stuId;
    while (tmpStu != nullptr)
    {
        if(tmpStu->student_id == stuId)
        {
            cout << "This student ID is already in this class." << endl;
            cout << "Do you want to try again? (Y/y for yes - other keys for no): "; cin >> input;
            if(input != "Y" && input != "y")
            {
                cout << "You add no student to this class";
                system("pause");
                return;
            }
            else
            {
                cout << "Try another student ID: "; cin >> stuId;
                tmpStu = tmpClass->Hstudent;
            }
        }
        else tmpStu = tmpStu->next;
    }

    cout << "First Name: "; cin >> fName;
    cout << "Last Name: "; cin >> lName;
    cout << "Gender: "; cin >> gder;
    cout << "Birth Date:  "; cin >> birth;
    cout << "Social ID: "; cin >> socialId;

    tmpStu = new Student(tmpClass->class_name, stuId, fName, lName, gder, birth, socialId);
    tmpStu->next = tmpClass->Hstudent;
    tmpClass->Hstudent = tmpStu;

    cout << "You added " << tmpStu->fullName() << "with the ID of " << stuId << "to class " << tmpClass->class_name;
    system("pause");
}

void AddStudentToCourse(Course* &Hcourse)
{
    if(Hcourse == nullptr)
    {
        cout << "There's no course for you to add a student to!"<<endl;
        return;
    }
    cout << "Here are courses available: " << endl;
    Course* tmpCourse = Hcourse;
    while (tmpCourse != nullptr)
    {
        cout << '+' << tmpCourse->course_id << endl;
        tmpCourse = tmpCourse->next;
    }
    tmpCourse = Hcourse;    

    string input;
    cout << "Name of course you want to add student to: "; cin >> input;  
    while (true)
    {      
        if(tmpCourse->course_id == input) break;
        tmpCourse = tmpCourse->next;
        if(tmpCourse == nullptr)
        {
            cout << "The course you typed in was invalid!" <<endl;
            cout << "Do you want to try again ? (Y/y for yes and others for no): "; cin >> input;
            if(input != "Y" && input != "y")
            {
                cout << "You added no student!" <<endl;
                system("pause");
                return;
            }
            else
            {
                cout << "Try again with another course name: "; cin >> input;
                tmpCourse = Hcourse;
            }
        }
    }
    cout << "ID of the student you want to add to course: "; cin >> input;
    Scoreboard* tmpStu = tmpCourse->Hscore;
    cout << "Student's IDs in this course: " << endl;
    while (tmpStu != nullptr)
    {
        cout << '.' << tmpStu->student_id << endl;
        tmpStu = tmpStu->next;
    }
    tmpStu = tmpCourse->Hscore;
    while (tmpStu != nullptr)
    {
        if(tmpStu->student_id == input)
        {
            cout << "The student is already in the course." <<endl;
            cout << "Do you want to add a different student? (Y/y for yes - others for no): "; cin >> input;
            if(input != "Y" && input != "y")
            {
                cout << "You added no student!" << endl;
                system("pause");
                return;
            }
            else
            {
                cout << "Type another ID: "; cin >> input;
                tmpStu = tmpCourse->Hscore;
            }
        }
        else tmpStu = tmpStu->next;
    }

    tmpStu = new Scoreboard(input);
    tmpStu->next = tmpCourse->Hscore;
    tmpCourse->Hscore = tmpStu;
    cout << "You added this Student ID: " << input << "to " << tmpCourse->course_name << endl;
    system("pause");
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

//fileName: year+ #semester.csv
//format: courseID, courseName, className, teacherName, credits, capacity, day_of_week, session_time
Course* ImportCourses(string fileName)//school_year + #semester.csv
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
//semesName = school_year+semester->season, e.g 202301, 202302
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

    inFile.close();
    cout<<">semesters/"<<fileName<<".csv loaded."<<endl;

    return Hsemester;
}
//filename : course_id.csv
//format: studentID,student_name,midterm,finalterm,other
Scoreboard* ImportScoreboard(Course* Hcourse)
{
    ifstream inFile("input/scoreboard/"+ Hcourse->course_id +".csv");
    if (!inFile.is_open())
    {
        cout<<"Failed to open "<<Hcourse->course_id<<".csv\n";
        return nullptr;
    }
    string line;
    while (getline(inFile, line))
    {
        stringstream ss(line);
        string std_id,std_name, mid, final, othr;
        getline(ss,std_id,',');
        getline(ss,std_name,',');
        getline(ss,mid,',');
        getline(ss,final,',');
        getline(ss,othr,',');

        Scoreboard* newscoreB = new Scoreboard(std_id);
        newscoreB->full_name = std_name;
        newscoreB->midterm = std::stof(mid);
        newscoreB->midterm = std::stof(final);
        newscoreB->midterm = std::stof(othr);

        if (!Hcourse->Hscore)
            Hcourse->Hscore = newscoreB;
        else
        {
            newscoreB->next = Hcourse->Hscore;
            Hcourse->Hscore = newscoreB;
        }
    }
    inFile.close();
    cout<<">scoreboard/"<<Hcourse->course_id<<".csv loaded."<<endl;
    return Hcourse->Hscore;
}

void UpdateCourseInfo(Course* &Hcourse)
{
    Course* pcourse = Hcourse;
    if (!pcourse)
    {
        cout<<"No course to update\n";
        return;
    }
    cout<<"Available courses:\n";
    cout<<"| "<<setw(15)<<left<<"Course ID"
        <<"| "<<setw(30)<<left<<"Course Name"<<" |"<<endl;
    {
        cout<<"| "<<setw(15)<<left<<pcourse->course_id
        <<"| "<<setw(30)<<left<<pcourse->course_name<<" |"<<endl;
        pcourse = pcourse->next;
    }
    string course_id;
    string  course_name, class_name, teacher_name,
            credits, day_of_week, session_time;
    int capacity;
    while (true)
    {
        cout<<"Enter course ID to update: ";
        cin>>course_id;
        pcourse = Hcourse;
        while (pcourse)
        {
            if (pcourse->course_id == course_id)
            {
                cout<<"Enter new course name: "; cin>>course_name;
                cout<<"Enter new teacher name: "; cin>>teacher_name;
                cout<<"Enter new credits: "; cin>>credits;
                cout<<"Enter new capacity: "; cin>>capacity;
                cout<<"Enter new day of week: "; cin>>day_of_week;
                cout<<"Enter new session time: "; cin>>session_time;

                pcourse->course_name = course_name;
                pcourse->teacher_name = teacher_name;
                pcourse->num_credits = credits;
                pcourse->capacity = capacity;
                pcourse->day = day_of_week;
                pcourse->session = session_time;
                cout<<"Course updated\n";
                return;
            }
            pcourse = pcourse->next;
        }
        cout<<"No course found\n";
        system("pause");
    }
}

void UpdateStudentResult(Course* &Hcourse)
{
    if(Hcourse == nullptr)
    {
        cout << "There is no courses to update student's result.";
        return;
    }

    Course* tmpCourse = Hcourse;
    cout << "Here are available courses: " << endl;
    while (tmpCourse != nullptr)
    {
        cout << '+' << tmpCourse->course_id << endl;
        tmpCourse = tmpCourse->next;
    }
    tmpCourse = Hcourse;
    string input;
    cout << "Choose the course ID you want to update its student's result."; cin >> input;
    while (true)
    {
        if(input == tmpCourse->course_id) break;
        tmpCourse = tmpCourse->next;
        if(tmpCourse == nullptr)
        {
            cout << "The course you want is currently invalid.";
            cout << "Do you want to try again? (Y/y for yes - other keys for no): "; cin >> input;
            if(input != "Y" && input != "y")
            {
                cout << "You chose not to update any student.";
                return;
            }
            else
            {
                cout << "Try another course ID: "; cin >> input;
                tmpCourse = Hcourse;
            }
        }
    }
    cout << "Here are IDs of students of this course: " << endl;
    int count = 0;
    Scoreboard* tmpSB = tmpCourse->Hscore;
    while (tmpSB != nullptr)
    {
        count++;
        cout << '.' << tmpSB->student_id;
        if(count == 3)
        {
            count = 0;
            cout << endl;
        }
        else cout << "      ";
        tmpSB = tmpSB->next;
    }
    tmpSB = tmpCourse->Hscore;
    cout << "Which student's ID you want to update its owner's result?: "; cin >> input;
    while (true)
    {
        if(tmpSB->student_id == input) break;
        tmpSB = tmpSB->next;
        if(tmpSB == nullptr)
        {
            cout << "The student you want is not in this class.";
            cout << "Do you want to try again? (Y/y for yes - other keys for no): "; cin >> input;
            if(input != "Y" && input != "y")
            {
                cout << "You chose not to update any student.";
                return;
            }
            else
            {
                cout << "Try another student's ID: "; cin >> input;
                tmpSB = tmpCourse->Hscore;
            }
        }
    }
    float midT, finalT, otherT;
    cout << "Type in the student's result: " << endl;
    cout << "Midterm Result: "; cin >> midT; 
    cout << "Finalterm Result: "; cin >> finalT;
    cout << "Other results: "; cin >> otherT;
    tmpSB->midterm = midT;
    tmpSB->finalterm = finalT;
    tmpSB->other = otherT;
    cout << "You have updated successfully results of " << tmpSB->full_name << " with the ID: " << tmpSB->student_id;
    system("pause");
}