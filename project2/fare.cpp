#include <iostream>
#include <string>
using namespace std;

int main()
{
	string Name;
	string RideType;
	double time;
	double distance;
	double total;

	cout << "Customer Name: ";
	getline(cin, Name);

		if (Name == "")
		{
			cout << "--- You must enter a customer name." << endl;
			return 1;
		}

	cout << "Miles to be driven: ";
	cin >> distance;
		if (distance <= 0)
		{
			cout << "--- The mileage must be positive." << endl;
			return 1;
		}

	cout << "Minutes to be driven: ";
	cin >> time;
		if (time <= 0)
		{
			cout << "--- The time must be positive." << endl;
			return 1;
		}

	cout << "Ride Type: ";
	cin >> RideType;
	if (RideType == "Br-UberX")
	{
		time = time * 0.15;
		distance = distance * 0.90;
		total = 1.65 + time + distance;
		if (total < 5.15)
		{
			total = 5.15;
			}
	}

	else if (RideType == "Br-UberXL")
	{
		time = time * 0.30;
		distance = distance * 1.55;
		total = 1.65 + time + distance;
		if (total < 7.65)
		{
			total = 7.65;
		}
	}
	
	else
		{
			cout << "--- The ride type is not valid." << endl;
		return 1;
		}

	cout.setf(ios::fixed);
	cout.precision(2);
	cout << "--- The fare for " << Name << " is $" << total  << endl;
}