#include <string>
#include <iostream>
#include <iomanip>
#include "VoterDatabase.h"
#include <stdlib.h>
#include <fstream>

VoterDatabase::VoterDatabase(){
	arr = NULL;
	maxVoters = 0;
	openSlots = maxVoters;
}

void VoterDatabase::init(int max){
	arr = new Voter[max];
	maxVoters = max;
	openSlots = max;
}

void VoterDatabase::init(std::string textfile, int max){
	maxVoters = max;
	std::ifstream file(textfile.c_str());
	std::string username;
	std::string pw;
	std::string firstname;
	std::string lastname;
	std::string age;
	std::string streetNumber;
	std::string streetName;
	std::string town;
	std::string zipCode;
	std::string amountDonated;
	std::string stateStr;
	State state;
	int ageInt;
	int streetNumberInt;
	int zipCodeInt;
	double amountDonatedDbl;
	int i = 0;
	arr = new Voter[max];
	terminate = false;
	while(file.good() && (i < maxVoters)){
		std::getline(file, username);
		std::getline(file, pw);
		std::getline(file, firstname);
		std::getline(file, lastname);
		std::getline(file, age);
		std::getline(file, streetNumber);
		std::getline(file, streetName);
		std::getline(file, town);
		std::getline(file, stateStr);
		std::getline(file, zipCode);
		std::getline(file, amountDonated);
		if(stateStr == "NY"){
		state = NY;
		}
		else if(stateStr == "PA"){
			state = PA;
		}
		else if(stateStr == "ME"){
			state = ME;
		}
		else if(stateStr == "VT"){
			state = VT;
		}
		else if(stateStr == "NH"){
			state = NH;
		}
		else if(stateStr == "RI"){
			state = RI;
		}
		else if(stateStr == "MA"){
			state = MA;
		} 
		else{
			state = CT;
		}
		ageInt = atoi(age.c_str());
		streetNumberInt = atoi(streetNumber.c_str());
		zipCodeInt = atoi(zipCode.c_str());
		amountDonatedDbl = atof(amountDonated.c_str());
		if(!file.eof()){
			arr[i] = Voter(username, pw, firstname, lastname, ageInt, streetNumberInt, streetName, town, state, zipCodeInt, amountDonatedDbl);
			i++;
			openSlots = maxVoters - i;
		}
	}
	std::string newLineChar;
	std::getline(file, newLineChar);
	if(!file.eof()){
		i++;
	}
	if(i > maxVoters){
		terminate = true;
	}
	file.close();
}

