//
//  student.cpp
//  csce1040Homework2
//
//  Created by Andrew Sansom on 2/21/19.
//  Copyright © 2019 Andrew Sansom. All rights reserved.
//

#include "student.hpp"
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
