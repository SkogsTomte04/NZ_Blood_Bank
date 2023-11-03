#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "colors.hpp"

using namespace std;

void intro_screen() 
{
    cout << colors::red << "===============================================" << colors::reset << endl;
    cout << colors::bright_red << "\tNew Zealand Blood Bank" << colors::reset << endl;
    cout << colors::bright_grey << "Welcome from the largest blood bank in NZ," << colors::reset << endl;
    cout << colors::bright_grey << " where blood donors donate to save lives." << colors::reset << endl;
    cout << endl;
    cout << colors::bright_grey << "\tEnter your option from (1-2): " << colors::reset << endl;
    cout << colors::white << "\t       1. Login" << colors::reset << endl;
    cout << colors::white << "\t      2. Register" << colors::reset << endl;
    cout << colors::red << "===============================================" << colors::reset << endl;
    cout << colors::white << "\nAnswer: " << colors::green;

    fstream file("userdata.txt");

    string fakeVariable = "Dummy";
    int userOptions;
    int userCategory;
    char userRegister;
    cin >> userOptions;

    if (userOptions == 1) {
        cout << colors::bright_red << "\n[!] " << colors::bright_grey << "You choosed Login." << colors::reset << endl;
        cout << colors::bright_grey << "Checking... You are a " << fakeVariable << "!" << endl;
        cout << colors::white << "Test and Hello!" << colors::reset << endl;
        cout << colors::white << "\nAnswer: " << colors::green;
        cin >> userCategory;
    }
    else if (userOptions == 2) {
        cout << colors::bright_red << "\n[!] " << colors::bright_grey << "You choosed Register." << colors::reset << endl;

        do {
            cout << colors::white << "Username: " << colors::green;
            string username;
            cin.ignore();
            getline(cin, username);
            file << "Username: " << username << endl;

            cout << colors::white << "First Name: " << colors::green;
            string firstName;
            getline(cin, firstName);
            file << "First Name: " << firstName << endl;

            cout << colors::white << "Last Name: " << colors::green;
            string lastName;
            getline(cin, lastName);
            file << "Last Name: " << lastName << endl;

            cout << colors::white << "Email Address: " << colors::green;
            string emailAddress;
            getline(cin, emailAddress);
            file << "Email Address: " << emailAddress << endl;

            cout << colors::white << "Password: " << colors::green;
            string password;
            getline(cin, password);
            file << "Password: " << password << endl;

            cout << colors::white << "Contact Number: " << colors::green;
            string contactNumber;
            getline(cin, contactNumber);
            file << "Contact Number: " << contactNumber << endl;

            cout << colors::white << "Nationality: " << colors::green;
            string nationality;
            getline(cin, nationality);
            file << "Nationality: " << nationality << endl;

            cout << colors::white << "Ethnicity: " << colors::green;
            string ethnicity;
            getline(cin, ethnicity);
            file << "Ethnicity: " << ethnicity << endl;

            cout << colors::white << "Medical Conditions: " << colors::green;
            string medicalConditions;
            getline(cin, medicalConditions);
            file << "Medical Conditions: " << medicalConditions << endl;

            cout << colors::white << "Blood Group: " << colors::green;
            string bloodGroup;
            getline(cin, bloodGroup);
            file << "Blood Group: " << bloodGroup << endl;
            
            cout << colors::bright_red << "\n[!] " << colors::bright_grey << "Registration finished! Do you want to register again?" << colors::reset << endl;
            cout << colors::bright_grey << "Enter your answer from (1-2): " << colors::reset << endl;
            cout << colors::white << "1. Yes" << colors::reset << endl;
            cout << colors::white << "2. No" << colors::reset << endl;
            cout << colors::white << "\nAnswer: " << colors::green;
            cin >> userRegister;

        } while (userRegister == 1);
        file.close();
    }
    else {
        cout << colors::red << "\n/!\\ " << colors::white << "Error: Invalid Number!" << colors::reset << endl;
    }
}