/*****************************************************
// Created by Michael Hefner on 5/20/19.
// Scripting and Programming - Applications – C867 C++
// Student ID #001075355
*****************************************************/


#ifndef ROSTER_SOFTWARESTUDENT_H
#define ROSTER_SOFTWARESTUDENT_H

#include "student.h"

class SoftwareStudent : public Student {
public:
    // Empty getDegreeProgram() function
    Degree getDegreeProgram() const;
};
#endif //ROSTER_SOFTWARESTUDENT_H
