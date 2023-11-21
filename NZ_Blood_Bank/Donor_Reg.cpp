#include "Donor_Reg.h"
#include "jsonManager.h"
#include "colors.hpp"


using json = nlohmann::ordered_json;
using namespace std;

struct User
{
	string username;
	string firstName;
	string lastName;
	array<int, 3> DOB;
	string nationality;
	string ethnicity;
	vector<string> medical;
	string bloodGroup;
	string contact;
	string email;
	string adress;
	array<int, 3> prev_donation;
	string password;

};

string getString(string category) {
	string str;
	cout << colors::bright_grey << "\nEnter a " << category << ": " << colors::reset << endl;
	cout << colors::white << "\nAnswer: " << colors::green;

	//cin.ignore();
	getline(cin, str);

	return str;
}

long int getInt(string category) {
	long int i;
	cout << colors::bright_grey << "\nEnter a " << category << ": " << colors::reset << endl;
	cout << colors::white << "\nAnswer: " << colors::green;

	cin >> i;

	cin.ignore();
	return i;
}

std::vector <string> getVector(string category) {
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

std::array <int,3> getDate(string category) {
	string dmy[3] = {"Day (DD)", "Month (MM)", "Year (YY)"};
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

string getUsername(nlohmann::ordered_json j) {
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

void Register() {
	/*ifstream in("user_data.json");
	auto Doc = nlohmann::ordered_json::parse(in);*/ //creates a json object 
	json Doc = getUserdata();

	User userStruct;

	userStruct.username = getUsername(Doc);
	userStruct.password = getString("Password");
	userStruct.firstName = getString("First Name");
	userStruct.lastName = getString("Last Name");
	userStruct.DOB = getDate("Date of Birth");
	userStruct.nationality = getString("Nationality");
	userStruct.ethnicity = getString("Ethnicity");
	userStruct.medical = getVector("Medical Record");
	userStruct.bloodGroup = getString("Blood Group");
	userStruct.contact = getString("Contact Number");
	userStruct.email = getString("Email");
	userStruct.adress = getString("Adress");
	userStruct.prev_donation = getDate("Previous Donation Date (Enter \"0\" if there is no previous date)");
	

	Doc["Donators"][userStruct.username] = {
		{"User_Info", {
			{"First_Name", userStruct.firstName},
			{"Last_Name", userStruct.lastName},
			{"DOB", userStruct.DOB/*{
				{"DD", userStruct.DOB[0]},
				{"MM", userStruct.DOB[1]},
				{"YY", userStruct.DOB[2]}
			}*/},
			{"Nationality", userStruct.nationality},
			{"Ethnicity", userStruct.ethnicity},
			{"Medical", userStruct.medical},
			{"Blood_Group", userStruct.bloodGroup},
			{"Contact_no", userStruct.contact},
			{"Email", userStruct.email},
			{"Adress", userStruct.adress},
			{"Prev_Donation_Date", userStruct.prev_donation},
			{"Password", userStruct.password}
		}},
		{"Appointment_Date", {
			{"Day", "N/A"},
			{"Time", 0}
		}}
	};


	//fstream file;
	//file.open("user_data.json", std::ios::out); // opens json file
	//file << std::setw(4) << Doc; // inserts changes into json file
	//file.close(); // close json file
	updateJson(Doc, "user_data.json");
}