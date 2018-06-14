void NewVoter(float &amountDonated, std::string &lastName, std::string &firstName, int &streetNumber, std::string &streetName, int &age, std::string &town, int &zipcode);

void UpdateVoter(std::string &lastName, std::string &firstName, int &streetNumber, std::string &streetName, int &age, std::string &town, int &zipcode);

void ViewInformation(float amountDonated, std::string lastName, std::string firstName, int streetNumber, std::string streetName, int age, std::string town, int zipcode);

void DonateMoney(float &amountDonated);

void ReportInformation(float amountDonated, std::string lastName);

bool CheckCommand(std::string command);
