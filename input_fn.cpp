#include "header.h"

void AddSchoolYear(SchoolYear* &Hyear)
{
    system("cls");
    string input;
    ofstream outFile;
    if (Hyear != nullptr)
    {
        SchoolYear* ptr = Hyear;
        SchoolYear* lastNode; 
        cout << " -----------------------------------------" << endl;
        cout << "(.) Available school-years: " << endl;
        cout << " -----------------------------------------" << endl;
        int count = 0;
        while(ptr != nullptr)
        {
            count++;
            cout << '-' << ptr->year << '-';
            if(count % 3 == 0) cout << endl;
            else cout << "      ";
            lastNode = ptr;
            ptr = ptr->next;
        }
        if(count % 3 != 0) cout << endl;
        cout << " -----------------------------------------" << endl;
        cout<<"(...) School year to add: ";  cin>>input;
        ptr = Hyear;
        while(ptr != nullptr)
        {
            if (ptr->year == input) 
            {
                cout<<"(!) School year existed."<<endl;
                cout << "(?) Do you want to try again (Y/y for yes - other keys for no): "; cin >> input;
                if(input != "y" && input != "Y")
                {
                    system("cls");
                    cout << "--------------------------------------------" << endl;
                    cout << "(!) You chose not to add any school-year." << endl;
                    cout << "--------------------------------------------" << endl;
                    cout << endl << "Press any key to return...";
                    system("pause");
                    system("cls");
                    return;
                }
                else
                {
                    cout << endl << "(...) Try another year: "; cin >> input;
                    ptr = Hyear;
                }
            }
            else ptr = ptr->next;
        }
        SchoolYear* newschlyr = new SchoolYear(input);
        lastNode->next = newschlyr;

        system("cls");

        outFile.open("yearlist.csv", ios::app);
        if(outFile.is_open())
        {
            outFile << ',' << input;
        }
        outFile.close();
    }
    else
    {
        cout<<"(...) School year to add: ";  cin>>input;
        cout << endl;
        Hyear = new SchoolYear(input);
        outFile.open("yearlist.csv");
        if(outFile.is_open())
        {
            outFile << input;
        }
        outFile.close();
    }
    cout << " --------------------------------------------------" << endl;
    cout << "(.) You added the year of: " << input << '.' << endl;
    cout << " --------------------------------------------------" << endl;
    cout << endl << "Press any key to return...";
    system("pause"); 
    system("cls");
}

void AddClassToSchoolYear(SchoolYear* &tmpYear)
{
    system("cls");
    if(tmpYear == nullptr)
    {
        cout << "--------------------------------------------" << endl;
        cout << "(!) There is no school-year to add semester" << endl;
        cout << "--------------------------------------------" << endl;
        cout << endl << "Press any key to return...";
        system("pause");
        system("cls");
        return;
    }
    string input;
    Class* tmpClass = tmpYear->Hclass;
    Class* lastClass = nullptr;
    string className;
    cout << endl << "-----------------------------------------" << endl;
    cout << "(.) Classes in this year: " << endl;
    cout << "-----------------------------------------" << endl;
    if(tmpClass == nullptr)
    {
        cout << "\"No class\"" << endl;
        cout << "-----------------------------------------" << endl;
        cout << endl << "(...) Class to add: "; cin >> className;
    }
    else
    {
        int count = 0;
        while (tmpClass != nullptr)
        {
            count++;
            cout << '-' << tmpClass->class_name << '-';
            if(count % 3 == 0) cout << endl;
            else cout << "      ";
            lastClass = tmpClass;
            tmpClass = tmpClass->next;
        }
        if(count % 3 != 0) cout << endl;
        cout << "-----------------------------------------" << endl;
        tmpClass = tmpYear->Hclass;
        cout << endl << "(...) Name of class to add: ";  cin >> className;
        while (tmpClass != nullptr)
        {
            if(tmpClass->class_name == className)
            {
                cout << "(!) This class is already in the school year." << endl;
                cout << "(?) Do you want to try again (Y/y for yes - others for no): "; cin >> input;
                if(input != "Y" && input != "y")
                {
                    system("cls");
                    cout << "--------------------------------------------" << endl;
                    cout << "(!) You added no class to the school year." << endl;
                    cout << "--------------------------------------------" << endl;
                    cout << endl << "Press any key to return...";
                    system("pause");
                    system("cls");
                    return;
                }
                else
                {
                    cout << endl << "(...) Try another class's name: "; cin >> className;
                    tmpClass = tmpYear->Hclass;
                }
            }
            else tmpClass = tmpClass->next;
        }
    }     
    tmpClass = new Class(className);
    if(lastClass != nullptr) lastClass->next = tmpClass;
    else tmpYear->Hclass = tmpClass;
    system("cls");
    cout << "------------------------------------------------------------------------------------------" << endl;
    cout << "(.) You added class " << className << "to the school-year of " << tmpYear->year << '.' << endl;
    cout << "------------------------------------------------------------------------------------------" << endl;
    cout << endl << "Press any key to return...";
    system("pause");
    system("cls");
}

