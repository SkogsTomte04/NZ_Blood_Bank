#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "json.hpp"
#include "jsonManager.h"
#include "InputManager.h"

using json = nlohmann::ordered_json;

struct Recipiant {
	string id;
	string fullname;
	string hospitalname;
	string address;
	string email;
	string contactnumber;
};

void patient_details() { // creates a new recever
	json j_User = getUserdata();

	Recipiant reci;

	cout << endl << colors::bright_red << "[!] " << colors::bright_grey << "You chose receive." << colors::reset << endl;
	cout << endl << colors::bright_red << "      RECIPIENT'S REGISTRATION" << colors::reset << endl;
	cout << colors::bright_grey << " Please fill in the following questions" << colors::reset << endl;
	cout << colors::red << "----------------------------------------" << colors::reset << endl;

	reci.fullname = getString("Full Name");
	reci.hospitalname = getString("Blood Bank or Hospital's name");
	reci.address = getString("Physical adress");
	reci.email = getString("Email Address");
	reci.contactnumber = getString("Contact Number");

	reci.id = reci.fullname;
	replace(reci.id.begin(), reci.id.end(), ' ', '_');

	j_User["Recipiants"][reci.id]["User_Info"] = { {"Full name", reci.fullname},{"Hospital/Bloodbank", reci.hospitalname}, {"Adress", reci.address}, {"Email", reci.email}, {"Contact_no", reci.contactnumber} };

	system("cls");

	printUser(j_User, reci.id, "Recipiants");
	updateJson(j_User, "user_data.json");
	
	cout << endl << colors::bright_red << "[!] " << colors::bright_grey << "Your registration is valid to access blood! Please continue to the booking process!" << colors::reset << endl;
	
	system("pause");
	system("cls");
}
