/*****************************************************
// Created by Michael Hefner on 5/20/19.
// Scripting and Programming - Applications – C867 C++
// Student ID #001075355
*****************************************************/


using namespace std;
#ifndef ROSTER_STUDENT_H
#define ROSTER_STUDENT_H

#include "degree.h"
#include <string>

class Student {
private:
    string studentID = "";
    string firstName = "";
    string lastName = "";
    string emailAddress = "";
    int age = 0;
    int daysUntilComplete[3] = {-1,-1,-1};
    Degree degreeType;
public:
    // Getters
    const string &getStudentId() const;
    const string &getFirstName() const;
    const string &getLastName() const;
    const string &getEmailAddress() const;
    int getAge() const;
    const int *getDaysUntilComplete() const;
    Degree getDegreeType() const;

    //Setters
    void setStudentId(const string &studentId);
    void setFirstName(const string &firstName);
    void setLastName(const string &lastName);
    void setEmailAddress(const string &emailAddress);
    void setAge(int age);
    void setDaysUntilComplete(int addCourseDaysInt[]);
    void setDegreeType(Degree degreeType);

    Student();                          // Default constructor
    ~Student();                         // Destructor
    Student(string studentID,
            string firstName,
            string lastName,
            string emailAddress,
            int age,
            int daysUntilComplete[3],
            Degree degree);             // Full constructor
    void print();
    Degree getDegreeProgram();          // Function to be overwritten

};


#endif //ROSTER_STUDENT_H
