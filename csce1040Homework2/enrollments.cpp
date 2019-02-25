//
//  enrollments.cpp
//  csce1040Homework2
//
//  Created by Andrew Sansom on 2/21/19.
//  Copyright © 2019 Andrew Sansom. All rights reserved.
//

#include "enrollments.hpp"

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
