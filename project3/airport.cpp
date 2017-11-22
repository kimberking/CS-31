#include <iostream>
#include <string>
#include <cassert>

using namespace std;
bool isWellFormedAirportString(string commands);
double ontimeArrivalPercentage(string commands, string airlinecode);

int main() {
	assert(!isWellFormedAirportString("a")); //Fails, not enough info
	assert(!isWellFormedAirportString("ua")); //Fails, not enough info
	assert(!isWellFormedAirportString("sw5")); //Fails, not enough info
	assert(isWellFormedAirportString("aa001-100")); //Passes
	assert(isWellFormedAirportString("AA010+1")); //Passes
	assert(isWellFormedAirportString("al345-87")); //Passes
	assert(isWellFormedAirportString("al323-0")); //Passes
	assert(isWellFormedAirportString("va453+0")); //Passes
	assert(isWellFormedAirportString("VA100+001")); //Passes
	assert(isWellFormedAirportString("dl989-010")); //Passes
	assert(!isWellFormedAirportString("du101-294")); //Fails, du not supported
	assert(!isWellFormedAirportString("ua-934+1000")); //Fails, minutes outside of range
	assert(!isWellFormedAirportString("sw1000+555")); //Fails, fails, flight out of range
	assert(isWellFormedAirportString("va010-55aa100+54")); //Passes
	assert(!isWellFormedAirportString("va967-0dl543-3slo32-44")); //Fails, slo not supported
	assert(!isWellFormedAirportString("al555-4dl111-")); //Fails, no delay value
	assert(!isWellFormedAirportString(""));
	assert(isWellFormedAirportString("UA1+1"));
	assert(isWellFormedAirportString("SW999+999"));
	assert(!isWellFormedAirportString("    "));
	assert(!isWellFormedAirportString("ka12+34"));
	assert(!isWellFormedAirportString("ua12sw32"));
	assert(!isWellFormedAirportString("aa12a+2"));
	assert(!isWellFormedAirportString("aa1234+123"));
	assert(!isWellFormedAirportString("a12a+12"));
	assert(isWellFormedAirportString("ua12-2sW34+4"));
	assert(!isWellFormedAirportString("ua000+12"));
	assert(!isWellFormedAirportString("ua1000+12"));
	assert(!isWellFormedAirportString("ua1+1000"));
	assert(!isWellFormedAirportString("ua-190+12"));
	assert(!isWellFormedAirportString("ua1+sw12-1"));
	assert(isWellFormedAirportString("ua12-1sw670+12"));
	assert(isWellFormedAirportString("ua34+2dl891-20aa970+5"));
	assert(!isWellFormedAirportString("ua34+2+aa12-1"));
	assert(!isWellFormedAirportString("u!a1+2"));
	assert(!isWellFormedAirportString("ua1-2!"));
	assert(!isWellFormedAirportString("ua+12-1"));
	assert(!isWellFormedAirportString("aa"));
	assert(!isWellFormedAirportString("aa-12+1"));
	assert(!isWellFormedAirportString("aa12"));
	assert(!isWellFormedAirportString("aa1+"));
	assert(!isWellFormedAirportString("aa1+-2"));
	assert(isWellFormedAirportString("va1+0"));

	assert(isWellFormedAirportString("dl5-7"));
	assert(isWellFormedAirportString("dl55-7"));
	assert(isWellFormedAirportString("dl555-7"));
	assert(isWellFormedAirportString("dl5-7"));
	assert(isWellFormedAirportString("dl5-77"));
	assert(isWellFormedAirportString("dl5-777"));
	assert(!isWellFormedAirportString("va12!34dl34+455"));


	cerr << "ALL isWellFormedAirportString CASES PASS" << endl;

	assert(ontimeArrivalPercentage("aa+12", "aa") == -1);
	assert(ontimeArrivalPercentage("ua12-1", "aa") == 0);
	assert(ontimeArrivalPercentage("aa1+1", "az") == -1);
	assert(ontimeArrivalPercentage("sw1-1dl23+6aa67+20sw56+11sw634+22sw34+5dl67-5ua90+5sw55+10", "sw") == .8);
	assert(ontimeArrivalPercentage("ua1-1SW2+23Al34-1aL56+15AL2+20al75+17va99-0", "Al") == .25);

	assert(ontimeArrivalPercentage("a", "aa") == -1); //Fails, string failure
	assert(ontimeArrivalPercentage("ua", "ua") == -1); //Fails, string failure
	assert(ontimeArrivalPercentage("sw5", "sw") == -1); //Fails, string failure
	assert(ontimeArrivalPercentage("aa001-100", "aa") == 1); //Passes with 100% arrival ratio
	assert(ontimeArrivalPercentage("AA010+1", "aa") == 1); //Passes with 100% arrival ratio
	assert(ontimeArrivalPercentage("al345-87", "al") == 1); //Passes wtih 100% arrival ratio
	assert(ontimeArrivalPercentage("al323-0", "al") == 1); //Passes with 100% arrival ratio
	assert(ontimeArrivalPercentage("va453+0", "va") == 1); //passes with 100% arrival ratio
	assert(ontimeArrivalPercentage("VA100+001", "va") == 1); //Passes wtih 100% arrival ratio
	assert(ontimeArrivalPercentage("dl989-010", "du") == -1); //Fails, du not supported
	assert(ontimeArrivalPercentage("ua-934+1000", "ua") == -1); //Fails, string failure
	assert(ontimeArrivalPercentage("sw1000+555", "sw") == -1); //Fails, string failure
	assert(ontimeArrivalPercentage("va010-55aa100+54", "va") == 1); //Passes with 100% arrival ratio
	assert(ontimeArrivalPercentage("va010-55aa100+54", "aa") == 0); //Passes with 0% arrival ratio
	assert(ontimeArrivalPercentage("va030-43aa232+3", "aa") == 1); //Passes with 100% arrival ratio
	assert(ontimeArrivalPercentage("va967-0dl543-3slo32-44", "va") == -1); //Fails, string failure
	assert(ontimeArrivalPercentage("va967-0dl543-3slo32-44", "dl") == -1); //Fails, string failure
	assert(ontimeArrivalPercentage("va967-0dl543-3slo32-44", "slo") == -1); //Fails, string failure
	assert(ontimeArrivalPercentage("al555-4dl111-", "al") == -1); //Fails, string failure
	assert(ontimeArrivalPercentage("al555-4dl111-", "dl") == -1); //Fails, string failure
	assert(ontimeArrivalPercentage("sw343-53aa222+45ua33-0sw222+45sw999-0va834+3sw874-3sw333+15", "sw") == .6); // Passes wtih 50% arrival ratio
	assert(ontimeArrivalPercentage("sw333-54 sw888-5", "sw") == -1); // Fails, string failure
	cerr << "ALL ontimeArrivalPercentage CASES PASS" << endl;
}

