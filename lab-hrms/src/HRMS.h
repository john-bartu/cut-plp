//
// Created by bartu on 12/29/2020.
//

#ifndef LABORATORIES_HRMS_H
#define LABORATORIES_HRMS_H

#include "Employee.h"
#include <string>
#include <map>

using namespace std;

class HRMS {
    map <int, Employee> employeeMap;
    map <int, string> employeeDepartment;
    map <int, double> employeeSalary;
};


#endif //LABORATORIES_HRMS_H
