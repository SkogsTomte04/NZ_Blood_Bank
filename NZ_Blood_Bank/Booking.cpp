#include "Booking.h"

using json = nlohmann::json;
using namespace std;

int getHour() { // user picks time of day
	int userinput;

	array<int, 8> hours;
	iota(hours.begin(), hours.end(), 9);

	for (int i = 1; i <= size(hours); i++) {
		cout << i << ". " << hours[i - 1] << ":00" << endl;
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

<<<<<<< Updated upstream
=======
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

>>>>>>> Stashed changes
void BookAppointment(string user) { // Gives user object both day of and time of appointment
	system("cls");

	ifstream in("user_data.json");
	json Doc = json::parse(in);

<<<<<<< Updated upstream
	Doc[user]["Appointment_Date"]["day"] = getDay();
	Doc[user]["Appointment_Date"]["Hour"] = getHour();
=======
	string day;
	int time;

	if (j_Schedule["Clients"].contains(user)) {
		int userinput;
		time = j_Userdata[user]["Appointment_Date"]["Time"];
		day = j_Userdata[user]["Appointment_Date"]["Day"];

		cout << "You already have a booked day!\n\n1. Change date\n2. Unbook\n3. Back to home" << endl;
		cin >> userinput;

		system("cls");
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
	
>>>>>>> Stashed changes

	fstream file;
	file.open("user_data.json", std::ios::out);
	file << std::setw(4) << Doc;
	file.close();
}