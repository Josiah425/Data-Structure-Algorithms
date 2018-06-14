#include <iostream>
#include <string>
#include <fstream>
#include "VoterDatabase.h"
#include <stdlib.h>
#include <sstream>

int main(int argc, char **argv){
	int maxVoters;
	std::string command;
	std::string file;
	Voter voter;
	VoterDatabase voterDatabase;
	if(argc > 1){
		std::istringstream buffer(argv[1]);
		buffer >> maxVoters;
		if(maxVoters < 1 || maxVoters > 1000){
			return 0;
		}
		if(argc > 2){
			std::istringstream buffer(argv[2]);
			buffer >> file;
			voterDatabase.init(file, maxVoters);
			if(voterDatabase.CheckTerminate()){
				std::cout << "Database is too big for maximum voters.  Terminating program.\n";
				return 0;
			}
		}
		else{
			voterDatabase.init(maxVoters);
		}
	}
	else{
		return 0;
	}
	while(command != "Quit"){
		std::cout << "Enter a command.\n" << "Choose from [\"Login\" \"New\" \"Save\" \"Load\" \"Report\" \"Quit\"]\n:";
		std::cin >> command;
		while(!ValidTopCommand(command)){
			std::cout << "You entered an invalid command.\n" << "Choose from [\"Login\" \"New\" \"Save\" \"Load\" \"Report\" \"Quit\"]\n:";
			std::cin >> command;
		}
		if(command == "New"){
			voter = voterDatabase.NewVoter();
		}
		else if(command == "Save"){
			std::string fileStr;
			std::cout << "Enter textfile : ";
			std::cin >> fileStr;
			voterDatabase.Save(fileStr);
		}
		else if(command == "Load"){
			std::string fileStr;
			std::cout << "Enter textfile: ";
			std::cin >> fileStr;
			voterDatabase.Load(fileStr);
			if(voterDatabase.CheckTerminate()){
				std::cout << "Database is too big for maximum voters.  Terminating program.\n";
				return 0;
			}
		}
		else if(command == "Report"){
			voterDatabase.Report();
		}
		else if(command == "Quit"){
			std::string yesOrNo;
			std::cout << "Before you Quit would you like to save? [Y, N]\n:";
			std::cin >> yesOrNo;
			if(yesOrNo == "Y"){
				std::string fileStr;
				std::cout << "Enter textfile : ";
				std::cin >> fileStr;
				voterDatabase.Save(fileStr);
			}
		}
		else if(command == "Login"){
			std::string username;
			std::string pw;
			std::cout << "Enter username: ";
			std::cin >> username;
			std::cout << "Enter password: ";
			std::cin >> pw;
			if(!voterDatabase.ValidLogin(username, pw)){
				std::cout << "Invalid username or password.\n";
				continue;
			}
			voter = voterDatabase.Login(username, pw);
			std::string command2;
			while(command2 != "Logout"){
				std::cout << "Enter a command.\n" << "Choose from [\"Update\" \"Passwd\" \"View\" \"Donate\" \"Report\" \"Logout\"]\n:";
				std::cin >> command2;
				while(!ValidLowerCommand(command2)){
					std::cout << "Invalid command.\nChoose from [\"Update\" \"Passwd\" \"View\" \"Donate\" \"Report\" \"Logout\"]\n:";
					std::cin >> command2;
				}
				if(command2 == "Update"){
					std::string response = "Yes";
					while(response == "Yes"){
						std::string updateCommand;
						std::cout << "What would you like to update [\"firstname\" \"lastname\" \"age\" \"streetnumber\" \"streetname\" \"town\" \"zipcode\"]\n:";
						std::cin >> updateCommand;
						while(!ValidUpdateCommand(updateCommand)){
							std::cout << "Invalid update command.\nWhat would you like to update [\"firstname\" \"lastname\" \"age\" \"streetnumber\" \"streetname\" \"town\" \"zipcode\"]\n:";
							std::cin >> updateCommand;
						}
						voter.Update(updateCommand);
						std::cout << "Would you like to update something else? [Yes, No]\n";
						std::cin >> response;
						while(response != "Yes" && response != "No"){
							std::cout << "Invalid response.\nWould you like to update something else? [Yes, No]\n";
							std::cin >> response;
						}
					}
				}
				else if(command2 == "Passwd"){
					voter.ChangePassword();
				}
				else if(command2 == "View"){
					voter.View();
				}
				else if(command2 == "Donate"){
					double amount;
					std::cout << "Enter amount to donate: ";
					std::cin >> amount;
					while(!voter.ValidDonation(amount)){
						std::cout << "Enter amount to donate: ";
						std::cin >> amount;
					}
					voter.Donate(amount);
				}
				else if(command2 == "Report"){
					voter.Report();
				}
				voterDatabase.Update(voter, username);
				
			}
		}
	}
	

	return 0;
}
