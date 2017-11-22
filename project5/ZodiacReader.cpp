#include "Date.h"
#include "ZodiacReader.h"

ZodiacReader::ZodiacReader(Date date) {
	mDate = date; //the assigned date
}

ZodiacReader::Sign ZodiacReader::checkSign() { //uses the date to check what sign it is
	Sign sign;
	int day = mDate.mDay;
	int mn = mDate.mMonth;
	
	if (mn == 3) {       // I went through every single month and write down what it will be using if and else statements by using the day and month
		if (day >= 21) {
			sign = ARIES;
		}
		else {
			sign = PISCES;
		}
	}
	else if (mn == 4) {
		if (day >= 20) {
			sign = TAURUS;
		}
		else {
			sign = ARIES;
		}
	}
	else if (mn == 5) {
		if (day >= 21) {
			sign = GEMINI;
		}
		else {
			sign = TAURUS;
		}
	}
	else if (mn == 6) {
		if (day >= 21) {
			sign = CANCER;
		}
		else {
			sign = GEMINI;
		}
	}
	else if (mn == 7) {
		if (day >= 23) {
			sign = LEO;
		}
		else {
			sign = CANCER;
		}
	}
	else if (mn == 8) {
		if (day >= 23) {
			sign = VIRGO;
		}
		else {
			sign = LEO;
		}
	}
	else if (mn == 9) {
		if (day >= 23) {
			sign = LIBRA;
		}
		else {
			sign = VIRGO;
		}
	}
	else if (mn == 10) {
		if (day >= 23) {
			sign = SCORPIO;
		}
		else {
			sign = LIBRA;
		}
	}
	else if (mn == 11) {
		if (day >= 22) {
			sign = SAGITTARIUS;
		}
		else {
			sign = SCORPIO;
		}
	}
	else if (mn == 12) {
		if (day >= 22) {
			sign = CAPRICORN;
		}
		else {
			sign = SAGITTARIUS;
		}
	}
	else if (mn == 1) {
		if (day >= 20) {
			sign = AQUARIUS;
		}
		else {
			sign = CAPRICORN;
		}
	}
	else if (mn == 2) {
		if (day >= 19) {
			sign = PISCES;
		}
		else {
			sign = AQUARIUS;
		}
	}
	return sign;
}

bool ZodiacReader::onCusp() { //check if it is on the cusp, returns true if it is and false if it isnt
	bool cuspCheck;
	int day = mDate.mDay;
	int mn = mDate.mMonth;

	if (mn == 3) {
		if ((day == 21) || (day == 20) || (day == 22) || (day == 19)) {
			cuspCheck = true;
		}
		else {
			cuspCheck = false;
		}
	}
	else if (mn == 4) {
		if ((day == 20) || (day == 19) || (day == 21) || (day == 18)) {
			cuspCheck = true;
		}
		else {
			cuspCheck = false;
		}
	}
	else if (mn == 5) {
		if ((day == 21) || (day == 20) || (day == 22) || (day == 19)) {
			cuspCheck = true;
		}
		else {
			cuspCheck = false;
		}
	}
	else if (mn == 6) {
		if ((day == 21) || (day == 20) || (day == 22) || (day == 19)) {
			cuspCheck = true;
		}
		else {
			cuspCheck = false;
		}
	}
	else if (mn == 7) {
		if ((day == 23) || (day == 22) || (day == 24) || (day == 21)) {
			cuspCheck = true;
		}
		else {
			cuspCheck = false;
		}
	}
	else if (mn == 8) {
		if ((day == 23) || (day == 22) || (day == 24) || (day == 21)) {
			cuspCheck = true;
		}
		else {
			cuspCheck = false;
		}
	}
	else if (mn == 9) {
		if ((day == 23) || (day == 22) || (day == 24) || (day == 21)) {
			cuspCheck = true;
		}
		else {
			cuspCheck = false;
		}
	}
	else if (mn == 10) {
		if ((day == 23) || (day == 22) || (day == 24) || (day == 21)) {
			cuspCheck = true;
		}
		else {
			cuspCheck = false;
		}
	}
	else if (mn == 11) {
		if ((day == 22) || (day == 21) || (day == 23) || (day == 20)) {
			cuspCheck = true;
		}
		else {
			cuspCheck = false;
		}
	}
	else if (mn == 12) {
		if ((day == 22) || (day == 21) || (day == 23) || (day == 20)) {
			cuspCheck = true;
		}
		else {
			cuspCheck = false;
		}
	}
	else if (mn == 1) {
		if ((day == 20) || (day == 19) || (day == 21) || (day == 18)) {
			cuspCheck = true;
		}
		else {
			cuspCheck = false;
		}
	}
	else if (mn == 2) {
		if ((day == 19) || (day == 18) || (day == 20) || (day == 17)) {
			cuspCheck = true;
		}
		else {
			cuspCheck = false;
		}
	}
	return cuspCheck;
} 

