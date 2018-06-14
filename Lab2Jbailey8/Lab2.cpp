#include <iostream>
#include <string>
#include "Voter.h"

int main(){
	std::string command;
	float amountDonated = 0;
	std::string lastName;
	std::string firstName;
	int age = -1;
	int streetNumber = 0;
	std::string streetName;
	std::string town;
	int zipcode;

	while(command != "Quit"){
        std::cout << "Enter a command.\n" << "Choose from [\"New\" \"View\" \"Update\" \"Donate\" \"Report\" \"Quit\"]\n:";
		std::cin >> command;

		bool validCommand = CheckCommand(command);

		if(!validCommand){
			std::cout << "Command not recognized. Please try again. ";
		}

		if(command == "New"){
			NewVoter(amountDonated, lastName, firstName, streetNumber, streetName, age, town, zipcode);
		}
		else if(command == "Update"){
			UpdateVoter(lastName, firstName, streetNumber, streetName, age, town, zipcode);
		}
		else if(command == "View"){
			ViewInformation(amountDonated, lastName, firstName, streetNumber, streetName, age, town, zipcode);
		}
        	else if(command == "Donate"){
			DonateMoney(amountDonated);
		}
		else if(command == "Report"){
			ReportInformation(amountDonated, lastName);
		}
	}

	return 0;
}
