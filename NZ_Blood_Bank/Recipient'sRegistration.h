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

	cout << '\n';
	cout << colors::bright_grey << "Full Name: " << fullname << '\n';
	cout << colors::bright_grey << "Hospital or Blood Bank: " << hospitalname << '\n';
	cout << colors::bright_grey << "Physical address: " << address << '\n';
	cout << colors::bright_grey << "Email: " << email << '\n';
	cout << colors::bright_grey << "Contact Number: " << contactnumber << '\n' << '\n';

	cout << '\n';
	cout << "Your registration is valid to access blood! Please continue to the booking process!" << '\n';
	updateJson(j_User, "user_data.json");
	system("pause");

	system("cls");
}
