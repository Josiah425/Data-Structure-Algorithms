#include <string>
#include <iostream>
#include <iomanip>
#include "Voter.h"
#include <stdlib.h>

Voter::Voter(){
	userId = "-1";
	password = "WAYTOLONGOFAPASSWORDTOBEAPASSWORD";
	firstName = "*!@#&!$";
	lastName = "*#$@#$&@#$";
	age = -1;
	streetNumber = -1;
	streetName = "This is not a real road";
	zipCode = -1;
	town = "A nonexistant town";
	amountDonated = -1;
}

Voter::Voter(std::string userId, std::string password,std::string firstName,std::string lastName,int age,int streetNumber,std::string streetName,std::string town, State state, int zipCode, double amountDonated){
	this->userId = userId;
	this->password = password;
	this->firstName = firstName;
	this->lastName = lastName;
	this->age = age;
	this->streetNumber = streetNumber;
	this->streetName = streetName;
	this->town = town;
	this->state = state;
	this->zipCode = zipCode;
	this->amountDonated = amountDonated;
}

Voter::~Voter(){

}

void Voter::Update(std::string command){
	std::cout << "Enter Change: \n";
	if(command == "firstname"){
		std::cin >> firstName;
		while(!ValidName(firstName)){
			std::cout << "Name must contain only letters\nFirst Name: ";
			std::cin >> firstName;
		}
	}
	else if(command == "lastname"){
		std::cin >> lastName;
		while(!ValidName(lastName)){
			std::cout << "Name must contain only letters\nLast Name: ";
			std::cin >> lastName;
		}
	}
	else if(command == "age"){
		std::string ageStr;
		std::cin >> ageStr;
		while(!ValidAge(ageStr)){
			std::cout << "Age must be more than 18\nAge: ";
			std::cin >> ageStr;
		}
		age = atoi(ageStr.c_str());
	}
	else if(command == "streetnumber"){
		std::string streetNumberStr;
		std::cin >> streetNumberStr;
		while(!ValidStreetNumber(streetNumberStr)){
			std::cout << "Street number must be positive\nStreet Number: ";
			std::cin >> streetNumberStr;
		}
		streetNumber = atoi(streetNumberStr.c_str());
	}
	else if(command == "streetname"){
		std::getline(std::cin, streetName);
	}
	else if(command == "town"){
		std::getline(std::cin, town);
	}
	else if(command == "state"){
		std::string stateStr;
		std::getline(std::cin, stateStr);
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
	}
	else if(command == "zipcode"){
		std::string zipCodeStr;
		std::cin >> zipCodeStr;
		while(!ValidZipCode(zipCodeStr)){
			std::cout << "Zip Code must be exactly 5 digits long\nZip Code: ";
			std::cin >> zipCodeStr;
		}
		zipCode = atoi(zipCodeStr.c_str());
	}
}

void Voter::ChangePassword(){
	std::cout << "Enter new password: \n";
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
}

void Voter::View(){
	std::string stateStr;
	if(state == NY){
		stateStr = "NY";
	}
	else if(state == PA){
		stateStr = "PA";
	}
	else if(state == ME){
		stateStr = "ME";
	}
	else if(state == VT){
		stateStr = "VT";
	}
	else if(state == NH){
		stateStr = "NH";
	}
	else if(state == RI){
		stateStr = "RI";
	}
	else if(state == MA){
		stateStr = "MA";
	} 
	else{
		stateStr = "CT";
	}	
	std::cout << "Name: " << lastName << ", " << firstName << std::endl;
	std::cout << "Age: " << age << std::endl;
	std::cout << "Address: " << streetNumber << ' ' << streetName << ' ' << town << ", " << stateStr << ' ' << zipCode << std::endl;
	std::cout << "Amount Donated: $" << std::fixed << std::setprecision(2) << amountDonated << std::endl;
}

void Voter::Donate(double amount){
	amountDonated += amount;
}

void Voter::Report(){
	std::cout << lastName << " $" << std::fixed << std::setprecision(2) << amountDonated << std::endl;
}

bool Voter::ValidDonation(double amount){
	bool returnVal = true;
	if(amount < 0 || amountDonated + amount > 2700){
		returnVal = false;
	}
	if(amount < 0){
		std::cout << "Invalid donation\n";
	}
	else if(amountDonated + amount > 2700){
		std::cout << "Amount entered will put you over donation limit." << std::endl;
	}

	return returnVal;
}

bool Voter::ValidPassword(std::string passwordStr){
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

bool Voter::ValidStreetNumber(std::string streetNumberStr){
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

bool Voter::ValidZipCode(std::string zipCodeStr){
	for(int i = 0; i < zipCodeStr.length(); i++){
		if(!isdigit(zipCodeStr.at(i)) || zipCodeStr.length() != 5){
			return false;
		}
	}
	return true;
}

bool Voter::ValidName(std::string name){
	bool returnVal = true;
	for(int i = 0; i < name.length(); i++){
		if(!((name.at(i) >= 'a' && name.at(i) <= 'z') || (name.at(i) >= 'A' && name.at(i) <= 'Z'))){
			returnVal = false;
		}
	}
	return returnVal;
}

bool Voter::ValidAge(std::string ageStr){
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

bool Voter::ValidState(std::string state){
	return state == "NY" || state == "PA" || state == "ME" || state == "VT" || state == "NH" || state == "RI" || state == "MA" || state == "CT";
}

bool ValidLowerCommand(std::string command){
	return command == "Update" || command == "Passwd" || command == "View" || command == "Donate" || command == "Report" || command == "Logout";
}

bool ValidUpdateCommand(std::string command){
	return command == "firstname" || command == "lastname" || command == "age" || command == "streetnumber" || command == "streetname" || command == "town" || command == "state" || command == "zipcode";
}

std::string Voter::getUserId(){
	return this->userId;
}

std::string Voter::getPassword(){
	return this->password;
}

std::string Voter::getFirstName(){
	return this->firstName;
}

std::string Voter::getLastName(){
	return this->lastName;
}

int Voter::getAge(){
	return this->age;
}

int Voter::getStreetNumber(){
	return this->streetNumber;
}

std::string Voter::getStreetName(){
	return this->streetName;
}

std::string Voter::getTown(){
	return this->town;
}

int Voter::getZipCode(){
	return this->zipCode;
}

std::string Voter::getState(){
	if(this->state == 0){
		return "NY";
	}
	else if(this->state == 1){
		return "PA";
	}
	else if(this->state == 2){
		return "ME";
	}
	else if(this->state == 3){
		return "VT";
	}
	else if(this->state == 4){
		return "NH";
	}
	else if(this->state == 5){
		return "RI";
	}
	else if(this->state == 6){
		return "MA";
	}
	else{
		return "CT";
	}
}

double Voter::getAmountDonated(){
	return this->amountDonated;
}
