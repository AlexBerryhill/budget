/***********************************************************************   
* Program:                                                                 
*    Project 04, Monthly Budget                                            
*    Brother Ridges, CS124                                                 
* Author:                                                                  
*    Alexander Berryhill                                                   
* Summary:                                                                 
*    This program will ask for a budget, accept a budget input, and        
*    display the budget and monthly expenses in a graph. All using         
*    functions.                                                            
*                                                                          
*                                                                          
*    Estimated:  3.0 hrs                                                   
*    Actual:     2.0 hrs                                                   
*      The hardest part was adding all the boxes for individual functions.
*                                                                          
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************    
 * getIncome will ask user for income, receive income, and return income.  
 **********************************************************************/
double getIncome()
{
   double income;
   cout << "\tYour monthly income: ";
   cin >> income;
   return income;
}

/**********************************************************************    
 * getBudgetLiving will ask user for budgeted living, receive budgeted     
 * living, and return budgeted living.                                     
 **********************************************************************/
float getBudgetLiving()
{
   float budgLiving;
   cout << "\tYour budgeted living expenses: ";
   cin >> budgLiving;
   return budgLiving;
}

/**********************************************************************    
 * getActualLiving will ask user for actual living, receive actual living,
 * and return actual living.                                               
 **********************************************************************/
float getActualLiving()
{
   float actLiving;
   cout << "\tYour actual living expenses: ";
   cin >> actLiving;
   return actLiving;
}

/**********************************************************************    
 * getActualOther will ask user for other, receive other,                  
 * and return other.                                                       
 **********************************************************************/
float getActualOther()
{
    float actOther;
   cout << "\tYour actual other expenses: ";
   cin >> actOther;
   return actOther;
}

/**********************************************************************    
 * getActualTithing will ask user for tithing, receive tithing,            
 * and return tithing.                                                     
 **********************************************************************/
float getActualTithing()
{
   float actTithe;
   cout << "\tYour actual tithe offerings: ";
   cin >> actTithe;
   return actTithe;
}

/**********************************************************************    
 * getActualTax will ask user for tax, receive tax, and return tax.        
 **********************************************************************/
float getActualTax()
{
   float actTax;
   cout << "\tYour actual taxes withheld: ";
   cin >> actTax;
   return actTax;
}

/**********************************************************************    
 * computeTax will receive income, do the math, and return monthly tax.    
 **********************************************************************/
 double computeTax(double income)
{
   double yrlyIncome = income * 12;
   double yrlyTax;

   if (yrlyIncome < 15100)
   {
      yrlyTax = (yrlyIncome * 0.10);
      return (yrlyTax / 12);
   }
   else if (yrlyIncome < 61300)
   {
      yrlyTax = 1510 + 0.15 * (yrlyIncome - 15100);
      return (yrlyTax / 12);
   }
   else if (yrlyIncome < 123700)
   {
      yrlyTax = 8440 + 0.25 * (yrlyIncome - 61300);
      return (yrlyTax / 12);
   }
   else if (yrlyIncome < 188450)
   {
      yrlyTax = 24040 + 0.28 * (yrlyIncome - 123700);
      return (yrlyTax / 12);
   }
   else if (yrlyIncome < 336550)
   {
      yrlyTax = 42170 + 0.33 * (yrlyIncome - 188450);
      return (yrlyTax / 12);
   }
   else
   {
        yrlyTax = 91043 + 0.35 * (yrlyIncome - 336550);
      return (yrlyTax / 12);
   }
}

/**********************************************************************    
 * computeTithing will receive income, do math, and return tithing.        
 **********************************************************************/
float computeTithing(float income)
{
   return income * .1;
}

/**********************************************************************    
 * display will take all the input and display it in a graph.              
 **********************************************************************/
void display(double income, float budgLiving, float actLiving,
             float actTithe, float actTax,  float actOther)
{
   //declare values I will need soon                                       
   float budgTax = computeTax(income);
   float budgTithe = computeTithing(income);
   float budgOther = income - budgTax - budgTithe - budgLiving;
   float actDiffnce = income - actTax - actTithe - actLiving - actOther;

   //display all my values in a graph                                      
   cout << "The following is a report on your monthly expenses\n";
   cout << "\tItem                  Budget          Actual\n";
   cout << "\t=============== =============== ===============\n";
   cout << "\tIncome          $" << setw(11) << income;
   cout << "    $" << setw(11) << income << endl;
   cout << "\tTaxes           $" << setw(11) << budgTax;
    cout << "    $" << setw(11) << actTax << endl;
   cout << "\tTithing         $" << setw(11) << budgTithe;
   cout << "    $" << setw(11) << actTithe << endl;
   cout << "\tLiving          $" << setw(11) << budgLiving;
   cout << "    $" << setw(11) << actLiving << endl;
   cout << "\tOther           $" << setw(11) << budgOther;
   cout << "    $" << setw(11) << actOther << endl;
   cout << "\t=============== =============== ===============\n";
   cout << "\tDifference      $" << setw(11) << 0.00;
   cout << "    $" << setw(11) << actDiffnce << endl;

   return;
}

/**********************************************************************    
 * The main will declare the float values, set the cout to show money,     
 * call functions to fill values, PUT the values into the display          
 * function.                                                               
 ***********************************************************************/
int main()
{
   //declare all floats and double                                         
   double income;
   float budgLiving;
   float actLiving;
   float actTax;
   float actTithe;
   float actOther;

   //Set cout to display money                                             
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
      cout.precision(2);

   //Ask and ye shall receive float values                                 
   cout << "This program keeps track of your monthly budget\n";
   cout << "Please enter the following:\n";
   income = getIncome();
   budgLiving = getBudgetLiving();
   actLiving = getActualLiving();
   actTax = getActualTax();
   actTithe = getActualTithing();
   actOther = getActualOther();
   cout << endl;

   //Display values in a graph                                             
   display(income, budgLiving, actLiving, actTithe, actTax, actOther);

   return 0;
}
