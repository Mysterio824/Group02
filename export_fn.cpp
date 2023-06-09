#include "header.h"

void exportStudents (Class *listClass){
    if(!listClass) return;
    string fileName;
    while (listClass){
        Student *list = listClass->Hstudent;
        fileName =  listClass -> class_name;
        ofstream outputFile("input/classes/" + fileName + ".csv");
        if (!outputFile.is_open())
        {
            cout << "Error opening file" << endl;
            outputFile.close();
        }
        else{
            while (list)
            {
                outputFile << list->student_id << ",";
                outputFile << list->first_name << ",";
                outputFile << list->last_name << ",";
                outputFile << list->gender << ",";
                outputFile << list->birth_date << ",";
                outputFile << list->social_id << endl;
                list = list->next;
            }
            listClass = listClass -> next; 
            outputFile.close();
        }
    }
    cout << endl << "Your data have been updated successful!";
}

void exportClass (SchoolYear* thisyear){
    if(!thisyear) return;
    ofstream outputFile("input/schoolyear/" + thisyear->year + ".csv");
    if (!outputFile.is_open())
    {
        cout << "Error opening file" << endl;
        return;
    }
    Class *list = thisyear->Hclass;
    while (list)
    {
        outputFile << list->class_name << ",";
        list = list->next;
    }
    cout << endl << "Your data have been added successful!";
    outputFile.close();
}

void exportScoreBoard (Course *list){
    if(!list) return;
    string fileName = list -> course_id;
    ofstream outputFile(fileName + ".csv");
    if (!outputFile.is_open())
    {
        cout << "Error opening file" << endl;
        return;
    }
    Scoreboard *ref = list -> Hscore;
    while (ref)
    {
        outputFile << ref -> student_id << ",";
        outputFile << ref -> full_name << ",";
        outputFile << (ref -> other > 0 ? ref -> other:'x') << ",";
        outputFile << (ref -> midterm > 0 ? ref -> midterm:'x') << ",";
        outputFile << (ref -> finalterm > 0 ? ref -> finalterm:'x') << endl;
        ref = ref->next;
    }
    cout << endl << "Your data have been added successful!";
    outputFile.close();
}

void exportCourse(Semester *smt){
    if(!smt) return;
    ofstream outputFile("input/courses/" + smt->school_year + smt->season + ".csv");
    if (!outputFile.is_open())
    {
        cout << "Error opening file" << endl;
        return;
    }
    Course* list = smt->Hcourse;
    while (list)
    {
        outputFile << list->course_id << ",";
        outputFile << list->course_name << ",";
        outputFile << list->class_name << ",";
        outputFile << list->teacher_name << ",";
        outputFile << list->num_credits << ",";
        outputFile << list->capacity << ",";
        outputFile << list->day << ",";
        outputFile << list->session << endl;
        list = list->next;
    }
    cout << endl << "Your data have been added successful!";
    outputFile.close();
}

void exportSchoolYear (SchoolYear *list){
        if(!list) return;
    ofstream outputFile("listOfSchoolYear.csv");
    if (!outputFile.is_open())
    {
        cout << "Error opening file" << endl;
        return;
    }
    while (list)
    {
        outputFile << list->year << ",";
        outputFile << list->semes_count << ",";
        outputFile << list -> semes_num << endl;
        list = list->next;
    }
    cout << endl << "Your data have been added successful!";
    outputFile.close();
}
