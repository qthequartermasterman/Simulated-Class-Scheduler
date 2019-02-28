/*=============enrollments.h================*/
/*
 DESCRIPTION:   Contains functions and data collection necessary to maintain one Enrollments collection.
 AUTHOR:        Andrew P. Sansom
 VERSION:       1.0.0
 VERSION DATE:  20 Feb 2019
 EMAIL:         andrewsansom@my.unt.edu
 COURSE:        CSCE 1040
 =============enrollments.h================*/
#ifndef enrollments_h
#define enrollments_h

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
    //Memory Allocation
    Enrollments();
    ~Enrollments(){delete [] ENROLLMENTS;};
    int addEnrollment(int studentID,int courseID); //generates a new Enrollment instance and adds it to ENROLLMENTS, allocating memory if necessary. Returns the id of the enrollment instance.
    
    //Verification functions. These are used to check if the enrollment item really can be made.
    bool isCourseFull(int courseID); // returns true if the course has 48 students enrolled in it.
    int countClassesStudentIsEnrolledIn(int studentID); //Counts the number of classes a student is enrolled in, based on the number of enrollment items with the proper student ID. Loops over each element in ENROLLMENTS and adds one to a counter each time the studentID matches that enrollment instance's.
    int countStudentsInClass(int courseID); //Counts the number of students in a class, based on the number of enrollment items with the proper class ID. Loops over each element in ENROLLMENTS and adds one to a counter each time the courseID matches that enrollment instance's.
    
    //Grade Manipulation functions. These either manipulate grades or run some statistic on them.
    bool addGrade(int studentID, int classID, int grade); //adds a grade for student with id studentID who is enrolled in class with id classID. Iterates over the ENROLLMENTS array for the object with matching studentID and classID. Calls that Enrollment instances AddGradeForStudent function. Returns true if successful, returns false if not.
    float computeAverageOfStudent(int studentID, int courseID); //Computes the average of a student in a course.
    float calculateAverageOfStudentsInCourse(int courseID);     ///computes the average of the average of every student in a particular class.

    //Print functions. These print some sort of data to the console.
    void printAllStudentsInClass(int courseID, Students *students, Courses *courses);    //prints a list of all of the students in the class to the console, including their names. Loops over each enrollment and prints the student's name if they are in that class.
    void printAllGradesOfStudentInCourse(int studentID, int courseID); //Loops over the ENROLLMENTS array, finds the first enrollment instance that matches the studentID and courseID. Then prints the grades to the console.
    
    //File storage functions. These well... store files.
    void storeEnrollmentsData();    //stores student data to the file "enrollments.dat" in the working directory
    void loadEnrollmentsData();     //loads student data from the file "enrollments.dat" in the working directory
};

#endif /* enrollments_h */
