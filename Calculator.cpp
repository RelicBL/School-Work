/* -----------------------------------------------------------------------------

FILE:              Calculator
DESCRIPTION:       Project 1
COMPILER:          MinGW  C++ compiler
NOTES:             

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Brandon Lieng     2019-09-10         1.0 Beginning
Brandon Lieng     2019-09-12		 1.1 Adding Functions
Brandon Lieng	  2019-09-15		 1.2 Adding Powers&Roots functions
Brandon Lieng     2019-09-22         1.3 Adding static values
Brandon Lieng     2019-10-03         1.4 Finishing touches on code. Polishing
Brandon Lieng	  2019-10-08		 1.5 Trying to figure out what isn't working. screenshots
Brandon Lieng	  2019-10-09		 1.6 Working on modularity and catches for errors
----------------------------------------------------------------------------- */

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <cctype>
#include <cmath>
#include <math.h>
using namespace std;

float x,y;

const string PROGRAMMER_NAME = "Brandon Lieng";		// Global constant

// Prototypes 
char Get_Choice();	
void Addition();
void Subtraction();
void Multiplication();
void Division();
void Powers_Roots(); 
void Square_a_number();
void Cube_a_number();
void Raise_to_any_power();
void Square_root_a_number();
void Cube_root_a_number();
void Take_any_root();
char Powers_Roots_Get_Choice();
char main_2();
void Get_i_or_d();
void Get_x_and_y();
void Static_cast();
/* -----------------------------------------------------------------------------
FUNCTION:          int main()
DESCRIPTION:       Opener to choices
RETURNS:           0
NOTES:             
------------------------------------------------------------------------------- */

int main()
{
	char choice;
	
	cout << " Welcome to the Calculator Practice Program." << endl; 		  
	cout << " This Program allows you to practice your math skills." << endl;
	cout << " Choose what you want to practice in the menu shown below." << endl << endl;
	
	while (choice != 'q')
	{
		if(choice != 'q')
		choice = Get_Choice();
		
		
		switch (choice)
		{
			case 'a':	
				Addition();
			break;
			
			case 'b':   
				Subtraction();
			break;

			case 'c':   
				Multiplication();
			break;

			case 'd':   
				Division();
			break;

			case 'e':   
				choice = main_2();
			break;

			case 'q': 	 //  To quit. You need some "exit" stategy here.
			cout << "Program will now close" << endl << endl;
			break;
		}
	}

	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << "  " __TIME__ << endl;
	cout << endl;

	system("pause");

	return 0;
}


/* -----------------------------------------------------------------------------
FUNCTION:          Get_Choice()
DESCRIPTION:       Finding Calculations
RETURNS:           0
NOTES:             
------------------------------------------------------------------------------- */

char Get_Choice()
{
	char choice;

	//system("cls"); // First, clear the screen

	// Display the main menu
	//cout << endl << endl;
	//cout << " Hello, and welcome to the Calculator Practice Program." << endl; 		  
	//cout << " This Program allows you to practice your math skills." << endl;
	//cout << " Choose what you want to practice in the menu shown below." << endl << endl;
	//cout << endl << endl;
	cout << "-------------------------------------------" << endl;
	cout << "---------------Main Menu-------------------" << endl << endl;
	cout << "	a.  Addition		(X+Y)"		<< endl;
	cout << "	b.  Subtraction		(X-Y)"		<< endl; //<< endl;
	cout << "	c.  Multiplication	(X*Y)"		<< endl;
	cout << "	d.  Division		(X/Y)"		<< endl;
	cout << "	e.  Powers_Roots"				<< endl;
	cout << "	q.  Quit the Program"			<< endl << endl;
	cout << "-------------------------------------------" << endl;
	cout << endl << endl;
	cout << "Choice [a - e, q] ";
	cin >> choice;
	cout << endl << endl;

	if (choice >= 'a' && choice <= 'q')
			cout << "You entered: '" << choice << "', that input will work," << endl;
	else
	{
		
			cout << "You did not enter 'a', 'b', 'c', 'd', 'e', 'q'." << endl;
			cout << "Please enter a provided choice." << endl;
	}	
	
	cout << endl;
	
	return choice;
}

/* -----------------------------------------------------------------------------
FUNCTION:          Addition()
DESCRIPTION:       Finding Addition
RETURNS:           void
NOTES:             
------------------------------------------------------------------------------- */

void Addition()
{
	float sum;		
	
	char choice;

	Get_i_or_d();
	cout << endl;
	Get_x_and_y();
 
	sum = x + y;
	cout << endl;
	
	/*if(!(sum - int(sum) > 0))
	{
		cout << " x + y = " << x << " + " << y
		 << " = " << sum << ".0" << endl;
	}
	else
	{*/
	cout << "	x + y = " << x << " + " << y //used setprecision, but does not work for integer.
		 << " = " << sum << endl;
	//}
}

