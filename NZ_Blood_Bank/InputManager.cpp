#include "InputManager.h"

using namespace std;
using json = nlohmann::ordered_json;

int getInt() { // validates then returns a userinput of type "int"
	int input = 0;
	bool valid = false;
	do {
		std::cin >> input;
		if (std::cin.good()) {
			valid = true;
		}
		else {
			std::cin.clear();
			std::cin.ignore((std::numeric_limits<uint32_t>::max)(), '\n');
			std::cout << "Invalid input, try again: ";
		}
	} while (!valid);

	return input;
}

string getString(string category) {
	string str;
	cout << colors::bright_grey << "\nEnter a " << category << ": " << colors::reset << endl;
	cout << colors::white << "\nAnswer: " << colors::green;

	getline(cin, str);

	return str;
}

std::vector <string> getVector(string category) { // returns vector with users medical conditions
	vector<string> vec;
	string str;

	while (true) {
		cout << endl << colors::bright_red << category << colors::reset << endl;
		for (int i = 0; i < size(vec); i++) {
			cout << vec[i] << endl;
		}
		str = getString("medical condition,\nor \"none\" if you don't have anything more to say");
		cout << endl;
		if (str != "none") {
			vec.push_back(str);
		}
		else if (str == "none") {
			break;
		}
		system("cls");
	}

	system("cls");
	return vec;
}

std::array <int, 3> getDate(string category) { // returns an array with values dd/mm/yy
	string dmy[3] = { "Day (DD)", "Month (MM)", "Year (YY)" };
	array <int, 3> date;

	cout << endl << colors::bright_red << category << colors::reset << endl;
	cout << colors::bright_grey << "For example, you can put 01 for DD, which stands for the first day of the month, \n" << colors::reset;
	cout << colors::bright_grey << "08 for MM, meaning the month of August, and 24 for YY, meaning the year 2024.\n" << colors::reset;
	for (int i = 0; i < size(date); i++) {
		cout << colors::bright_grey << "\nEnter a " << dmy[i] << ": " << endl;
		cout << colors::white << "\nAnswer: " << colors::green;
		cin >> date[i];
	}
	cin.ignore();
	return date;
}

string getUsername(nlohmann::ordered_json j) { // returns a unique usename for user
	bool isUnique = false;
	string str;
	while (!isUnique) {
		cout << colors::bright_red << "\n[!] " << colors::bright_grey << "You chose donate." << colors::reset << endl;
		cout << colors::bright_grey << "Enter a Username:" << colors::reset << endl;
		cout << colors::white << "\nAnswer: " << colors::green;
		cin >> str;
		cin.ignore();
		if (j["Donators"].contains(str)) {
			system("cls");
			cout << colors::red << "\n/!\\ " << colors::white << "Error: Username taken!" << colors::reset << endl;
		}
		else {
			return str;
		}
	}
}