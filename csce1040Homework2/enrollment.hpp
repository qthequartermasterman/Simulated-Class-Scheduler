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
    int ID;        //representing the ID number of the enrollment data
    int studentID;     //representing the student's ID
    int courseID;      //representing the course's ID
    int grades[10];        //an integer array of size ten representing the 10 grades in the course
    int numberOfGrades;    //an integer representing the number of grades in the course.
    float average;       //representing the average of all of the grades
    char letterGarde;           //representing the letter grade ( Intervals written in mathematical interval notation [90,100] => 'A'; [80,90) => 'B'; [75,80) => 'C'; [70,75) => 'D'; [0,70) => 'F')
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

};

#endif /* enrollment_hpp */
