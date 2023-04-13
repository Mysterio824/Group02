#include "header.h"

//importing all data of a chosen schoolyear
void startProgram(SchoolYear* &thisyear)
{
    string year = getCurrentYear();

    thisyear = ImportSchoolYears(year);
    thisyear->Hsemester = ImportSemesters(year);

    //semester pointer create
    Semester* currentSemes = thisyear->Hsemester;
    Course* pcourse = nullptr;
    while(currentSemes)//iterate through semesters
    {
        string courseName = "semester"+currentSemes->season;//get filename semester#.csv
        currentSemes->Hcourse = ImportCourses(courseName);//import courses
        pcourse = currentSemes->Hcourse;
        while (pcourse)
        {
            pcourse->Hscore = ImportScoreboard(pcourse);//import scoreboards
            pcourse = pcourse->next;
        }
        currentSemes = currentSemes->next;
    }
    cout<<"Database ready!"<<endl;
    return;
    //ImportSchoolYears() will also imports all classes & students that are listed in >schoolyear/school_year.csv
}

void SaveChosenYear(SchoolYear* thisyear)
{
    ofstream ofs("input/schoolyear/" + thisyear->year + ".csv");
    if (!ofs.is_open())
    {
        cout<<"Saving failed > Could not open "<<thisyear->year<<".csv";
        return;
    }

    //saving all classes to chosen schoolyear
    Class* pclass = thisyear->Hclass;
    while (pclass)
    {
        ofs<<pclass->class_name<<",";
        pclass = pclass->next;
    }
    ofs.close();

    //saving all students to classes
    pclass = thisyear->Hclass;//points to class
    Student* pstu = pclass->Hstudent;//points to pclass' students = [nullptr]

    while (pclass)
    {
        //open input/classes/className.csv for saving students
        ofs.open("input/classes/" + pclass->class_name + ".csv");
        if (!ofs.is_open())
        {
            cout<<"Saving failed > Could not open"<<pclass->class_name<<".csv\n";
            return;
        }
        //iteration
        pstu = pclass->Hstudent;
        while (pstu)
        {
            ofs<<pstu->student_id<<","<<pstu->first_name<<","<<pstu->last_name<<","<<pstu->gender<<","<<pstu->birth_date<<","<<pstu->social_id<<"\n";
            pstu = pstu->next;
        }
        pclass = pclass->next;
        ofs.close();
    }

    //save all semesters
    Semester* psemes = thisyear->Hsemester;
    ofs.open("input/semesters/" + thisyear->year + ".csv");
    if (!ofs.is_open())
    {
        cout<<"Saving failed > Could not open"<<thisyear->year<<".csv\n";
        return;
    }
    while (psemes)
    {
        ofs<<psemes->season<<","<<psemes->school_year<<","<<psemes->start_date<<","<<psemes->end_date<<"\n";
        psemes = psemes->next;
    }
    ofs.close();
    //save all courses
    psemes = thisyear->Hsemester;
    Course* pcourse = nullptr;
    Scoreboard* pscore = nullptr;
    ofstream scoreB;
    while (psemes)//saving courses & scoreboards in courses
    {
        pcourse = psemes->Hcourse;
        string courseName = "semester"+psemes->season; //semester01,semester02
        ofs.open("input/courses/" + courseName + ".csv");
        if (!ofs.is_open())
        {
            cout<<"Saving failed > could not open"<<courseName<<".csv\n";
            return;
        }
        while(pcourse)//saving courses & scoreboards in courses
        {
            ofs<<pcourse->course_id<<","<<pcourse->course_name<<","<<pcourse->class_name<<","<<pcourse->teacher_name<<","<<pcourse->num_credits<<","<<pcourse->capacity<<","<<pcourse->day<<","<<pcourse->session<<'\n';
            pscore = pcourse->Hscore;
            while (pscore)//iterates scoreboards in course
            {
                scoreB.open("input/scoreboard/" + pcourse->course_id + ".csv");
                if (!scoreB.is_open())
                {
                    cout<<"Saving failed > could not open"<<pcourse->course_id<<".csv\n";
                    return;
                }
                scoreB<<pscore->student_id<<","<<pscore->full_name<<","<<pscore->midterm<<","<<pscore->finalterm<<","<<pscore->other<<"\n";
                pscore = pscore->next;
            }
            pcourse = pcourse->next;
        }
        ofs.close();
        psemes = psemes->next;
    }
}