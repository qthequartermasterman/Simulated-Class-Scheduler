/*=============student.cpp================*/
/*
 DESCRIPTION:   Contains functions necessary to maintain one student record.
 AUTHOR:        Andrew P. Sansom
 VERSION:       1.0.0
 VERSION DATE:  20 Feb 2019
 EMAIL:         andrewsansom@my.unt.edu
 COURSE:        CSCE 1040
 =============student.cpp================*/

#include "student.h"
#include <iomanip>
bool student::addCourse(int courseID){
    if (numberOfClasses==5){
        std::cout << "Error: Student already enrolled in five classes.\n";
        return false;
    } else{
        numberOfClasses++;
        return true;
    }
} //Updates the numberOfClasses. Returns true if succesful (i.e. the student is not already at maximum enrollment and the class is not already full) but false if not.

void student::print(){
    std::cout << "Student: " << std::setw(12) << name << " Classification: " << std::setw(2) << classification << " ID: " << std::setw(5) << ID << " Number of Classes: " << std::setw(5)  << numberOfClasses << std::endl;
} //Prints all information about the student to the console. Simply prints everything using a formatted cout string.
