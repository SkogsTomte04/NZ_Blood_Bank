#include "Booking.h"

using json = nlohmann::ordered_json;
using namespace std;

string weekdays[5] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
int hours[8] = { 9, 10, 11, 12, 13, 14, 15, 16 };

json getSchedulejson() {
	ifstream in("Schedule.json");
	json j = json::parse(in);
	return j;
}

void inSchedule(string day, int hour, string user, json j) {
	string hour_key = to_string(hour);

	

	j["Days"][day][hour_key] = user;

	fstream file;
	file.open("Schedule.json", std::ios::out);
	file << std::setw(4) << j;
	file.close();
	
}

int getHour(json j, string day) { // user picks time of day
	int userinput;
	int counter = 1;
	for (int i = 0; i < size(hours); i++) {
		string i_str = to_string(hours[i]);
		if (j["Days"][day][i_str] == "Available") {
			cout << counter << ". " << hours[i] << ":00" << endl;
			counter++;
		}
	}
	cout << "Pick a time of day (1 - " << size(hours) << "): ";
	cin >> userinput;
	system("cls");
	return hours[userinput - 1]; // not working correctly, pls fix
}

string getDay() { // user picks day
	int userinput;
	
	for (int i = 1; i <= size(weekdays); i++) {
		cout << i << ". " << weekdays[i - 1] << endl;
	}
	cout << "Pick a day to Donate" << endl;
	cin >> userinput;
	system("cls");
	return weekdays[userinput - 1];
}

void BookAppointment(string user) { // Gives user object both day of and time of appointment
	system("cls");

	json j_Schedule = getSchedulejson();

	ifstream in("user_data.json");
	json Doc = json::parse(in);

	string day = getDay();
	int hour = getHour(j_Schedule, day);

	Doc[user]["Appointment_Date"]["day"] = day;
	Doc[user]["Appointment_Date"]["Hour"] = hour;

	

	fstream file;
	file.open("user_data.json", std::ios::out);
	file << std::setw(4) << Doc;
	file.close();
	inSchedule(day, hour, user, j_Schedule);
}