/* -----------------------------------------------------------------------------
FUNCTION:          Subtraction()
DESCRIPTION:       Finding Subtraction
RETURNS:           nothing (void)
NOTES:             
------------------------------------------------------------------------------- */
void Subtraction()
{
	float sum;		
	
	char choice;
	
	Get_i_or_d();
	cout << endl;
	Get_x_and_y();
 
	sum = x - y;
	cout << endl << endl;

	cout << "	x - y = " << x << " - " << y
		 << " = " << sum << endl;
}

/* -----------------------------------------------------------------------------
FUNCTION:          Multiplication()
DESCRIPTION:       Finding Multiplication
RETURNS:           nothing (void)
NOTES:             
------------------------------------------------------------------------------- */

void Multiplication()
{
	float sum;		
	
	char choice;
	Get_i_or_d();
	cout << endl;
	Get_x_and_y();

	sum = x * y;

	cout << endl << endl;

	cout << "	x * y = " << x << " * " << y
		 << " = " << sum << endl;

}
/* -----------------------------------------------------------------------------
FUNCTION:          Division()
DESCRIPTION:       Finding Division
RETURNS:           nothing (void)
NOTES:             
------------------------------------------------------------------------------- */

void Division()
{
	double sum;		
	//cout << setprecision(4);

	char choice;
	
	Get_i_or_d();
	cout << endl;
	Get_x_and_y();

	while (y == 0)
	{
		cout << "This is an undefined answer, please enter two numbers again." << endl;
	cin >> x;
	cin >> y;
	}
	
		sum = x / y;
	
	
	cout << endl << endl;

	cout << "	x / y = " << x << " / " << y
		 << " = " << sum << endl;

}
/* -----------------------------------------------------------------------------
FUNCTION:          char main_2()
DESCRIPTION:       Finding menu for Powers&Roots
RETURNS:           choice
NOTES:             
------------------------------------------------------------------------------- */

char main_2()
{
	char choice;
	bool flag = false;
	
	while (!flag)
	
	{
		choice = Powers_Roots_Get_Choice();
		
		
		switch (choice)
		{

			case 'a':	
				Square_a_number();
		break;
			
			case 'b':   
				Cube_a_number();
		break;

			case 'c':   
				Raise_to_any_power();
		break;

			case 'd':   
				Square_root_a_number();
		break;

			case 'e':   
				Cube_root_a_number();
		break;
			
			case 'f':	
				Take_any_root();
		break;

			case 'm': 
				flag = true;	//  To quit. You need some "exit" stategy here.
		break;

			case 'q': 
				flag = true;
		break;
		}
	}
	
	return choice;
}
/* -----------------------------------------------------------------------------
FUNCTION:          Powers_Roots_Get_Choice()
DESCRIPTION:       Menu
RETURNS:           choice
NOTES:             
------------------------------------------------------------------------------- */
char Powers_Roots_Get_Choice()
{

	char choice;
	cout << "-------------------------------------------" << endl;
	cout <<		"POWERS & ROOTS MENU"		   << endl;
	cout << "-------------------------------------------" << endl;
	cout << "	a. Square a number		(X^2)"	  << endl;
	cout << "	b. Cube a number		(X^3)"	 << endl;
	cout << "	c. Raise to any power		(X^Y)"	   << endl;
	cout << "	d. Square root a number		(X^1/2)" << endl;
	cout << "	e. Cube root a number		(X^1/3)"   << endl;
	cout << "	f. Take any root		(X^1/Y)"        << endl;
	cout << "	m. Return to Main Menu"          << endl;
	cout << "	q. Quit the program"				   << endl;
	
	cout << "-------------------------------------------" << endl;
	cout << "Enter your choice [ a - f, m, q ]:" << endl;
	cout << "-------------------------------------------" << endl;
	cout << endl << endl;
	cout << "Choice [a - f, m, q] ";
	cin >> choice;
	cout << endl << endl;
	

// while (choice >= 'a' && choice <= 'm')
			//cout << "You entered: '" << choice << "', that is correct input," << endl;
 
 
	//while(choice != 'a', 'b', 'c', 'd', 'e', 'f', 'm')
	{
		
			//cout << "You did not enter 'a', 'b', 'c', 'd', 'e', 'f', 'm'." << endl;
			//cout << "Please rerun the program." << endl;
	}	
	
	return choice;
	
}
/* -----------------------------------------------------------------------------
FUNCTION:          Square_a_number()
DESCRIPTION:       Squaring a number 
RETURNS:           nothing (void)
NOTES:             
------------------------------------------------------------------------------- */
 void Square_a_number()
	{
	 cout << "Please enter a number to be squared: " << endl;
	 
	  float x, sum;

	  cin >> x;

	  sum = pow(x,2);

	  cout << "x^2=" << " " << x << "^2" << " = " << sum << endl;
	
}
/* -----------------------------------------------------------------------------
FUNCTION:          Cube_a_number()
DESCRIPTION:       Cubing a number
RETURNS:           void
NOTES:             
------------------------------------------------------------------------------- */
void Cube_a_number()
{
	cout << " Please enter a number to be cubed: " << endl;
	
	float x, sum;

	cin >> x;

	sum = pow(x,3);

	cout << "x^3= "<< " " << x << " ^3" << " = " << sum << endl;
}
/* -----------------------------------------------------------------------------
FUNCTION:          Raise_to_any_power()
DESCRIPTION:       Raising the number to any power
RETURNS:           Nothing (void)
NOTES:             
------------------------------------------------------------------------------- */
void Raise_to_any_power()
{
	cout << "Please enter two numbers to be powered: " << endl;
	
	float sum;

	Get_x_and_y();

	sum = pow(x,y);

	cout << "x^y= " << " " << x << "^" << y << " = " << sum << endl;
}

