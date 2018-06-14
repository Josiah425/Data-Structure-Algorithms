#include <string>
#include "Voter.h"

bool ValidTopCommand(std::string command);

class VoterDatabase{
public:
	VoterDatabase();
	void init(int max);
	void init(std::string textfile, int max);
	Voter Login(std::string username, std::string pw);
	Voter NewVoter();
	void Load(std::string file);
	void Save(std::string file);
	void Report();
	void Update(Voter voter, std::string username);
	bool ValidLogin(std::string username, std::string pw);
	bool CheckTerminate();

private:
	bool ValidName(std::string name);
	bool ValidAge(std::string ageStr);
	bool ValidStreetNumber(std::string streetNumberStr);
	bool ValidZipCode(std::string zipCodeStr);
	bool ValidPassword(std::string passwordStr);
	bool UserIdExists(std::string user);
	bool ValidUserId(std::string user);
	bool ValidState(std::string state);
	Voter *arr;
	int maxVoters;
	int openSlots;
	bool terminate;
};
