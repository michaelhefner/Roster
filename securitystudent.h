/*****************************************************
// Created by Michael Hefner on 5/20/19.
// Scripting and Programming - Applications – C867 C++
// Student ID #001075355
*****************************************************/


#ifndef ROSTER_SECURITYSTUDENT_H
#define ROSTER_SECURITYSTUDENT_H

#include "student.h"

class SecurityStudent : public Student{
public:
    // Empty getDegreeProgram() function
    Degree getDegreeProgram() const;
};


#endif //ROSTER_SECURITYSTUDENT_H
