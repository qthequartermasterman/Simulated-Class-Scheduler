//
//  courses.hpp
//  csce1040Homework2
//
//  Created by Andrew Sansom on 2/21/19.
//  Copyright © 2019 Andrew Sansom. All rights reserved.
//

#ifndef courses_hpp
#define courses_hpp

#include "course.h"
#include <fstream>

#define CHUNKSIZE 2

class Courses{
private:
    course* COURSES;      //dynamic array representing the master list of courses
    int courseCount;         //the current number of courses in the system
    int courseCapacity;      //the current size of COURSES

public:
    int makeNewCourse(std::string name, std::string location); //creates a new course by calling the Course constructor and adding it to the COURSES array. If COURSES is not large enough, it allocates more space. Returns the ID number if successful, or -1 if not.
    bool isCourseIDValid(int courseID); //Returns true if there is a class with that courseID. False otherwise.
    
    
    Courses();
    ~Courses(){delete [] COURSES;};
    void printCourses();
    void cleanup();
    
    std::string getNameFromID(int courseID); //returns the course name of the course instance with the same courseID.
    
    void storeCoursesData();
    void loadCoursesData();
};

#endif /* courses_hpp */
