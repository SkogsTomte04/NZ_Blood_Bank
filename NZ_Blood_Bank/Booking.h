#pragma once
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp"
using json = nlohmann::json;
using namespace std;

string weekdays[5] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };

int getHour() {
	return 0;
}

string getDay() {
	int userinput;

	for (int i = 1; i <= size(weekdays); i++) {
		cout << i << ". " << weekdays[i - 1] << endl;
	}
	cout << "Pick a day to Donate" << endl;
	cin >> userinput;

	return weekdays[userinput - 1];
}

void getAvailable() {

}

void BookAppointment(string user) {
	ifstream in("user_data.json");
	json Doc = json::parse(in);
	string day = getDay();



	fstream file;
	file.open("user_data.json", std::ios::out);
	file << std::setw(4) << Doc;
	file.close();
}