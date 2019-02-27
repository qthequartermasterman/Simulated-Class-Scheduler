//
//  enrollments.cpp
//  csce1040Homework2
//
//  Created by Andrew Sansom on 2/21/19.
//  Copyright © 2019 Andrew Sansom. All rights reserved.
//

#include "enrollments.hpp"
#define CHUNKSIZE 2

float Enrollments::calculateAverageOfStudentsInCourse(int courseID){
    float runningTotal = 0;
    int numberOfStudents = 0;
    for (int i=0; i < currentNumberOfEnrollments; i++){
        if (ENROLLMENTS[i].getCourseID()==courseID){
            runningTotal += ENROLLMENTS[i].calculateAverage();
            numberOfStudents++;
        }
    }
    return runningTotal/numberOfStudents;
}

int Enrollments::addEnrollment(int studentID,int courseID){
    
    if (currentNumberOfEnrollments == enrollmentCapacity)
    {
        enrollment *temp;
        temp = new enrollment[enrollmentCapacity + CHUNKSIZE];
        for (int i = 0;i < currentNumberOfEnrollments;i++) temp[i] = ENROLLMENTS[i];
        delete [] ENROLLMENTS;
        enrollmentCapacity += CHUNKSIZE;
        ENROLLMENTS = temp;
    }

    ENROLLMENTS[currentNumberOfEnrollments].setID(currentNumberOfEnrollments);
    ENROLLMENTS[currentNumberOfEnrollments].setStudentID(studentID);
    ENROLLMENTS[currentNumberOfEnrollments].setCourseID(courseID);
    currentNumberOfEnrollments++;
    
    return currentNumberOfEnrollments-1;  
} //generates a new Enrollment instance and adds it to ENROLLMENTS, allocating memory if necessary. Returns the id of the enrollment instance.
void Enrollments::cleanup(){
    delete [] ENROLLMENTS;
}

Enrollments::Enrollments(){
    ENROLLMENTS = new enrollment[CHUNKSIZE];
    enrollmentCapacity = CHUNKSIZE;
    currentNumberOfEnrollments = 0;
}

void Enrollments::printAllStudentsInClass(int courseID){
    std::cout << "Course: " << courseID << " \tStudents: ";
    for (int i = 0; i < currentNumberOfEnrollments; i++){
        if (ENROLLMENTS[i].getCourseID() == courseID){
            std::cout << ENROLLMENTS[i].getStudentID() << " ";
        }
    }
    std::cout << std::endl;
}    //prints a list of all of the students in the class to the console. Loops over each enrollment and prints the student's name if they are in that class.

bool Enrollments::isCourseFull(int courseID){
    int counter = 0;
    for (int i = 0; i < currentNumberOfEnrollments; i++){
        if (ENROLLMENTS[i].getCourseID() == courseID){
            counter++;
        }
    }
    if (counter == 48){
        return true;
    } else {
            return false;
    }
} // returns true if the course has 48 students enrolled in it.
