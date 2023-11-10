#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "json.hpp"
#include "jsonManager.h"

using json = nlohmann::ordered_json;

void patient_details() {
	json j_User = getUserdata();
	
	std::string fullname;
	std::string hospitalname;
	std::string address;
	std::string email;
	std::string contactnumber;

	std::cout << "   RECIPIENT'S REGISTRATION" << '\n';
	std::cout << "------------------------------" << '\n' << '\n';

	std::cout << "Type your full name: ";
	getline(std::cin, fullname);

	std::cout << "What is the name of the Hospital or Blood Bank? ";
	getline(std::cin, hospitalname);

	std::cout << "Type your physical address: ";
	getline(std::cin, address);

	std::cout << "Type your email address: ";
	getline(std::cin, email);

	std::cout << "Type your contact number: ";
	getline(std::cin, contactnumber);

	j_User["Recipiants"][fullname]["User_Info"] = { {"Full name", fullname},{"Hospital/Bloodbank", hospitalname}, {"Adress", address}, {"Email", email}, {"Contact_no", contactnumber} };

	system("cls");

	std::cout << '\n';
	std::cout << "Full name: " << fullname << '\n';
	std::cout << "Hospital or Blood Bank: " << hospitalname << '\n';
	std::cout << "Physical address: " << address << '\n';
	std::cout << "Email: " << email << '\n';
	std::cout << "Contact Number: " << contactnumber << '\n' << '\n';

	std::cout << '\n';
	std::cout << "Your registration is valid to access blood! Please continue to the booking process!" << '\n';
	updateJson(j_User, "user_data.json");
	system("pause");

	system("cls");
}
