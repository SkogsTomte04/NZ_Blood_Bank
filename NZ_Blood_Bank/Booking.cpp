#include "Booking.h"

using json = nlohmann::ordered_json;
using namespace std;

string weekdays[5] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
vector<int> hours = { 9, 10, 11, 12, 13, 14, 15, 16 };



vector<int> getAvailableHours(json j, string day) {
	vector<int> Available_H;

	for (int i = 0; i < size(hours); i++) {
		string i_str = to_string(hours[i]);
		if (j["Days"][day][i_str] == "Available") {
			Available_H.push_back(hours[i]);
		}
	}
	return Available_H;
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
	vector<int> Available_H = getAvailableHours(j, day);
	for (int i = 0; i < size(Available_H); i++) {
		cout << i + 1 << ". (" << Available_H[i] << ":00)" << endl;
	}
	cout << "Pick a time of day (1 - " << size(Available_H) << "): ";
	cin >> userinput;
	system("cls");
	return Available_H[userinput - 1];
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

	ifstream readUserdata("user_data.json");
	ifstream readSchedule("Schedule.json");
	json j_Userdata = json::parse(readUserdata);
	json j_Schedule = json::parse(readSchedule);

	string day = getDay();
	int hour = getHour(j_Schedule, day);

	j_Userdata[user]["Appointment_Date"]["day"] = day;
	j_Userdata[user]["Appointment_Date"]["Hour"] = hour;

	

	fstream file;
	file.open("user_data.json", std::ios::out);
	file << std::setw(4) << j_Userdata;
	file.close();
	inSchedule(day, hour, user, j_Schedule);
}