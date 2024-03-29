/*=============main.cpp================*/
/*
 DESCRIPTION:   Console-based gradebook program with support for unlimited classes and students, as well as file saving.
 AUTHOR:        Andrew P. Sansom
 VERSION:       1.0.0
 VERSION DATE:  20 Feb 2019
 EMAIL:         andrewsansom@my.unt.edu
 COURSE:        CSCE 1040
 =============main.cpp================*/

#include <iostream>
#include <string>

#include "courses.h"
#include "students.h"
#include "enrollments.h"


Enrollments Enrollments;
Students Students;
Courses Courses;


bool enrollStudentInCourse(int studentID, int courseID){
    //First we test if the student has an available class spot. Then we check if the class is already full.
    bool toomanyclasses = Students.isStudentInTooManyClasses(studentID);
    bool isClassFull = Enrollments.isCourseFull(courseID);
    std::cout << "Student is currently enrolled in 5 classes? " << toomanyclasses << std::endl;
    if (toomanyclasses){
        std::cout << "Error: Student enrolled in 5 classes already.\n";
        return false;
    } else if(isClassFull){
        std::cout << "Error: Course already has 48 students.\n";
        return false;
    } else { //If both of the above conditions are fine, then we trigger the creation of an Enrollment and increase the student's record's numberOfCourses.
        int attemptToEnrollStudent = Enrollments.addEnrollment(studentID, courseID);
        std::cout << "Student enrolled in the enrollments instance? " << attemptToEnrollStudent << std::endl;
        if (attemptToEnrollStudent > -1){
            bool attemptToIncreaseStudentNumberOfClasses = Students.enrollStudentInCourse(studentID, courseID);
            std::cout << "Student's number of classes iterator function successful? " << attemptToIncreaseStudentNumberOfClasses << std::endl;
            return attemptToIncreaseStudentNumberOfClasses;
        } else {
            return false;
        }
    }
}

void storeData(){
    Students.storeStudentData();
    Enrollments.storeEnrollmentsData();
    Courses.storeCoursesData();
}

void loadData(){
    Students.loadStudentData();
    Enrollments.loadEnrollmentsData();
    Courses.loadCoursesData();
}


