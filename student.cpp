/*****************************************************
// Created by Michael Hefner on 5/20/19.
// Scripting and Programming - Applications – C867 C++
// Student ID #001075355
*****************************************************/


using namespace std;

#include <iostream>
#include <iomanip>
#include "degree.h"
#include "student.h"

// Constructor
Student::Student(){
    return;
}

// Desstructor
Student::~Student() {
    return;
}

// Constructor with arguments to load all values into local variables
Student::Student(string pStudentID,
                 string pFirstName,
                 string pLastName,
                 string pEmailAddress,
                 int pAge,
                 int pDaysUntilComplete[3],
                 Degree pDegree){

    studentID = pStudentID;
    firstName = pFirstName;
    lastName = pLastName;
    emailAddress = pEmailAddress;
    age = pAge;
    degreeType = pDegree;
    for (int i = 0; i < 3; ++i){
        daysUntilComplete[i] = pDaysUntilComplete[i];
    }
    return;
}

void Student::print(){
    // Create a line for structure.
    for (int i = 0; i < 118; ++i){
        cout << "=";
    }

    // Header
    cout << endl << "|";
    cout << setw(15) << left << "Student ID" << "|";
    cout << setw(15) << left << "First Name" << "|";
    cout << setw(15) << left << "Last Name" << "|";
    cout << setw(25) << left << "Email" << "|";
    cout << setw(10) << left <<  "Age" << "|";
    cout << setw(15) << left << "Days in Course" << "|";
    cout << setw(15) << left << "Degree"  << "|" << endl;
    for (int i = 0; i < 118; ++i){
        cout << "-";
    }

    cout << endl << '|';
    cout << setw(15) << left << studentID << "|";
    cout << setw(15) << left << firstName << "|" ;
    cout << setw(15) << left << lastName << "|";
    cout << setw(25) << left << emailAddress  << "|";
    cout << setw(10) << left << age << "|";

    // Cycle through daysUntilComplete to get all class days remaining.
    for(int i = 0; i < 3; ++i){
        cout <<  daysUntilComplete[i];
        if(i < 2){
            cout << ",";
        }
    }

    cout << setw(8) << right << "|";

    // Switch statement to find what degree was sent to print
    switch (degreeType){
        case 0:
            cout << setw(15) << left << "SECURITY" << "|" << endl;
            break;
        case 1:
            cout << setw(15) << left << "NETWORKING" << "|" << endl;
            break;
        case 2:
            cout << setw(15) << left << "SOFTWARE"  << "|" << endl;
            break;
    }
    for (int i = 0; i < 118; ++i){
        cout << "-";
    }
    cout << endl;
    return;
}


// Getters
const string &Student::getStudentId() const {
    return studentID;
}

const string &Student::getFirstName() const {
    return firstName;
}

const string &Student::getLastName() const {
    return lastName;
}

const string &Student::getEmailAddress() const {
    return emailAddress;
}

int Student::getAge() const {
    return age;
}

const int *Student::getDaysUntilComplete() const {
    return daysUntilComplete;
}

Degree Student::getDegreeType() const {
    return degreeType;
}


void getDegreeProgram(){
    return;
}




// Setters
void Student::setStudentId(const string &studentId) {
    studentID = studentId;
    return;
}

void Student::setFirstName(const string &firstName) {
    Student::firstName = firstName;
    return;
}

void Student::setLastName(const string &lastName) {
    Student::lastName = lastName;
    return;
}

void Student::setEmailAddress(const string &emailAddress) {
    Student::emailAddress = emailAddress;
    return;
}

void Student::setAge(int age) {
    Student::age = age;
    return;
}

void Student::setDaysUntilComplete(int addCourseDaysInt[]){
    for(int i = 0; i < 3; ++i){
        daysUntilComplete[i] = addCourseDaysInt[i];
    }
    return;

}

void Student::setDegreeType(Degree degreeType) {
    Student::degreeType = degreeType;
    return;
}
