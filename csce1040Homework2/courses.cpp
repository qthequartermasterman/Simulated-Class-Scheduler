/*=============courses.cpp================*/
/*
 DESCRIPTION:   Contains functions and data collection necessary to maintain one Courses collection.
 AUTHOR:        Andrew P. Sansom
 VERSION:       1.0.0
 VERSION DATE:  20 Feb 2019
 EMAIL:         andrewsansom@my.unt.edu
 COURSE:        CSCE 1040
 =============courses.cpp================*/

#include "courses.h"

Courses::Courses(){
    currentNumberOfCourses = 0;
    courseCapacity = CHUNKSIZE;
    COURSES = new course[CHUNKSIZE];
}

int Courses::makeNewCourse(std::string courseName, std::string locationName){
    //Check and see if we need to allocate more memory. If so, do that, please.
    if (currentNumberOfCourses == courseCapacity){
        course *temp;
        temp = new course [courseCapacity + CHUNKSIZE];
        for (int i = 0;i < currentNumberOfCourses;i++){
           temp[i] = COURSES[i];
        }
        courseCapacity += CHUNKSIZE;
        delete [] COURSES;
        COURSES = temp;
    }
    //Put in all the new info.
    COURSES[currentNumberOfCourses].setName(courseName);
    COURSES[currentNumberOfCourses].setLocation(locationName);
    COURSES[currentNumberOfCourses].setID(currentNumberOfCourses);
    COURSES[currentNumberOfCourses].print();
    
    currentNumberOfCourses++; //Iterate the thing so we don't accidentally overwrite it.
    return currentNumberOfCourses-1; //This will be the id of the previous course.
}

bool Courses::isCourseIDValid(int courseID){
    for (int i=0; i < currentNumberOfCourses; i++){
        if (COURSES[courseID].getID()==courseID){
            return true;
        }
    }
    return false;
} //Loops over each course instance in COURSES. Returns true if there is a class with that courseID.  False otherwise.

void Courses::printCourses(){
    for (int i = 0; i < currentNumberOfCourses; i++){
        COURSES[i].print();
    }
} //Prints a list of classes to the console.

std::string Courses::getNameFromID(int courseID){
    for (int i = 0; i < currentNumberOfCourses; i++){
        if (COURSES[i].getID() == courseID){
            return COURSES[i].getName();
        }
    }
    return "ERROR COURSE NOT FOUND";
}//returns the course name of the course instance with the same courseID.

void Courses::storeCoursesData(){
    std::ofstream fout;
    fout.open("courses.dat");
    fout << currentNumberOfCourses << std::endl;
    fout << courseCapacity << std::endl;
    //We iterate over each class
    for ( int i=0; i < currentNumberOfCourses; i++){
        //Iterate over each variable corresponding to each class
        fout << COURSES[i].getID() << " " << COURSES[i].getName() << " " << COURSES[i].getLocation() << std::endl;
    }
    fout.close();
} //Saves all courses data to the file "courses.dat" in the working directory.

void Courses::loadCoursesData(){
    std::ifstream fin;
    int id;
    std::string name;
    std::string location;
    fin.open("courses.dat");
    fin >> currentNumberOfCourses; fin.ignore();
    fin >> courseCapacity; fin.ignore();
    COURSES = new course[currentNumberOfCourses];
    for ( int i=0; i < currentNumberOfCourses; i++){
        fin >> id >> name >> location;
        COURSES[i].setName(name);
        COURSES[i].setID(id);
        COURSES[i].setLocation(location);
    }
    fin.close();
} //Loads all courses data to the file "courses.dat" in the working directory.
