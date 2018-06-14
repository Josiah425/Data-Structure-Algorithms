#include <string>
#include <iostream>
#include <iomanip>
#include "Voter.h"

void NewVoter(float &amountDonated, std::string &lastName, std::string &firstName, int &streetNumber, std::string &streetName, int &age, std::string &town, int &zipcode){
	amountDonated = 0;
	std::cout << "Last Name: ";
	std::cin >> lastName;
	std::cout << "First Name: ";
	std::cin >> firstName;
	std::cout << "Age: ";
	std::cin >> age;
	std::cout << "Street Name: ";
	std::cin >> streetName;
	std::cout << "House Number: ";
	std::cin >> streetNumber;
	std::cout << "Town: ";
	std::cin >> town;
	std::cout << "Zip Code: ";
	std::cin >> zipcode;
	std::cout << std::endl;
}

void UpdateVoter(std::string &lastName, std::string &firstName, int &streetNumber, std::string &streetName, int &age, std::string &town, int &zipcode){
	std::cout << "Last Name: ";
	std::cin >> lastName;
	std::cout << "First Name: ";
	std::cin >> firstName;
	std::cout << "Age: ";
	std::cin >> age;
	std::cout << "Street Name: ";
	std::cin >> streetName;
	std::cout << "House Number: ";
	std::cin >> streetNumber;
	std::cout << "Town: ";
	std::cin >> town;
	std::cout << "Zip Code: ";
	std::cin >> zipcode;
	std::cout << std::endl;
}

void ViewInformation(float amountDonated, std::string lastName, std::string firstName, int streetNumber, std::string streetName, int age, std::string town, int zipcode){
	std::cout << "Voter Info\n" << firstName << ' ' << lastName << ": age " << age << '\n' << streetNumber << ' ' << streetName << '\n' << town << ", NY " << zipcode << '\n' << "Current Amount Donated: $" << std::fixed << std::setprecision(2) << amountDonated << std::endl << std::endl;
}

void DonateMoney(float &amountDonated){
	float newDonation = 0;
	std::cout << "\nEnter Amount to Donate: ";
	std::cin >> newDonation;
	std::cout << '$' << std::fixed << std::setprecision(2) << newDonation << " donated." << std::endl << std::endl;
	amountDonated += newDonation;

}

void ReportInformation(float amountDonated, std::string lastName){
	std::cout << lastName << " $" << std::fixed << std::setprecision(2) << amountDonated << std::endl << std::endl;
}

bool CheckCommand(std::string command){
	return command == "New" || command == "Update" || command == "View" || command == "Donate" || command == "Report" || command == "Quit";
}
