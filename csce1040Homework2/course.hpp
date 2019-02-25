//
//  course.hpp
//  csce1040Homework2
//
//  Created by Andrew Sansom on 2/21/19.
//  Copyright © 2019 Andrew Sansom. All rights reserved.
//

#ifndef course_hpp
#define course_hpp

#include <string>
#include <iostream>
#include "enrollments.hpp"
#include "students.hpp"

class course {
private:
    int ID;        //representing the ID number of the course
    std::string name;       //representing the name of the course
    std::string location;       //representing the location of the course as  C-string
    int enrollmentCurrent;           //representing the current enrollment of the course. Clearly this value should not be negative. It has a maximum value of 48.
    int enrollmentCapacity;        //representing the current maximum enrollment of the course. Clearly this value should not be negative. It has a maximum value of 48.
    int* enrollmentIDs;   //dynamic array representing a collection of enrollment data
    int* studentIDs;  //dynamic array repesenting a collection of student records
    
    int findEnrollmentIdFromStudentId(int studentID); //returns the enrollment ID from the corresponding student ID. This will
public:
    course(int _ID, std::string _name, std::string _location);
    bool addStudentToCourse(int studentID, Enrollments* global_enollments, Students *globalStudents); //calls Enrollment's addEnrollment with the given studentID and the courseID. Adds studentID to the next spot in studentIDs and the returned enrollment ID to enrollmentIDs. It also updates the corresponding Student object's classes. Returns true if succesful (i.e. the student is not at maximum enrollment and the class is not already at capacity), and false is not.
    void printAllGradesOfStudent(int studentID, Enrollments *globalEnrollments); //prints all the grades of the student for a particular class to the console.
    void printAllStudentsInClass(Enrollments *globalEnrollments);    //prints a list of all of the students in the class to the console.
    float computeAverageOfClass(Enrollments *globalEnrollments); //computes the average of the average of every student in a particular class.

    int getID(){return ID;}
    void setID(int _ID){ID = _ID;}
};


#endif /* course_hpp */
