#include "Donor_Reg.h"
#include "jsonManager.h"


using json = nlohmann::ordered_json;
using namespace std;

std::array <int,3> getDate(string category) {
	string dmy[3] = {"Day (DD)", "Month (MM)", "Year (YY)"};
	array <int, 3> date;
	
	cout << category << endl;
	for (int i = 0; i < size(date); i++) {
		cout << dmy[i] << ": ";
		cin >> date[i];
	}

	return date;
}

string getString(string category) {
	string str;
	cout << category << ": ";

	cin >> str;
	return str;
}

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
	/*ifstream in("user_data.json");
	auto Doc = nlohmann::ordered_json::parse(in);*/ //creates a json object 
	json Doc = getUserdata();

	struct User
	{
		string username;
		string firstName;
		string lastName;
		array<int,3> DOB;
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

	userStruct.username = getUsername(Doc);
	userStruct.firstName = getString("First name");
	userStruct.lastName = getString("Last name");
	userStruct.DOB = getDate("Date of birth");
	userStruct.nationality = getString("Nationality");
	userStruct.ethnicity = getString("Ethnicity");

	Doc[userStruct.username] = {
		{"User_Info", {
			{"First_Name", userStruct.firstName},
			{"Last_Name", userStruct.lastName},
			{"DOB", {
				{"DD", userStruct.DOB[0]},
				{"MM", userStruct.DOB[1]},
				{"YY", userStruct.DOB[2]}
			}},
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


	//fstream file;
	//file.open("user_data.json", std::ios::out); // opens json file
	//file << std::setw(4) << Doc; // inserts changes into json file
	//file.close(); // close json file
	updateJson(Doc, "user_data.json");
}