void AddSemesterToSchoolYear(SchoolYear* &tmpYear)
{
    system("cls");
    if(tmpYear == nullptr)
    {
        cout << "--------------------------------------------" << endl;
        cout << "(!) There is no school year to add semester." << endl;
        cout << "--------------------------------------------" << endl;
        cout << endl << "Press any key to return...";
        system("pause");
        system("cls");
        return;
    }
    string input;
    Semester* tmpSemes = tmpYear->Hsemester;
    string season, startDate, endDate;
    Semester* lastSemes = nullptr;
    cout << endl;
    cout << "-----------------------------------------" << endl;
    cout << "(.) Semesters/seasons in this year: " << endl;
    cout << "-----------------------------------------" << endl;
    if(tmpSemes == nullptr)
    {
        cout << "\"No Semester\"" << endl;
        cout << "-----------------------------------------" << endl;
        cout << endl << "(...) Season to add (1, 2 or 3): "; cin >> season; 
        while (stoi(season) > 3 || stoi(season) < 1)
        {
            cout << endl << "(!) Wrong input." << endl;
            cout << "(...) Try again with [1, 2 or 3]: "; cin >> season;
        }
        if(stoi(season) == 1) season = "1";
        else if(stoi(season) == 2) season = "2";
        else if(stoi(season) == 3) season = "3";
    }
    else
    {
        int count = 0;
        while (tmpSemes != nullptr)
        {
            count++;
            cout << '-' << tmpSemes->season << '-';
            if(count % 3 == 0) cout << endl;
            else cout << "      ";
            lastSemes = tmpSemes;
            tmpSemes = tmpSemes->next;
        }
        if(count%3 != 0) cout << endl;
        cout << "-----------------------------------------" << endl;
        tmpSemes = tmpYear->Hsemester;
        cout << endl << "(...) Season to add (1, 2 or 3): ";  cin >> season;
        while (stoi(season) > 3 || stoi(season) < 1)
        {
            cout << endl << "(!) Wrong input." << endl;
            cout << "(...) Try again with [1, 2 or 3]: "; cin >> season;
        }
        if(stoi(season) == 1) season = "1";
        else if(stoi(season) == 2) season = "2";
        else if(stoi(season) == 3) season = "3";
        while (tmpSemes != nullptr)
        {
            if(tmpSemes->season == season)
            {
                cout << "(!) This season is already in the school year." << endl;
                cout << "(?) Do you want to try again (Y/y for yes - others for no): "; cin >> input;
                cout << endl;
                if(input != "Y" && input != "y")
                {
                    system("cls");
                    cout << "----------------------------------------------" << endl;
                    cout << "(!) You added no semester to the school year." << endl;
                    cout << "----------------------------------------------" << endl;
                    cout << endl << "Press any key to return...";
                    system("pause");
                    system("cls");
                    return;
                }
                else
                {
                    cout << endl << "(...) Try another season(1, 2 or 3): "; cin >> season;
                    while (stoi(season) > 3 || stoi(season) < 1)
                    {
                        cout << endl << "(!) Wrong input." << endl;
                        cout << "(...) Try again with [1, 2 or 3]: "; cin >> season;
                    }
                    if(stoi(season) == 1) season = "1";
                    else if(stoi(season) == 2) season = "2";
                    else if(stoi(season) == 3) season = "3";
                    tmpSemes = tmpYear->Hsemester;
                }
            }
            else tmpSemes = tmpSemes->next;
        }
    }  
    system("cls");
    cout << "(.) Season to add: " << season << endl;   
    cout << "(...) Start date of this semester: "; cin >> startDate;
    cout << "(...) End date of this semester: "; cin >> endDate;
    cout << endl;
    tmpSemes = new Semester(season, tmpYear->year, startDate, endDate);
    if(lastSemes != nullptr) lastSemes->next = tmpSemes;
    else tmpYear->Hsemester = tmpSemes;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << "(.) You added a semester season " << season << "to the school year of " << tmpYear->year << '.' << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << endl << "Press any key to return...";
    system("pause");
    system("cls");
}

