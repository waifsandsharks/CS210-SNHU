//============================================================================
// Name        : Airgead.cpp
// Author      : Ethan Daugherty
// Version     : 02/05/2021
// Copyright   : Your copyright notice
// Description : Airgead Banking App that shows in a grid arrangement - Initial Investment Amount,
// 				 Monthly Deposit, Annual Interest, and Number of Years passed
//============================================================================
#include <iostream>
#include "savings.h"
using namespace std;

int main(){
	while(1){

		//Prints the heading directing the user for their data input
        cout << "____________________________________" << endl;
        cout << "_______________Input________________" << endl;
        cout << "Initial investment amount: " << endl;
        cout << "Monthly deposit: " << endl;
        cout << "Annual interest yield: " << endl;
        cout << "Number of years in account: " << endl;

        system("read -p 'Press Return to continue' var");
        cout << endl;

        //collect user inputs
        cout << "____________________________________" << endl;
        cout << "_______________Input________________" << endl;
        cout << "Initial Investment Amount: $";
        double investment, monthlyDeposit, interestRate;
        int years;
        cin >> investment;
        cout << "Monthly Deposit: $";
        cin >> monthlyDeposit;
        cout << "Annual Interest: %";
        cin >> interestRate;
        cout << "Number of years: ";
        cin >> years;

        //system("PAUSE");
        system("read -p 'Press Return to continue' var");

        //Create savings object using the given inputs
        savings mysavings = savings(investment, monthlyDeposit, interestRate, years);
        cout << endl;

        //Starts up the report methods
        mysavings.reportNoMonthlyDeposits();
        cout << endl;

        //calls the monthly deposit report as long as > 0
        if(monthlyDeposit > 0){
        	mysavings.reportWithMonthlyDeposits();
        }



        //Get the user choice if they want to re-enter details for interest
        cout << endl << "Do you want to continue? (y/n): ";
        string choice;
        cin >> choice;

    //If user does not want to try continue the loop breaks
      if(choice != "y" || "Y"){
    	  break;
      }
      cout << endl;
	}
	return 0;
}
