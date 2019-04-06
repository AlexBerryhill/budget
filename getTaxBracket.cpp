/***********************************************************************   
* Program:                                                                 
*    Assignment 16, IF Statements                                          
*    Brother Ridges, CS124                                                 
* Author:                                                                  
*    Alexander Berryhill                                                   
* Summary:                                                                 
*    This program will take an input income and return what tax bracket    
*    it is in using if statements in a separate function.                  
*                                                                          
*                                                                          
*                                                                          
*    Estimated:  0.5 hrs                                                   
*    Actual:     0.2 hrs                                                   
*      The most difficult part was writing the weird numbers that brackets
*      seem to have.                                                       
************************************************************************/

#include <iostream>
using namespace std;

/***********************************************************************   
 * computeTax will take an income and return the income's tax bracket.     
 ***********************************************************************/
int computeTax(int income)
{
   if ( income <= 15100 )
   {
      return 10;
   }
   else if ( income <= 61300 )
   {
      return 15;
   }
   else if ( income <= 123700 )
   {
      return 25;
   }
   else if ( income <= 188450 )
   {
      return 28;
   }
   else if ( income <= 336550 )
   {
      return 33;
   }
   else
   {
      return 35;
   }
}

/***********************************************************************   
 * main will initialize income ask a user to fill income, fill the income  
 * then will call computeTax() and cout the income's tax bracket.          
 ***********************************************************************/
int main()
{
   int income;
   cout << "Income: ";
   cin >> income;
   cout << "Your tax bracket is " << computeTax(income) << "%\n";
   return 0;
}