void AddCourseToSemester(Semester* &tmpSemes) //Need to fix
{
    system("cls");
    if(tmpSemes == nullptr)
    {
        cout << "--------------------------------------------" << endl;
        cout << "(!) There is no semester to add course." << endl;
        cout << "--------------------------------------------" << endl;
        cout << endl << "Press any key to return...";
        system("pause");
        system("cls");
        return;
    }
    string input;
    Course* tmpCourse = tmpSemes->Hcourse;
    Course* lastCourse = nullptr;
    string cID, cName, clName, tName, nCredit, capacity, dei, ses;
    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << "(.) Courses in this semester: " << endl;
    cout << "--------------------------------------------" << endl;
    if(tmpCourse == nullptr)
    {
        cout << "\"No Course\"" << endl;
        cout << "--------------------------------------------" << endl;
        cout << endl << "(...) Course's ID to add: "; cin >> cID;
    }
    else
    {
        int count = 0;
        while (tmpCourse != nullptr)
        {
            count++;
            cout << '-' << tmpCourse->course_id << '-';
            if(count % 3 == 0) cout << endl;
            else cout << "      ";
            lastCourse = tmpCourse;
            tmpCourse = tmpCourse->next;
        }
        if(count % 3 != 0) cout << endl;
        cout << "--------------------------------------------" << endl;
        tmpCourse = tmpSemes->Hcourse;

        cout << endl << "(...) ID of the course to add: ";  cin >> cID;
        while (tmpCourse != nullptr)
        {
            if(tmpCourse->course_id == cID)
            {
                cout << "(!) This course ID is already in the semester." << endl;
                cout << "(?) Do you want to try again (Y/y for yes - others for no): "; cin >> input;
                if(input != "Y" && input != "y")
                {
                    system("cls");
                    cout << "-----------------------------------------" << endl;
                    cout << "(!) You added no course to the semester." << endl;
                    cout << "-----------------------------------------" << endl;
                    cout << endl << "Press any key to return...";
                    system("pause");
                    system("cls");
                    return;
                }
                else
                {
                    cout << endl << "(...) Try another course ID: "; cin >> cID;
                    tmpCourse = tmpSemes->Hcourse;
                }
            }
            else tmpCourse = tmpCourse->next;
        } 
    }
    system("cls");
    cout << "(.) ID of the course to add: " << cID;
    cout << "(...) Course's name: "; cin >> cName;
    cout << "(...) Class's name: "; cin >> clName;
    cout << "(...) Teacher's name: ";  cin >> tName;
    cout << "(...) The number of credits: "; cin >> nCredit;
    cout << "(...) Capacity: "; cin >> capacity;
    cout << "(...) Day of week: ";  cin >> dei;
    cout << "(...) Session: "; cin >> ses;
 
    tmpCourse = new Course(cID, cName, clName, tName, nCredit, capacity, dei, ses);
    if(lastCourse != nullptr) lastCourse->next = tmpCourse;
    else tmpSemes->Hcourse = tmpCourse;
    cout << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "(.) You added a course with ID " << cID << "to the semester season " << tmpSemes->season << ", year " << tmpSemes->school_year << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl << "Press any key to return...";
    system("pause");
    system("cls");
}

