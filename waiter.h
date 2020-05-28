/* waiter.h -------------------------------------------------------
   Header file for a class waiter derived from Employee that
   adds the attributes unique to waiters
Operations are:  A constructor and an output operation, calculate salary
-----------------------------------------------------------------------*/
#include "Employee.h"
#include <iostream>

#ifndef WAITER
#define WAITER

class waiter : public Employee
{
public:
    waiter(string empName = "", long empId = 0, char empClass = ' ', long empSalary = 3000, int yearsServed = 0, int profit = 0, int tips = 0);
    /*----------------------------------------------------------------------
     waiter constructor.
      Preconditions:  None.
      Postconditions: empId is initialized to id (default 0), empName
          to name (default empty string), empClass to t (default blank char),
          and empSal to salary (default 3000), profit to profit(default 0), tips to tips (Default 0)
          yearsServed to years (default 0)
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
    int years;
    long sal = getSalary();

};

//--- Definition of waiter's Constructor
inline waiter::waiter(string empName, long empId, char empClass, long empSalary, int yearsServed, int profit, int tips)
    : Employee(empName, empId, empClass, empSalary, profit, tips), //because they are private members
        years(yearsServed)
{ }


//--- Definition of waiter's display()
inline void waiter::display(ostream& out) const
{
    Employee::display(out);              //inherited members
    out << "Years worked: " << years << ' ' << endl;  //local members
    out << "Salary: " << sal << endl;


}
//--- Definition of calcSalary() function
inline int waiter::calculateSalary(int profit, int tips) {
    if(tips>0)
    sal = sal + tips;
    else {
        sal = sal;
    }
    return sal;
}
#endif
