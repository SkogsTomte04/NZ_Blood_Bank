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

json updateUserdate(json j, string day, int time, string user) {
	j[user]["Appointment_Date"]["Day"] = day;
	j[user]["Appointment_Date"]["Time"] = time;
	return j;
}

json NewDate(json j, string day, string time, string user) {
	
	j["Days"][day][time] = user;
	j["Clients"][user] = "Donation";
	return j;
}

void BookAppointment(string user) { // Gives user object both day of and time of appointment
	system("cls");

	ifstream readUserdata("user_data.json");
	ifstream readSchedule("Schedule.json");
	json j_Userdata = json::parse(readUserdata);
	json j_Schedule = json::parse(readSchedule);

	string day;
	int time;

	if (j_Schedule["Clients"].contains(user)) {
		int userinput;
		time = j_Userdata[user]["Appointment_Date"]["Time"];
		day = j_Userdata[user]["Appointment_Date"]["Day"];

		cout << "You already have a booked day!\n\n1. Change date\n2. Unbook\n3. Back to home" << endl;
		cin >> userinput;

		if (userinput == 1) {
			j_Schedule["Days"][day][to_string(time)] = "Available";

			day = getDay();
			time = getHour(j_Schedule, day);

			j_Schedule = NewDate(j_Schedule, day, to_string(time), user);
			j_Userdata = updateUserdate(j_Userdata, day, time, user);
		}
		if (userinput == 2) {
			j_Schedule["Days"][day][to_string(time)] = "Available";
			j_Schedule["Clients"].erase(j_Schedule["Clients"].find(user));
			j_Userdata = updateUserdate(j_Userdata, "n/a", 0, user);
		}
		if (userinput == 3) {
			
		}
	}
	else {
		day = getDay();
		time = getHour(j_Schedule, day);

		j_Schedule = NewDate(j_Schedule, day, to_string(time), user);
		j_Userdata = updateUserdate(j_Userdata, day, time, user);
	}
	

	fstream file;
	file.open("user_data.json", std::ios::out);
	file << std::setw(4) << j_Userdata;
	file.close();
	fstream fileTwo;
	fileTwo.open("Schedule.json", std::ios::out);
	fileTwo << std::setw(4) << j_Schedule;
	fileTwo.close();
	
}