int main() {
    // We will want to make a menu with an infinite loop. It displays the list of options, then expects a user input to the console as a string. Using a switch statement, it runs the appropriate function and displays any output (if appropriate) to the console.
    std::cout << "/*=============================*/\n DESCRIPTION:   Console-based gradebook program with support for unlimited classes and students, as well as file saving.\nAUTHOR:        Andrew P. Sansom\nVERSION:       1.0.0\nVERSION DATE:  20 Feb 2019\nEMAIL:         andrewsansom@my.unt.edu\nCOURSE:        CSCE 1040\n/*=============================*/"<<std::endl;
    char menuString[] = "\n\nWhat would you like to do? \nPlease insert the number of the corresponding action. \n\t0. Quit \n\t1. Add a new course \n\t2. Add a new student \n\t3. Add a student to a course \n\t4. Add grades for a student in a course \n\t5. Print a list of all grades for a student in a course \n\t6. Print a list of all students in a course \n\t7. Compute the average for a student in a course \n\t8. Print a list of all courses \n\t9. Print a list of all students \n\t10. Compute the average for a course \n\t11. Store Grade book (to a disk file) \n\t12. Load Grade book (from a disk file)\n\n";
    int userOption; //Stores the operation that the user requests
    std::cout << menuString << std::endl;
    std::cin >> userOption;
    std::cin.ignore();
    std::cout << std::endl << std::endl << std::endl;
    while (userOption != 0){
        switch (userOption){
            case 1:{ //1. Add a new course
                std::string courseName;
                std::string locationName;
                std::cout << "What is the name of the new course?\n";
                std::getline(std::cin, courseName);
                std::cout << "What is the location of the class?\n";
                std::getline(std::cin, locationName);
                int courseID = Courses.makeNewCourse(courseName, locationName);
                if (courseID==-1){
                    std::cout << "\nError occured. New course could not be made.\n";
                } else {
                    std::cout << "\nCourse created. It has the ID Number: " << courseID << std::endl;
                }
                break;
            }

            case 2:{ //2. Add a new student
                std::string studentName;
                int classification;
                std::cout << "What is the name of the new student?\n";
                std::getline(std::cin, studentName);
                std::cout << "What is the classification of said student?\n0=Freshman, 1=Sophomore, 2=Junior, and 3=Senior.\n";
                std::cin >> classification;
                while (classification<0 || classification>4){
                    std::cout << "Invalid classification. Please enter an integer between 0 and 4.\n";
                    std::cin >> classification;
                }
                if (Students.makeNewStudent(studentName, classification)>-1){
                    std::cout << "\nStudent created successfully.\n";
                } else {
                    std::cout << "\nError occured. New student could not be made.\n";
                }
                break;
            }
            case 3: { //3. Add a student to a course
                int studentID;
                int courseID;
                std::cout << "What is the student ID of the student you would like to enroll in a course?\n";
                std::cin >> studentID;
                while (!Students.isStudentIDValid(studentID)){
                    std::cout << "Invalid ID. Please enter valid ID.\n";
                    std::cin >> studentID;
                }
                std::cout << "What is the course ID of the class in which you would like to enroll the student?\n";
                std::cin >> courseID;
                while (!Courses.isCourseIDValid(courseID)){
                    std::cout << "Invalid ID. Please enter valid ID.\n";
                    std::cin >> courseID;
                }
                if (enrollStudentInCourse(studentID,courseID)){
                    std::cout << "\nStudent succesfully enrolled in course.\n";
                } else {
                    std::cout << "\nAn Error has occured.\n";
                }
                break;
            }
            case 4:{ //4. Add grades for a student in a course
                int studentID;
                int courseID;
                int grade;
                std::cout << "What is the student ID of the student whose grade you would like to add?\n";
                std::cin >> studentID;
                while (!Students.isStudentIDValid(studentID)){
                    std::cout << "Invalid ID. Please enter valid ID.\n";
                    std::cin >> studentID;
                }
                std::cout << "What is the course ID of the class in which the student is enrolled?\n";
                std::cin >> courseID;
                while (!Courses.isCourseIDValid(courseID)){
                    std::cout << "Invalid ID. Please enter valid ID.\n";
                    std::cin >> courseID;
                }
                std::cout << "What is the grade you would like to add?\n";
                std::cin >> grade;
                while (grade<0 || grade>100){
                    std::cout << "Invalid grade. Please enter an integer between 0 and 100 (inclusive).\n";
                    std::cin >> grade;
                }
                Enrollments.addGrade(studentID, courseID, grade);
                Enrollments.printAllGradesOfStudentInCourse(studentID, courseID);
                break;
            }
            case 5:{ //5. Print a list of all grades for a student in a course
                int studentID;
                int courseID;
                std::cout << "What is the student ID of the student whose grades you would like to see?\n";
                std::cin >> studentID;
                while (!Students.isStudentIDValid(studentID)){
                    std::cout << "Invalid ID. Please enter valid ID.\n";
                    std::cin >> studentID;
                }
                std::cout << "What is the course ID of the class in which the student is enrolled which you would like to see?\n";
                std::cin >> courseID;
                while (!Courses.isCourseIDValid(courseID)){
                    std::cout << "Invalid ID. Please enter valid ID.\n";
                    std::cin >> courseID;
                }
                std::cout << std::endl;
                Enrollments.printAllGradesOfStudentInCourse(studentID, courseID);
                break;
            }
            case 6:{ //6. Print a list of all students in a course
                int courseID;
                std::cout << "What is the course ID of the class in which you would like to view the student list?\n";
                std::cin >> courseID;
                Enrollments.printAllStudentsInClass(courseID, &Students, &Courses);
                break;
            }
            case 7:{ //7. Compute the average for a student in a course
                int studentID;
                int courseID;
                std::cout << "What is the student ID of the student whose average you would like to see?\n";
                std::cin >> studentID;
                while (!Students.isStudentIDValid(studentID)){
                    std::cout << "Invalid ID. Please enter valid ID.\n";
                    std::cin >> studentID;
                }
                std::cout << "What is the course ID of the class in which the student is enrolled?\n";
                std::cin >> courseID;
                while (!Courses.isCourseIDValid(courseID)){
                    std::cout << "Invalid ID. Please enter valid ID.\n";
                    std::cin >> courseID;
                }
                std::cout << std::endl;
                float studentAverage = Enrollments.computeAverageOfStudent(studentID, courseID);
                if (studentAverage != -1){
                    std::cout << "Student Average: " << studentAverage << std::endl;
                } else {
                    std::cout << "An error has occured. That student is not enrolled in that class.\n";
                }
                break;
            }
            case 8:{ //8. Print a list of all courses
                Courses.printCourses();
                break;
            }
            case 9:{ //9. Print a list of all students
                Students.printStudents();
                break;
            }
            case 10: { //10. Compute the average for a course
                int courseID;
                std::cout << "What is the course ID of the class whose average you want?\n";
                std::cin >> courseID;
                while (!Courses.isCourseIDValid(courseID)){
                    std::cout << "Invalid ID. Please enter valid ID.\n";
                    std::cin >> courseID;
                }
                std::cout << "The average of course with ID " << courseID << " is " << Enrollments.calculateAverageOfStudentsInCourse(courseID)<<std::endl;
                break;
            }
            case 11:{    //11. Store Grade book (to a disk file)
                storeData();
                std::cout << "Stored data to disk.\n";
                break;
            }
            case 12:{    //12. Load Grade book (from a disk file)
                loadData();
                std::cout << "Loaded data from disk.\n";
                break;
            }
            /*case 13:{
                int studentID;
                std::cout << "What is the student ID of the student whose info you would like to view?\n";
                std::cin >> studentID;
                Students.printStudentInfo(studentID);
            }*/
            default: {
                std::cout << "Unknown operation requested. Please enter a number between 0 and 12 inclusive.\n";
                break;
            }
        }
        /*std::cout << "\n\nPress return to continue...\n";
        std::cin.ignore(1000,'\n');*/
        std::cout << menuString;
        std::cin >> userOption;
        std::cin.ignore();
    }
    return 0;
}
