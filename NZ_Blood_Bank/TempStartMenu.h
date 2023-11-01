#pragma once
#include <iostream>
#include "LogIn.h"
#include "Donor_Reg.h"

using namespace std;

void start(bool& loggedIn, string& user) {
    
    while (!loggedIn) {
        int userinput;

        cout << "1. Log In\n2. Sign up" << endl;
        cin >> userinput;

        if (userinput == 1) {
            string status = LogIn();
            if (status != "exe.fail") {
                user = status;
                loggedIn = true;
            }

        }
        if (userinput == 2) {
            Register();
        }
    }
    
    while (loggedIn) {
        int userinput;
        cout << "1. Book appointment\n2. Log out" << endl;
        cin >> userinput;
        if (userinput == 1) {
            cout << "404 nothing here" << endl;
        }
        if (userinput == 2) {
            loggedIn = false;
        }
    }
}