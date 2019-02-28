//
//  course.cpp
//  csce1040Homework2
//
//  Created by Andrew Sansom on 2/21/19.
//  Copyright © 2019 Andrew Sansom. All rights reserved.
//

#include "course.hpp"
#include <iomanip>

void course::print(){
    std::cout << "Course: " << std::setw(12) << name << " Location: " << std::setw(12) << location << " ID: " << std::setw(5) << ID << std::endl;
}







/*
int ID;        //representing the ID number of the course
std::string name;       //representing the name of the course
std::string location;       //representing the location of the course as  C-string
int enrollmentCurrent;           //representing the current enrollment of the course. Clearly this value should not be negative. It has a maximum value of 48.
int enrollmentCapacity;        //representing the current maximum enrollment of the course. Clearly this value should not be negative. It has a maximum value of 48.
int* enrollmentIDs;   //dynamic array representing a collection of enrollment data
int* studentIDs;  //dynamic array repesenting a collection of student records

int findEnrollmentIdFromStudentId(int studentID); //returns the enrollment ID from the corresponding student ID. This will
 */

/*
course::course(int _ID, std::string _name, std::string _location){
    ID = _ID;
    name = _name;
    location = _location;
    //enrollmentCurrent = 0;
    //enrollmentCapacity = 5;
    //enrollmentIDs = new int[5];
    //studentIDs = new int[5];
}*/
/*
bool course::addStudentToCourse(int studentID, Enrollments *globalEnrollments, Students *globalStudents){
    if (enrollmentCurrent == 48){
        std::cout << "Error: Cannot add more than 48 students to a course.\n";
        return false;
    }
    if (!globalStudents->enrollStudentInCourse(studentID, ID)){
        std::cout << "Error: Student already enrolled in 5 courses.\n";
        return false;
    }
    if (enrollmentCurrent == enrollmentCapacity){ //Check if we need to expand the studentIDs array.
        int* temporaryStudentsArray;
        temporaryStudentsArray = new int[enrollmentCapacity + 5];
        for (int i =0; i < enrollmentCurrent; i++){
            temporaryStudentsArray[i] = studentIDs[i];
        }
        delete [] studentIDs;
        enrollmentCapacity += 5;
        studentIDs = temporaryStudentsArray;
    }
    (*globalEnrollments).addEnrollment(studentID, ID);
    studentIDs[enrollmentCurrent] = studentID;
    enrollmentCurrent++;
    return true;
} //calls Enrollments's addEnrollment with the given studentID and the courseID. Adds studentID to the next spot in studentIDs and the returned enrollment ID to enrollmentIDs. It also updates the corresponding Student object's classes. Returns true if succesful (i.e. the student is not at maximum enrollment and the class is not already at capacity), and false is not.
void course::printAllGradesOfStudent(int studentID, Enrollments *globalEnrollments){
    globalEnrollments->printAllGradesOfStudentInCourse(studentID, ID);
} //prints all the grades of the student for a particular class to the console.

void course::printAllStudentsInClass(Enrollments *globalEnrollments){
    for (int i=0; i < enrollmentCurrent; i++){
        globalEnrollments->printAllGradesOfStudentInCourse(studentIDs[i], ID);
    }
}    //prints a list of all of the students in the class to the console.
float course::computeAverageOfClass(Enrollments *globalEnrollments){
    return globalEnrollments->calculateAverageOfStudentsInCourse(ID);
} //computes the average of the average of every student in a particular class.
*/