Voter VoterDatabase::NewVoter(){
	std::string userId;
	std::string password;
	std::string firstName;
	std::string lastName;
	int age;
	int streetNumber;
	std::string streetName;
	std::string town;
	State state;
	int zipCode;
	int amountDonated;
	std::cout << "Please Enter a username: ";
	std::cin >> userId;
	while(!ValidUserId(userId)){
		bool invalidAlpha = false;
		for(int i = 0; i < userId.length(); i++){
			if(!(isalpha(userId[i]) || isdigit(userId[i]))){
				invalidAlpha = true;
			}
		}
		if(userId.length() < 5 || userId.length() > 10){
			std::cout << "Username must be between 5 and 10 letters\nPlease Enter a username: ";
			std::cin >> userId;
		}
		else if(invalidAlpha){
			std::cout << "Username can only contain numbers and letters\nPlease Enter a username: ";
			std::cin >> userId;
		}
		else if(UserIdExists(userId)){
			std::cout << "Username already exists\nPlease Enter a username: ";
			std::cin >> userId;
		}
	}
	std::cout << "Enter a password: ";
	std::cin >> password;
	while(!ValidPassword(password)){
		bool nonAlpha = false;
		bool containsNum = false;
		for(int i = 0; i < password.length(); i++){
			if(!isalpha(password[i]) && !isdigit(password[i])){
				nonAlpha = true;
				continue;
			}
			if(isdigit(password[i])){
				containsNum = true;
			}
		}
		if(password.length() < 6){
			std::cout << "Password too short\nEnter a password: ";
			std::cin >> password;
		}
		else if(!nonAlpha || !containsNum){
			std::cout << "Password must contain at least 1 digit and 1 character that is not a digit or letter\nEnter a password: ";
			std::cin >> password;
		}
	}
	std::cout << "First Name: ";
	std::cin >> firstName;
	while(!ValidName(firstName)){
		std::cout << "Name must contain only letters\nFirst Name: ";
		std::cin >> firstName;
	}
	std::cout << "Last Name: ";
	std::cin >> lastName;
	while(!ValidName(lastName)){
		std::cout << "Name must contain only letters\nLast Name: ";
		std::cin >> lastName;
	}
	std::string ageStr;
	std::cout << "Age: ";
	std::cin >> ageStr;
	while(!ValidAge(ageStr)){
		std::cout << "Age must be more than 18\nAge: ";
		std::cin >> ageStr;
	}
	age = atoi(ageStr.c_str());
	std::string streetNumberStr;
	std::cout << "Street Number: ";
	std::cin >> streetNumberStr;
	while(!ValidStreetNumber(streetNumberStr)){
		std::cout << "Street number must be positive\nStreet Number: ";
		std::cin >> streetNumberStr;
	}
	streetNumber = atoi(streetNumberStr.c_str());
	std::cout << "Street Name: ";
	std::string tmp;
	std::getline(std::cin, tmp);
	std::getline(std::cin, streetName);
	std::cout << "Town: ";
	std::getline(std::cin, town);
	std::string stateStr;
	std::cout << "State: ";
	std::cin >> stateStr;
	while(!ValidState(stateStr)){
		std::cout << "State must be 2 characters and can only be NY, PA, or New England states.\nState: ";
		std::cin >> stateStr;
	}
	if(stateStr == "NY"){
		state = NY;
	}
	else if(stateStr == "PA"){
		state = PA;
	}
	else if(stateStr == "ME"){
		state = ME;
	}
	else if(stateStr == "VT"){
		state = VT;
	}
	else if(stateStr == "NH"){
		state = NH;
	}
	else if(stateStr == "RI"){
		state = RI;
	}
	else if(stateStr == "MA"){
		state = MA;
	} 
	else{
		state = CT;
	}
	std::string zipCodeStr;
	std::cout << "Zip Code: ";
	std::cin >> zipCodeStr;
	while(!ValidZipCode(zipCodeStr)){
		std::cout << "Zip Code must be exactly 5 digits long\nZip Code: ";
		std::cin >> zipCodeStr;
	}
	zipCode = atoi(zipCodeStr.c_str());
	amountDonated = 0;
	arr[maxVoters-openSlots] = Voter(userId, password, firstName, lastName, age, streetNumber, streetName, town, state, zipCode, amountDonated);
	openSlots--;
	return arr[maxVoters-openSlots+1];
}

void VoterDatabase::Update(Voter voter, std::string username){
	for(int i = 0; i < maxVoters; i++){
		if(arr[i].getUserId() == username){
			arr[i] = voter;
		}
	}
}

Voter VoterDatabase::Login(std::string username, std::string pw){
	for(int i = 0; i < maxVoters; i++){
		if(arr[i].getUserId() == username && arr[i].getPassword() == pw){
			return arr[i];
		}
	}
}

bool VoterDatabase::ValidLogin(std::string username, std::string pw){
	for(int i = 0; i < maxVoters; i++){
		if(arr[i].getUserId() == username && arr[i].getPassword() == pw){
			return true;
		}
	}
	return false;
}

void VoterDatabase::Save(std::string textfile){
	std::ofstream voterFile(textfile.c_str());
	for(int i = 0; i < maxVoters; i++){
		if(arr[i].getUserId() != "-1"){
			voterFile << arr[i].getUserId() << std::endl << arr[i].getPassword() << std::endl << arr[i].getFirstName() << std::endl << arr[i].getLastName() << std::endl << arr[i].getAge() << std::endl << arr[i].getStreetNumber() << std::endl << arr[i].getStreetName() << std::endl << arr[i].getTown() << std::endl << arr[i].getState() << std::endl << arr[i].getZipCode() << std::endl << arr[i].getAmountDonated() << std::endl;
		}
	}
	voterFile.close();
}

