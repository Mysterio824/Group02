#include<iostream>
using namespace std;

/*used to login in the first place.

This function need to accomplish 2 main tasks:
+ Check if the account user pass in is available (return FALSE if not).
+ If the account is valid, the function check whether the user is student
or academic staff (return TRUE if the user is Student and FALSE for the academic staff).
*/
bool LogIn(bool isStudent);

void Student(); //function for Student.
void AcademicStaff(); //function for Academic Staff.