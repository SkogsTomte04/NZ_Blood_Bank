#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "colors.hpp"

using namespace std;

void recipient_screen()
{
    cout << colors::red << "==========================================" << colors::reset << endl;
    cout << colors::bright_red << "\tNew Zealand Blood Bank" << colors::reset << endl;
    cout << endl;
    cout << "Name: " << "Blood Group:   " << "Location: " << endl;
    cout << colors::white << "1." << ", " << colors::bright_grey << "Jezner Jeymz M. Leonidas" << ", " << "O" << ", " << "Auckland, City" << colors::reset << endl;
    cout << colors::red << "==========================================" << colors::reset << endl;
}