void VoterDatabase::Load(std::string file){
	init(file, maxVoters);
}

void VoterDatabase::Report(){
	int numberOfVoters = 0;
	double totalDonated = 0;
	for(int i = 0; i < maxVoters; i++){
		if(arr[i].getUserId() != "-1"){
			numberOfVoters++;
			totalDonated += arr[i].getAmountDonated();
		}
	}
	std::cout << "Number of Voters: " << numberOfVoters << std::endl << "Total Donated to Campaign: " << std::fixed << std::setprecision(2) << totalDonated << std::endl;
}

bool VoterDatabase::ValidStreetNumber(std::string streetNumberStr){
	bool returnVal = true;
	int streetNumberCheck = 0;
	if(streetNumberStr.length() < 1){
		returnVal = false;
	}
	for(int i = 0; i < streetNumberStr.length(); i++){
		if(!isdigit(streetNumberStr.at(i))){
			returnVal = false;
		}
	}
	if(returnVal){
		streetNumberCheck = atoi(streetNumberStr.c_str());
		if(streetNumberCheck < 1){
			returnVal = false;
		}
	}
	return returnVal;
	
}

bool VoterDatabase::ValidZipCode(std::string zipCodeStr){
	for(int i = 0; i < zipCodeStr.length(); i++){
		if(!isdigit(zipCodeStr.at(i)) || zipCodeStr.length() != 5){
			return false;
		}
	}
	return true;
}

bool VoterDatabase::ValidAge(std::string ageStr){
	bool returnVal = true;
	int ageCheck = 0;
	if(ageStr.length() < 1){
		returnVal = false;
	}
	for(int i = 0; i < ageStr.length(); i++){
		if(!isdigit(ageStr.at(i))){
			returnVal = false;
		}
	}
	if(returnVal){
		ageCheck = atoi(ageStr.c_str());
		if(ageCheck < 18){
			returnVal = false;
		}
	}
	return returnVal;
}

bool VoterDatabase::ValidName(std::string name){
	bool returnVal = true;
	for(int i = 0; i < name.length(); i++){
		if(!((name.at(i) >= 'a' && name.at(i) <= 'z') || (name.at(i) >= 'A' && name.at(i) <= 'Z'))){
			returnVal = false;
		}
	}
	return returnVal;
}

bool VoterDatabase::ValidPassword(std::string passwordStr){
	bool returnVal = true;
	bool nonAlpha = false;
	bool containsNum = false;
	for(int i = 0; i < passwordStr.length(); i++){
		if(!isalpha(passwordStr[i]) && !isdigit(passwordStr[i])){
			nonAlpha = true;
			continue;
		}
		if(isdigit(passwordStr[i])){
			containsNum = true;
		}
	}
	if(passwordStr.length() < 6){
		returnVal = false;
	}
	else if(!nonAlpha || !containsNum){
		returnVal = false;
	}
	return returnVal;
}

bool VoterDatabase::ValidState(std::string state){
	return state == "NY" || state == "PA" || state == "ME" || state == "VT" || state == "NH" || state == "RI" || state == "MA" || state == "CT";
}

bool VoterDatabase::ValidUserId(std::string user){
	bool returnVal = true;
	for(int i = 0; i < user.length(); i++){
		if(!(isalpha(user[i]) || isdigit(user[i]))){
			returnVal = false;
		}
	}
	return (user.length() > 5 && user.length() < 10) && returnVal && !UserIdExists(user);
}

bool VoterDatabase::UserIdExists(std::string user){
	std::string aWord;
	for(int i = 0; i < maxVoters; i++){
		if(arr[i].getUserId() == user){
			return true;
		}
	}
	return false;
}

bool VoterDatabase::CheckTerminate(){
	return terminate;
}

bool ValidTopCommand(std::string command){
	return command == "Login" || command == "New" || command == "Save" || command == "Load" || command == "Report" || command == "Quit";
}
