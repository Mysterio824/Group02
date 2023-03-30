#include"function.cpp"

int main()
{
    system("clear");
    bool isStudent;
    bool hasLogIn = LogIn(isStudent);
    char input;
    while (hasLogIn == false)
    {
        system("clear");
        cout << "Cannot find your account." << endl;
        cout << "Do you want to log in again (y/n): ";
        cin >> input;

        if(input == 'y')
        {
            hasLogIn = LogIn(isStudent);
        }
        else if(input == 'n')
        {
            system("clear");
            cout << "Thanks for having me !" << endl;
            cout << "Press any key to exit....";
            cin >> input;
            return 0;
        }
        else
        {
            cout << "Your input is not approriate." << endl;
        }
    }
    
    if(isStudent)
    {
        Student();
    }
    else
    {
        AcademicStaff();
    }

    return 0;
}