#include "Donor_Reg.h"

using json = nlohmann::ordered_json;
using namespace std;

string FileArray[12] = { "First_Name", "Last_Name",
"dob", "Nationality", "Ethnicity", "Med_Conditions",
"Blood_Group", "Contact_no", "Email", "Adress",
"Prev_Donation_Date", "Password" };

string getUsername(nlohmann::ordered_json j) {
	bool isUnique = false;
	string str;
	while (!isUnique) {
		cout << "Enter a Username: " << endl;
		cin >> str;
		if (j.contains(str)) {
			system("cls");
			cout << "Username taken!" << endl;
		}
		else {
			return str;
		}
	}
}

void Register() {
	ifstream in("user_data.json");
	auto Doc = nlohmann::ordered_json::parse(in); //creates a json object 

	struct User
	{
		string username;
		string firstName;
		string lastName;
		int DOB[3];
		string nationality;
		string ethnicity;
		vector<string> medical;
		string bloodGroup;
		int contact;
		string email;
		string adress;
		int prev_donation[3];
		string password;

	}userStruct;

	userStruct.firstName = getUsername(Doc);

	Doc[userStruct.username] = {
		{"User_Info", {
			{"First_Name", userStruct.firstName},
			{"Last_Name", userStruct.lastName},
			{"DOB", userStruct.DOB},
			{"Nationality", userStruct.nationality},
			{"Ethnicity", userStruct.ethnicity},
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


	fstream file;
	file.open("user_data.json", std::ios::out); // opens json file
	file << std::setw(4) << Doc; // inserts changes into json file
	file.close(); // close json file
}