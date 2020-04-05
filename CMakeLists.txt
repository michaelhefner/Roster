cmake_minimum_required(VERSION 3.14)
project(Roster)

set(CMAKE_CXX_STANDARD 14)

add_executable(Roster roster.cpp roster.h student.cpp student.h securitystudent.cpp securitystudent.h softwarestudent.cpp softwarestudent.h degree.h networkstudent.cpp networkstudent.h)