ZodiacReader::Sign ZodiacReader::cuspSign() { //if it is on the cusp then it returns a cusp sign
	Sign cuspCheck;
	int day = mDate.mDay;
	int mn = mDate.mMonth;
	//I went through each case and wrote down what it could be like the check sign
	if (mn == 3) {
		if ((day == 20) || (day == 19)) {
			cuspCheck = ARIES;
		}
		else if ((day == 21) || (day == 22)) {
			cuspCheck = PISCES;
		}
		else {
			cuspCheck = ARIES;
		}

	} 
	else if (mn == 4) {
		if ((day == 20) || (day == 21)) {
			cuspCheck = ARIES;
		}
		else if ((day == 19) || (day == 18)) {
			cuspCheck = TAURUS;
		}
		else {
			cuspCheck = ARIES;
		}
	}
	else if (mn == 5) {
		if ((day == 21) || (day == 22)) {
			cuspCheck = TAURUS;
		}
		else if ((day == 20) || (day == 19)) {
			cuspCheck = GEMINI;
		}
		else {
			cuspCheck = ARIES;
		}
	}
	else if (mn == 6) {
		if ((day == 21) || (day == 22)) {
			cuspCheck = GEMINI;
		}
		else if ((day == 20) || (day == 19)) {
			cuspCheck = CANCER;
		}
		else {
			cuspCheck = ARIES;
		}
	}
	else if (mn == 7) {
		if ((day == 22) || (day == 21))  {
			cuspCheck = LEO;
		}
		else if ((day == 23) || (day == 24)) {
			cuspCheck = CANCER;
		}
		else {
			cuspCheck = ARIES;
		}
	}
	else if (mn == 8) {
		if ((day == 23) || (day == 24)) {
			cuspCheck = LEO;
		}
		else if ((day == 22) || (day == 21)) {
			cuspCheck = VIRGO;
		}
		else {
			cuspCheck = ARIES;
		}
	}
	else if (mn == 9) {
		if ((day == 22) || (day == 21))  {
			cuspCheck = LIBRA;
		}
		else if ((day == 23) || (day == 24)) {
			cuspCheck = VIRGO;
		}
		else {
			cuspCheck = ARIES;
		}
	}
	else if (mn == 10) {
		if ((day == 22) || (day == 21)) {
			cuspCheck = SCORPIO;
		}
		else if ((day == 23) || (day == 24)) {
			cuspCheck = LIBRA;
		}
		else {
			cuspCheck = ARIES;
		}
	}
	else if (mn == 11) {
		if ((day == 22) || (day == 23)) {
			cuspCheck = SCORPIO;
		}
		else if ((day == 21) || (day == 20)) {
			cuspCheck = SAGITTARIUS;
		}
		else {
			cuspCheck = ARIES;
		}
	}
	else if (mn == 12) {
		if ((day == 21) || (day == 20)) {
			cuspCheck = CAPRICORN;
		}
		else if ((day == 22) || (day == 23)) {
			cuspCheck = SAGITTARIUS;
		}
		else {
			cuspCheck = ARIES;
		}
	}
	else if (mn == 1) {
		if ((day == 19) || (day == 18)) {
			cuspCheck = AQUARIUS;
		}
		else if ((day == 20) || (day == 21)) {
			cuspCheck = CAPRICORN;
		}
		else {
			cuspCheck = ARIES;
		}
	}
	else if (mn == 2) {
		if ((day == 18) || (day == 17)) {
			cuspCheck = PISCES;
		}
		else if ((day == 19) || (day == 20)) {
			cuspCheck = AQUARIUS;
		}
		else {
			cuspCheck = ARIES;
		}
	}
	return cuspCheck;
}

std::string ZodiacReader::stringifySign(ZodiacReader::Sign sign) {
	//returns the sign in lowercase
	switch (sign) //switch statement to look at the enums
	{
	case 0:
		return "Aries";
		break;
	case 1:
		return "Taurus";
		break;
	case 2:
		return "Gemini";
		break;
	case 3:
		return "Cancer";
		break;
	case 4:
		return "Leo";
		break;
	case 5:
		return "Virgo";
		break;
	case 6:
		return "Libra";
		break;
	case 7:
		return "Scorpio";
		break;
	case 8:
		return "Sagittarius";
		break;
	case 9:
		return "Capricorn";
		break;
	case 10:
		return "Aquarius";
		break;
	case 11:
		return "Pisces";
		break;
	}
} 