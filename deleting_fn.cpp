#include "header.h"
#include "userInterface.h"

void RemoveCourseFromSemester (Semester *&thisSem)
{
    system("cls");
    string course_id;
    int x = 0, y = 0;
    gotoxy(x,y);
    cout << " -----------------------------------------" << endl;
    gotoxy(x, y + 1);
    cout << "| Course ID:  |                             |" << endl;
    gotoxy(x, y + 2);
    cout << " -----------------------------------------" << endl;
    gotoxy(x + 16, y + 1);
    cin>>course_id;
    gotoxy(x,y + 4);
    // courseID obtained
    Semester* psm = thisSem;
    while (psm)
    {
            Course* pcourse = psm->Hcourse;
            while(pcourse){
                if(pcourse->course_id == course_id){
                    psm->Hcourse = pcourse->next;
                    delete pcourse;
                    std::cout<<"Course removed!"<<std::endl;
                    return;
                }
                pcourse = pcourse->next;
            }
            std::cout<<"Course not found!"<<std::endl;
    }
}
void RemoveStudentFromCourse (Course *&thisCourse)
{
    system("cls");
    string std_id;
    int x = 0, y = 0;
    gotoxy(x,y);
    cout << " -----------------------------------------" << endl;
    gotoxy(x, y + 1);
    cout << "| Student ID:  |                           |" << endl;
    gotoxy(x, y + 2);
    cout << " -----------------------------------------" << endl;
    gotoxy(x + 16, y + 1);
    cin >> std_id;
    gotoxy(x,y + 3);

    Course* pcourse = thisCourse;
    while(pcourse){
        Scoreboard* pscore = pcourse->Hscore;
        while(pscore){
            if(pscore->student_id == std_id){
                pcourse->Hscore = pscore->next;
                delete pscore;
                std::cout<<"Student removed!"<<std::endl;
                return;
            }
            pscore = pscore->next;
        }
        std::cout<<"Student not found!"<<std::endl;
    }
}
void RemoveStudentfromClass(Class *&thisClass)
{

    system("cls");
    string std_id;
    int x = 0, y = 0;
    gotoxy(x,y);
    cout << " -----------------------------------------" << endl;
    gotoxy(x, y + 1);
    cout << "| Student ID: |                           |" << endl;
    gotoxy(x, y + 2);
    cout << " -----------------------------------------" << endl;
    gotoxy(x, y + 3);
    gotoxy(x + 16, y + 1);
    cin >> std_id;
    gotoxy(x,y + 4);

    Class* pclass = thisClass;
    while (pclass)
    {
            Student* pstd = pclass->Hstudent;

            while (pstd)
            {
                if (pstd->student_id == std_id)
                {
                    pclass->Hstudent = pstd->next;
                    delete pstd;
                    std::cout<<"Student removed!"<<std::endl;
                    return;
                }
                pstd = pstd->next;
            }
            std::cout<<"Student not found!"<<std::endl;
    }
}

void MemoryRelease(SchoolYear* &thisyear)
{
    Class* pclass = thisyear->Hclass;
    while (pclass)
    {
        Student* pstd = pclass->Hstudent;
        while (pstd)
        {
            Student* pstd2 = pstd->next;
            delete pstd;
            pstd = pstd2;
        }
        Class* pclass2 = pclass->next;
        delete pclass;
        pclass = pclass2;
    }
    Semester* psm = thisyear->Hsemester;
    while (psm)
    {
        Course* pcourse = psm->Hcourse;
        while (pcourse)
        {
            Scoreboard* pscore = pcourse->Hscore;
            while (pscore)
            {
                Scoreboard* pscore2 = pscore->next;
                delete pscore;
                pscore = pscore2;
            }
            Course* pcourse2 = pcourse->next;
            delete pcourse;
            pcourse = pcourse2;
        }
        Semester* psm2 = psm->next;
        delete psm;
        psm = psm2;
    }
    delete thisyear;
}