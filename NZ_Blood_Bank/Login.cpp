#include "LogIn.h"
#include "colors.hpp"

using json = nlohmann::json;
using namespace std;


bool PasswordCheck(json j, string str, string type) {
	string password;
	cout << colors::white << "Password: " << colors::green;
	cin >> password;
	if (type == "Donator") {
		if (j["Donators"][str]["User_Info"]["Password"] == password) {
			return true;
		}
	}
	if (type == "admin") {
		if (j["ADMINS"][str]["Password"] == password) {
			return true;
		}
	}
	
	else { return false; }
}

bool getLogin(json j, string usr) {
	if (j["Donators"].contains(usr)) {

		if (PasswordCheck(j, usr, "Donator")) {
			return true;
		}
		else {
			cout << colors::red << "\n/!\\ " << colors::white << "Error: Incorrect Password!" << colors::reset << endl;
			system("pause");
			system("cls");
			return false;
		}
	}
	else if (j["ADMINS"].contains(usr)) {
		if (PasswordCheck(j, usr, "admin")) {
			return true;
		}
		else {
			cout << colors::red << "\n/!\\ " << colors::white << "Error: Incorrect Password!" << colors::reset << endl;
			system("pause");
			system("cls");
			return false;
		}
	}
	else {
		cout << colors::red << "\n/!\\ " << colors::white << "Error: Username not found!" << colors::reset << endl;
		system("pause");
		system("cls");
		return false;
	}
}

string LogIn() {
	system("cls");

	ifstream in("user_data.json");
	json Doc = json::parse(in);

	string username;
	cout << colors::bright_red << "[!] " << colors::bright_grey << "You choosed Login." << colors::reset << endl;
	cout << colors::white << "Username: " << colors::green;

	cin >> username;

	if (getLogin(Doc, username)) {
		return username;
	}
	else {
		return "exe.fail";
	}

}
