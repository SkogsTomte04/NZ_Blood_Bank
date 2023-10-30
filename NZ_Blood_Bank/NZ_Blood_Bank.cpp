#include <iostream>
#include <string>
#include "colors.hpp"

using namespace std;

int main()
{
    cout << colors::red << "==========================================" << colors::reset << endl;
    cout << colors::bright_red << "\tNew Zealand Blood Bank" << colors::reset << endl;
    cout << colors::bright_grey << "Welcome from the largest blood bank in NZ," << colors::reset << endl;
    cout << colors::bright_grey << " where blood donors donate to save lives." << colors::reset << endl;
    cout << endl;
    cout << colors::white << "\t      Login" << colors::reset << endl;
    cout << colors::white << "\t     Register" << colors::reset << endl;
    cout << colors::red << "==========================================" << colors::reset << endl;

    return 0;
}
