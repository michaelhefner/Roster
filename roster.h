/*****************************************************
// Created by Michael Hefner on 5/20/19.
// Scripting and Programming - Applications – C867 C++
// Student ID #001075355
*****************************************************/

#ifndef ROSTER_ROSTER_H
#define ROSTER_ROSTER_H
using namespace std;

#include "networkstudent.h"
#include "securitystudent.h"
#include "softwarestudent.h"

class Roster {
private:
    NetworkStudent networkStudent;
    SecurityStudent securityStudent;
    SoftwareStudent softwareStudent;
    Student classRosterArray[5] = {};
public:
    Roster();           // Constructor
    ~Roster();          // Destructor
    const Student *getClassRosterArray() const;
    void add(string studentID,
            string firstName,
            string lastName,
            string emailAddress,
            int age,
            int daysInCourse1,
            int daysInCourse2,
            int daysInCourse3,
            Degree program);            //set the instance variables from D1 and update the roster
    void remove(string studentID);      // remove student from the roster
    void printAll();                    // print a complete tab-separated list of student data
    void printAverageDaysInCourse(string studentID);   // print students average number of days in the three courses
    void printInvalidEmails();          // verifies student email addresses and displays all invalid email addresses
    void printByDegreeProgram(Degree degreeProgram);   //print out student information for a degree program specified by an enumerated type

};


#endif //ROSTER_ROSTER_H