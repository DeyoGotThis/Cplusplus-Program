/*************************************************************************
************************************************************************** 
**File         : Compound Interest Calculator
**Description  : Program calculates inputs and compounds monthly interest.
**Author       : Daniel Leon
**Date         : 04-07-23 

**This program takes in user inputs and calculates monthly compounded 
interest for given amount of years, with or without monthly deposits.
It then displays said information for both cases.**
**************************************************************************
**************************************************************************/


#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include "Calc.h"
using namespace std;


int main() {


	CompoundInterestCalculator userInfo;      //Object is created for CompoundInterestCalculator class

    userInfo.displayScreen();                 //Function is called to display screen info and take user input

	userInfo.balanceWithoutMonthlyDeposit();  //Function calculates inputs without monthly deposits and calls 
	                                          //another function to print the details
	cout << endl << endl << endl;

	userInfo.balanceWithMonthlyDeposit();     //Function calculates inputs with monthly deposits and calls 
	                                          //another function to print the details


	return 0;
}