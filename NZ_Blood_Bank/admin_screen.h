#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "colors.hpp"

using namespace std;

void admin_screen()
{
    int adminOptions;
    bool adminStatus = false;

    while (true) {
        cout << colors::red << "\n====================================================" << colors::reset << endl;
        cout << colors::bright_red << "\t     New Zealand Blood Bank" << colors::reset << endl;
        cout << endl;
        cout << colors::bright_grey << "Bob, welcome back! You have been sent to this screen" << colors::reset << endl;
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
            cout << colors::white << "\nAnswer: " << colors::green;
            cin >> infoOptions;

            if (infoOptions == 1) {
                cout << colors::bright_red << "\n[!] " << colors::bright_grey << "You choosed Recipient Information." << colors::reset << endl;
                cout << colors::bright_grey << "Input the recipient's name to view their information." << colors::reset << endl;
                cout << colors::white << "\nAnswer: " << colors::green;
                cin >> answer;

                cout << "\n" << colors::white << fakeVariable << colors::reset << endl;
                cout << colors::white << "1. " << colors::bright_grey << "Jezner Jeymz M. Leonidas" << ", " << "O" << ", " << "Auckland, City" << colors::reset << endl;
                adminStatus = true;
                break;
            }
            else if (infoOptions == 2) {
                cout << colors::bright_red << "\n[!] " << colors::bright_grey << "You choosed Donator Information." << colors::reset << endl;
                cout << colors::bright_grey << "Input the donator's name to view their information." << colors::reset << endl;
                cout << colors::white << "\nAnswer: " << colors::green;
                cin >> answer;

                cout << "\n" << colors::white << fakeVariable << colors::reset << endl;
                cout << colors::white << "1. " << colors::bright_grey << "Jezner Jeymz M. Leonidas" << ", " << "O" << ", " << "Auckland, City" << colors::reset << endl;
                adminStatus = true;
                break;
            }
            if (cin.fail()) {
                cout << colors::red << "\n/!\\ " << colors::white << "Error: Invalid Number!" << colors::reset << endl;
                adminStatus = false;
            }
        }
        else if (adminOptions == 2) {
            cout << colors::bright_red << "\n[!] " << colors::bright_grey << "You choosed Update Reports." << colors::reset << endl;
            cout << colors::bright_grey << "Input the donators's name to update the blood testing report." << colors::reset << endl;
            cout << colors::white << "\nAnswer: " << colors::green;
            cin >> answer;

            cout << "\n" << colors::white << fakeVariable << colors::reset << endl;
            cout << colors::white << "1. " << colors::bright_grey << "Jezner Jeymz M. Leonidas" << ", " << "O" << ", " << "Auckland, City" << colors::reset << endl;
            adminStatus = true;
            break;
        }
        if (cin.fail()) {
            cout << colors::red << "\n/!\\ " << colors::white << "Error: Invalid Number!" << colors::reset << endl;
        }
    }
}