string TurnToLower(string commands) {              // turns the cases to lower case so we dont need to check UU Uu and uU
	for (int i = 0; i < commands.length(); i++) {
		if (isupper(commands[i])) {
			commands[i] = tolower(commands[i]);
		}
	}
	return commands;
}

bool isWellFormedAirportString(string commands) { //check if it is a valid airline string
	string thing = TurnToLower(commands);
	string a = thing.substr(0, 2);
	int charLocation = 1;

	while ((charLocation < thing.length())
		&& ((a == "aa") || (a == "dl") || (a == "ua") || (a == "sw")
			|| (a == "va") || (a == "al"))) {
		int iNum = 0;

		// this block is to consider multiple airlines
		if (charLocation == 1) {
			charLocation++;
		}
		else {
			charLocation = charLocation + 2;
		}

		char readc = thing[charLocation];

		if (isdigit(readc)) { // need to remove (readc != '0')  to consider areline number 005 case; add iNum check later to make sure airline number is not 0
			std::string str = commands.substr(charLocation, 1);
			iNum = std::stoi(str);
		}
		else {
			return false;
		}

		charLocation++;
		readc = thing[charLocation]; // .substr(3, 1)

		bool sign;

		if (isdigit(readc)) {
			std::string str = commands.substr(charLocation, 1);
			iNum = iNum * 10 + std::stoi(str);

			charLocation++;
			char readc2 = thing[charLocation]; // .substr(4, 1);

			if (isdigit(readc2)) {
				std::string str = commands.substr(charLocation, 1); // need to add this line to change the datatype for number conversion
				iNum = iNum * 10 + std::stoi(str);

				charLocation++;
				char readc2 = thing[charLocation]; // .substr(4, 1);


												   // need to add one more loop to consider the case with three full digit airline
				if (readc2 == '+') {
					sign = true;

				}
				else if (readc2 == '-') {
					sign = true;
				}
				else {
					return false;
				}
			}
			else if (readc2 == '+') {
				sign = true;
			}
			else if (readc2 == '-') {
				sign = true;
			}
			else {
				return false;
			}

		}
		else if (readc == '+') {
			sign = true;
		}
		else if (readc == '-') {
			sign = true;
		}
		else {
			return false;
		}

		// add this block to check if the airline number is 0 or not
		if (iNum == 0) {
			return false;
		}
		int iNum2 = 0;

		charLocation++;
		readc = thing[charLocation]; // .substr(charLocation, 1);

		if (isdigit(readc)) {
			std::string str = commands.substr(charLocation, 1);
			iNum2 = std::stoi(str);
		}
		else {
			return false;
		}

		charLocation++;
		readc = thing[charLocation]; // .substr(charLocation, 1);

		if (isdigit(readc)) {
			std::string str = commands.substr(charLocation, 1);
			iNum2 = iNum2 * 10 + std::stoi(str);

			charLocation++;
			char readc2 = thing[charLocation]; // .substr(charLocation, 1);

			if (isdigit(readc2)) {
				std::string str = commands.substr(charLocation, 1);
				iNum2 = iNum2 * 10 + std::stoi(str);

				// need to add the following code to check if there is addition airline
				charLocation++;

				char readc2 = thing[charLocation];
				if ((charLocation < (thing.length() - 1))
					&& (isalpha(readc2))) { //need to add isalpha, there was a type at readc2
					a = thing.substr(charLocation, 2);

				}
				else if (charLocation == thing.length()) {
					return true;   // read all of commands without error
				}
				else {
					return false;
				}

			}
			else if (isalpha(readc2)) {              // change readc to readc2
				if (charLocation < (thing.length() - 1)) {
					a = thing.substr(charLocation, 2);

				}
				else {
					return false;
				}
			}
			else if (charLocation == thing.length()) {
				return true;
			}
			else {
				return false;
			}

		}
		else if (isalpha(readc)) {
			if (charLocation < (thing.length() - 1)) {
				a = thing.substr(charLocation, 2);

			}
			else {
				return false;
			}
		}
		else if (charLocation == thing.length()) {
			return true;
		}
		else {
			return false;
		}
	}

	if ((charLocation) < thing.length()) {
		return false;
	}
	else if (thing.size() <= 5) { //it has to be at least have a length of 5
		return false;
	}
	else {
		return true;
	}
}

