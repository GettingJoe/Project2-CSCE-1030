// Author: Joseph Fergen
// Course Section: CSCE 1030.002
// Date: 2/22/2018
// Description: 
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cctype>
using namespace std;

int main()
{
	cout <<" +----------------------------------------------+" << endl;
	cout <<" | Computer Science and Engineering             |" << endl;
	cout <<" | CSCE 1030 - Computer Science I               |" << endl;
	cout <<" | Joseph Fergen jpf0095 jpf0095@my.unt.edu     |" << endl;
	cout <<" +----------------------------------------------+" << endl;
	
	srand(time(NULL));
	
	double bonusPercent = 0.00; // Number that will hold the random percent for salery
	int years; // Number of years experience for the employee
	const double EXECUTIVE_BONUS = 10000.00; // Constant bonus for executives
	const double MANAGER_BONUS = 5000.00; // Constant bonus for managers
	const double STAFF_BONUS = 1000.00; // Constant bonus for staff
	double startingSalary = 0.00; // The starting salary of employee
	double endingSalary = 0.00; // The final payout of the employee
	double companyPayout = 0.00; // Amount the company will payout to all employees
	enum  employeeRole {EXECUTIVE = 1, MANAGER, STAFF}; //The role of the employee
	int empVal; // Used to hold the employees role
	int numExec = 0; // Number of executives
	int numMan = 0; // Number of managers
	int numStaff = 0; // Number of staff
	string name; // Full name of employee
	char goOn; // Used to determine if user would like to enter another employee
	
	// d0-while loop to continue looping as long as user needs to enter more employees
	do
	{

		// Getting the full name of employee
		cout << "Enter full name of employee: ";
		getline(cin, name);

		// Changing first letter of each name to be capital
		name.at(0) = toupper(name.at(0));
		for(int i = 0; i < name.length(); i++)
		{
			if (isspace(name.at(i)))
				name.at(i + 1) = toupper(name.at(i + 1));
			
		}	

		// Getting years of experience for employee
		cout << "Enter years of experience for " << name << ": ";
		cin >> years;
	
		// Getting the salary of the employee	
		cout << "Enter salary of the employee: ";
		cin >> startingSalary;
	
		// Getting the employee role
		cout << "Enter the employee role: " << endl;
		cout << "1. Executive" << endl;
		cout << "2. Manager" << endl;
		cout << "3. Staff" << endl;
		empVal = 0;
	
		// While-statement to keep going until user enters a correct value
		while (empVal != 1 && empVal != 2 && empVal != 3)
		{
			
			cin >> empVal;

			// Switch statement to output the employees money stuff
			switch (empVal)
			{
				// Executive
				case 1:
				if (years > 20)
				{
					// Getting bonus percent number and final salary of employee
					bonusPercent = (rand() % 6 + 15) / 100.00;
					endingSalary = startingSalary +  EXECUTIVE_BONUS + (startingSalary * bonusPercent);
					
					// Setting number to be correct currency format and outputting employee salary
					cout.precision(2);
					cout << name << " obtained a total payout of $" << fixed << endingSalary << endl;
					
					// Number of executives + 1 and adding to total company payout
					++numExec;
					companyPayout = companyPayout + endingSalary;
				} 
				if (years > 10 && years <= 20)
				{
					
					bonusPercent = (rand() % 6 + 10) / 100.00;
					endingSalary = startingSalary + EXECUTIVE_BONUS + (startingSalary * bonusPercent);
					
					cout.precision(2);
					cout << name << " obtained a total payout of $" << fixed << endingSalary << endl;

					++numExec;
					companyPayout = companyPayout + endingSalary;
				}
				if (years <= 10)
				{
					bonusPercent = (rand() % 6 + 5) / 100.00;
					endingSalary = startingSalary + EXECUTIVE_BONUS + (startingSalary * bonusPercent);

					cout.precision(2);
					cout << name << " obtained a total payout of $" << fixed << endingSalary << endl;

					++numExec;
					companyPayout = companyPayout + endingSalary;
				}	
				break;	
	
				// Manager
				case 2:
				if (years > 20)
				{
					// Getting bonus percent number and final salary of employee
					bonusPercent = (rand() % 6 + 10) / 100.00;
					endingSalary = startingSalary + MANAGER_BONUS + (startingSalary * bonusPercent);
					
					// Setting number to be correct currency format and outputting employee salary
					cout.precision(2);
					cout << name << " obtained a total payout of $" << fixed << endingSalary << endl;
					
					// Number of managers + 1 and adding to total company payout
					++numMan;
					companyPayout = companyPayout + endingSalary;
				}
				if (years > 10 && years <= 20)
				{
					bonusPercent = (rand() % 6 + 5) / 100.00;
					endingSalary = startingSalary + MANAGER_BONUS + (startingSalary * bonusPercent);

					cout.precision(2);
					cout << name << " obtained a total payout of $" << fixed << endingSalary << endl;

					++numMan;
					companyPayout = companyPayout + endingSalary;
				}
				if (years <= 10)
				{
					bonusPercent = (rand() % 5 + 1) / 100.00;
					endingSalary = startingSalary + MANAGER_BONUS + (startingSalary * bonusPercent);

					cout.precision(2);
					cout << name << " obtained a total payout of $" << fixed << endingSalary << endl;

					++numMan;
					companyPayout = companyPayout + endingSalary;
				}	
				break;

				// Staff
				case 3:
				if (years > 20)
				{
					// Getting bonus percent number and final salary of employee
					bonusPercent = (rand() % 6 + 5) / 100.00;
					endingSalary = startingSalary + STAFF_BONUS + (startingSalary * bonusPercent);
					
					// Setting number to be correct currency format and outputting employee salary
					cout.precision(2);
					cout << name << " obtained a total payout of $" << fixed << endingSalary << endl;

					// Number of staff + 1 and adding to total company payout
					++numStaff;
					companyPayout = companyPayout + endingSalary;
				}
				if (years > 10 && years <= 20)
				{
					bonusPercent = (rand() % 5 + 1) / 100.00;
					endingSalary = startingSalary + STAFF_BONUS + (startingSalary * bonusPercent);

					cout.precision(2);
					cout << name << " obtained a total payout of $" << fixed << endingSalary << endl;

					++numStaff;
					companyPayout = companyPayout + endingSalary;
				}
				if (years <= 10)
				{
					endingSalary = startingSalary + STAFF_BONUS;

					cout.precision(2);
					cout << name << " obtained a total payout of $" << fixed << endingSalary << endl;

					++numStaff;
					companyPayout = companyPayout + endingSalary;
				}		
				break;

				default:
				cout << "Wrong or unknown employee role. Please enter 1 for Executive, 2 for Manager, or 3 for Staff." << endl;
			}
		}
		
		// Seeing if user would like to continue or not
		cout << "Would you like to enter another employee? ('n' or 'N' to stop, anything else to continue)" << endl;
		cin >> goOn;
		cin.ignore();
	} while ((goOn != 'n') && (goOn != 'N')) ;
	
	// Outputting the total company payout to number of executives, managers, and staff
	cout << "The company is paying out a total of $" << companyPayout << " to: " << endl;
	cout << numExec << " Executives" << endl;
	cout << numMan << " Managers" << endl;
	cout << numStaff << " Staff" << endl;

	return 0;
}

