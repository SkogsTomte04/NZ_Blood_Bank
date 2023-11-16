#include "jsonManager.h"

using namespace std;
using json = nlohmann::ordered_json;

void printUser(json j, string username, string type) { // might want to be able to print recipiants too
    string str, tempStr;
    
    std::cout << colors::green << "[ " << colors::reset;
    std::cout << colors::white << username << colors::reset;
    std::cout << colors::green << " ]" << colors::reset << endl;

    for (auto it = j[type][username].begin(); it != j[type][username].end(); it++) {
        std::cout << " | " << colors::red << it.key() << colors::reset << endl;
        for (auto it2 = j[type][username][it.key()].begin(); it2 != j[type][username][it.key()].end(); ++it2) {
            if (it2.value().is_string()) { // check if iterator value is a string
                tempStr = it2.value(); // assign string to temporary variable 
                std::cout << " | | " << colors::yellow << it2.key() << ": " << colors::bright_grey << tempStr << colors::reset << endl; // print value and key
            }
            else { // if value is not string: print out value without temporary variable
                std::cout << " | | " << colors::yellow << it2.key() << ": " << colors::bright_grey << it2.value() << colors::reset << endl;
            }
        }
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