double ontimeArrivalPercentage(string commands, string airlinecode) { //check airline string and airline code to find ratio
	string thing = TurnToLower(commands);
	string lcAirlineCode = TurnToLower(airlinecode);
	string a = thing.substr(0, 2);
	int charLocation = 1;
	int numFlight = 0, numDelay = 0;

	while ((charLocation < thing.length())
		&& ((a == "aa") || (a == "dl") || (a == "ua") || (a == "sw")
			|| (a == "va") || (a == "al")) && ((lcAirlineCode == "aa") || (lcAirlineCode == "dl") || (lcAirlineCode == "ua") || (lcAirlineCode == "sw")
				|| (lcAirlineCode == "va") || (lcAirlineCode == "al"))) {
		int iNum = 0;

		if (lcAirlineCode == a) {
			numFlight++;
		}

		// this block is to consider multiple airlines
		if (charLocation == 1) {
			charLocation++;
		}
		else {
			charLocation = charLocation + 2;
		}

		char readc = thing[charLocation];

		if (isdigit(readc)) { // need to remove (readc != '0')  to consider areline number 005 case; add iNum check later to make sure airline number is not 0
			std::string str = commands.substr(charLocation, 1);
			iNum = std::stoi(str);


		}
		else {
			return -1;
		}

		charLocation++;
		readc = thing[charLocation]; // .substr(3, 1)

		bool posSign;

		if (isdigit(readc)) {
			std::string str = commands.substr(charLocation, 1);
			iNum = iNum * 10 + std::stoi(str);

			charLocation++;
			char readc2 = thing[charLocation]; // .substr(4, 1);

			if (isdigit(readc2)) {
				std::string str = commands.substr(charLocation, 1); // need to add this line to change the datatype for number conversion
				iNum = iNum * 10 + std::stoi(str);

				charLocation++;
				char readc2 = thing[charLocation]; // .substr(4, 1);

												   // need to add one more loop to consider the case with three full digit airline
				if (readc2 == '+') {
					posSign = true;

				}
				else if (readc2 == '-') {
					posSign = false;

				}
				else {
					return -1;
				}
			}
			else if (readc2 == '+') {
				posSign = true;
			}
			else if (readc2 == '-') {
				posSign = false;
			}
			else {
				return -1;
			}

		}
		else if (readc == '+') {
			posSign = true;
		}
		else if (readc == '-') {
			posSign = false;
		}
		else {
			return -1;
		}

		// add this block to check if the airline number is 0 or not
		if (iNum == 0) {
			return -1;
		}
		int iNum2 = 0;


		charLocation++;
		readc = thing[charLocation]; // .substr(charLocation, 1);

		if (isdigit(readc)) {
			std::string str = commands.substr(charLocation, 1);
			iNum2 = std::stoi(str);

		}
		else {
			return -1;
		}

		charLocation++;
		readc = thing[charLocation]; // .substr(charLocation, 1);

		if (isdigit(readc)) {
			std::string str = commands.substr(charLocation, 1);
			iNum2 = iNum2 * 10 + std::stoi(str);

			charLocation++;
			char readc2 = thing[charLocation]; // .substr(charLocation, 1);

			if (isdigit(readc2)) {
				std::string str = commands.substr(charLocation, 1);
				iNum2 = iNum2 * 10 + std::stoi(str);

				// need to add the following code to check if there is addition airline
				charLocation++;

				char readc2 = thing[charLocation];
				if ((charLocation < (thing.length() - 1))
					&& (isalpha(readc2))) { //need to add isalpha, there was a type at readc2

					if ((posSign) && (iNum2 >= 15) && (lcAirlineCode == a)) {
						numDelay++;
						
					}

					a = thing.substr(charLocation, 2);
				}
				else if (charLocation == thing.length()) {
					if ((posSign) && (iNum2 >= 15) && (lcAirlineCode == a)) {
						numDelay++;

					}
					if (numFlight == 0) {
						return 0;
					}
					else {
						return (double)((double)(numFlight - numDelay) / numFlight);
					}   // read all of commands without error
				}
				else {
					return -1;
				}

			}
			else if (isalpha(readc2)) {              // change readc to readc2

				if (charLocation < (thing.length() - 1)) {
					if ((posSign) && (iNum2 >= 15) && (lcAirlineCode == a)) {
						numDelay++;

					}

					a = thing.substr(charLocation, 2);
				}
				else {
					return -1;
				}
			}
			else if (charLocation == thing.length()) {
				if ((posSign) && (iNum2 >= 15) && (lcAirlineCode == a)) {
					numDelay++;

			
				}


				if (numFlight == 0) {
					return 0;
				}
				else {

					return ((double)(numFlight - numDelay) / numFlight); //final answer for onetime rate
				}
			}
			else {
				return -1;
			}

		}
		else if (isalpha(readc)) {
			if (charLocation < (thing.length() - 1)) {

				if ((posSign) && (iNum2 >= 15) && (lcAirlineCode == a)) {
					numDelay++;


				}

				a = thing.substr(charLocation, 2);

			}
			else {
				return -1;
			}
		}
		else if (charLocation == thing.length()) {
			if ((posSign) && (iNum2 >= 15) && (lcAirlineCode == a)) {
				numDelay++;

	
			}
			if (numFlight == 0) {
				return 0;
			}
			else {
				return ((double)(numFlight - numDelay) / numFlight); //final answer for onetime rate
			}
		}
		else {
			return -1;
		}
	}

	if ((charLocation) < thing.length()) {
		return -1;
	}
	else if (thing.size() <= 5) {  //it has to be at least have a length of 5
		return -1;
	}
	else {
		if (numFlight == 0) {
			return 0;
		}
		else {
			return ((double)(numFlight - numDelay) / numFlight); //final answer for onetime rate
		}
	}
}