/*=============students.cpp================*/
/*
 DESCRIPTION:   Contains functions necessary to maintain one Students collection.
 AUTHOR:        Andrew P. Sansom
 VERSION:       1.0.0
 VERSION DATE:  20 Feb 2019
 EMAIL:         andrewsansom@my.unt.edu
 COURSE:        CSCE 1040
 =============students.cpp================*/

#include "students.h"
#define CHUNKSIZE 2

Students::Students(){
    currentNumberOfStudents=0;
    studentsCapacity=CHUNKSIZE;
    STUDENTS = new student[CHUNKSIZE];
}

void Students::printStudents(){
    for (int i = 0; i < currentNumberOfStudents; i++){
        STUDENTS[i].print();
    }
} //prints a list of all students to the console

void Students::printStudentInfo(int studentID){
    STUDENTS[studentID].print();
} //prints the student's information to the console.

int Students::makeNewStudent(std::string name, int classification){
    //Check and see if we need to allocate more memory. If so, do that, please.
    if (currentNumberOfStudents == studentsCapacity){
        student *temp;
        temp = new student [studentsCapacity + CHUNKSIZE];
        for (int i = 0; i < currentNumberOfStudents; i++){
            temp[i] = STUDENTS[i];
        }
        studentsCapacity += CHUNKSIZE;
        delete [] STUDENTS;
        STUDENTS = temp;
    }
    //Put in all the new info.
    STUDENTS[currentNumberOfStudents].setName(name);
    STUDENTS[currentNumberOfStudents].setClassification(classification);
    STUDENTS[currentNumberOfStudents].setID(currentNumberOfStudents);
    STUDENTS[currentNumberOfStudents].print();
    
    currentNumberOfStudents++; //Iterate the thing so we don't accidentally overwrite it.
    return currentNumberOfStudents-1; //This will be the id of the previous student.
}

bool Students::enrollStudentInCourse(int studentID, int courseID){
    if (STUDENTS[studentID].getNumberOfClasses()==5){
        return false;
    }
    return STUDENTS[studentID].addCourse(courseID);
} //enrolls student with studentID in student with studentID. Returns false if student's numberOfSTUDENTS is equal to 5. Iterates the student's numberOfSTUDENTS by 1. Returns true if successful, and false if not.

bool Students::isStudentInTooManyClasses(int studentID){
    if (STUDENTS[studentID].getNumberOfClasses()==5){
        return true;
    } else {
        return false;
    }
} //returns true if the student is in too many classes already.

bool Students::isStudentIDValid(int studentID){
    for (int i=0; i < currentNumberOfStudents; i++){
        if (STUDENTS[studentID].getID()==studentID){
            return true;
        }
    }
    return false;
} //Returns true if there is a student with that studentID. False otherwise.

std::string Students::getNameFromID(int studentID){
    for (int i = 0; i < currentNumberOfStudents; i++){
        if (STUDENTS[i].getID() == studentID){
            return STUDENTS[i].getName();
        }
    }
    return "ERROR STUDENT NOT FOUND";
}//returns the student name of the student instance with the same studentID.

void Students::storeStudentData(){
    std::ofstream fout;
    fout.open("students.dat");
    fout << currentNumberOfStudents << std::endl;
    fout << studentsCapacity << std::endl;
    for ( int i=0; i < currentNumberOfStudents; i++){
        fout << STUDENTS[i].getID() << " " << STUDENTS[i].getName() << " " << STUDENTS[i].getClassification() << " " << STUDENTS[i].getNumberOfClasses() << std::endl;
    }
    fout.close();
} //stores student data to the file "students.dat" in the working directory

void Students::loadStudentData(){
    std::ifstream fin;
    int id;
    std::string name;
    int classification;
    int numberOfClasses;
    fin.open("students.dat");
    fin >> currentNumberOfStudents; fin.ignore();
    fin >> studentsCapacity; fin.ignore();
    STUDENTS = new student[currentNumberOfStudents];
    for ( int i=0; i < currentNumberOfStudents; i++){
        fin >> id >> name >> classification >> numberOfClasses;
        STUDENTS[i].setName(name);
        STUDENTS[i].setID(id);
        STUDENTS[i].setClassification(classification);
        STUDENTS[i].setNumberOfClasses(numberOfClasses);
    }
    fin.close();
} //loads student data to the file "students.dat" in the working directory