void AddStudentToClass(Class* &tmpClass)
{
    system("cls");
    if(tmpClass == nullptr)
    {
        cout << "-----------------------------------------" << endl;
        cout << "(!) There is no class to add student.";
        cout << "-----------------------------------------" << endl;
        cout << endl << "Press any key to return...";
        system("pause");
        system("cls");
        return;
    }   
    string input;
    Student* tmpStu = tmpClass->Hstudent;
    Student* lastStudent = nullptr;
    string stuId;
    cout << endl;
    cout << "-----------------------------------------" << endl;
    cout << "(.) Student's IDs in this class: " << endl;
    cout << "-----------------------------------------" << endl;
    if(tmpStu == nullptr)
    {
        cout << "\"No Student\"" << endl;
        cout << "-----------------------------------------" << endl;
        cout << endl << "(...) Student's ID to add: "; cin >> stuId;
    }
    else
    {
        int count = 0;
        while (tmpStu != nullptr)
        {
            count++;
            cout << '-' << tmpStu->student_id << '-';
            if(count % 3 == 0) cout << endl;
            else cout << "      ";
            lastStudent = tmpStu;
            tmpStu = tmpStu->next;
        }
        if(count % 3 != 0) cout << endl;
        cout << "-----------------------------------------" << endl;
        tmpStu = tmpClass->Hstudent;
        cout << endl << "(...) Student's ID to add: "; cin >> stuId;
        while (tmpStu != nullptr)
        {
            if(tmpStu->student_id == stuId)
            {
                cout << "(!) This student ID is already in this class." << endl;
                cout << "(?) Do you want to try again (Y/y for yes - other keys for no): "; cin >> input;
                if(input != "Y" && input != "y")
                {
                    system("cls");
                    cout << "-----------------------------------------" << endl;
                    cout << "(!) You add no student to this class.";
                    cout << "-----------------------------------------" << endl;
                    cout << endl << "Press any key to return...";
                    system("pause");
                    system("cls");
                    return;
                }
                else
                {
                    cout << endl << "(...) Try another student's ID: "; cin >> stuId;
                    tmpStu = tmpClass->Hstudent;
                }
            }
            else tmpStu = tmpStu->next;
        }
    }
    system("cls");
    string fName, lName, gder, birth, socialId;
    cout << "(.) Student's ID to add: " << stuId;
    cout << "(...) First Name: "; cin >> fName;
    cout << "(...) Last Name: "; cin >> lName;
    cout << "(...) Gender: "; cin >> gder;
    cout << "(...) Birth Date:  "; cin >> birth;
    cout << "(...) Social ID: "; cin >> socialId;
    cout << endl;
    tmpStu = new Student(tmpClass->class_name, stuId, fName, lName, gder, birth, socialId);
    if(lastStudent != nullptr) lastStudent->next = tmpStu;
    else tmpClass->Hstudent = tmpStu;
    cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "(.) You added " << tmpStu->fullName() << "with the ID of " << stuId << "to class " << tmpClass->class_name << '.' << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl << "Press any to return...";
    system("pause");
    system("cls");
}

