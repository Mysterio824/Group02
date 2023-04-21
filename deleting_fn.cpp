#include "header.h"
#include <LogInInterface.h>

void RemoveCourseFromSemester (SchoolYear* &thisyear)
{
    system("cls");
    string season, course_id;
    int x = 0, y = 0;
    gotoxy(x,y);
    cout << " -----------------------------------------" << endl;
    gotoxy(x, y + 1);
    cout << "| Season    |                             |" << endl;
    gotoxy(x, y + 2);
    cout << " -----------------------------------------" << endl;
    gotoxy(x, y + 3);
    cout << "| Course ID |                             |" << endl;
    gotoxy(x, y + 4);
    cout << " -----------------------------------------" << endl;
    gotoxy(x + 14, y + 1);
    cin>>season;
    gotoxy(x + 14, y + 3);
    cin >> course_id;
    gotoxy(x,y + 5);
    //season & courseID obtained
    Semester* psm = thisyear->Hsemester;
    while (psm)
    {
        if (psm->season == season)
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
            return;
        }
        psm = psm->next;
    }
    std::cout<<"Semester not found!"<<std::endl;
}
void RemoveStudentFromCourse (SchoolYear* &thisyear)
{
    system("cls");
    string std_id, course_id;
    int x = 0, y = 0;
    gotoxy(x,y);
    cout << " -----------------------------------------" << endl;
    gotoxy(x, y + 1);
    cout << "| Course ID   |                           |" << endl;
    gotoxy(x, y + 2);
    cout << " -----------------------------------------" << endl;
    gotoxy(x, y + 3);
    cout << "| Student ID  |                           |" << endl;
    gotoxy(x, y + 4);
    cout << " -----------------------------------------" << endl;
    gotoxy(x + 16, y + 1);
    cin >> course_id;
    gotoxy(x + 16, y + 3);
    cin>>std_id;
    gotoxy(x,y + 5);


    Course* pcourse = thisyear->Hsemester->Hcourse;
    while(pcourse){
        if(pcourse->course_id == course_id){
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
            return;
        }

        pcourse = pcourse->next;
    }
    std::cout<<"Coursse not found!"<<std::endl;
}
void RemoveStudentfromClass(SchoolYear* &thisyear)
{
    system("cls");
    string std_id, class_name;
    int x = 0, y = 0;
    gotoxy(x,y);
    cout << " -----------------------------------------" << endl;
    gotoxy(x, y + 1);
    cout << "| Class name  |                           |" << endl;
    gotoxy(x, y + 2);
    cout << " -----------------------------------------" << endl;
    gotoxy(x, y + 3);
    cout << "| Student ID  |                           |" << endl;
    gotoxy(x, y + 4);
    cout << " -----------------------------------------" << endl;
    gotoxy(x + 16, y + 1);
    cin >> class_name;
    gotoxy(x + 16, y + 3);
    cin>>std_id;
    gotoxy(x,y + 5);

    Class* pclass = thisyear->Hclass;
    while (pclass)
    {
        if (pclass->class_name == class_name)
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
            return;
        }
        pclass = pclass->next;
    }
    std::cout<<"Class not found!"<<std::endl;
}

void MemmoryRelease(SchoolYear* &thisyear)
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