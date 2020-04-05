/*****************************************************
// Created by Michael Hefner on 5/20/19.
// Scripting and Programming - Applications – C867 C++
// Student ID #001075355
*****************************************************/

#include <iostream>
#include <sstream>
#include "student.h"
#include "roster.h"

using namespace std;

// The getNextComma function searches through the student string,
// that is provided by one location in the studentData array,
// that finds the location of the next ',' and returns the index.
// If no comma is found -1 is returned
int getNextComma(string student){
    int returnValue = -1;
    if (student.find(",")){
        returnValue = student.find(",");
    }
    return returnValue;
}

// removedPriorEntry function takes in the current student string and
// removes the used data from the string.
string removedPriorEntry(string currentStudent){
    return currentStudent.substr(getNextComma(currentStudent) + 1,
            currentStudent.length() - getNextComma(currentStudent));
}

// nextParsedEntry function returns the next peice of information from
// the currentStudent string by taking the index zero to the index of
// the next comma.
string nextParsedEntry(string currentStudent){
    return currentStudent.substr(0, getNextComma(currentStudent));
}

// parseStudentData function utilized the three prior functions to parse
// each iteration of the studentData array.
Student parseStudentData(string currentStudent){
    // A temporary Student object is needed to load all parsed information into
    Student* tempStudent = new Student;

    // Parse and load each value into the tempStudent object
    tempStudent->setStudentId(nextParsedEntry(currentStudent));
    currentStudent = removedPriorEntry(currentStudent);

    tempStudent->setFirstName(nextParsedEntry(currentStudent));
    currentStudent = removedPriorEntry(currentStudent);

    tempStudent->setLastName(nextParsedEntry(currentStudent));
    currentStudent = removedPriorEntry(currentStudent);

    tempStudent->setEmailAddress(nextParsedEntry(currentStudent));
    currentStudent = removedPriorEntry(currentStudent);

    int age = 0;
    // sstream library is neaded to convert the string to an integer
    istringstream convert(nextParsedEntry(currentStudent));
    convert >> age;
    tempStudent->setAge(age);
    currentStudent = removedPriorEntry(currentStudent);

    int days1 = 0;
    int days2 = 0;
    int days3 = 0;
    // sstream library is neaded to convert the string to an integer
    istringstream convertDays1(nextParsedEntry(currentStudent));
    convertDays1 >> days1;
    currentStudent = removedPriorEntry(currentStudent);

    // sstream library is neaded to convert the string to an integer
    istringstream convertDays2(nextParsedEntry(currentStudent));
    convertDays2 >> days2;
    currentStudent = removedPriorEntry(currentStudent);

    // sstream library is neaded to convert the string to an integer
    istringstream convertDays3(nextParsedEntry(currentStudent));
    convertDays3 >> days3;
    currentStudent = removedPriorEntry(currentStudent);

    int daysToComplete[] = {days1, days2, days3};
    tempStudent->setDaysUntilComplete(daysToComplete);
    currentStudent = removedPriorEntry(currentStudent);

    string degree = nextParsedEntry(currentStudent);
    if (degree == "SECURITY") {
        tempStudent->setDegreeType(SECURITY);
    }else if (degree == "NETWORKING"){
        tempStudent->setDegreeType(NETWORKING);
    }else if(degree == "SOFTWARE") {
        tempStudent->setDegreeType(SOFTWARE);
    }

    return *tempStudent;
}


int main() {

    Roster* classRoster = new Roster;

    const string studentData[] =
            {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
             "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORKING",
             "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
             "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
             "A5,Michael,Hefner,mhefne6@my.wgu.edu,35, 10,21,22,SOFTWARE"
            };

    // Create a temporary student to load parse data into
    Student* tempStudent = new Student;
    for ( int i = 0; i < 5; ++i){
        *tempStudent = parseStudentData(studentData[i]);
        int days1 = tempStudent->getDaysUntilComplete()[0];
        int days2 = tempStudent->getDaysUntilComplete()[1];
        int days3 = tempStudent->getDaysUntilComplete()[2];
        classRoster->add(tempStudent->getStudentId(),
                tempStudent->getFirstName(),
                tempStudent->getLastName(),
                tempStudent->getEmailAddress(),
                tempStudent->getAge(),
                days1,
                days2,
                days3,
                tempStudent->getDegreeType());
    }
    cout << "\n\n\n" << "Scripting and Programming Applications C867\t"
        << "C++\t"
        << "Student ID #001075355\t"
        << "Michael Hefner" << endl;
    classRoster->printAll();
    classRoster->printInvalidEmails();

    // Loop through the classRosterArray to call printAverageDaysInCourse()
    for(int i = 0; i < 5; ++i){
        classRoster->printAverageDaysInCourse(classRoster->getClassRosterArray()[i].getStudentId());
    }

    // Print students based on given program
    classRoster->printByDegreeProgram(SOFTWARE);
    // First removal attempt
    classRoster->remove("A3");
    // Second removal attempt
    classRoster->remove("A3");
    // Deconstruct
    delete classRoster;
    // Deconstruct
    delete tempStudent;
    return 0;
}