void AddStudentToCourse(Course* &tmpCourse)
{
    system("cls");
    if(tmpCourse == nullptr)
    {
        cout << "------------------------------------------------" << endl;
        cout << "(!) There is no course to add a student to."<<endl;
        cout << "------------------------------------------------" << endl;
        cout << endl << "Press any key to return...";
        system("pause");
        system("cls");
        return;
    }
    string input;
    Scoreboard* tmpStu = tmpCourse->Hscore;
    Scoreboard* lastStudent = nullptr;
    cout << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Student's IDs in this course: " << endl;
    cout << "------------------------------------------------" << endl;
    if(tmpStu == nullptr)
    {
        cout << "\"No Student\"" << endl;
        cout << "------------------------------------------------" << endl;
        cout << endl << "(...) Student's to add: "; cin >> input;
    }
    else
    {
        int count = 0;
        while (tmpStu != nullptr)
        {
            count++;
            cout << '-' << tmpStu->student_id << '-';
            if(count % 3 == 0) cout << endl;
            else cout << "      ";
            lastStudent = tmpStu;
            tmpStu = tmpStu->next;
        }
        if(count % 3 != 0) cout << endl;
        cout << "------------------------------------------------" << endl;
        tmpStu = tmpCourse->Hscore;
        cout << endl << "(...) Student's ID to add: "; cin >> input;
        while (tmpStu != nullptr)
        {
            if(tmpStu->student_id == input)
            {
                cout << "(!) The student is already in the course." <<endl;
                cout << "(?)Do you want to add a different student (Y/y for yes - others for no): "; cin >> input;
                if(input != "Y" && input != "y")
                {
                    system("cls");
                    cout << "-----------------------------" << endl;
                    cout << "(!) You added no student." << endl;
                    cout << "-----------------------------" << endl;
                    cout << endl << "Press any key to return...";
                    system("pause");
                    system("cls");
                    return;
                }
                else
                {
                    cout << endl << "(...) Try another student's ID: "; cin >> input;
                    tmpStu = tmpCourse->Hscore;
                }
            }
            else tmpStu = tmpStu->next;
        }
    }
    system("cls");
    cout << "(.) Student's ID to add: " << input << endl;
    tmpStu = new Scoreboard(input);
    if(lastStudent != nullptr) lastStudent->next = tmpStu;
    else tmpCourse->Hscore = tmpStu;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << "(.) You added this student's ID: " << input << "to " << tmpCourse->course_name << '.' << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << endl << "Press any key to return...";
    system("pause");
    system("cls");
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
    SchoolYear* Hschyear = nullptr;
    //creates newSchoolyear
    ifstream inFile("input/schoolyear/"+fileName + ".csv");
    if (!inFile.is_open())
    {
        cout<<"failed to open "<<fileName<<".csv"<<endl;
        return nullptr;
    }
    SchoolYear* newyear = new SchoolYear(fileName);
    SchoolYear* pyear;
    if (!Hschyear)
    {
        Hschyear = newyear;
        pyear = Hschyear;
    }
    else
    {
        pyear->next = newyear;
        pyear = newyear;
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
            Class* pclass;
            newclass->Hstudent = ImportStudents(className);
            if (!Hschyear->Hclass)
            {
                Hschyear->Hclass = newclass;
                pclass = Hschyear->Hclass;
            }
            else
            {
                pclass->next = newclass;
                pclass = newclass;
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
        Course* pcourse;

        if(!Hcourse)
        {
            Hcourse = newCourse;
            pcourse = Hcourse;
        }
        else
        {
            pcourse->next = newCourse;
            pcourse = newCourse;
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
        string season, year, begin, end;
        getline(ss,season,',');
        getline(ss,year,',');
        getline(ss,begin,',');
        getline(ss,end,',');

        Semester* newsemester = new Semester(season, year, begin, end);
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
        Scoreboard* pscore;
        newscoreB->full_name = std_name;
        newscoreB->midterm = std::stof(mid);
        newscoreB->finalterm = std::stof(final);
        newscoreB->other = std::stof(othr);

        if (!Hcourse->Hscore)
        {
            Hcourse->Hscore = newscoreB;
            pscore = Hcourse->Hscore;
        }
        else
        {
            pscore->next = newscoreB;
            pscore = newscoreB;
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
    system("cls");
    if(Hcourse == nullptr)
    {
        cout << "----------------------------------------------------" << endl;
        cout << "(!) There is no course to update student's result.";
        cout << "----------------------------------------------------" << endl;
        cout << endl << "Press any key to return...";
        system("pause");
        system("cls");
        return;
    }
    Course* tmpCourse = Hcourse;
    cout << "----------------------------------------------------" << endl;
    cout << "(.) Available courses: " << endl;
    cout << "----------------------------------------------------" << endl;
    int count = 0;
    while (tmpCourse != nullptr)
    {
        count++;
        cout << '-' << tmpCourse->course_id << '-';
        if(count % 3 == 0) cout << endl;
        else cout << "      ";
        tmpCourse = tmpCourse->next;
    }
    if(count % 3 != 0) cout << endl;
    cout << "----------------------------------------------------" << endl;
    tmpCourse = Hcourse;
    string input;
    cout << endl << "(...) Course's ID to update its student's result: "; cin >> input;
    while (true)
    {
        if(input == tmpCourse->course_id) break;
        tmpCourse = tmpCourse->next;
        if(tmpCourse == nullptr)
        {
            cout << "(!) The course you want is invalid.";
            cout << "(?) Do you want to try again (Y/y for yes - other keys for no): "; cin >> input;
            if(input != "Y" && input != "y")
            {
                system("cls");
                cout << "----------------------------------------------------" << endl;
                cout << "(!) You chose not to update any student.";
                cout << "----------------------------------------------------" << endl;
                cout << endl << "Press any key to return...";
                system("pause");
                system("cls");
                return;
            }
            else
            {
                cout << endl << "(...) Try another course's ID: "; cin >> input;
                tmpCourse = Hcourse;
            }
        }
    }
    if(tmpCourse->Hscore == nullptr)
    {
        system("cls");
        cout << "----------------------------------------" << endl;
        cout << "(!) There is no student to update.";
        cout << "----------------------------------------" << endl;
        cout << endl << "Press any key to return...";
        system("pause");
        system("cls");
        return;
    }
    cout << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "(.) IDs of students in this course: " << endl;
    cout << "----------------------------------------------------" << endl;
    count = 0;
    Scoreboard* tmpSB = tmpCourse->Hscore;
    while (tmpSB != nullptr)
    {
        count++;
        cout << '-' << tmpSB->student_id << '-';
        if(count % 3 == 0) cout << endl;
        else cout << "      ";
        tmpSB = tmpSB->next;
    }
    if(count % 3 != 0) cout << endl;
    cout << "----------------------------------------------------" << endl;
    tmpSB = tmpCourse->Hscore;
    cout << endl << "(...) Student's ID to update results: "; cin >> input;
    while (true)
    {
        if(tmpSB->student_id == input) break;
        tmpSB = tmpSB->next;
        if(tmpSB == nullptr)
        {
            cout << "(!) The student you want is not in this class.";
            cout << "(?) Do you want to try again (Y/y for yes - other keys for no): "; cin >> input;
            if(input != "Y" && input != "y")
            {
                system("cls");
                cout << "----------------------------------------------------" << endl;
                cout << "(!) You chose not to update any student.";
                cout << "----------------------------------------------------" << endl;
                cout << endl << "Press any key to return...";
                system("pause");
                system("cls");
                return;
            }
            else
            {
                cout << endl << "(...) Try another student's ID: "; cin >> input;
                tmpSB = tmpCourse->Hscore;
            }
        }
    }
    system("cls");
    cout << "(.) Student's ID to update results: " << input;
    float midT, finalT, otherT;
    cout << "(.) Type in the student's result: " << endl;
    cout << "(...) Midterm Result: "; cin >> midT; 
    cout << "(...) Finalterm Result: "; cin >> finalT;
    cout << "(...) Other results: "; cin >> otherT;
    tmpSB->midterm = midT;
    tmpSB->finalterm = finalT;
    tmpSB->other = otherT;
    cout << endl;
    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
    cout << "(.) You have updated successfully results of student with the ID: " << tmpSB->student_id << '.' << endl;
    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
    cout << endl << "Press any key to return...";
    system("pause");
    system("cls");
}