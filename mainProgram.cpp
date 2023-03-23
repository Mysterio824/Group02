#include "mainProgram.h"


void Course::AddClass()
{
    int n;
    std::cout << "How many classes you want to add? ";
    std::cin >> n;
    
    std::string className;
    Class* newClass;
    for(int i = 1; i <= n; i++)
    {
        std::cout << i << ". Class? ";
        std::cin >> className;
        
        newClass = new Class(className);
        
        if(classes == nullptr) classes = newClass;
        else classes->next = newClass;
        
        newClass = newClass->next;
    }
}

void Class::AddStudent(string fileName)
{
    ifstream file(fileName);
    if(!file.is_open())
    {
        std::cout << "Cannot open " << fileName << std::endl;
        return;
    }
    
    Student* stu;
    string line;
    while (getline(file, line)){
        stringstream ss(line);
        string no, student_id, last_name, first_name, gender, birth_date, social_id ;
        getline(ss, no , ',');
        getline(ss, student_id, ',');
        getline(ss, first_name, ',');
        getline(ss, last_name, ',');
        getline(ss, gender, ',');
        getline(ss, birth_date, ',');
        getline(ss, social_id, ',');
        Student *newStudent = createStudent(no, student_id, first_name, last_name, gender, birth_date, social_id);
        addStudentToList (stu, newStudent);
    }
    file.close();
}
Student* createStudent(string No, string student_id, string first_name, string last_name, string gender, string birth_date, string social_id){ 
    Student* newStudent = new Student;
    newStudent -> No = No;
    newStudent -> student_id = student_id;
    newStudent -> first_name = first_name;
    newStudent -> last_name = last_name;
    newStudent -> gender = gender;
    newStudent -> birth_date = birth_date;
    newStudent -> social_id = social_id;
    newStudent -> next = nullptr;
    return newStudent;
}

void addStudentToList(Student *&head, Student *newStudent){
    if (head == nullptr) {
        head = newStudent;
    } else {
        Student *cur = head;
        while (cur -> next != nullptr) {
            cur = cur -> next;
        }
        cur -> next = newStudent;
    }
}

