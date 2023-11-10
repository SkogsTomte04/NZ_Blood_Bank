#include <iostream>
#include "Donor_Reg.h"
#include "DonorsScreen.h"
#include "LogIn.h"
#include "Booking.h"
#include "intro_screen.h"
#include "Recipient'sRegistration.h"
#include "jsonManager.h"


int main()
{
    bool isRunning = true, loggedIn = false;
    string activeUser;

    while (isRunning) {
        while (!loggedIn) { // does this if user is not logged in
            system("cls");

            draw_intro();

            int userinput;
            cin >> userinput;

            if (userinput == 1) {
                string loginStatus = LogIn();
                if (loginStatus != "exe.fail") {
                    activeUser = loginStatus;
                    loggedIn = true;
                }

            }
            if (userinput == 2) {
                cout << "Donate or receive?\n\n1. Donate\n2. Receive" << endl;
                cin >> userinput;
                cin.ignore();
                if (userinput == 1) {
                    Register();
                }
                if (userinput == 2) {
                    patient_details();
                }
            }

        }

        while (loggedIn) { // does this if user is logged in
            system("cls");
            int userinput;
            
            cout << "1. Book appointment\n2. Log out" << endl;
            cin >> userinput;
            if (userinput == 1) {
                DScreen();
                BookAppointment(activeUser);
            }
            if (userinput == 2) {
                loggedIn = false;
            }
        }
    }
}