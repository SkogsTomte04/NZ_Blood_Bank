#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "colors.hpp"

using namespace std;

void Bloodtype(json j) { // this needs a lot of work
    for (auto it = j["Donators"].begin(); it != j["Donators"].end(); ++it)
    {
        cout << *it << endl;
    }
}

void findUser(json j, string type) { // "type" is either "Donators" or "Recipiants"
    string input;
    
    cout << colors::bright_grey << "Input the " << type << "'s name to view their information." << colors::reset << endl;
    cout << colors::white << "\nAnswer: " << colors::green;

    cin >> input;
    system("cls");
    if (j[type].contains(input)) {
        cout << j[type][input].dump(4);
    }
    else {
        cout << "error: name not found";
        system("pause");
    }
}

void printUsers(json j, string type) { // prints all users of type "Donators" or "Recipiants" 
    cout << colors::bright_grey << j[type].dump(4) << colors::reset << endl;

    findUser(j, type);
}

void admin_screen(string user)
{
    json j_user = getUserdata();
    json j_schedule = getScheduledata();
    int adminOptions;
    bool adminStatus = false;

    cout << colors::red << "\n====================================================" << colors::reset << endl;
    cout << colors::bright_red << "\t     New Zealand Blood Bank" << colors::reset << endl;
    cout << endl;
    cout << colors::bright_grey << user << ", welcome back! You have been sent to this screen" << colors::reset << endl;
    cout << colors::bright_grey << "because the system recognized you as an admin." << colors::reset << endl;
    cout << colors::bright_grey << "Below, you have the ability to view or edit the info." << colors::reset << endl;
    cout << endl;
    cout << colors::bright_grey << "\t Enter your option from (1-2): " << colors::reset << endl;
    cout << colors::white << "\t     1. View Information" << colors::reset << endl;
    cout << colors::white << "\t      2. Update Reports" << colors::reset << endl;
    cout << colors::red << "====================================================" << colors::reset << endl;
    cout << colors::white << "\nAnswer: " << colors::green;
    cin >> adminOptions;

    int infoOptions;
    int answer;
    string fakeVariable = "This is a fake string / Dummy";

    if (adminOptions == 1) {
        cout << colors::bright_red << "\n[!] " << colors::bright_grey << "You choosed View Information/Update." << colors::reset << endl;
        cout << colors::bright_grey << "Enter your answer from (1-2): " << colors::reset << endl;
        cout << colors::white << "1. Recipient Information" << colors::reset << endl;
        cout << colors::white << "2. Donator Information" << colors::reset << endl;
        cout << colors::white << "3. Find users by bloodtype" << colors::reset << endl;
        cout << colors::white << "\nAnswer: " << colors::green;
        cin >> infoOptions;

        if (infoOptions == 1) {
            printUsers(j_user, "Recipiants");

            system("pause");
        }
        if (infoOptions == 2) {
            printUsers(j_user, "Donators");
            
            system("pause");
        }
        if (infoOptions == 3) {
            Bloodtype(j_user);

            system("pause");
        }
        else if (cin.fail()) {
            cout << colors::red << "\n/!\\ " << colors::white << "Error: Invalid Number!" << colors::reset << endl;

        }
    }
    if (adminOptions == 2) {
        cout << colors::bright_red << "\n[!] " << colors::bright_grey << "You choosed Update Reports." << colors::reset << endl;
        cout << colors::bright_grey << "Input the donators's name to update the blood testing report." << colors::reset << endl;
        cout << colors::white << "\nAnswer: " << colors::green;
        cin >> answer;

        cout << "\n" << colors::white << fakeVariable << colors::reset << endl;
        cout << colors::white << "1. " << colors::bright_grey << "Jezner Jeymz M. Leonidas" << ", " << "O" << ", " << "Auckland, City" << colors::reset << endl;
    }
    else if (cin.fail()) {
        cout << colors::red << "\n/!\\ " << colors::white << "Error: Invalid Number!" << colors::reset << endl;
    }
}