/* -----------------------------------------------------------------------------
FUNCTION:          Square_root_a_number()
DESCRIPTION:       Square-rooting a number
RETURNS:           Nothing (void)
NOTES:             
------------------------------------------------------------------------------- */
void Square_root_a_number()
{
	cout << "Please enter a number to square-root: " << endl;
	float x, sum;
	

	cin >> x;

	while (x < 0)
	{
		cout << "An imaginary number is not allowed, please enter another number:" << endl;
		
		cin >> x;
		cout << " " << endl;
		sum = sqrtf(x);

	}

		sum = sqrtf(x);

		cout << "xsqrt=" << "" << x << " Square Root is " << " = "
		<< sum << endl;
}
/* -----------------------------------------------------------------------------
FUNCTION:          Cube_root_a_number()
DESCRIPTION:       Finding the cube root of any number
RETURNS:           Nothing (void)
NOTES:             
------------------------------------------------------------------------------- */
void Cube_root_a_number()
{
	cout << "Please enter a number " << endl;
	
	float x, sum;

	cin >> x;

	while (x < 0)
	{
		cout << "This is an imaginary number, please enter another number." << endl;
		cin >> x;
	}
	
		sum = cbrt(x);
	
		cout << "x^1/3=" << " " << x << "^1/3" << " = " << sum << endl;
}
/* -----------------------------------------------------------------------------
FUNCTION:          Take_any_root()
DESCRIPTION:       Taking a root of any number
RETURNS:           Nothing (void)
NOTES:             
------------------------------------------------------------------------------- */
void Take_any_root()
{
	cout << "Please enter two numbers " << endl;
	float sum;

	Get_x_and_y();
do
{

	while (x < 0)
	{
		cout << "Cannot take a negative root of a number, please enter two numbers again." << endl;
		cin >> x;
		cin >> y;
	}
	while (y == 0)
	{
	
		cout << "Cannot take a zero root of something, Please enter two numbers again. " << endl;
		cin >> x;
		cin >> y;
	}
	}while (x < 0, y == 0);

		sum = pow(x, 1/y);
	
		cout << "x sqrt y =" << " " << x << " Root " << y << " = " << sum << endl;
}
/* -----------------------------------------------------------------------------
FUNCTION:          Get_x_and_y()
DESCRIPTION:       Will be in the functions to pull x and y
RETURNS:           void
NOTES:             
------------------------------------------------------------------------------- */
void Get_x_and_y()
{
	cout << "x and y will be needed: " << endl;
	cout << "Please input x and y:  ";
	cin >> x;
	cin >> y;
	/*if (cin.fail())
	{
		cout << "Letter is not allowed, program will turn it into a zero." << endl;
		cin. clear();
	}*/
}
/* -----------------------------------------------------------------------------
FUNCTION:          Get_i_or_d()
DESCRIPTION:       Finding Division
RETURNS:           nothing (void)
NOTES:             
------------------------------------------------------------------------------- */
void Get_i_or_d()  //The function here will call either an iteger or decimal
{
	float sum;
	char choice;
	cout << "Please enter an 'i' or an 'd' (i for integer, d for decimal)" << endl;
	cin >> choice;

	 if (choice == 'i')   //If integer is chosen, there will be a static cast to keep decimals out
	{	
	 x = static_cast<int>(x);
	 y = static_cast<int>(y);
	 sum = static_cast<int>(sum);
	}
}
