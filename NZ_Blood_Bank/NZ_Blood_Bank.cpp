#include <iostream>
#include "Donor_Reg.h"
#include "LogIn.h"
#include "TempStartMenu.h"


int main()
{
    bool isLoggedin = false;
    string activeUser;

    while (!isLoggedin) {
        start(isLoggedin, activeUser);
    }
}