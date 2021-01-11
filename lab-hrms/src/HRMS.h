//
// Created by bartu on 12/29/2020.
//

#ifndef LABORATORIES_HRMS_H
#define LABORATORIES_HRMS_H

#include "Employee.h"
#include <string>
#include <map>
#include <list>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class HRMS {
private:
    map<string, Employee> employeeMap;
    map<string, list<string>> employeeDepartment;
    map<string, double> employeeSalary;
public:
    void add(Employee employee, double salary);

    void printDepartment(string departmentId);

    void changeSalary(string employeeId, double salary);

    void printSalaries();

    void printSalariesSorted();

    void printEmployee(string employeeId);

    bool employeeExists(string employeeId);
};


#endif //LABORATORIES_HRMS_H
