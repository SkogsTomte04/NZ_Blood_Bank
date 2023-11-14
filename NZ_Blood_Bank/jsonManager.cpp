#include "jsonManager.h"

using namespace std;
using json = nlohmann::ordered_json;

void printUser(json j, string user, string type) {
	cout << j[type][user]
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