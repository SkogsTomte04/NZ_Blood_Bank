#pragma once
#include <iostream>
#include <fstream>
#include "json.hpp"
using json = nlohmann::json;
using namespace std;

bool PasswordCheck(json j, string str) {
	string password;
	cout << "Password: ";
	cin >> password;
	if (j[str]["Password"] == password) {
		return true;
	}
	else { return false; }
}

bool FindUsername(json j,string usr) {
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

string LogIn(){
	system("cls");
	
	ifstream in("user_data.json");
	json Doc = json::parse(in);
	
	string username;
	cout << "UserName: ";
	
	cin >> username;
	
	if (FindUsername(Doc, username)) {
		Doc[username]["isActive"] = true;
		return username;
	}
	else {
		return "exe.fail";
	}
	

}