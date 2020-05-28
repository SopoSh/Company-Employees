// Ass4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*--------------------------------------------------------------------------
      Driver program to process a list of pointers to employee objects.
 -------------------------------------------------------------------------*/

#include <iostream>
#include <list> //STL library for implemented list
#include <string>

using namespace std;
#include "Employee.h"
#include "waiter.h"
#include "Owner.h"
#include "Chef.h"

int main()
{
    cout << "Enter this month's profit and tips for three waiters: " << endl;
    int empProfit, empTips1, empTips2, empTips3;
    cin >> empProfit;
    cin >> empTips1;
    cin >> empTips2;
    cin >> empTips3;

    Employee* ptr;                   //create pointer to the object of type employee, linked list
    list<Employee*> empList; 

    ptr = new Owner("Heath Ledger", 7754368, 'O', 15000, 15, empProfit, empTips1);
    ptr->calculateSalary(empProfit, empTips1);
    empList.push_back(ptr);         //pushback adds node to a list

    ptr = new Chef("Cesar Romero", 79143891, 'C', 10000, "Italian", empProfit, empTips1);
    ptr->calculateSalary(empProfit, empTips1);
    empList.push_back(ptr);

    ptr = new Chef("Mark Hamill", 82736451, 'C', 10000, "French", empProfit, empTips1);
    ptr->calculateSalary(empProfit, empTips1);
    empList.push_back(ptr);

    ptr = new waiter("Jared Leto", 17362549, 'W', 3000, 3, empProfit, empTips1);
    ptr->calculateSalary(empProfit, empTips1);
    empList.push_back(ptr);

    ptr = new waiter("Jack Nicholson", 73635284, 'W', 3000, 5, empProfit, empTips2);
    ptr->calculateSalary(empProfit, empTips2);
    empList.push_back(ptr);

    ptr = new waiter("Joaquin Phoenix", 28364522, 'W', 3000, 7, empProfit, empTips3);
    ptr->calculateSalary(empProfit, empTips3);
    empList.push_back(ptr);

    for (list<Employee*>::iterator it = empList.begin();       //iterator acts like a sticker and helps with iteration
        it != empList.end(); it++)
    {
        ptr = *it;
        cout << *ptr << endl;   //here can be used **it
    }
 
}
