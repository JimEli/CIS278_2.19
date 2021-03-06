/*************************************************************************
* Title: Arithmetic, Smallest and Largest
* File: CIS278_Week1_2.19.cpp
* Author: James Eli
* Date: 1/17/2018
*
* Exercise 2.19 on page 69 - (Arithmetic, Smallest and Largest) Write a 
* program that inputs three integers from the keyboard and prints the sum, 
* average, product, smallest and largest of these numbers. The screen 
* dialog should appear as follows:
*
*   Input three different integers: 13 27 14
*   Sum is 54
*   Average is 18
*   Product is 4914
*   Smallest is 13
*   Largest is 27
*
* Notes:
*  (1) Compiled with MS Visual Studio 2017 Community (v141).
*
* Submitted in partial fulfillment of the requirements of PCC CIS-278.
*************************************************************************
* Change Log:
*   01/17/2018: Initial release. JME
*************************************************************************/
#include <iostream>  // cin/cout/endl
#include <algorithm> // min/max
#include <limits>    // numeric_limits

using namespace std;

int main() {
	int num1{0}, num2{0}, num3{0}; // 3 integer inputs.

	// Validate input for 3 seperate integers.
	while (true) {
		cout << "Input three different integers: ";
		cin >> num1 >> num2 >> num3;

		// Check for trailing non-whitespace chars in stream.
		while (cin.peek() != '\n') {
			if (cin.peek() != ' ') {
				cout << "Extra trailing characters ignored.\n";
				break;
			}
			cin.ignore(1, ' ');
		}

		// Check for non-integer input.
		if (cin.fail()) {
			// Clear failure flag and discard any remaining input.
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter only integer values.\n";
		} else {
			// Check for duplicates.
			if (num1 == num2 || num1 == num3 || num2 == num3)
				cout << "Please enter 3 distinct integer values.\n";
			else
				break; // Success.
		}
	} 

	// Calculate and display outputs.
	cout << "Sum is "      << num1 + num2 + num3      << endl;
	cout << "Average is "  << (num1 + num2 + num3)/3  << endl;
	cout << "Product is "  << num1 * num2 * num3      << endl;
	cout << "Smallest is " << min({num1, num2, num3}) << endl;
	cout << "Largest is "  << max({num1, num2, num3}) << endl;

	return 0;
}
