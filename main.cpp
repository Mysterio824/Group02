#include "header.h"
#include "userInterface.h"
#include "logInInterface.h"

int main() {
    user *account = logIn(); //user's account
    SchoolYear *thisYear = nullptr;
    switchyear(account, thisYear);
    interFace(account, thisYear);
    return 0;
}
