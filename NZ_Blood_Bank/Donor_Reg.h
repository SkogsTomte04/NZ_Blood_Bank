#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

string FileArray[12] = { "First_Name", "Last_Name", "dob", "Nationality", "Ethnicity", "Med_Conditions", "Blood_Group", "Contact_no", "Email", "Adress", "Prev_Donation_Date", "Password" };


void Register() {
	ifstream in("user_data.json");

	json Doc = json::parse(in);

	string userInput, username;
	cout << "Enter a Username: ";
	getline(cin, username);
	Doc[username];
	Doc[username]["isActive"] = false;
	Doc[username]["Username"] = username;
	
	for (int i = 0; i < size(FileArray); i++) {
		cout << FileArray[i] << ": ";
		getline(cin, userInput);

		Doc[username][FileArray[i]] = userInput;
	}
	fstream file;
	file.open("user_data.json", std::ios::out);
	file << std::setw(4) << Doc;
	file.close();
}