//
//  enrollment.hpp
//  csce1040Homework2
//
//  Created by Andrew Sansom on 2/21/19.
//  Copyright © 2019 Andrew Sansom. All rights reserved.
//

#ifndef enrollment_hpp
#define enrollment_hpp

class enrollment {
private:
    int ID=-1;        //representing the ID number of the enrollment data
    int studentID;     //representing the student's ID
    int courseID;      //representing the course's ID
    int grades[10];        //an integer array of size ten representing the 10 grades in the course
    int numberOfGrades=0;    //an integer representing the number of grades in the course.
    float average=-1;       //representing the average of all of the grades
    char letterGrade;           //representing the letter grade ( Intervals written in mathematical interval notation [90,100] => 'A'; [80,90) => 'B'; [75,80) => 'C'; [70,75) => 'D'; [0,70) => 'F')
public:
    bool addGrade(int grade); //adds a grade to the next available spot in the grades array. Also increments numberOfGrades. Returns true if successful, false otherwise
    float calculateAverage();    //returns the average of all of the grades in an enrollment object as a float.
    char calculateLetterGrade();  //returns the letter grade of the student as a char.
    
    int getID(){return ID;};
    int getStudentID(){return studentID;};
    int getCourseID(){return courseID;};
    void setID(int _id){ID=_id;};
    void setStudentID(int _studentID){studentID=_studentID;};
    void setCourseID(int _courseID){courseID=_courseID;};
    int getNumberOfGrades(){return numberOfGrades;};
    void setNumberOfGrades(int _number){numberOfGrades=_number;};
    int getGradeNumber(int gradeNumber){return grades[gradeNumber];}; //Returns the gradeNumber-th element in the grades array.
    void setGradeNumber(int gradeNumber, int grade){grades[gradeNumber]=grade;}; //Sets the gradeNumber-th element of the grades array to grade.
    
    void printGrades(); //prints all grades to the console.

};

#endif /* enrollment_hpp */
