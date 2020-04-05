/*****************************************************
// Created by Michael Hefner on 5/20/19.
// Scripting and Programming - Applications – C867 C++
// Student ID #001075355
*****************************************************/


#ifndef ROSTER_NETWORKSTUDENT_H
#define ROSTER_NETWORKSTUDENT_H

#include "student.h"

class NetworkStudent : public Student{

public:
    // Empty getDegreeProgram() function
    Degree getDegreeProgram() const;
};


#endif //ROSTER_NETWORKSTUDENT_H
