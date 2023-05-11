#include "header.h"
#include "userInterface.h"

void RemoveCourseFromSemester(Semester *&thisSem)
{
    system("cls");
    Course* chosen = printListCourse(thisSem -> Hcourse);
    // courseID obtained
    Semester *psm = thisSem;
    Course *pcourse = psm->Hcourse;
    if (pcourse->course_id == chosen -> course_id)
    {
        psm->Hcourse = psm->Hcourse->next;
        delete pcourse;
        std::cout << "Course removed!" << std::endl;
        return;
    }
    else
    {
        while (pcourse->next && pcourse-> next->course_id != chosen -> course_id)
            pcourse = pcourse->next;
        if (pcourse->next)
        {
            Course *tmp = pcourse->next;
            pcourse->next = pcourse->next->next;
            delete tmp;
            std::cout << "Course removed!" << std::endl;
            return;
        }
    }
    std::cout << "Course not found!" << std::endl;
}
void RemoveStudentFromCourse(Course *&thisCourse)
{
    system("cls");
    string std_id;
    int x = 0, y = 0;
    gotoxy(x, y);
    cout << " -----------------------------------------" << endl;
    gotoxy(x, y + 1);
    cout << "| Student ID:  |                           |" << endl;
    gotoxy(x, y + 2);
    cout << " -----------------------------------------" << endl;
    gotoxy(x + 16, y + 1);
    cin >> std_id;
    gotoxy(x, y + 3);

    Course *pcourse = thisCourse;
    Scoreboard *pstd = pcourse->Hscore;
    if (pstd->student_id == std_id)
    {
        pcourse->Hscore = pcourse->Hscore->next;
        delete pstd;
        std::cout << "Student removed!" << std::endl;
        return;
    }
    else
    {
        while (pstd->next && pstd->next->student_id != std_id)
            pstd = pstd->next;
        if (pstd->next)
        {
            Scoreboard *tmp = pstd->next;
            pstd->next = pstd->next->next;
            delete tmp;
            std::cout << "Student removed!" << std::endl;
            return;
        }
    }
    std::cout << "Student not found!" << std::endl;
}
void RemoveStudentFromClass(Class *&thisClass)
{

    system("cls");
    string std_id;
    int x = 0, y = 0;
    gotoxy(x, y);
    cout << " -----------------------------------------" << endl;
    gotoxy(x, y + 1);
    cout << "| Student ID: |                           |" << endl;
    gotoxy(x, y + 2);
    cout << " -----------------------------------------" << endl;
    gotoxy(x, y + 3);
    gotoxy(x + 16, y + 1);
    cin >> std_id;
    gotoxy(x, y + 4);

    Class *pclass = thisClass;

    Student *pstd = pclass->Hstudent;
    if (pstd->student_id == std_id)
    {
        pclass->Hstudent = pclass->Hstudent->next;
        delete pstd;
        std::cout << "Student removed!" << std::endl;
        return;
    }
    else
    {
        while (pstd->next && pstd->next->student_id != std_id)
            pstd = pstd->next;
        if (pstd->next)
        {
            Student *tmp = pstd->next;
            pstd->next = pstd->next->next;
            delete tmp;
            std::cout << "Student removed!" << std::endl;
            return;
        }
    }
    std::cout << "Student not found!" << std::endl;
}

void MemoryRelease(SchoolYear *&thisyear)
{
    Class *pclass = thisyear->Hclass;
    while (pclass)
    {
        Student *pstd = pclass->Hstudent;
        while (pstd)
        {
            Student *pstd2 = pstd->next;
            delete pstd;
            pstd = pstd2;
        }
        Class *pclass2 = pclass->next;
        delete pclass;
        pclass = pclass2;
    }
    Semester *psm = thisyear->Hsemester;
    while (psm)
    {
        Course *pcourse = psm->Hcourse;
        while (pcourse)
        {
            Scoreboard *pscore = pcourse->Hscore;
            while (pscore)
            {
                Scoreboard *pscore2 = pscore->next;
                delete pscore;
                pscore = pscore2;
            }
            Course *pcourse2 = pcourse->next;
            delete pcourse;
            pcourse = pcourse2;
        }
        Semester *psm2 = psm->next;
        delete psm;
        psm = psm2;
    }
    delete thisyear;
}