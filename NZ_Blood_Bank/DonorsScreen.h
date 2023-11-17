#pragma once
#include <iostream>
#include <string>
#include "colors.hpp"

using namespace std;

void DScreen() {
	cout << endl;
	cout << colors::bright_red << "----------------------------------------------------------------------------------------------" << colors::reset << endl;
	cout << colors::bright_red << "\t                  Guidelines for donating blood " << colors::reset << endl;
	cout << colors::bright_grey << "1. Answer questions about your medical history and previous trips in a private interview.\n"
		"2. Tell us the medications you have on prescription or over-the-counter.\n"
		"3. Your temperature, pulse, blood pressure, and hemoglobin level will all be monitored.\n"
		"4. If you are donating blood, we will clean the area under your arm and put in a new,\n"
		"sterile needle to take your blood.\n"
		"5. Both arms will be attached to an apheresis machine, which is used to make other contributions, such platelets.\n"
		"6. You will be lying down or comfortably sitting for 8 to 10 minutes for a whole blood donation.\n"
		"7. A staff member will bandage your arm once the donation is complete. It usually takes about a pint of whole blood.\n"
		"8. The apheresis machine will draw a small amount of blood, remove the platelets,\n"
		"and then return blood from the other arm. This process will be done multiple times\n"
		"over the course of two hours.\n" << colors::reset;
	cout << endl;
	cout << colors::bright_green << "The benefits of donating blood:" << endl;
	cout << colors::white << "1. May expose health issues\n"
		"2. Hemochromatosis prevention\n"
		"3. Maintain cardiovascular health\n"
		"4. Reduce the risk of developing cancer\n"
		"5. Promotes the production of blood cells\n"
		"6. Keeps the liver healthy\n"
		"7. Weight Loss\n"
		"8. Help improve your mental health\n" << colors::reset;
	cout << colors::bright_red << "----------------------------------------------------------------------------------------------" << colors::reset << endl;
	system("pause");
}