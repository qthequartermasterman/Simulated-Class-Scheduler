/*=============courses.h================*/
/*
 DESCRIPTION:   Contains functions and data collection necessary to maintain one Courses collection.
 AUTHOR:        Andrew P. Sansom
 VERSION:       1.0.0
 VERSION DATE:  20 Feb 2019
 EMAIL:         andrewsansom@my.unt.edu
 COURSE:        CSCE 1040
 =============courses.h================*/

#ifndef courses_h
#define courses_h

#include "course.h"
#include <fstream>

#define CHUNKSIZE 2

class Courses{
private:
    course* COURSES;      //dynamic array representing the master list of courses
    int currentNumberOfCourses;         //the current number of courses in the system
    int courseCapacity;      //the current size of COURSES

public:
    Courses();
    ~Courses(){delete [] COURSES;};
    
    int makeNewCourse(std::string name, std::string location); //creates a new course by calling the Course constructor and adding it to the COURSES array. If COURSES is not large enough, it allocates more space. Returns the ID number if successful, or -1 if not.
    bool isCourseIDValid(int courseID); //Loops over each course instance in COURSES. Returns true if there is a class with that courseID.  False otherwise.
    void printCourses();        //Prints a list of classes to the console.
    std::string getNameFromID(int courseID); //returns the course name of the course instance with the same courseID.
    void storeCoursesData();        //Saves all courses data to the file "courses.dat" in the working directory.
    void loadCoursesData();         //Loads all courses data to the file "courses.dat" in the working directory.
};

#endif /* courses_h */