// Set the instance variables from D1 and update the roster
void Roster::add(string studentID,
         string firstName,
         string lastName,
         string emailAddress,
         int age,
         int daysInCourse1,
         int daysInCourse2,
         int daysInCourse3,
         Degree program){
    // Keep track of the current amount of entries and increment at the end
    static int rosterCounter = 0;

    int daysInCourse[3] = {daysInCourse1, daysInCourse2, daysInCourse3};

    // Based on the given program, create student based on program
    switch (program){
        case 0:
            securityStudent.setStudentId(studentID);
            securityStudent.setFirstName(firstName);
            securityStudent.setLastName(lastName);
            securityStudent.setEmailAddress(emailAddress);
            securityStudent.setAge(age);
            securityStudent.setDaysUntilComplete(daysInCourse);
            securityStudent.setDegreeType(program);

            classRosterArray[rosterCounter] = securityStudent;
            break;
        case 1:
            networkStudent.setStudentId(studentID);
            networkStudent.setFirstName(firstName);
            networkStudent.setLastName(lastName);
            networkStudent.setEmailAddress(emailAddress);
            networkStudent.setAge(age);
            networkStudent.setDaysUntilComplete(daysInCourse);
            networkStudent.setDegreeType(program);

            classRosterArray[rosterCounter] = networkStudent;
            break;
        case 2:
            softwareStudent.setStudentId(studentID);
            softwareStudent.setFirstName(firstName);
            softwareStudent.setLastName(lastName);
            softwareStudent.setEmailAddress(emailAddress);
            softwareStudent.setAge(age);
            softwareStudent.setDaysUntilComplete(daysInCourse);
            softwareStudent.setDegreeType(program);

            classRosterArray[rosterCounter] = softwareStudent;
            break;
    }

    ++rosterCounter;
    return;

}

// remove student from the roster
void Roster::remove(string studentID){
    bool studentIDFound = false;

    // Search through array for student ID, if found place an empty set in the current location
    for(int i = 0; i < 5; ++i){
        if(classRosterArray[i].getStudentId() == studentID){
            classRosterArray[i] = {};
            studentIDFound = true;
        }
    }

    // If no student is found display result
    if(!studentIDFound){
        cout << "SUCH A STUDENT WITH THIS ID WAS NOT FOUND '" << studentID << "'" << endl;
    }
    return;

}

// print a complete tab-separated list of student data
void Roster::printAll(){
    // Loop through all roster entries and print
    for( int i = 0; i < 5; ++i){
        classRosterArray[i].print();
    }
    return;

}

// print students average number of days in the three courses
void Roster::printAverageDaysInCourse(string studentID){
    int sum = 0;
    double avg = 0.0;

    for (int i = 0; i < 5; ++i){

        // Find requested student by id
        if(classRosterArray[i].getStudentId() == studentID) {
            // Add the three integers together into 'sum'
            for (int j = 0; j < 3; ++j) {
                sum += classRosterArray[i].getDaysUntilComplete()[j];
            }

            // Calculate average and put into 'avg'
            avg = sum / 3.0;

            // Display header and average
            cout << endl << "THE AVERAGE FOR THE FOLLOWING STUDENT's COURSE DAYS REAMAINING IS " << avg << endl;
            classRosterArray[i].print();
        }
    }
    return;

}

// verifies student email addresses and displays all invalid email addresses
// Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
void Roster::printInvalidEmails(){
    // Header
    cout << endl << "THE FOLLOWING ARE INVALID EMAIL ADDRESSES" << endl;

    for(int i = 0; i < 5; ++i){
        // Get the email from the current student info
        string email = classRosterArray[i].getEmailAddress();

        // Check to see if the student email is correct and store in bool isValid
        bool isValid = (email.find('@') < email.length()) &&
                (email.find('.') < email.length()) &&
                (email.find(' ') > email.length());

        // If bool isValid is false then print the student info that is incorrect
        if (!isValid){
            classRosterArray[i].print();
        }
    }
    return;

}

//print out student information for a degree program specified by an enumerated type
void Roster::printByDegreeProgram(Degree degreeProgram){
    // Print out the requested degree program
    cout << "THE FOLLOWING ARE IN DEGREE PROGRAM ";
    switch (degreeProgram){
        case 0:
            cout << "SECURITY" << endl;
            break;
        case 1:
            cout << "NETWORKING" << endl;
            break;
        case 2:
            cout << "SOFTWARE" << endl;
            break;
    }
    for(int i = 0;i < 5;++i){
        // Find all matching students to degree program
        if(classRosterArray[i].getDegreeType() == degreeProgram){
            classRosterArray[i].print();
        }
    }
    return;

}

// Accessor for the classRosterArray
const Student *Roster::getClassRosterArray() const {
    return classRosterArray;
}

Roster::Roster() {
    return;

}    // Constuctor Method
Roster::~Roster(){
    return;

}    // Destructor Method