#pragma once
#include <iostream>
#include <string>
#include <fstream>

void patient_details(std::string path) {
	std::fstream strm;

	strm.open(path, std::ios_base::in | std::ios_base::app);

	if (strm.is_open()) {
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

		std::cout << '\n';
		std::cout << "Full name: " << fullname << '\n';
		std::cout << "Hospital or Blood Bank: " << hospitalname << '\n';
		std::cout << "Physical address: " << address << '\n';
		std::cout << "Email: " << email << '\n';
		std::cout << "Contact Number: " << contactnumber << '\n' << '\n';

		strm << "Full name: " << fullname << '\n';
		strm << "Hospital or Blood Bank: " << hospitalname << '\n';
		strm << "Physical address: " << address << '\n';
		strm << "Email: " << email << '\n';
		strm << "Contact Number: " << contactnumber << '\n' << '\n';

		strm.close();
	}
	else {
		std::cout << "NO" << "\n";
	}

	std::cout << '\n';
	std::cout << "Your registration is valid to access blood! Please continue to the booking process!" << '\n';
}
