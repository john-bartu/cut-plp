//
// Created by bartu on 12/29/2020.
//

#include "Employee.h"

Employee::Employee() {

}

Employee::Employee(string id, string name, string surname, string departmentId,
                   string position) {
    this->departmentId = departmentId;
    this->id = id;
    this->name = name;
    this->position = position;
    this->surname = surname;
}

string Employee::getId() {
    return this->id;
}

string Employee::getName() {
    return this->name;
}

string Employee::getSurname() {
    return this->surname;
}

string Employee::getPosition() {
    return this->position;
}

string Employee::getDepartmentId() {
    return this->departmentId;
}


