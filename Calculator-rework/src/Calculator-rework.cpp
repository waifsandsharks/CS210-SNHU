/*
 * Calculator.cpp
 * Version 1.21.2021
 *  Date: 01/19/2021 -01/21/2021 current
 *  Author: Ethan Duagherty
 */

#include <iostream>
/* added in "using namespace std;"
 * this allows our program to access the functions, classes, and variables with conflict.
 */

using namespace std;
int main()
{
	// removed this as it isn't used in calculator char statement[100];
	// changed op1, op2 to double so user can put in decimal numbers
	double op1, op2;
	char operation;
	char answer = 'Y';
	// added ; to finish the declaration of the variable
	while (answer == 'y' || answer=='Y')
		// added in the option to put in 'y' so if user doesn't put in 'Y' app can still run
		// also corrected single quotes to y as characters are in single quotes
	{
		// removed ; to allow if loop to continue
		// added ; to allow cout to finish operation
		cout << "Enter expression" <<endl; //asks user to put in their numbers and expressions
		cin >> op2 >> operation >> op1; // takes the input from the user

		if (operation == '+') //checks if user entered in addition for expression
			// also corrected double quotations into single '
			cout << op1 << " + " << op2 << " = " << op1 + op2 << endl;
		//corrected << to ensure operation is continuing

		if (operation == '-')// checks to see if operator entered in subtraction
		// corrected << again
			cout << op1 << " - " << op2 << " = " << op1 - op2 << endl;


		if (operation == '*') // checks if input multiplication
			// corrected / to * to reflect users choice for operator
			cout << op1 << " * " << op2 << " = " << op1 * op2 << endl;


		if (operation == '/') // checks to see if user is using division
			//corrected operator sign from */ to reflect user selection
			cout << op1 << " / " << op2 << " = " << op1 / op2 << endl;
// spaced this a little differently for readability
		cout << endl << "Do you wish to evaluate another expression? " << endl;
		cin >> answer;
		// added a return statement so program returns back to beginning

	}
	// added this in user is finished with evaluating
	cout<<endl<<"Finished evaluating, goodbye!";
	return 0;
};







