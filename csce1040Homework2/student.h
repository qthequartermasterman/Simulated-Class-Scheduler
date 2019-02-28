/*=============student.h================*/
/*
 DESCRIPTION:   Contains functions and data collection necessary to maintain one student record.
 AUTHOR:        Andrew P. Sansom
 VERSION:       1.0.0
 VERSION DATE:  20 Feb 2019
 EMAIL:         andrewsansom@my.unt.edu
 COURSE:        CSCE 1040
 =============student.h================*/

#ifndef student_h
#define student_h

#include <string>
#include <iostream>

class student{
private:
    int ID=-1;        //representing the ID number of the student
    std::string name;       //representing the name of the student
    int numberOfClasses = 0;       //representing the number of classes in which the student is currently enrolled. Clearly this value should not be negative. This cannot be more than 5.
    int classification;        //representing the student's classification. 0=Freshman, 1=Sophomore, 2=Junior, and 3=Senior.
public:
    bool addCourse(int courseID); //adds a course to "courses" and updates the numberOfClasses. Returns true if succesful (i.e. the student is not already at maximum enrollment and the class is not already full) but false if not.
    
    //Getters and Setters
    int getNumberOfClasses(){return numberOfClasses;}
    void setNumberOfClasses(int _classes){numberOfClasses=_classes;};
    std::string getName(){return name;}
    void setName(std::string _name){name = _name;}
    int getID(){return ID;}
    void setID(int _id){ID=_id;}
    int getClassification(){return classification;}
    void setClassification(int _classification){classification = _classification;}
    
    void print(); //Prints all information about the student to the console. Simply prints everything using a formatted cout string.
};


#endif /* student_h */
