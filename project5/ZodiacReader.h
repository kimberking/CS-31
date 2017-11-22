#ifndef PIZZA
#define PIZZA
#include <string>
#include "Date.h"

class ZodiacReader {

public:
	Date mDate;

	ZodiacReader(Date date);

	enum Sign {ARIES, TAURUS, GEMINI, CANCER, LEO, VIRGO, LIBRA, SCORPIO, SAGITTARIUS, CAPRICORN, AQUARIUS, PISCES}; //the enums for the signs

	Sign checkSign(); //check what sign it is
	bool onCusp(); //check if it is on the cusp, returns true or false
	Sign cuspSign(); //if it is on the cusp then it returns a cusp sign
	std::string stringifySign(ZodiacReader::Sign); //reads the sign of the string, lowercase

};
#endif