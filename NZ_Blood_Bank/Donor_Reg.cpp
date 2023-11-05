#include "Donor_Reg.h"

using json = nlohmann::ordered_json;
using namespace std;

string FileArray[12] = { "First_Name", "Last_Name", 
"dob", "Nationality", "Ethnicity", "Med_Conditions", 
"Blood_Group", "Contact_no", "Email", "Adress", 
"Prev_Donation_Date", "Password" };



string getUsername() {
	string str;
	cout << "Enter a Username: " << endl;
	cin >> str;

	return str;
}

void Register() {
	system("cls");

	ifstream in("user_data.json");
	json Doc = json::parse(in); //creates a json object 

	string username = getUsername();

	Doc[username]; // new user initialization

	for (int i = 0; i < size(FileArray); i++) {
		string userInput;

		cout << FileArray[i] << ": ";
		getline(cin, userInput);
		while (userInput.length() == 0) {
			getline(cin, userInput);
		}
		Doc[username]["User_Info"][FileArray[i]] = userInput;
	}
	
	Doc[username]["Appointment_Date"] = { {"day", "n/a"} , {"Hour", 0} };

	fstream file;
	file.open("user_data.json", std::ios::out); // opens json file
	file << std::setw(4) << Doc; // inserts changes into json file
	file.close(); // close json file
}