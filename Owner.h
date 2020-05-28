/* Owner.h -------------------------------------------------------
   Header file for a class owner derived from Employee that
   adds the attributes unique to owner
Operations are:  A constructor and an output operation, calculate salary
-----------------------------------------------------------------------*/
#include "Employee.h"
#include <iostream>

#ifndef OWNER
#define OWNER

class Owner : public Employee
{
public:
    Owner(string empName = "", long empId = 0, char empClass = ' ', long empSalary =15000, int profit = 0, int tips = 0, int yearsOfBusiness = 0);
    /*----------------------------------------------------------------------
     waiter constructor.
      Preconditions:  None.
      Postconditions: empId is initialized to id (default 0), empName
          to name (default empty string), empClass to t (default blank char),
          and empSal to salary (default 15 000), profit to profit(default 0), tips to tips (Default 0)
          yearsOfBusiness to businessYears (default 0)
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
    int businessYears;
    long sal = getSalary();
};

//--- Definition of waiter's Constructor
inline Owner::Owner(string empName, long empId, char empClass, long empSalary, int profit , int tips , int yearsOfBusiness)
    : Employee(empName, empId, empClass, empSalary, profit, tips), businessYears(yearsOfBusiness)
{ }

//--- Definition of calcSalary() function
inline int Owner::calculateSalary(int profit, int tips) {
    if (profit > 0)
        sal = sal + profit * 60 / 100;
    else {
        sal = sal;
    }

    return sal;
}


//--- Definition of waiter's display()
inline void Owner::display(ostream& out) const
{
    Employee::display(out);              //inherited members
    out << "Years of Business: " << businessYears << ' ' << endl;  //local members
    out << "Salary: " << sal << endl;


}

#endif