#include "LogIn.h"

using json = nlohmann::json;
using namespace std;


bool PasswordCheck(json j, string str) {
	string password;
	cout << "Password: ";
	cin >> password;
	
	if (j[str]["User_Info"]["Password"] == password) {
		return true;
	}
	else { return false; }
}

bool getLogin(json j, string usr) {
	if (j.contains(usr)) {

		if (PasswordCheck(j, usr)) {
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
		ofstream file("user_data.json");
		file << setw(4) << Doc;
		return username;
	}
	else {
		return "exe.fail";
	}


}
