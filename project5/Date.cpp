#include "Date.h"
Date::Date() {} //default constructor
Date::Date(int month, int day) //ints for monthes to be read
{
	mMonth = month;
	mDay = day;
}

int Date::getMonth()
{
	return mMonth; //gets the month and returns it
}

int Date::getDay()
{
	return mDay; //gets the day and returns it
}