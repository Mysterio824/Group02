#include "header.h"

//start the program (import all the data)
void startProgram (Student* &listStudents, Course* &listCourses, Class* &listClasses, SchoolYear* &listSchoolYears, Semester* &listSemesters)
{
    string stuList = "listOfStudents.csv";
    string classList = "listOfClasses.csv";
    string courseList = "listOfCourses.csv";
    string semesterList = "listOfSemesters.csv";
    string yearList = "listOfSchoolYears.csv";

    listStudents = ImportStudents(stuList);
    listClasses = ImportClasses(classList);
    listCourses = ImportCourses(courseList);
    listSemesters = ImportSemesters(semesterList);
    listSchoolYears = ImportSchoolYears(yearList);
}