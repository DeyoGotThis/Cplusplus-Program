/**************************************************************************
This .cpp file defines all functions from CompoundInterestCalculator class*
***************************************************************************/

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include "Calc.h"
using namespace std;


//Function displays screen info and accesses private variables to store user inputs
void CompoundInterestCalculator::displayScreen() {


	cout << "********************************\n" << "********** " << "Data Input" << " **********\n";  //Formats display screen
	cout << "Initial Investment Amount: " << endl;
	cout << "Monthly Deposit: " << endl;                                                               //Options for user inputs
	cout << "Annual Interest: " << endl;
	cout << "Number of years: " << endl;


	cin >> m_initialInvestment;                                                                        //Takes user input, clears
	system("cls");                                                                                     //clears screen and displays
	cout << "********************************\n" << "********** " << "Data Input" << " **********\n";  //new screen with input shown
	cout << "Initial Investment Amount: " << "$" << m_initialInvestment << ".00" << endl;
	cout << "Monthly Deposit: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of years: " << endl;


	cin >> m_monthlyDep;                                                                               //Takes next input and repeats
	system("cls");                                                                                     //process with next user input
	cout << "********************************\n" << "********** " << "Data Input" << " **********\n";  //shown
	cout << "Initial Investment Amount: " << "$" << m_initialInvestment << ".00" << endl;
	cout << "Monthly Deposit: " << "$" << m_monthlyDep << ".00" << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of years: " << endl;


	cin >> m_interestRate;                                                                             //Process is repeated with next
	system("cls");                                                                                     //user input
	cout << "********************************\n" << "********** " << "Data Input" << " **********\n";
	cout << "Initial Investment Amount: " << "$" << m_initialInvestment << ".00" << endl;
	cout << "Monthly Deposit: " << "$" << m_monthlyDep << ".00" << endl;
	cout << "Annual Interest: " << m_interestRate << "%" << endl;
	cout << "Number of years: " << endl;


	cin >> m_numberOfYears;                                                                            //Process is repeated with next
	system("cls");                                                                                     //user input
	cout << "********************************\n" << "********** " << "Data Input" << " **********\n";
	cout << "Initial Investment Amount: " << "$" << m_initialInvestment << ".00" << endl;
	cout << "Monthly Deposit: " << "$" << m_monthlyDep << ".00" << endl;
	cout << "Annual Interest: " << m_interestRate << "%" << endl;
	cout << "Number of years: " << m_numberOfYears << endl;
	cout << "Press any key to continue... " << endl;                                                  //After all inputs are taken, user
	                                                                                                  //is prompted to continue to next screen
	
	_getwch();                                                                                        //Helps not display character of previously entered key
	system("cls");                                                                                    //Clears screen for next function call

	m_initialInvestment2 = m_initialInvestment;                                                       //Saves initial user input before first
	                                                                                                  //function calculation to be used for 
	                                                                                                  //second function call
}


//Function calculates inputs without monthly deposits and calls
//another function to print the details
void CompoundInterestCalculator::balanceWithoutMonthlyDeposit() {

	int t_yearCount = 0;                                                                 //Local variable and other function parameters
	double monthlyInterest = 0;                                                          // are initialized
	double t_yearlyInterest = 0;
	double t_yearEndBalance = 0;


	cout << "    Balance and Interest Without Additional Monthly Deposits" << endl;      //Screen is formatted with relevant info
	cout << "================================================================" << endl;  //for calculated results
	cout << right << setw(5) << "Year";
	cout << right << setw(25) << "Year End Balance";
	cout << right << setw(30) << "Year End Earned Interest" << endl;
	cout << "----------------------------------------------------------------" << endl;



	for (int i = 0; i < m_numberOfYears; ++i) {                                         //Loop created for compounding for each year

		for (int j = 0; j < 12; ++j) {                                                  //Loop created for compounding for each month

			monthlyInterest = (m_initialInvestment) * ((m_interestRate / 100) / 12);    //Calculates monthly interest

			m_initialInvestment += monthlyInterest;                                     //Interest added to investment and loops around
			t_yearlyInterest += monthlyInterest;                                        //Interest amount accounted for separately

		}


		t_yearEndBalance = m_initialInvestment;                                         //Exits inner loop with balance with interest
		                                                                                //for end of each year
		t_yearCount += 1;                                                               //Counts years

		printDetails(t_yearCount, t_yearEndBalance, t_yearlyInterest);                  //Prints results of each parameter specified

		t_yearlyInterest = 0;                                                           //Resets interest for each year to be accounted
	}                                                                                   //for separately

}


//Function calculates inputs with monthly deposits and calls 
//another function to print the details
void CompoundInterestCalculator::balanceWithMonthlyDeposit() {

	int t_yearCount = 0;                                                                 //Local variable and other function parameters
	double monthlyInterest = 0;                                                          //are initialized
	double t_yearlyInterest = 0;
	double t_yearEndBalance = 0;

	cout << "      Balance and Interest With Additional Monthly Deposits" << endl;       //Screen is formatted with relevant info 
	cout << "================================================================" << endl;  //for calculated results
	cout << right << setw(5) << "Year";
	cout << right << setw(25) << "Year End Balance";
	cout << right << setw(30) << "Year End Earned Interest" << endl;
	cout << "----------------------------------------------------------------" << endl;



	for (int i = 0; i < m_numberOfYears; ++i) {                                          //Loop created for compounding for each year


		for (int j = 0; j < 12; ++j) {                                                   //Loop created for compounding for each month

			monthlyInterest = (m_initialInvestment2 + m_monthlyDep) * ((m_interestRate / 100) / 12);  //Calculates monthly interest with 
			                                                                                          //deposits
			m_initialInvestment2 += m_monthlyDep + monthlyInterest;                      //Interest and monthly deposit added to investment and loops around
			t_yearlyInterest += monthlyInterest;                                         //Interest amount accounted for separately

		}


		t_yearEndBalance = m_initialInvestment2;                                         //Exits inner loop with balance with interest
		                                                                                 //for end of each year
		t_yearCount += 1;                                                                //Counts years

		printDetails(t_yearCount, t_yearEndBalance, t_yearlyInterest);                   //Prints results of each parameter specified

		t_yearlyInterest = 0;                                                            //Resets interest for each year to be accounted 
	}                                                                                    //for separately

}


//Function prints compound interest results 
//based on user input calculations from  
//functions
void CompoundInterestCalculator::printDetails(int t_yearCount, double t_yearEndBalance, double t_yearlyInterest) {

	int lengthCount = trunc(log10(t_yearEndBalance)) + 1;                  //Local variable that counts length of given parameter
	int lengthCount2 = trunc(log10(t_yearlyInterest)) + 1;                 //Local variable that counts length of given parameter

	cout << right;                                                         //Formats and prints results of calculations from functions
	cout << fixed << setprecision(2);
	cout << setw(5) << t_yearCount;
	cout << setw(22 - lengthCount) << "$" << t_yearEndBalance;
	cout << setw(27 - lengthCount2) << "$" << t_yearlyInterest << endl;

}

