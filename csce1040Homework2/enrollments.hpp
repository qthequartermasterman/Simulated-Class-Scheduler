//
//  enrollments.hpp
//  csce1040Homework2
//
//  Created by Andrew Sansom on 2/21/19.
//  Copyright © 2019 Andrew Sansom. All rights reserved.
//

#ifndef enrollments_hpp
#define enrollments_hpp

#include "enrollment.h"
#include <iostream>
#include <fstream>

class Students;
class Courses;

class Enrollments{
private:
    enrollment *ENROLLMENTS;      //dynamic array representing the master list of enrollments
    int currentNumberOfEnrollments;      //representing the current number of enrollment items
    int enrollmentCapacity;      //representing the current capacity of enrollments.
public:
    Enrollments();
    ~Enrollments(){delete [] ENROLLMENTS;};
    void allocateFiveMoreEnrollments();      //allocates space for five more enrollments (the maximum number needed for a single student)
    bool addGrade(int studentID, int classID, int grade); //adds a grade for student with id studentID who is enrolled in class with id classID. Iterates over the ENROLLMENTS array for the object with matching studentID and classID. Calls that Enrollment instances AddGradeForStudent function. Returns true if successful, returns false if not.
    int addEnrollment(int studentID,int courseID); //generates a new Enrollment instance and adds it to ENROLLMENTS, allocating memory if necessary. Returns the id of the enrollment instance.
    void printAllGradesOfStudentInCourse(int studentID, int courseID); //Loops over the ENROLLMENTS array, finds the first enrollment instance that matches the studentID and courseID. Then prints the grades to the console.
    float calculateAverageOfStudentsInCourse(int courseID);
    
    
    /*NEW REDESIGNED FUNCTIONS*/
    int countStudentsInClass(int courseID); //Counts the number of students in a class, based on the number of enrollment items with the proper class ID. Loops over each element in ENROLLMENTS and adds one to a counter each time the courseID matches that enrollment instance's.
    
    int countClassesStudentIsEnrolledIn(int studentID); //Counts the number of classes a student is enrolled in, based on the number of enrollment items with the proper student ID. Loops over each element in ENROLLMENTS and adds one to a counter each time the studentID matches that enrollment instance's.
    
    //void printAllGradesOfStudent(int studentID, int courseID); //prints all the grades of the student for a particular class to the console. Loops over each enrollment and prints the grades if it is in the desired class and the desired student.
    void printAllStudentsInClass(int courseID, Students *students, Courses *courses);    //prints a list of all of the students in the class to the console. Loops over each enrollment and prints the student's name if they are in that class.
    float computeAverageOfClass(int courseID); //computes the average of the average of every student in a particular class.
    float computeAverageOfStudent(int studentID, int courseID); //Computes the average of a student in a course.
    bool isCourseFull(int courseID); // returns true if the course has 48 students enrolled in it.
    
    void cleanup();
    
    void storeEnrollmentsData();
    void loadEnrollmentsData();
};

#endif /* enrollments_hpp */
