//
//  students.hpp
//  csce1040Homework2
//
//  Created by Andrew Sansom on 2/21/19.
//  Copyright © 2019 Andrew Sansom. All rights reserved.
//

#ifndef students_hpp
#define students_hpp

#include <stdio.h>
#include <string>
#include <fstream>

#include "student.hpp"


class Students{
private:
    student* STUDENTS;      //dynamic array representing the master list of students
    int currentNumberOfStudents;     //representing the current number of student records
    int studentsCapacity;      //representing the current capacity of student records.
public:
    Students();
    ~Students(){delete [] STUDENTS;};
    int makeNewStudent(std::string name, int classification); //creates a new student record by calling the Student Constructor and adds it to the STUDENTS array, allocating memory if necessary. Returns with the id number if succesful, but -1 if not.
    void printStudents(); //prints a list of all students to the console
    void printStudentInfo(int studentID); //prints the student's information to the console.
    bool enrollStudentInCourse(int studentID, int courseID); //enrolls student with studentID in course with courseID. Returns false if student's numberOfCourses is equal to 5. Then calls Courses's addStudentToCourse method. Adds the courseID to the student's enrolledCourses array. Iterates the student's numberOfCourses by 1. Returns true if successful, and false if not.
    int getStudentIdFromName(std::string name); //returns the ID number of the student with a given name.
    bool isStudentInTooManyClasses(int studentID);
    bool isStudentIDValid(int studentID); //Returns true if there is a student with that studentID. False otherwise.
    std::string getNameFromID(int studentID); //returns the student name of the student instance with the same studentID.
    void cleanup();
    
    void storeStudentData(); //stores student data to the file "students.dat"
    void loadStudentData(); //loads student data from the file "students.dat"
};
#endif /* students_hpp */
