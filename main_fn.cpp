#include "header.h"

//importing all data of a chosen schoolyear
void startProgram(SchoolYear* &thisyear)
{
    string year = getCurrentYear();

    thisyear = ImportSchoolYears(year);
    thisyear->Hsemester = ImportSemesters(year);

    //semester pointer create
    Semester* currentSemes = thisyear->Hsemester;

    string courseName = "semester"+currentSemes->season;
    currentSemes->Hcourse = ImportCourses(courseName);
    cout<<"Database ready!"<<endl;
    return;
    //ImportSchoolYears() will also imports all classes & students that are listed in >schoolyear/school_year.csv
}