//
//  main.cpp
//  csce1040Homework2
//
//  Created by Andrew Sansom on 2/13/19.
//  Copyright © 2019 Andrew Sansom. All rights reserved.
//

#include <iostream>
#include <string>

#include "courses.hpp"
#include "students.hpp"
#include "enrollments.hpp"


Enrollments Enrollments;
Students Students;
Courses Courses;


bool enrollStudentInCourse(int studentID, int courseID){
    //First we test if the student has an available class spot. Then we check if the class is already full.
    bool toomanyclasses = Students.isStudentInTooManyClasses(studentID);
    bool isClassFull = Enrollments.isCourseFull(courseID);
    std::cout << "Student is currently enrolled in 5 classes? " << toomanyclasses << std::endl;
    if (toomanyclasses){
        std::cout << "Error: Student enrolled in 5 classes already.\n";
        return false;
    } else if(isClassFull){
        std::cout << "Error: Course already has 48 students.\n";
        return false;
    } else { //If both of the above conditions are fine, then we trigger the creation of an Enrollment and increase the student's record's numberOfCourses.
        int attemptToEnrollStudent = Enrollments.addEnrollment(studentID, courseID);
        std::cout << "Student enrolled in the enrollments instance? " << attemptToEnrollStudent << std::endl;
        if (attemptToEnrollStudent > -1){
            bool attemptToIncreaseStudentNumberOfClasses = Students.enrollStudentInCourse(studentID, courseID);
            std::cout << "Student's number of classes iterator function successful? " << attemptToIncreaseStudentNumberOfClasses << std::endl;
            return attemptToIncreaseStudentNumberOfClasses;
        } else {
            return false;
        }
    }
}


int main() {
    // We will want to make a menu with an infinite loop. It displays the list of options, then expects a user input to the console as a string. Using a chain of if statements, it runs the appropriate function and displays any output (if appropriate) to the console.
    char menuString[] = "What would you like to do? \nPlease insert the number of the corresponding action. \n0. Quit \n1. Add a new course \n2. Add a new student \n3. Add a student to a course \n4. Add grades for a student in a course \n5. Print a list of all grades for a student in a course \n6. Print a list of all students in a course \n7. Compute the average for a student in a course \n8. Print a list of all courses \n9. Print a list of all students \n10. Compute the average for a course \n11. Store Grade book (to a disk file) \n12. Load Grade book (from a disk file)\n";
    int userOption; //Stores the operation that the user requests
    std::cout << menuString << std::endl;
    std::cin >> userOption;
    std::cout << std::endl << std::endl << std::endl;
    while (userOption != 0){
        switch (userOption){
            case 1:{ //1. Add a new course
                std::string courseName;
                std::string locationName;
                std::cout << "What is the name of the new course?\n";
                std::cin >> courseName;
                std::cout << "What is the location of the class?\n";
                std::cin >> locationName;
                int courseID = Courses.makeNewCourse(courseName, locationName);
                if (courseID==-1){
                    std::cout << "Error occured. New course could not be made.\n";
                } else {
                    std::cout << "Course created. It has the ID Number: " << courseID << std::endl;
                }
                break;
            }
                
            case 2:{ //2. Add a new student
                std::string studentName;
                int classification;
                std::cout << "What is the name of the new student?\n";
                std::cin >> studentName;
                std::cout << "What is the classification of said student?\n0=Freshman, 1=Sophomore, 2=Junior, and 3=Senior.\n";
                std::cin >> classification;
                while (classification<0 || classification>4){
                    std::cout << "Invalid classification. Please enter an integer between 0 and 4.\n";
                    std::cin >> classification;
                }
                if (Students.makeNewStudent(studentName, classification)){
                    std::cout << "Student created successfully.\n";
                } else {
                    std::cout << "Error occured. New student could not be made.\n";
                }
                break;
            }
            case 3: { //3. Add a student to a course
                int studentID;
                int courseID;
                std::cout << "What is the student ID of the student you would like to enroll in a course?\n";
                std::cin >> studentID;
                while (!Students.isStudentIDValid(studentID)){
                    std::cout << "Invalid ID. Please enter valid ID.\n";
                    std::cin >> studentID;
                }
                std::cout << "What is the course ID of the class in which you would like to enroll the student?\n";
                std::cin >> courseID;
                while (!Courses.isCourseIDValid(courseID)){
                    std::cout << "Invalid ID. Please enter valid ID.\n";
                    std::cin >> courseID;
                }
                if (enrollStudentInCourse(studentID,courseID)){
                    std::cout << "Student succesfully enrolled in course.\n";
                } else {
                    std::cout << "An Error has occured.\n";
                }
                break;
            }
            case 4:{ //4. Add grades for a student in a course
                break;
            }
            case 5:{ //5. Print a list of all grades for a student in a course
                break;
            }
            case 6:{ //6. Print a list of all students in a course
                int courseID;
                std::cout << "What is the course ID of the class in which you would like to view the student list?\n";
                std::cin >> courseID;
                Enrollments.printAllStudentsInClass(courseID);
                break;
            }
            case 7:{ //7. Compute the average for a student in a course
                break;
            }
            case 8:{ //8. Print a list of all courses
                break;
            }
            case 9:{ //9. Print a list of all students
                break;
            }
            case 10: { //10. Compute the average for a course
                break;
            }
            case 11:{    //11. Store Grade book (to a disk file)
                break;
            }
            case 12:{    //12. Load Grade book (from a disk file)
                break;
            }
            case 13:{
                int studentID;
                std::cout << "What is the student ID of the student whose info you would like to view?\n";
                std::cin >> studentID;
                Students.printStudentInfo(studentID);
                break;
            }
            default: {
                std::cout << "Unknown operation requested. Please enter a number between 0 and 12 inclusive.\n";
                break;
            }
        }
        std::cout << std::endl << std::endl << menuString;
        std::cin >> userOption;
    }
    return 0;
}
