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

class course {
private:
    int ID;        //representing the ID number of the course
    std::string name;       //representing the name of the course
    std::string location;       //representing the location of the course as  C-string
    //int enrollmentCurrent;           //representing the current enrollment of the course. Clearly this value should not be negative. It has a maximum value of 48.
    //int enrollmentCapacity;        //representing the current maximum enrollment of the course. Clearly this value should not be negative. It has a maximum value of 48.
    //int* enrollmentIDs;   //dynamic array representing a collection of enrollment data
    //int* studentIDs;  //dynamic array repesenting a collection of student records
    
    //int findEnrollmentIdFromStudentId(int studentID); //returns the enrollment ID from the corresponding student ID. This will
public:
    int getID(){return ID;}
    void setID(int _ID){ID = _ID;}
    
    std::string getName(){return name;};
    void setName(std::string _name){name = _name;};
    
    std::string getLocation(){return location;};
    void setLocation(std::string _location){location=_location;};
    
    void print();
    };


#endif /* course_hpp */
