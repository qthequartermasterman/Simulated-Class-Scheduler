//
//  student.hpp
//  csce1040Homework2
//
//  Created by Andrew Sansom on 2/21/19.
//  Copyright © 2019 Andrew Sansom. All rights reserved.
//

#ifndef student_hpp
#define student_hpp

#include <string>

class student{
private:
    int ID;        //representing the ID number of the student
    std::string name;       //representing the name of the student
    int numberOfClasses;       //representing the number of classes in which the student is currently enrolled. Clearly this value should not be negative. This cannot be more than 5.
    int classification;        //representing the student's classification. 0=Freshman, 1=Sophomore, 2=Junior, and 3=Senior.
    int courses[5];         //representing the current courses in which the student is enrolled.
public:
    bool addCourse(int courseID); //adds a course to "courses" and updates the numberOfClasses. Returns true if succesful (i.e. the student is not already at maximum enrollment and the class is not already full) but false if not.
    
    std::string getName(){return name;}
    void setName(std::string _name){name = _name;}
    int getID(){return ID;}
    void setID(int _id){ID=_id;}
    int getClassification(){return classification;}
    
};


#endif /* student_hpp */
