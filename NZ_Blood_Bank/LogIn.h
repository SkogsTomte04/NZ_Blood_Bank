#pragma once
#include <iostream>
#include <fstream>
#include "json.hpp"
using json = nlohmann::json;
using namespace std;

bool PasswordCheck(json j, string str) {
	string password;
	getline(cin, password);
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
			return false;
		}
	}
	else {
		cout << "Username not found!" << endl;
		return false;
	}
}

string LogIn(){
	ifstream in("user_data.json");
	json Doc = json::parse(in);
	
	string username;
	cout << "UserName: ";
	getline(cin, username);

	
	if (FindUsername(Doc, username)) {
		Doc[username]["isActive"] = true;
		return username;
	}
	else {
		return "exe.fail";
	}
	
	cout << "gobedu";
}