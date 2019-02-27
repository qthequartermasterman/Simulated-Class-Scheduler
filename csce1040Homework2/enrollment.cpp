//
//  enrollment.cpp
//  csce1040Homework2
//
//  Created by Andrew Sansom on 2/21/19.
//  Copyright © 2019 Andrew Sansom. All rights reserved.
//

#include "enrollment.hpp"
#include <iostream>

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
    return true;
} //adds a grade to the next available spot in the grades array. Also increments numberOfGrades. Returns true if successful, false otherwise

float enrollment::calculateAverage(){
    float runningTotal = 0;
    for (int i = 0; i < 10; i++){
        runningTotal += grades[i];
    }
    return runningTotal/numberOfGrades;
}    //returns the average of all of the grades in an enrollment object as a float.

char enrollment::calculateLetterGrade(){
    float average = calculateAverage();
    if (average>=90){
        return 'A';
    } else if (average>=80 && average < 90){
        return 'B';
    } else if (average >= 70 && average < 80){
        return 'C';
    } else if (average >= 60 && average < 70){
        return 'D';
    } else {
        return 'F';
    }
}  //returns the letter grade of the student as a char.
