#include "header.h"

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