#include "jsonManager.h"

using namespace std;
using json = nlohmann::ordered_json;

void printuserSchedule(json j, string username, string type) {
    std::cout << colors::yellow << " [" << colors::reset;
    std::cout << colors::white << "Booked Date" << colors::reset;
    std::cout << colors::yellow << "]" << colors::reset << endl;
    for (auto it = j[type][username]["Appointment_Date"].begin(); it != j[type][username]["Appointment_Date"].end(); it++) {
        if (it.value().is_string()) { // check if iterator value is a string
            string tempStr = it.value(); // assign string to temporary variable 
            std::cout << " | | " << colors::yellow << it.key() << ": " << colors::bright_grey << tempStr << colors::reset << endl; // print value and key
        }
        else { // if value is not string: print out value without temporary variable
            std::cout << " | | " << colors::yellow << it.key() << ": " << colors::bright_grey << it.value() << colors::reset << endl;
        }
    }
}

void printuserInfo(json j, string username, string type) {
    std::cout << colors::yellow << " [" << colors::reset;
    std::cout << colors::white << "User info" << colors::reset;
    std::cout << colors::yellow << "]" << colors::reset << endl;
    for (auto it = j[type][username]["User_Info"].begin(); it != j[type][username]["User_Info"].end(); it++) {
        if (it.value().is_string()) { // check if iterator value is a string
            string tempStr = it.value(); // assign string to temporary variable 
            std::cout << " | | " << colors::yellow << it.key() << ": " << colors::bright_grey << tempStr << colors::reset << endl; // print value and key
        }
        else { // if value is not string: print out value without temporary variable
            std::cout << " | | " << colors::yellow << it.key() << ": " << colors::bright_grey << it.value() << colors::reset << endl;
        }
    }
}

void printUser(json j, string username, string type) { // might want to denest this into smaler functions like printuserSchedule() and printuserInfo
    string str, tempStr;
    
    std::cout << colors::green << "[ " << colors::reset;
    std::cout << colors::white << username << colors::reset;
    std::cout << colors::green << " ]" << colors::reset << endl;

    printuserInfo(j, username, type);
    if (j[type][username].contains("Appointment_Date")) {
        printuserSchedule(j, username, type);
    }
    std::cout << endl;
}

void updateJson(json j, string filepath) {
	fstream file;
	file.open(filepath, std::ios::out);
	file << std::setw(4) << j;
	file.close();
}

json getUserdata() {
	ifstream in("user_data.json");
	auto j = nlohmann::ordered_json::parse(in);

	return j;
}

json getScheduledata() {
	ifstream in("Schedule.json");
	auto j = nlohmann::ordered_json::parse(in);

	return j;
}