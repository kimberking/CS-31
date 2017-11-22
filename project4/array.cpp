#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int locateMinimum(const string array[], int n) { //Returns the index of the smallest item found in the array or -1 if n <= 0.
	if (n <= 0) {
		return -1;
	}
	else {
		int min = 0;
		for (int i = 0; i < n; i++) { //start comparing the array to see which one has the lowest index which to my knowledge is by the first letter
			if (array[i] < array[min]) {
				min = i;
			}
		}
		return min; //return the smallest value
	}
}

int findLastOccurrence(const string array[], int n, string target) { //Return the largest index that holds the target value in the array or -1 if it is not found at all or n <= 0.
	int largestIndex = -1; //starts from -1 and returns -1 if it doesnt make it past the if loop
	if (n > 0) {
		for (int i = 0; i < n; i++) { //start checking where the target is in the array.
			if (array[i] == target) {
				largestIndex = i;
			}
		}
	}
	return largestIndex;
}

int flipAround(string array[], int n) { //Flips the items found in the array so that the first item holds what was
										//originally found in the last item, the last item holds what was originally found in the first item, and so on throughout the array.
	int count = 0;
	if (n > 0) {
		for (int i = 0; i < int(n / 2); i++) { // modify < = to <  and add int() to n/2
			if (i != (n - (i + 1))) {    // need to and ()  between n - (i+1)
				count++;
				string b = array[i];
				array[i] = array[n - i - 1];
				array[n - (i + 1)] = b;
			}
		}
	}
	return count;
}

bool hasNoDuplicates(const string array[], int n) { //If every value in the array is unique and unduplicated, return true otherwise false or if n < 0 return false.
	if (n < 0) {
		return false;
	}
	else {
		for (int i = 0; i < (n - 1); i++) { // check to i< (n-1)  & i++ ;  we set i from 0 to one element prior to last one
			for (int j = (i + 1); j < n; ++j) { // set j start with i+1 to n so that we can compare two different elements
				if (array[i] == array[j]) { // remove the i != j  statement since we set i and j at different elements
					return false;
				}
			}
		}
		return true;
	}
}

 void unionWithNoDuplicates(const string array1[], int n1, const string array2[],
	int n2, string resultingString[], int&resultingSize) {
	//Create a new array by combining together all the items of array1 and array2,
	//while ensuring that the new array has no duplicated values.   If either n1 or n2 is less than or equal to zero, set the resultingSize to -1.

	if ((n1 <= 0) || (n2 <= 0)) {           // need to ad () at each statement
		resultingSize = 0;
		string tempStr[10000];    // use a temporary string array with the full size n1+n2

		for (int i = 0; i < n1; ++i) {
			bool found = false;
			if (resultingSize > 0) {							// check if any duplicate only if resultingSize > 0
				for (int j = 0; j < resultingSize; j++) {
					if (array1[i] == tempStr[j]) {
						found = true;
					}
				}
			}
			if (!found) {                              // take care if n1=0
				tempStr[resultingSize++] = array1[i];
				cerr << resultingSize << endl;
			}
		}

		for (int i = 0; i < n2; ++i) {
			bool found = false;
			if (resultingSize > 0) {							// check if any duplicate only if resultingSize > 0
				for (int j = 0; j < resultingSize; j++) {
					if (array2[i] == tempStr[j]) {
						found = true;
					}
				}
			}
			if (!found) {							// take care if n2=0
				tempStr[resultingSize++] = array2[i];
				cerr << resultingSize << endl;
			}
		}

		for (int i = 0; i< resultingSize; i++) {
			resultingString[i] = tempStr[i];
		}

		resultingSize = -1;
	}
	else {

		string tempStr[10000];    // use a temporary string array with the full size n1+n2
		resultingSize = 0;

		for (int i = 0; i < n1; ++i) {
			bool found = false;
			if (resultingSize > 0) {							// check if any duplicate only if resultingSize > 0
				for (int j = 0; j < resultingSize; j++) {
					if (array1[i] == tempStr[j]) {
						found = true;
					}
				}
			}
			if (!found) {                              // take care if n1=0
				tempStr[resultingSize++] = array1[i];
				cerr << resultingSize << endl;
			}
		}

		for (int i = 0; i < n2; ++i) {
			bool found = false;
			if (resultingSize > 0) {							// check if any duplicate only if resultingSize > 0
				for (int j = 0; j < resultingSize; j++) {
					if (array2[i] == tempStr[j]) {
						found = true;
					}
				}
			}
			if (!found) {							// take care if n2=0
				tempStr[resultingSize++] = array2[i];
				cerr << resultingSize << endl;
			}
		}

		for (int i = 0; i< resultingSize; i++) {
			resultingString[i] = tempStr[i];
		}
	}
} 

int shiftRight(string array[], int n, int amount, string placeholderToFillEmpties) {
	//Adjust the items found in the array, shifting each value to the right by amount parameter,
	//filling the resulting first amount elements of the array with the placeholder parameter and returning the number of original array items still remaining in the array after all the shifting has been performed.
	if ((amount < 0) || (amount > n) || (n < 0)) {         // need to add () in each statement
		return -1;
	}
	else {
		for (int i = n-1; i > amount-1; i--) {					   // start shift from amount location
			array[i] = array[i - amount];
		}
		for (int i = 0; i < amount; i++) {                    // add this for statement to place the placeholderToFillEmpties into the first amount elements
			array[i] = placeholderToFillEmpties;
		}
		return (n - amount);
	}
}

bool isInIncreasingOrder(const string array[], int n) {
	//If every value in the array is larger than the one that precedes it, return true  otherwise  false.
	if (n < 0) {
		return false; //when it is less than 0 return false
	}
	else if ((n == 0) || (n == 1)) {
		return true;  // when size is 0 and 1 return true
	}
	else {
		for (int i = 1; i < n; i++) { //check the values before
			if (array[i] <= array[i - 1]) {
				return false;
			}
		}
		return true;
	}
}


int main()
{
	string a[6] = { "alpha", "beta", "gamma", "gamma", "beta", "delta" };

	string b[6] = { "delta", "gamma", "beta", "alpha", "beta", "alpha" };
	string h[7] = { "samwell", "jon", "margaery", "daenerys", "", "tyrion", "margaery" };
	int answer;


	string output[6] = { " ", " ", " ", " ", " ", " " };
	int outputSize = 6;

	assert(locateMinimum(a, 3) == 0);
	assert(locateMinimum(b, 3) == 2);

	assert(findLastOccurrence(a, 5, "beta") == 4);
	assert(findLastOccurrence(b, 3, "beta") == 2);

	assert(hasNoDuplicates(a, 3) == true);
	assert(hasNoDuplicates(a, 6) == false);

	assert(isInIncreasingOrder(a, 3) == true);
	assert(isInIncreasingOrder(a, 6) == false);

	unionWithNoDuplicates(a, 6, b, 2, output, outputSize);
	assert(outputSize == 4);
	assert(output[0] == "alpha");

	answer = shiftRight(h, 6, 1, "foobar");
	assert(answer == 5);
	assert(h[0] == "foobar");

	assert(flipAround(b, 3) == 1);
	assert(flipAround(b, 4) == 2);

	cout
		<< "All tests succeeded" << endl; return(0);
}
