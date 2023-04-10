#include "header.h"

void RemoveCourseFromSemester (SchoolYear* &thisyear)
{
    std::string season;
    std::cout<<"Season: ";
    std::cin>>season;
    Semester* psm = thisyear->Hsemester;
    while (psm)
    {
        if (psm->season == season)
        {
            std::string course_id;
            std::cout<<"Course ID: ";
            std::cin>>course_id;
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
    std::string course_id;
    std::cout<<"Course ID: ";
    std::cin>>course_id;

    Course* pcourse = thisyear->Hsemester->Hcourse;
    while(pcourse){
        if(pcourse->course_id == course_id){
            Scoreboard* pscore = pcourse->Hscore;
            std::string std_id;
            std::cout<<"Student ID to remove: ";
            std::cin>>std_id;
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
    std::string class_name;
    std::cout<<"Class name: ";
    std::cin>>class_name;
    Class* pclass = thisyear->Hclass;
    while (pclass)
    {
        if (pclass->class_name == class_name)
        {
            Student* pstd = pclass->Hstudent;
            std::string std_id;
            std::cout<<"Student ID to delete: ";
            std::cin>>std_id;
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