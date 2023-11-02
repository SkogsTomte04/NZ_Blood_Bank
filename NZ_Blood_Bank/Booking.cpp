#include "Booking.h"

using json = nlohmann::json;
using namespace std;

int getHour() { // user picks time of day
	int userinput;

	array<int, 8> hours;
	iota(hours.begin(), hours.end(), 9);

	for (int i = 1; i <= size(hours); i++) {
		cout << i << ". " << hours[i - 1] << endl;
	}
	cout << "Pick a time of day (1 - " << size(hours) << "): ";
	cin >> userinput;

	return hours[userinput - 1];
}

string getDay() { // user picks day
	int userinput;

	string weekdays[5] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };

	for (int i = 1; i <= size(weekdays); i++) {
		cout << i << ". " << weekdays[i - 1] << endl;
	}
	cout << "Pick a day to Donate" << endl;
	cin >> userinput;

	return weekdays[userinput - 1];
}

void BookAppointment(string user) { // Gives user object both day of and time of appointment
	ifstream in("user_data.json");
	json Doc = json::parse(in);
	string day = getDay();

	Doc[user]["Appointment_Date"]["day"] = getDay();
	Doc[user]["Appointment_Date"]["Hour"] = getHour();

	fstream file;
	file.open("user_data.json", std::ios::out);
	file << std::setw(4) << Doc;
	file.close();
}