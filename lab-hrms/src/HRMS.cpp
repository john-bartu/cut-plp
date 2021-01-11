//
// Created by bartu on 12/29/2020.
//


#include "HRMS.h"

void HRMS::add(Employee employee, double salary) {
    if(salary<0){
        throw invalid_argument("Salary of " + employee.getId() + " shall not be less than zero");
    }

    string emplyeeId = employee.getId();
    string departmentId = employee.getDepartmentId();

    if (this->employeeMap.insert(make_pair(emplyeeId, employee)).second) {
        this->employeeSalary[emplyeeId] = salary;
        this->employeeDepartment[departmentId].push_back(emplyeeId);
    } else {
        throw invalid_argument("Employee already exists in HRMS...");
    }
}

void HRMS::printDepartment(string departmentId) {

    cout << "Department id: " << departmentId << " employees:" << endl;

    if (this->employeeDepartment[departmentId].empty()) {
        cout << "-- empty --" << endl;
    } else {

        for (string employeeId: this->employeeDepartment[departmentId]) {
            Employee employee = this->employeeMap[employeeId];
            cout << employee.getName() << " | " << employee.getSurname() << " | " << employee.getPosition() << endl;
        }
    }
    cout << endl;

}

void HRMS::changeSalary(string employeeId, double salary) {
    if (employeeExists(employeeId))
        this->employeeSalary[employeeId] = salary;
    else
        throw invalid_argument("Employee not exists in HRMS");
}

void HRMS::printSalaries() {
    if (this->employeeSalary.empty()) {
        cout << "-- HRMS salary is empty --" << endl;
    } else {


        for (auto item: this->employeeSalary) {
            string employeeId = item.first;
            double salary = item.second;

            Employee employee = this->employeeMap[employeeId];
            cout << employee.getName() << " | " << employee.getSurname() << " | " << employee.getPosition() << ": "
                 << salary << endl;
        }
    }

}


void HRMS::printSalariesSorted() {

    if (this->employeeSalary.empty()) {
        cout << "-- HRMS salary is empty --" << endl;
    } else {

        vector<pair<string, double>> sortedSalaries;
        for (auto employeeSalary : this->employeeSalary) {
            sortedSalaries.push_back(employeeSalary);
        }

        sort(sortedSalaries.begin(), sortedSalaries.end(),
             [](pair<string, double> &a, pair<string, double> &b) -> bool { return a.second < b.second; }
        );

        for (auto item: sortedSalaries) {
            string employeeId = item.first;
            double salary = item.second;

            Employee employee = this->employeeMap[employeeId];
            cout << employee.getName() << " | " << employee.getSurname() << " | " << employee.getPosition() << ": "
                 << salary << endl;
        }
    }

}

void HRMS::printEmployee(string employeeId) {
    if (employeeExists(employeeId)) {
        cout << "-- employee not found --" << endl;
    } else {

        Employee employee = this->employeeMap[employeeId];
        cout << employee.getName() << " | " << employee.getSurname() << " | " << employee.getPosition() << endl;

    }
}

bool HRMS::employeeExists(string employeeId) {
    return this->employeeMap.find(employeeId) != this->employeeMap.end();
}

