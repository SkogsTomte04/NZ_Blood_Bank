#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "json.hpp"
#include "jsonManager.h"

using json = nlohmann::ordered_json;

void patient_details() {
	json j_User = getUserdata();
	
	string id;
	string fullname;
	string hospitalname;
	string address;
	string email;
	string contactnumber;

	cout << endl << colors::bright_red << "[!] " << colors::bright_grey << "You chose receive." << colors::reset << endl;
	cout << endl << colors::bright_red << "      RECIPIENT'S REGISTRATION" << colors::reset << endl;
	cout << colors::bright_grey << " Please fill in the following questions" << colors::reset << endl;
	cout << colors::red << "----------------------------------------" << colors::reset << endl;

	cout << colors::white << "Full Name: " << colors::green;
	getline(cin, fullname);

	cout << colors::white << "Blood Bank or Hospital's name: " << colors::green;
	getline(cin, hospitalname);

	cout << colors::white << "Physical Address: " << colors::green;
	getline(cin, address);

	cout << colors::white << "Email Address: " << colors::green;
	getline(cin, email);

	cout << colors::white << "Contact Number: " << colors::green;
	getline(cin, contactnumber);

	id = fullname;
	replace(id.begin(), id.end(), ' ', '_');

	j_User["Recipiants"][id]["User_Info"] = { {"Full name", fullname},{"Hospital/Bloodbank", hospitalname}, {"Adress", address}, {"Email", email}, {"Contact_no", contactnumber} };

	system("cls");

	cout << endl;
	cout << colors::white << "Full Name: " << colors::green << fullname << colors::reset << endl;
	cout << colors::white << "Hospital or Blood Bank: " << colors::green << hospitalname << colors::reset << endl;
	cout << colors::white << "Physical address: " << colors::green << address << colors::reset << endl;
	cout << colors::white << "Email: " << colors::green << email << colors::reset << endl;
	cout << colors::white << "Contact Number: " << colors::green << contactnumber << colors::reset << endl;

	cout << endl << colors::bright_red << "[!] " << colors::bright_grey << "Your registration is valid to access blood! Please continue to the booking process!" << colors::reset << endl;
	updateJson(j_User, "user_data.json");
	system("pause");

	system("cls");
}
