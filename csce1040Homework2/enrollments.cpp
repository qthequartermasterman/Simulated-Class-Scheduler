/*=============enrollments.cpp================*/
/*
 DESCRIPTION:   Contains functions necessary to maintain one Enrollments collection.
 AUTHOR:        Andrew P. Sansom
 VERSION:       1.0.0
 VERSION DATE:  20 Feb 2019
 EMAIL:         andrewsansom@my.unt.edu
 COURSE:        CSCE 1040
 =============enrollments.cpp================*/

#include "enrollments.h"
#include "students.h"
#include "courses.h"
#define CHUNKSIZE 2

//Memory Allocation
Enrollments::Enrollments(){
    ENROLLMENTS = new enrollment[CHUNKSIZE];
    enrollmentCapacity = CHUNKSIZE;
    currentNumberOfEnrollments = 0;
}

int Enrollments::addEnrollment(int studentID,int courseID){
    //Allocate more memory if needed.
    if (currentNumberOfEnrollments == enrollmentCapacity){
        enrollment *temp;
        temp = new enrollment[enrollmentCapacity + CHUNKSIZE];
        for (int i = 0;i < currentNumberOfEnrollments;i++) temp[i] = ENROLLMENTS[i];
        delete [] ENROLLMENTS;
        enrollmentCapacity += CHUNKSIZE;
        ENROLLMENTS = temp;
    }
    ENROLLMENTS[currentNumberOfEnrollments].setID(currentNumberOfEnrollments);
    ENROLLMENTS[currentNumberOfEnrollments].setStudentID(studentID);
    ENROLLMENTS[currentNumberOfEnrollments].setCourseID(courseID);
    currentNumberOfEnrollments++;
    return currentNumberOfEnrollments-1;
} //generates a new Enrollment instance and adds it to ENROLLMENTS, allocating memory if necessary. Returns the id of the enrollment instance.

//Verification functions. These are used to check if the enrollment item really can be made.
bool Enrollments::isCourseFull(int courseID){
    int counter = 0;
    for (int i = 0; i < currentNumberOfEnrollments; i++){
        if (ENROLLMENTS[i].getCourseID() == courseID){
            counter++;
        }
    }
    if (counter == 48){
        return true;
    } else {
        return false;
    }
} // returns true if the course has 48 students enrolled in it.


//Grade Manipulation functions. These either manipulate grades or run some statistic on them.

bool Enrollments::addGrade(int studentID, int classID, int grade){
    for (int i = 0; i < currentNumberOfEnrollments; i++){
        if (ENROLLMENTS[i].getStudentID()==studentID && ENROLLMENTS[i].getCourseID()==classID){
            return ENROLLMENTS[i].addGrade(grade);
        }
    }
    return false;
} //adds a grade for student with id studentID who is enrolled in class with id classID. Iterates over the ENROLLMENTS array for the object with matching studentID and classID. Calls that Enrollment instances AddGradeForStudent function. Returns true if successful, returns false if not.

float Enrollments::computeAverageOfStudent(int studentID, int courseID){
    for (int i = 0; i < currentNumberOfEnrollments; i++){
        if (ENROLLMENTS[i].getStudentID()==studentID && ENROLLMENTS[i].getCourseID()==courseID){
            return ENROLLMENTS[i].calculateAverage();
        }
    }
    return -1;
} //Computes the average of a student in a course.

float Enrollments::calculateAverageOfStudentsInCourse(int courseID){
    float runningTotal = 0;
    int numberOfStudents = 0;
    for (int i=0; i < currentNumberOfEnrollments; i++){
        if (ENROLLMENTS[i].getCourseID()==courseID){
            runningTotal += ENROLLMENTS[i].calculateAverage();
            numberOfStudents++;
        }
    }
    return runningTotal/numberOfStudents;
} //Computes the average of a student in a course.


//Print functions. These print some sort of data to the console.
void Enrollments::printAllStudentsInClass(int courseID, Students *students, Courses *courses){
    std::cout << "Course (ID): " << courses->getNameFromID(courseID) << " (" << courseID << ")\n";
    std::cout << "Students (ID): \n";
    for (int i = 0; i < currentNumberOfEnrollments; i++){
        if (ENROLLMENTS[i].getCourseID() == courseID){
            std::cout << students->getNameFromID(ENROLLMENTS[i].getStudentID()) << " ("<< ENROLLMENTS[i].getStudentID() << ")\n";
        }
    }
    std::cout << std::endl;
}    //prints a list of all of the students in the class to the console. Loops over each enrollment and prints the student's name if they are in that class.

void Enrollments::printAllGradesOfStudentInCourse(int studentID, int courseID){
    for (int i = 0; i < currentNumberOfEnrollments; i++){
        if (ENROLLMENTS[i].getCourseID()==courseID && ENROLLMENTS[i].getStudentID()==studentID){
            ENROLLMENTS[i].printGrades();
        }
    }
} //Loops over the ENROLLMENTS array, finds the first enrollment instance that matches the studentID and courseID. Then prints the grades to the console.


//File storage functions. These well... store files.
void Enrollments::storeEnrollmentsData(){
    std::ofstream fout;
    fout.open("enrollments.dat");
    fout << currentNumberOfEnrollments << std::endl;
    //Print to file in this order:
    //enrollmentID, studentID, courseID, currentNumberOfGrades, each grade individually
    for ( int i=0; i < currentNumberOfEnrollments; i++){
        fout << ENROLLMENTS[i].getID() << " " << ENROLLMENTS[i].getStudentID() << " " << ENROLLMENTS[i].getCourseID() << " " << ENROLLMENTS[i].getNumberOfGrades() << " ";
        for (int j = 0; j < ENROLLMENTS[i].getNumberOfGrades(); j++){
            fout << ENROLLMENTS[i].getGradeNumber(j) << " ";
        }
        fout << std::endl;
    }
    fout.close();
}
void Enrollments::loadEnrollmentsData(){
    std::ifstream fin;
    int id;
    int studentID;
    int courseID;
    int numberOfGrades;
    int grade;
    fin.open("enrollments.dat");
    fin >> currentNumberOfEnrollments; fin.ignore();
    ENROLLMENTS = new enrollment[currentNumberOfEnrollments];
    for ( int i=0; i < currentNumberOfEnrollments; i++){
        fin >> id >> studentID >> courseID >> numberOfGrades;
        ENROLLMENTS[i].setID(id);
        ENROLLMENTS[i].setStudentID(studentID);
        ENROLLMENTS[i].setCourseID(courseID);
        ENROLLMENTS[i].setNumberOfGrades(numberOfGrades);
        for (int j = 0; j < numberOfGrades; j++){
            fin >> grade;
            ENROLLMENTS[i].setGradeNumber(j, grade);
        }
        
    }
    fin.close();
}
