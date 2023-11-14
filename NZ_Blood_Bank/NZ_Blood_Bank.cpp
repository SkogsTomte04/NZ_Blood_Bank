#include <iostream>
#include "Donor_Reg.h"
#include "DonorsScreen.h"
#include "LogIn.h"
#include "Booking.h"
#include "intro_screen.h"
#include "Recipient'sRegistration.h"
#include "jsonManager.h"
#include "admin_screen.h"


int main()
{
    bool isRunning = true, loggedIn = false, isAdmin = false;
    string activeUser;

    while (isRunning) {
        while (!loggedIn) { // does this if user is not logged in
            json j = getUserdata();
            draw_intro();

            int userinput;
            cin >> userinput;

            if (userinput == 1) {
                string loginStatus = LogIn();
                
                if (j["ADMINS"].contains(loginStatus)) {
                    activeUser = loginStatus;
                    loggedIn = true;
                    isAdmin = true;
                }
                else if (loginStatus != "exe.fail") {
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
            
            if (isAdmin) {
                cout << "1. Sign in as admin\n2. Log out" << endl;
                cin >> userinput;
                if (userinput == 1) {
                    admin_screen(activeUser);
                }
                if (userinput == 2) {
                    loggedIn = false;
                    isAdmin = false;
                    break;
                }
            }
            else if (!isAdmin) {
                cout << "1. Book appointment\n2. Log out" << endl;
                cin >> userinput;
                if (userinput == 1) {
                    DScreen();
                    BookAppointment(activeUser);
                }
                if (userinput == 2) {
                    loggedIn = false;
                    break;
                }
            }
        }
    }
}