#include "jsonManager.h"

using namespace std;
using json = nlohmann::ordered_json;

void printUser(json j, string username) { // might want to be able to print recipiants too
    string tempStr;
    cout << colors::white << username << colors::reset << endl;
    
    for (auto it = j["Donators"][username].begin(); it != j["Donators"][username].end(); it++) {
        cout << " " << colors::bright_magenta << it.key() << endl;
        for (auto it2 = j["Donators"][username][it.key()].begin(); it2 != j["Donators"][username][it.key()].end(); ++it2) {
            if (it2.value().is_string()) { // check if iterator value is a string
                tempStr = it2.value(); // assign string to temporary variable 
                cout << "  " << colors::bright_blue << it2.key() << ": " << colors::bright_grey << tempStr << colors::reset << endl; // print value and key
            }
            else { // if value is not string: print out value without temporary variable
                cout << "  " << colors::bright_blue << it2.key() << ": " << colors::bright_grey << it2.value() << colors::reset << endl;
            }
        }
    }
    cout << endl;
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