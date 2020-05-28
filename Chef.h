/* Chef.h -------------------------------------------------------
   Header file for a class owner derived from Employee that
   adds the attributes unique to owner
Operations are:  A constructor and an output operation, calculate salary
-----------------------------------------------------------------------*/
#include "Employee.h"
#include <iostream>

#ifndef CHEF
#define CHEF

class Chef : public Employee
{
public:
    Chef(string empName = "", long empId = 0, char empClass = ' ', long empSalary = 10000, string cusineExpertise = "", int profit = 0, int tips = 0);
    /*----------------------------------------------------------------------
     waiter constructor.
      Preconditions:  None.
      Postconditions: empId is initialized to id (default 0), empName
          to name (default empty string), empClass to t (default blank char),
          and empSal to salary (default 10 000), profit to profit(default 0), tips to tips (Default 0)
          cuisineExpertise to exp (default 0)
    -----------------------------------------------------------------------*/

    virtual void display(ostream& out) const;
    /*-----------------------------------------------------------------------
      Output function member.
      Precondition:  ostream out is open.
      Postcondition: A text representation of this waiter
          object has been output to out.
     -----------------------------------------------------------------------*/

     // ... Other hourly employee operations ...
    virtual int calculateSalary(int profit, int tips);
    /*-----------------------------------------------------------------------
     calculate salary function
     Precondition:  profit and empSalary entered by user
     Postcondition: calculates salary for waiter object
   ------------------------------------------------------------------------*/

private:
    string exp;
    long sal = getSalary();

};

//--- Definition of waiter's Constructor
inline Chef::Chef(string empName, long empId, char empClass, long empSalary, string cusineExpertise, int profit, int tips)
    : Employee(empName, empId, empClass, empSalary, profit, tips), //because they are private members
    exp(cusineExpertise)
{ }


//--- Definition of waiter's display()
inline void Chef::display(ostream& out) const
{
    Employee::display(out);              //inherited members
    out << "Cuisine of expertise: "<< exp << ' ' << endl;  //local members
    out << "Salary: " << sal << endl;

}
//--- Definition of calcSalary() function
inline int Chef::calculateSalary(int profit, int tips) {
    if(profit>0)
    sal = sal + profit * 20 / 100;
    else {
        sal = sal;
    }
    return sal;
}
#endif