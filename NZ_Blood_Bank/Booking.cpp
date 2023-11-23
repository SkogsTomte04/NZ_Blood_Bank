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

int getTime(json j, string day) { // user picks time of day
	int userinput;
	vector<int> Available_H = getAvailableHours(j, day);
	cout << colors::bright_red << "\n[!] " << colors::bright_grey << "You chose " << colors::reset << endl;
	cout << colors::bright_grey << "Pick a time of day from (1 - " << size(Available_H) << "): " << colors::reset << endl;
	for (int i = 0; i < size(Available_H); i++) {
		cout << colors::white << i + 1 << ". (" << colors::yellow << Available_H[i] << ":00" << colors::white << ")" << colors::reset << endl;
	}
	cout << colors::white << "\nAnswer: " << colors::green;
	userinput = getInt();
	system("cls");
	return Available_H[userinput - 1];
}

string getDay() { // user picks day
	int userinput;
	
	cout << colors::bright_red << "\n[!] " << colors::bright_grey << "You chose change date." << colors::reset << endl;
	cout << colors::bright_grey << "Pick a day to donate from (1-5)" << endl;
	for (int i = 1; i <= size(weekdays); i++) {
		cout << colors::white << i << ". " << colors::yellow << weekdays[i - 1] << endl;
	}
	cout << colors::white << "\nAnswer: " << colors::green;
	userinput = getInt();
	system("cls");
	return weekdays[userinput - 1];
}

json updateUserdate(json j, string day, int time, string user) {
	j["Donators"][user]["Appointment_Date"]["Day"] = day;
	j["Donators"][user]["Appointment_Date"]["Time"] = time;
	return j;
}

json NewDate(json j, string day, string time, string user) {
	
	j["Days"][day][time] = user;
	j["Clients"]["Donation"][user] = { { "Day",day }, {"Time", time}};
	return j;
}

void BookAppointment(string user) { // Gives user object both day of and time of appointment
	system("cls");
	json j_Userdata = getUserdata();
	json j_Schedule = getScheduledata();

	string day;
	int time;

	if (j_Schedule["Clients"]["Donation"].contains(user)) {
		int userinput;
		time = j_Userdata["Donators"][user]["Appointment_Date"]["Time"];
		day = j_Userdata["Donators"][user]["Appointment_Date"]["Day"];

		cout << colors::bright_grey << "Enter your answer from (1-3): " << colors::reset << endl;
		cout << colors::white << "1. Change date" << colors::reset << endl;
		cout << colors::white << "2. Unbook" << colors::reset << endl;
		cout << colors::white << "3. Back to home" << colors::reset << endl;
		cout << colors::white << "\nAnswer: " << colors::green;
		cout << "You already have a booked day!" << endl;
		printuserSchedule(j_Userdata, user, "Donators");
		cout << "\n\n1.Change date\n2.Unbook\n3.Back to home" << endl;
		userinput = getInt();

		if (userinput == 1) {
			j_Schedule["Days"][day][to_string(time)] = "Available";

			day = getDay();
			time = getTime(j_Schedule, day);

			j_Schedule = NewDate(j_Schedule, day, to_string(time), user);
			j_Userdata = updateUserdate(j_Userdata, day, time, user);
		}
		if (userinput == 2) {
			j_Schedule["Days"][day][to_string(time)] = "Available";
			j_Schedule["Clients"]["Donation"].erase(j_Schedule["Clients"]["Donation"].find(user));
			j_Userdata = updateUserdate(j_Userdata, "n/a", 0, user);
		}
		if (userinput == 3) {
			
		}
	}
	else {
		day = getDay();
		time = getTime(j_Schedule, day);

		j_Schedule = NewDate(j_Schedule, day, to_string(time), user);
		j_Userdata = updateUserdate(j_Userdata, day, time, user);
	}
	
	updateJson(j_Userdata, "user_data.json");
	updateJson(j_Schedule, "Schedule.json");
	
}