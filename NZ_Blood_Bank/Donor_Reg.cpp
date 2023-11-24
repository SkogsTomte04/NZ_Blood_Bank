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

void Register() {
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
			{"DOB", userStruct.DOB},
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
	updateJson(Doc, "user_data.json");
}