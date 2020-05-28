/* Employee.h --------------------------------------------------------------
   Header file for a class Employee that encapsulates the attributes common
   to all three types of employees (is a relationship)
   Operations are:  A constructor and an output operation, calculate salary
   -----------------------------------------------------------------------*/
#include <iostream>

#ifndef EMPLOYEE
#define EMPLOYEE

class Employee
{
public:
    Employee(string empName = "", long empId = 0, char empClass = ' ', long empSalary = 0, int profit = 0, int tips=0);
    /*-----------------------------------------------------------------------
      Employee constructor.
      Preconditions:  None.
      Postconditions: empId is initialized to id (default 0), empName
          to name (default empty string), empClass to t (default blank char),
          and empSal to salary (default 0), profit to profit(default 0), tips to tips (Default 0).
      ----------------------------------------------------------------------*/

    virtual void display(ostream& out) const;
    /*-----------------------------------------------------------------------
      Output function member.
      Precondition:  ostream out is open.
      Postcondition: A text representation of this Employee object has
          been output to out.
    ------------------------------------------------------------------------*/

    // ... Other employee operations ...
    virtual int calculateSalary(int profit, int tips) = 0; //pure virtual function, defined for each child class seperately 
     /*-----------------------------------------------------------------------
      calculate salary function 
      Precondition:  profit and empSalary entered by user
      Postcondition: calculates salary for each type
    ------------------------------------------------------------------------*/
    long getSalary(); //need accessor to use it for calculateSalary function

private:
    //commonalities
    string name;         //     employee's st name
    long id;             // Employee's id number
    char t;          //   type of employee
    long salary;             //    employee salary
    //
    int profit;
    int tips;
  
};
inline long Employee::getSalary() {
    return salary;
}

//--- Definition of Employee's Constructor
inline Employee::Employee(string empName, long empId, char empClass, long empSalary, int profit, int tips)
    : name(empName), id(empId),
    t(empClass), salary(empSalary), profit(profit), tips(tips)
{ }

//--- Definition of Employee's display()
inline void Employee::display(ostream& out) const
{
    out <<  endl;
    out << "Name: " << name << endl;
    out << "Id: " << id << endl;
    out << "Class: " << t << endl;
} 

//--- Definition of output operator <<
inline ostream& operator<<(ostream& out, const Employee& emp)
{
    emp.display(out);
    return out;
};

#endif
