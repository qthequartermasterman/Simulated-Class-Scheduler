/*=============course.h================*/
/*
 DESCRIPTION:   Contains functions and data collection necessary to maintain one course record.
 AUTHOR:        Andrew P. Sansom
 VERSION:       1.0.0
 VERSION DATE:  20 Feb 2019
 EMAIL:         andrewsansom@my.unt.edu
 COURSE:        CSCE 1040
 =============course.h================*/

#ifndef course_h
#define course_h

#include <string>
#include <iostream>

class course {
private:
    int ID=-1;        //representing the ID number of the course
    std::string name;       //representing the name of the course
    std::string location;       //representing the location of the course as  C-string
public:
    //Getters and Setters
    int getID(){return ID;}
    void setID(int _ID){ID = _ID;}
    std::string getName(){return name;};
    void setName(std::string _name){name = _name;};
    std::string getLocation(){return location;};
    void setLocation(std::string _location){location=_location;};
    
    void print(); //prints the course's information to the console.
};


#endif /* course_h */
