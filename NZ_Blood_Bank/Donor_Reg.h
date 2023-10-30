#pragma once
#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

using namespace std;


string FileArray[13] = { "First_Name", "Last_Name", "dob", "Nationality", "Ethnicity", "Med_Conditions", "Blood_Group", "Contact_no", "Email", "Adress", "Prev_Donation_Date", "Username", "Password" };

void Register() {
	
	string userInput;
	json j;


	for (int i = 0; i < size(FileArray); i++) {
		cout << FileArray[i] << ": ";
		getline(cin, userInput);
		j[FileArray[i]] = userInput;
	}
	ofstream jsonOut("./user_data.json");
	jsonOut << std::setw(4) << j << std::endl;
	
}