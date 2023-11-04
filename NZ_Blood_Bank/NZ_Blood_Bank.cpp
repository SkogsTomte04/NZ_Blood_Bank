#include <iostream>
#include "Donor_Reg.h"
#include "LogIn.h"
#include "Booking.h"
#include "intro_screen.h"


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
                Register();
            }

        }

        while (loggedIn) { // does this if user is logged in
            system("cls");
            int userinput;
            cout << "1. Book appointment\n2. Log out" << endl;
            cin >> userinput;
            if (userinput == 1) { // PLEASE add a check to see if user already has a booked date
                BookAppointment(activeUser);
            }
            if (userinput == 2) {
                loggedIn = false;
            }
        }
    }
}