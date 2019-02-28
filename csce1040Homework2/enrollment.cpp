//
//  enrollment.cpp
//  csce1040Homework2
//
//  Created by Andrew Sansom on 2/21/19.
//  Copyright © 2019 Andrew Sansom. All rights reserved.
//

#include "enrollment.hpp"
#include <iostream>
#include <iomanip>
/*
int ID;        //representing the ID number of the enrollment data
int studentID;     //representing the student's ID
int courseID;      //representing the course's ID
int grades[10];        //an integer array of size ten representing the 10 grades in the course
int numberOfGrades;    //an integer representing the number of grades in the course.
float average;       //representing the average of all of the grades
char letterGarde;           //representing the letter grade ( Intervals written in mathematical interval notation [90,100] => 'A'; [80,90) => 'B'; [75,80) => 'C'; [70,75) => 'D'; [0,70) => 'F')
*/


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
        return -1;
    }
    for (int i = 0; i < numberOfGrades; i++){
        runningTotal += grades[i];
    }
    average = runningTotal/numberOfGrades;
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
    letterGrade = letter;
    return letter;
}  //returns the letter grade of the student as a char.

void enrollment::printGrades(){
    std::cout << std::left << std::setw(12) << "Student ID:" << std::setw(12) << "Course ID:" << std::setw(12) << "Grades: ";
    for (int i = 0; i < numberOfGrades; i++){
        std::cout << std::left << std::setw(4) << i+1 << " ";
    }
    std::cout << std::setw(10) << "Average: " << std::endl;
    std::cout << std::left << std::setw(10) << studentID << "  " << std::setw(10) << courseID << "  " << std::setw(12) << " ";
    for (int i = 0; i < numberOfGrades; i++){
        std::cout << std::right << std::setw(4) << grades[i] << " ";
    }
    std::cout << std::setw(10) << std::setprecision(2) << std::fixed << calculateAverage() << std::setw(2) << calculateLetterGrade() << std::endl;
} //prints all grades to the console.
