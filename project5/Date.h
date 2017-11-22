#ifndef PIZZA1
#define PIZZA1
class Date {

public:
	int mMonth; //get the month
	int mDay; //get the day
	Date();
	Date(int month, int day); //month and day ints to be used in the other class
	int getMonth();
	int getDay();
};

#endif