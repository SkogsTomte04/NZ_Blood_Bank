#include "Donor_Reg.h"

using json = nlohmann::json;
using namespace std;

<<<<<<< Updated upstream
string FileArray[12] = { "First_Name", "Last_Name", "dob", "Nationality", "Ethnicity", "Med_Conditions", "Blood_Group", "Contact_no", "Email", "Adress", "Prev_Donation_Date", "Password" };


string getUsername() {
=======
string FileArray[12] = { "First_Name", "Last_Name", 
"dob", "Nationality", "Ethnicity", "Med_Conditions", 
"Blood_Group", "Contact_no", "Email", "Adress", 
"Prev_Donation_Date", "Password" };

string getUsername(nlohmann::ordered_json j) {
	bool isUnique = false;
>>>>>>> Stashed changes
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
	system("cls");

	ifstream in("user_data.json");
<<<<<<< Updated upstream
	json Doc = json::parse(in);
=======
	auto Doc = nlohmann::ordered_json::parse(in); //creates a json object 
>>>>>>> Stashed changes

	struct User
	{
		string username = getUsername(Doc);
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

<<<<<<< Updated upstream
	Doc[username];

	Doc[username]["isActive"] = false;
	Doc[username]["Appointment_Date"] = { {"day", "n/a"} , {"Hour", 0} };

	for (int i = 0; i < size(FileArray); i++) {
		string userInput;

		cout << FileArray[i] << ": ";
		getline(cin, userInput);
		while (userInput.length() == 0) {
			getline(cin, userInput);
		}
		Doc[username]["User_Info"][FileArray[i]] = userInput;
	}
=======
	}userStruct;

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
	

>>>>>>> Stashed changes
	fstream file;
	file.open("user_data.json", std::ios::out);
	file << std::setw(4) << Doc;
	file.close();
}