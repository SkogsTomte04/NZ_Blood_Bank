#include "LogIn.h"

using json = nlohmann::json;
using namespace std;


bool PasswordCheck(json j, string str, string type) {
	string password;
	cout << "Password: ";
	cin >> password;
	if (type == "donator") {
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

		if (PasswordCheck(j, usr, "donor")) {
			return true;
		}
		else {
			cout << "Incorrect Password" << endl;
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
			cout << "Incorrect Password" << endl;
			system("pause");
			system("cls");
			return false;
		}
	}
	else {
		cout << "Username not found!" << endl;
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
	cout << "UserName: ";

	cin >> username;

	if (getLogin(Doc, username)) {
		return username;
	}
	else {
		return "exe.fail";
	}

}
