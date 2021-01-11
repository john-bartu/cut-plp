//
// Created by bartu on 12/29/2020.
//

#include <iostream>
#include <list>
#include "Employee.h"
#include "HRMS.h"

using namespace std;

int main() {


    HRMS system;
    try {
        list<pair<Employee, double>> employees;
        employees.emplace_back(Employee("101", "Maliha ", "Hunter", "StatMat", "STUDENT"), 17000);
        employees.emplace_back(Employee("102", "Christina ", "Leon", "StatMat", "STUDENT"), 17000);
        employees.emplace_back(Employee("104", "Harriette ", "East", "JiPP", "LECTURER"), 6000);
        employees.emplace_back(Employee("105", "Winnie ", "Muir", "JiPP", "LECTURER"), 4800);
        employees.emplace_back(Employee("106", "Lori ", "Bowman", "JiPP", "LECTURER"), 4800);
        employees.emplace_back(Employee("107", "Aairah ", "Delacruz", "JiPP", "LECTURER"), 4200);
        employees.emplace_back(Employee("109", "Aston ", "Skinner", "Law", "BOSS"), 9000);
        employees.emplace_back(Employee("110", "Tyler ", "Ferry", "Law", "BOSS"), 8200);
        employees.emplace_back(Employee("111", "Cillian ", "Wickens", "Law", "BOSS"), 7700);
        employees.emplace_back(Employee("112", "Brandan  ", "Clemons", "Law", "BOSS"), 7800);
        employees.emplace_back(Employee("113", "Boyd ", "Fountain", "Law", "BOSS"), 6900);
        employees.emplace_back(Employee("117", "Nazim ", "Villa", "Biology", "MANAGER"), 3100);

        for (auto employeeSalary : employees)
            system.add(employeeSalary.first, employeeSalary.second);

        system.printDepartment("Biology");
        system.printDepartment("JiPP");
        system.printDepartment("Astronomy");

        cout << "Unsorted salaries:" << endl;
        system.printSalaries();

        cout << "Nazim now gets 999$..." << endl << endl;
        system.changeSalary("117", 999);

        cout << "Sorted salaries:" << endl;
        system.printSalariesSorted();
    } catch (invalid_argument &e) {
        cout << "\tERR: " << e.what() << endl;
    }


    cout << endl << "--- tests ---" << endl << endl;

    cout << "Adding employee with already existing id..." << endl;
    try {
        Employee emp = Employee("101", "Maliha", "Hunter", "StatMat", "STUDENT");
        system.add(emp, 10000);
    } catch (invalid_argument &e) {
        cout << "\tERR: " << e.what() << endl;
    }

    cout << "Adding employee with salary less than zero" << endl;
    try {
        system.add(Employee("Im", "Not", "A", "Test", "TEST POS"), -999);
    } catch (invalid_argument &e) {
        cout << "\tERR: " << e.what() << endl;
    }

    cout << "Changing salary of employee whichone not exist..." << endl;
    try {
        system.changeSalary("1000", 5000);
    } catch (invalid_argument &e) {
        cout << "\tERR: " << e.what() << endl;
    }

    return 0;
}