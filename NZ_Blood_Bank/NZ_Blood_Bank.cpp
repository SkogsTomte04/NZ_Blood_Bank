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
                cout << colors::bright_red << "\n[!] " << colors::bright_grey << "You choosed Register." << colors::reset << endl;
                cout << colors::bright_grey << "Please indicate if you are donating or receiving blood before continuing." << colors::reset << endl;
                cout << colors::bright_grey << "Enter your answer from (1-2): " << colors::reset << endl;
                cout << colors::white << "1. Donate" << colors::reset << endl;
                cout << colors::white << "2. Receive" << colors::reset << endl;
                cout << colors::white << "\nAnswer: " << colors::green;
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

        while (loggedIn && !isAdmin) { // does this if user is logged in
            system("cls");
            int userinput;

            cout << colors::bright_red << "[!] " << colors::bright_grey << "Login successful." << colors::reset << endl;
            
            printUser(getUserdata(), activeUser, "Donators");

            cout << colors::bright_grey << "Enter your answer from (1-2): " << colors::reset << endl;
            cout << colors::white << "1. Book Appointment" << colors::reset << endl;
            cout << colors::white << "2. Log Out" << colors::reset << endl;
            cout << colors::white << "\nAnswer: " << colors::green;
            cin >> userinput;
            system("cls");
            if (userinput == 1) {
                DScreen();
                BookAppointment(activeUser);
            }
            if (userinput == 2) {
                loggedIn = false;
                break;
            }
        }
        while (isAdmin) {
            string input;
            admin_screen(activeUser);
            loggedIn = false;
            isAdmin = false;
        }
    }
}