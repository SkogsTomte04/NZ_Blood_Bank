#include "TempStartMenu.h"
using namespace std;

extern void BookAppointment(string);
extern void Register();
extern string LogIn();

void start(bool& loggedIn, string& user) {

    while (!loggedIn) {
        system("cls");
        
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
        else {
            userinput = 1;
        }
    }

    while (loggedIn) {
        system("cls");
        int userinput;
        cout << "1. Book appointment\n2. Log out" << endl;
        cin >> userinput;
        if (userinput == 1) {
            BookAppointment(user);
        }
        if (userinput == 2) {
            loggedIn = false;
        }
    }
}