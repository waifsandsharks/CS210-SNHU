#include <iomanip>
#include <iostream>
#include "savings.h"
using namespace std;

savings::savings(double investment, double monthDeposit, double rate, int years){
	this->initialDeposit = investment;
	this->monthlyDeposit = monthDeposit;
	this->interestRate = rate;
	this->numYears = years;
}

//destructor
savings::~savings(){
}

//Prints report without monthly deposit
void savings::reportNoMonthlyDeposits(){
	cout << "   Balance & interest yield without monthly deposits" << endl;
	cout <<"__________________________________________________________________________"	<< endl;
    cout << setw(10) << "Year" << setw(20) << "Year end balance" << setw(35) << "Year end earned interest yield" << endl;
    cout << "__________________________________________________________________________" << endl;


    int currentYear = 1;

    double yearEndBalance = this->initialDeposit;
    while(currentYear <= this->numYears){
    	double interestEarned = yearEndBalance * this->interestRate / 100;
    	cout << right << setw(10) << currentYear << fixed << setprecision(2)
    	<< setw(20) << yearEndBalance << setw(35) << interestEarned << endl;
    	//Increment the year by +1
    	currentYear++;
    }
}

//Prints report considering monthly deposit
void savings::reportWithMonthlyDeposits(){

	//Print heading and prepares table
	cout << "   Balance & Interest without monthly deposits" << endl;
	cout << "__________________________________________________________________________" << endl;
	cout << setw(10) << "Year" << setw(20) << "Year End Balance" << setw(35) << "Year End Earned Interest Rate" << endl;
	cout <<"__________________________________________________________________________" << endl;

//takes the years and calculate the interest earned
	int currentYear = 1;
	double yearEndBalance = this->initialDeposit;
	while(currentYear <= this->numYears){
		//calculate interest monthly and finds compound interest
		int month = 1;
		double interestEarned = 0.0;
		double monthEndBalance = yearEndBalance;
		while(month <= 12){
			monthEndBalance += this->monthlyDeposit;
			double monthlyInterest = monthEndBalance * this->interestRate / (100*12);
			interestEarned += monthlyInterest;
			monthEndBalance += monthlyInterest;
			month++;
		}

		// After 12 months converts months to years
		yearEndBalance = monthEndBalance;
		cout << right << setw(10) << currentYear << fixed << setprecision(2)<< setw(20)
				<< yearEndBalance << setw(35) << interestEarned << endl;
		currentYear++;
    		    }
    		}
