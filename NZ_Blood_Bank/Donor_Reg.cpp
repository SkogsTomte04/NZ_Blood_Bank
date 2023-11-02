#include "Donor_Reg.h"

using json = nlohmann::json;
using namespace std;

string FileArray[12] = { "First_Name", "Last_Name", "dob", "Nationality", "Ethnicity", "Med_Conditions", "Blood_Group", "Contact_no", "Email", "Adress", "Prev_Donation_Date", "Password" };


string getUsername() {
	string str;
	cout << "Enter a Username: " << endl;
	cin >> str;

	return str;
}

void Register() {
	system("cls");

	ifstream in("user_data.json");
	json Doc = json::parse(in);

	string username = getUsername();

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
	fstream file;
	file.open("user_data.json", std::ios::out);
	file << std::setw(4) << Doc;
	file.close();
}