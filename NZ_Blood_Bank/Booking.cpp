#include "Booking.h"

using json = nlohmann::ordered_json;
using namespace std;

string weekdays[5] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
int hours[8] = { 9, 10, 11, 12, 13, 14, 15, 16 };

void inSchedule(string day, int hour, string user) {
	string hour_key = to_string(hour);

	ifstream in("Schedule.json");
	json j = json::parse(in);

	j["Days"][day][hour_key] = user;

	fstream file;
	file.open("Schedule.json", std::ios::out);
	file << std::setw(4) << j;
	file.close();
	/*for (int i = 0; i < size(hours); i++) {
		if (j[day][hours[i]] == "Available") {
			cout << 
		}
	}*/
}

int getHour() { // user picks time of day
	int userinput;

	for (int i = 1; i <= size(hours); i++) {
		cout << i << ". " << hours[i - 1] << ":00" << endl;
	}
	cout << "Pick a time of day (1 - " << size(hours) << "): ";
	cin >> userinput;

	return hours[userinput - 1];
}

string getDay() { // user picks day
	int userinput;

	for (int i = 1; i <= size(weekdays); i++) {
		cout << i << ". " << weekdays[i - 1] << endl;
	}
	cout << "Pick a day to Donate" << endl;
	cin >> userinput;

	return weekdays[userinput - 1];
}

void BookAppointment(string user) { // Gives user object both day of and time of appointment
	system("cls");

	ifstream in("user_data.json");
	json Doc = json::parse(in);

	string day = getDay();
	int hour = getHour();

	Doc[user]["Appointment_Date"]["day"] = day;
	Doc[user]["Appointment_Date"]["Hour"] = hour;

	

	fstream file;
	file.open("user_data.json", std::ios::out);
	file << std::setw(4) << Doc;
	file.close();
	inSchedule(day, hour, user);
}