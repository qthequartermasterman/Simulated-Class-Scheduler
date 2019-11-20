/*=============enrollment.cpp================*/
/*
 DESCRIPTION:   Contains functions necessary to maintain one enrollment record.
 AUTHOR:        Andrew P. Sansom
 VERSION:       1.0.0
 VERSION DATE:  20 Feb 2019
 EMAIL:         andrewsansom@my.unt.edu
 COURSE:        CSCE 1040
 =============enrollment.cpp================*/

#include "enrollment.h"
#include <iostream>
#include <iomanip>

bool enrollment::addGrade(int grade){
    if (numberOfGrades == 10){
        std::cout << "Maximum Number of Grades exceeded. Grade not recorded. \n";
        return false;
    }
    grades[numberOfGrades] = grade;
    numberOfGrades++;
    calculateAverage();
    calculateLetterGrade();
    return true;
} //adds a grade to the next available spot in the grades array. Also increments numberOfGrades. Returns true if successful, false otherwise

float enrollment::calculateAverage(){
    float runningTotal = 0;
    if (numberOfGrades==0){
        //Aint nobody got time for division by zero errors!.
        //Clearly, the average cannot be -1, so this signals to the otherside that there is a division by zero error here.
        return -1;
    }
    for (int i = 0; i < numberOfGrades; i++){
        runningTotal += grades[i];
    }
    average = runningTotal/numberOfGrades; //saves this to the variable in the enrollment object, since the specifications require that for some reason.
    return average;
}    //returns the average of all of the grades in an enrollment object as a float.

char enrollment::calculateLetterGrade(){
    float average = calculateAverage();
    char letter;
    if (average>=90){
        letter = 'A';
    } else if (average>=80 && average < 90){
        letter = 'B';
    } else if (average >= 70 && average < 80){
        letter = 'C';
    } else if (average >= 60 && average < 70){
        letter = 'D';
    } else {
        letter = 'F';
    }
    letterGrade = letter; //saves this to the variable in the enrollment object, since the specifications require that for some reason.
    return letter;
}  //returns the letter grade of the student as a char.

void enrollment::printGrades(){
    //Headers
    std::cout << std::left << std::setw(12) << "Student ID:" << std::setw(12) << "Course ID:" << std::setw(12) << "Grades: ";
    //Grade Headers (variable number, so we compensate with a for loop.
    for (int i = 0; i < numberOfGrades; i++){
        std::cout << std::left << std::setw(4) << i+1 << " ";
    }
    //More Headers...
    std::cout << std::setw(10) << "Average: " << std::endl;
    //Data
    std::cout << std::left << std::setw(10) << studentID << "  " << std::setw(10) << courseID << "  " << std::setw(12) << " ";
    //Grades (variable number)
    for (int i = 0; i < numberOfGrades; i++){
        std::cout << std::right << std::setw(4) << grades[i] << " ";
    }
    //Average and Letter grade
    std::cout << std::setw(10) << std::setprecision(2) << std::fixed << calculateAverage() << std::setw(2) << calculateLetterGrade() << std::endl;
} //prints all grades to the console.
