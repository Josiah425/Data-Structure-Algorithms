#include <string>

bool ValidLowerCommand(std::string command);
bool ValidUpdateCommand(std::string command);

enum State{NY, PA, ME, VT, NH, RI, MA, CT};

class Voter{
public:
	Voter();
	~Voter();
	Voter(std::string userId, std::string password,std::string firstName,std::string lastName,int age,int streetNumber,std::string streetName,std::string town,State state,int zipCode, double amountDonated);
	void Update(std::string command);
	void ChangePassword();
	void View();
	void Donate(double amount);
	void Report();
	bool ValidDonation(double amount);
	std::string getUserId();
	std::string getPassword();
	std::string getFirstName();
	std::string getLastName();
	int getAge();
	int getStreetNumber();
	std::string getStreetName();
	std::string getTown();
	std::string getState();
	int getZipCode();
	double getAmountDonated();

private:
	bool ValidName(std::string name);
	bool ValidAge(std::string ageStr);
	bool ValidStreetNumber(std::string streetNumberStr);
	bool ValidZipCode(std::string zipCodeStr);
	bool ValidPassword(std::string password);
	bool ValidState(std::string state);
	std::string userId;
	std::string firstName;
	std::string lastName;
	int age;
	int streetNumber;
	std::string streetName;
	int zipCode;
	State state;
	std::string password;
	std::string town;
	double amountDonated;
};
