//
//  enrollments.hpp
//  csce1040Homework2
//
//  Created by Andrew Sansom on 2/21/19.
//  Copyright © 2019 Andrew Sansom. All rights reserved.
//

#ifndef enrollments_hpp
#define enrollments_hpp

#include <stdio.h>
#include "enrollment.hpp"

class Enrollments{
private:
    enrollment *ENROLLMENTS;      //dynamic array representing the master list of enrollments
    int currentNumberOfEnrollments;      //representing the current number of enrollment items
    int enrollmentCapacity;      //representing the current capacity of enrollments.
public:
    Enrollments();
    ~Enrollments();
    void allocateFiveMoreEnrollments();      //allocates space for five more enrollments (the maximum number needed for a single student)
    bool addGrade(int studentID, int classID, int grade); //adds a grade for student with id studentID who is enrolled in class with id classID. Iterates over the ENROLLMENTS array for the object with matching studentID and classID. Calls that Enrollment instances AddGradeForStudent function. Returns true if successful, returns false if not.
    int addEnrollment(int studentID,int courseID); //generates a new Enrollment instance and adds it to ENROLLMENTS, allocating memory if necessary. Returns the id of the enrollment instance.
    void printAllGradesOfStudentInCourse(int studentID, int courseID);
    float calculateAverageOfStudentsInCourse(int courseID);
};

#endif /* enrollments_hpp */
