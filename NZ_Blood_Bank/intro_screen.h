#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "colors.hpp"

using namespace std;

void draw_intro() {
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
    cout << colors::reset;
}
