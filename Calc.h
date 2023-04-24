/************************************************************************************
This is a header file that creates a class for calculating compound monthly interest*
*************************************************************************************/

#ifndef CALC_H_
#define CALC_H_

class CompoundInterestCalculator {              //Class is created to organize program functions

private:

	double m_initialInvestment;                 //Variables are created to keep user info private
	double m_initialInvestment2;
	double m_monthlyDep;
	double m_interestRate;
	int m_numberOfYears;

public:

	void displayScreen();                       //Function displays screen info and accesses private variables to store user inputs

	void balanceWithoutMonthlyDeposit();        //Function calculates inputs without monthly deposits and calls 
	                                            //another function to print the details

	void balanceWithMonthlyDeposit();           //Function calculates inputs with monthly deposits and calls 
	                                            //another function to print the details

	void printDetails(int t_yearCount, double t_yearEndBalance, double t_yearlyInterest);  //Function prints compound interest results 
	                                                                                       //based on user input calculations from  
	                                                                                       //functions
};




#endif //CALC_H_
