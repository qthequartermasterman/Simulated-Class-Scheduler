//
//  students.cpp
//  csce1040Homework2
//
//  Created by Andrew Sansom on 2/21/19.
//  Copyright © 2019 Andrew Sansom. All rights reserved.
//

#include "students.hpp"
#define CHUNKSIZE 2

int Students::makeNewStudent(std::string name, int classification){
    
    //Check and see if we need to allocate more memory. If so, do that, please.
    if (currentNumberOfStudents == studentsCapacity)
    {
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

bool Students::isStudentInTooManyClasses(int studentID){
    if (STUDENTS[studentID].getNumberOfClasses()==5){
        return true;
    } else {
        return false;
    }
}

bool Students::enrollStudentInCourse(int studentID, int courseID){
    if (STUDENTS[studentID].getNumberOfClasses()==5){
        return false;
    }
    return STUDENTS[studentID].addCourse(courseID);
} //enrolls student with studentID in student with studentID. Returns false if student's numberOfSTUDENTS is equal to 5. Iterates the student's numberOfSTUDENTS by 1. Returns true if successful, and false if not.


bool Students::isStudentIDValid(int studentID){
    for (int i=0; i < currentNumberOfStudents; i++){
        if (STUDENTS[studentID].getID()==studentID){
            return true;
        }
    }
    return false;
} //Returns true if there is a student with that studentID. False otherwise.

void Students::cleanup(){
    delete [] STUDENTS;
}

Students::Students(){
    currentNumberOfStudents=0;
    studentsCapacity=CHUNKSIZE;
    STUDENTS = new student[CHUNKSIZE];
}

void Students::printStudentInfo(int studentID){
    STUDENTS[studentID].print();
} //prints the student's information to the console.

std::string Students::getNameFromID(int studentID){
    for (int i = 0; i < currentNumberOfStudents; i++){
        if (STUDENTS[i].getID() == studentID){
            return STUDENTS[i].getName();
        }
    }
    return "ERROR STUDENT NOT FOUND";
}//returns the student name of the student instance with the same studentID.

void Students::printStudents(){
    for (int i = 0; i < currentNumberOfStudents; i++){
        STUDENTS[i].print();
    }
}


void Students::storeStudentData(){
    std::ofstream fout;
    fout.open("students.dat");
    fout << currentNumberOfStudents << std::endl;
    for ( int i=0; i < currentNumberOfStudents; i++){
        fout << STUDENTS[i].getID() << " " << STUDENTS[i].getName() << " " << STUDENTS[i].getClassification() << " " << STUDENTS[i].getNumberOfClasses() << std::endl;
    }
    fout.close();
}

void Students::loadStudentData(){
    std::ifstream fin;
    int id;
    std::string name;
    int classification;
    int numberOfClasses;
    fin.open("students.dat");
    fin >> currentNumberOfStudents; fin.ignore();
    STUDENTS = new student[currentNumberOfStudents];
    for ( int i=0; i < currentNumberOfStudents; i++){
        fin >> id >> name >> classification >> numberOfClasses;
        STUDENTS[i].setName(name);
        STUDENTS[i].setID(id);
        STUDENTS[i].setClassification(classification);
        STUDENTS[i].setNumberOfClasses(numberOfClasses);
    }
    fin.close();
}
