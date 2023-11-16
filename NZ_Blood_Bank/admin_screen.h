#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "jsonManager.h"
#include "colors.hpp"

using namespace std;

void editUser(json j, string str) {
    string input;
    if (j["Donators"].contains(str)) {
        cout << "User: " << str << endl << "Blood Type: " << j["Donators"][str]["User_Info"]["Blood_Group"] << endl;
        cout << "Enter new blood type: ";
        cin >> input;
        j["Donators"][str]["User_Info"]["Blood_Group"] = input;
        updateJson(j, "user_data.json");
    }
    else {
        cout << "Error: name not found" << endl;
        system("pause");
    }
}

void BloodBank(json j) {
    int counter = 0;
    string input;

    cout << "Enter Blood Bank: ";
    std::cin >> input;

    for (auto it = j["Recipiants"].begin(); it != j["Recipiants"].end(); ++it)
    {
        if (j["Recipiants"][it.key()]["User_Info"]["Hospital/Bloodbank"] == input) {
            cout << colors::blue << it.key() << endl << colors::bright_grey << j["Recipiants"][it.key()].dump(4) << colors::reset << endl;
            counter++;
        }
    }
    if (counter == 0) {
        cout << "No users found with Blood Bank \"" << input << "\"" << endl;
    }
}

void Bloodtype(json j) {
    string input, tempStr;
    int counter = 0;
    cout << "Enter Blood Group: ";
    std::cin >> input;

    for (auto it = j["Donators"].begin(); it != j["Donators"].end(); ++it)
    {
        if (j["Donators"][it.key()]["User_Info"]["Blood_Group"] == input) {
            printUser(j, it.key(), "Donators");
            counter++;
        }
    }
    if (counter == 0) {
        cout << "No users found with Blood Group \"" << input << "\"" << endl;
    }
}

void findUser(json j, string type) { // "type" is either "Donators" or "Recipiants"
    string input;
    
    cout << colors::bright_grey << "Input the " << type << "'s name to view their information." << colors::reset << endl;
    cout << colors::white << "\nAnswer: " << colors::green;

    std::cin >> input;
    system("cls");
    if (j[type].contains(input)) {
        /*cout << j[type][input].dump(4);*/
        printUser(j, input, type);
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
int printMenu(int screen) {
    int userInput;
    string str;

    switch (screen) {
    case 1:
        cout << colors::red << "\n====================================================" << colors::reset << endl;
        cout << colors::bright_red << "\t     New Zealand Blood Bank" << colors::reset << endl;
        cout << endl;
        cout << colors::bright_grey << "Welcome back! You have been sent to this screen" << colors::reset << endl;
        cout << colors::bright_grey << "because the system recognized you as an admin." << colors::reset << endl;
        cout << colors::bright_grey << "Below, you have the ability to view or edit the info." << colors::reset << endl;
        cout << endl;
        cout << colors::bright_grey << "\t Enter your option from (1-2): " << colors::reset << endl;
        cout << colors::white << "\t     1. View Information" << colors::reset << endl;
        cout << colors::white << "\t      2. Update Reports" << colors::reset << endl;
        cout << colors::white << "\t      3. Quit" << colors::reset << endl;
        cout << colors::red << "====================================================" << colors::reset << endl;
        cout << colors::white << "\nAnswer: " << colors::green;

        break;
    case 2:
        cout << colors::bright_red << "\n[!] " << colors::bright_grey << "You choosed View Information/Update." << colors::reset << endl;
        cout << colors::bright_grey << "Enter your answer from (1-2): " << colors::reset << endl;
        cout << colors::white << "1. Recipient Information" << colors::reset << endl;
        cout << colors::white << "2. Donator Information" << colors::reset << endl;
        cout << colors::white << "3. Find users by bloodtype" << colors::reset << endl;
        cout << colors::white << "\nAnswer: " << colors::green;
        break;
    case 3:
        cout << colors::bright_red << "\n[!] " << colors::bright_grey << "You choosed Update Reports." << colors::reset << endl;
        cout << colors::bright_grey << "Input the donators's name to update the blood testing report." << colors::reset << endl;
        cout << colors::white << "\nAnswer: " << colors::green;
        return 0;
    }
    std::cin >> userInput;
    return userInput;
}

void admin_screen(string user)
{
    int menuInput;
    bool adminStatus = true;

    while (adminStatus) {
        json j_user = getUserdata();
        json j_schedule = getScheduledata();
        menuInput = printMenu(1);

        if (menuInput == 1) {
            int userInput = printMenu(2);
            
            switch (userInput) {
            case 1:
                printUsers(j_user, "Recipiants");

                system("pause");
                break;
            case 2:
                printUsers(j_user, "Donators");

                system("pause");
                break;
            case 3:
                Bloodtype(j_user);

                system("pause");
                break;
            case 4:
                BloodBank(j_user);

                system("pause");
                break;
            }
        }
        if (menuInput == 2) {
            string input;
            printMenu(3);
            std::cin >> input;
            editUser(j_user, input);
        }
        if (menuInput == 3) {
            break;
        }
        else if (std::cin.fail()) {
            cout << colors::red << "\n/!\\ " << colors::white << "Error: Invalid Number!" << colors::reset << endl;
        }
        system("cls");
    }
}