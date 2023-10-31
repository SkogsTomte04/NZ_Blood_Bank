#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

string FileArray[13] = { "First_Name", "Last_Name", "dob", "Nationality", "Ethnicity", "Med_Conditions", "Blood_Group", "Contact_no", "Email", "Adress", "Prev_Donation_Date", "Username", "Password" };
json Doc;

void Register() {
	
	string userInput, username;
	cout << "Enter a Username: ";
	cin >> username;
	getline(cin, userInput);

	Doc["users"][username];
	
	for (int i = 0; i < size(FileArray); i++) {
		cout << FileArray[i] << ": ";
		getline(cin, userInput);

		Doc["users"][username][FileArray[i]] = userInput;
	}
	
	std::fstream File;
	File.open("user_data.json", std::ios::out);

	File << std::setw(4) << Doc;
}