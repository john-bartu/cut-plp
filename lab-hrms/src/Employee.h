//
// Created by bartu on 12/29/2020.
//

#ifndef LABORATORIES_EMPLOYEE_H
#define LABORATORIES_EMPLOYEE_H

#include <string>

using namespace std;

class Employee {
private:
    string id;
    string name;
    string surname;
    string departmentId;
    string position;

public:
    Employee();

    Employee(string id, string name, string surname, string departmentId,
             string position);

    string getId();
    string getName();
    string getSurname();
    string getPosition();
    string getDepartmentId();
};


#endif //LABORATORIES_EMPLOYEE_H
