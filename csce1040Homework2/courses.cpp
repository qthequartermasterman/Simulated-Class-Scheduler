//
//  courses.cpp
//  csce1040Homework2
//
//  Created by Andrew Sansom on 2/21/19.
//  Copyright © 2019 Andrew Sansom. All rights reserved.
//

#include "courses.hpp"

int Courses::makeNewCourse(std::string courseName, std::string locationName){

    //Check and see if we need to allocate more memory. If so, do that, please.
    if (courseCount == courseCapacity)
    {
        course *temp;
        temp = new course [courseCapacity + CHUNKSIZE];
        for (int i = 0;i < courseCount;i++){
           temp[i] = COURSES[i];
        }
        courseCapacity += CHUNKSIZE;
        delete [] COURSES;
        COURSES = temp;
    }
    //Put in all the new info.
    COURSES[courseCount].setName(courseName);
    COURSES[courseCount].setLocation(locationName);
    COURSES[courseCount].setID(courseCount);
    COURSES[courseCount].print();
    
    courseCount++; //Iterate the thing so we don't accidentally overwrite it.
    return courseCount-1; //This will be the id of the previous course.
}

void Courses::printCourses(){
    for (int i = 0; i < courseCount; i++){
        COURSES[i].print();
    }
}

void Courses::cleanup()
{
    delete [] COURSES;
}

bool Courses::isCourseIDValid(int courseID){
    for (int i=0; i < courseCount; i++){
        if (COURSES[courseID].getID()==courseID){
            return true;
        }
    }
    return false;
}

Courses::Courses(){
    courseCount = 0;
    courseCapacity = CHUNKSIZE;
    COURSES = new course[CHUNKSIZE];
}
