#include "header.h"

//importing all data of a chosen schoolyear
void startProgram(SchoolYear* &thisyear, string getyear)
{
    thisyear = ImportSchoolYears(getyear);
    if(!thisyear || getyear == "") return;
    thisyear->Hsemester = ImportSemesters(thisyear->year);

    //semester pointer create
    Semester* currentSemes = thisyear->Hsemester;
    Course* pcourse = nullptr;
    while(currentSemes)//iterate through semesters
    {
        string courseName = thisyear->year + "-" + currentSemes->season;//get filename year+#semester.csv
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
    if(!thisyear || !(thisyear->Hclass) || !(thisyear->Hsemester)) return;
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
    //saving courses
    while (psemes)
    {
        string courseName = thisyear->year + "-" + psemes->season;//get filename year+#semester.csv
        ofs.open("input/courses/" + courseName + ".csv");
        if (!ofs.is_open())
        {
            cout<<"Saving failed > Could not open input/courses/"<<courseName<<".csv\n";
            return;
        }
        pcourse = psemes->Hcourse;
        while (pcourse)
        {
            ofs<<pcourse->course_id<<","<<pcourse->course_name<<","<<pcourse->class_name<<","<<pcourse->teacher_name<<","
            <<pcourse->num_credits<<","<<pcourse->capacity<<","<<pcourse->day<<","<<pcourse->session<<"\n";
            //saving scoreboards
            scoreB.open("input/scoreboard/" + pcourse->course_id + ".csv");
            if (!scoreB.is_open())
            {
                cout<<"Saving failed > Could not open input/scoreboard/"<<pcourse->course_id<<".csv\n";
                return;
            }
            pscore = pcourse->Hscore;
            while (pscore)
            {
                scoreB<<pscore->student_id<<","<<pscore->full_name<<","<<pscore->midterm<<","<<pscore->finalterm<<","<<pscore->other<<"\n";
                pscore = pscore->next;
            }
            scoreB.close();
            pcourse = pcourse->next;
        }
        ofs.close();
        psemes = psemes->next;
    }
    ifstream ifs("input/yearlist.csv");
    string line;
    while (!ifs.eof())
    {
        while (getline(ifs, line))
        {
            stringstream ss(line);
            string temp;
            while (getline(ss,temp,','))
                if (temp == thisyear->year)
                {
                    ifs.close();
                    return;
                }
        }
    }
    ofs.open("input/yearlist.csv", ios::app);
    ofs<<thisyear->year<<',';
    ofs.close();
}

//----------------get school year------------------------

bool isInRange(string curr, string start, string end) {
    stringstream sscur(curr);
    stringstream ssstart(start);
    stringstream ssend(end);

    string curday, curmonth;
    string startday, startmonth;
    string endday, endmonth;

    getline(sscur, curday, '/');
    getline(sscur, curmonth, '/');
    getline(ssstart, startday, '/');
    getline(ssstart, startmonth, '/');
    getline(ssend, endday, '/');
    getline(ssend, endmonth, '/');

    //in range
    if (stoi(startmonth) < stoi(curmonth) && stoi(curmonth) < stoi(endmonth)) // start < cur < end
        return true;

    if (stoi(curmonth) == stoi(startmonth) && stoi(curmonth) < stoi(endmonth)) // start == cur < end
        if (stoi(curday) >= stoi(startday))
            return true;

    if (stoi(curmonth) > stoi(startmonth) && stoi(curmonth) == stoi(endmonth)) // start > cur == end
        if (stoi(curday) <= stoi(endday))
            return true;

    if (stoi(curmonth) == stoi(startmonth) && stoi(curmonth) == stoi(endmonth))//start == cur == end
        if (stoi(curday) >= stoi(startday) && stoi(curday) <= stoi(endday))
            return true;
    //out of range
    return false;
}

string getCurrentYear()
{
    string year;
    int tmp;
    time_t t = time(nullptr);
    tm *const pTInfo = localtime(&t);
    tmp = 1900 + pTInfo->tm_year;
    if(!checkCurrentYear("01/09", "31/12"))
        year = to_string(tmp-1) + "-" + to_string(tmp);
    else    
        year = to_string(tmp) + "-" + to_string(tmp+1);
    return year;
}

bool checkCurrentYear(string start, string end)
{

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    stringstream ss;
    ss << setfill('0') << setw(2) << tm.tm_mday << "/";
    ss << setfill('0') << setw(2) << tm.tm_mon + 1;
    string currentdate = ss.str();//current date obtained

    if (isInRange(currentdate, start, end))
        return true;
    return false;
}


void switchyear(user* account, SchoolYear* &thisyear)
{
    if(account -> isStudent || !thisyear){
        startProgram(thisyear, getCurrentYear());
        if(thisyear)
            thisyear -> next = nullptr;
        return;
    }

    string getyear = displayyears();
    if(getyear == thisyear -> year) return;
    SaveChosenYear(thisyear);
    MemoryRelease(thisyear);
    startProgram(thisyear, getyear);
    thisyear -> next = nullptr;
}

int checkValidSems(Semester* hSem){
    if(!hSem) return 0;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    stringstream ss;
    ss << setfill('0') << setw(2) << tm.tm_mday << "/";
    ss << setfill('0') << setw(2) << tm.tm_mon + 1;
    string currentdate = ss.str();//current date obtained

    Semester* cur = hSem;
    for(int i = 0; i < 3; i ++){
        if(cur){
            if(i == 2 && isInRange(currentdate, cur -> end_date, "05/09"))
                return 3;
            if(isInRange(currentdate, cur -> start_date, cur -> end_date))
                return i;
            cur = cur -> next;
        }
    }
    cur = hSem;
    for(int i = 1; i < 3; i++ ){
        if(cur){
            if(isInRange(currentdate, cur -> end_date, cur -> next -> start_date))
                return i;
        cur = cur -> next;
        }
    }
    

}