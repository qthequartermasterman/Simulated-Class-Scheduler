# CSCE 1040 Homework 2
Andrew Sansom
## Classes

### Class Student
This represent's a single student's record.
#### Variables
- int ID        representing the ID number of the student
- string name       representing the name of the student
- int numberOfClasses       representing the number of classes in which the student is currently enrolled. Clearly this value should not be negative. This cannot be more than 5.
- int classification        representing the student's classification. 0=Freshman, 1=Sophomore, 2=Junior, and 3=Senior.
#### Functions
- bool addCourse(int courseID); //adds a course to "courses" and updates the numberOfClasses. Returns true if succesful (i.e. the student is not already at maximum enrollment and the class is not already full) but false if not.
- void print(); //Prints all information about the student to the console. Simply prints everything using a formatted cout string.




### Class course
This represents the data for a course.
#### Variables
private:
- int ID        representing the ID number of the course
- string name       representing the name of the course
- string location       representing the location of the course as  C-string
#### Functions
public:
- void print(); //prints the course's information to the console.





### Class enrollment
Represents a single student's grade data for a single class.
#### Variables
private:
- int ID        representing the ID number of the enrollment data
- int studentID     representing the student's ID
- int courseID      representing the course's ID
- int grades[10]         an integer array of size ten representing the 10 grades in the course
- int numberOfGrades    an integer representing the number of grades in the course.
- float average       representing the average of all of the grades
- char letterGrade           representing the letter grade ( Intervals written in mathematical interval notation [90,100] => 'A'; [80,90) => 'B'; [75,80) => 'C'; [70,75) => 'D'; [0,70) => 'F')

#### Functions
- bool addGrade(int grade);       //adds a grade to the next available spot in the grades array. Also increments numberOfGrades. Returns true if successful, false otherwise
- float calculateAverage();           //returns the average of all of the grades in an enrollment object as a float. Returns -1 if the average is undefined (due to a division by zero error).
- char calculateLetterGrade();        //returns the letter grade of the student as a char.
- void printGrades();         //prints all grades to the console.
//Special Setter and Getter functions
- int getGradeNumber(int gradeNumber);    //Returns the gradeNumber-th element in the grades array.
- void setGradeNumber(int gradeNumber, int grade);       //Sets the gradeNumber-th element of the grades array to grade.




### Class Courses
This contains the master list of courses and associated functions
#### Variables
private:
Course[] COURSES      dynamic array representing the master list of courses
int courseCount         the current number of courses in the system
int courseCapacity      the current size of COURSES
#### Functions
public:
Constructor Courses::Courses()
Deconstuctor Courses::~Courses()
int makeNewCourse(char[] name, char[] location, int enrollmentCapacity) creates a new course by calling the Course constructor and adding it to the COURSES array. If COURSES is not large enough, it allocates more space. Returns the ID number if successful, or -1 if not.
void printAllGradesOfStudentInCourse(int studentID, int classID) prints all the grades of the student for a particular class to the console. Calls the Course::printAllGradesOfStudent on the correct course object.
void printListOfAllStudentsInCourse(int classID) prints a list of all students enrolled in a course to the console.
void printListOfAllCourses() prints a list of all courses to the console
float computeAverageOfStudentInClass(int studentID, int classID) computes the average of a student in a particular class, saves it to their corresponding enrollment instance and returns it.
_____ addStudentToCourse(int studentID, int courseID) calls the correct course's addStudentToCourse function.


### Class Students
This contains the master list of students and associated functions
#### Variables
private:
Student[] STUDENTS      dynamic array representing the master list of students
int currentNumberOfStudents     representing the current number of student records
int studentsCapacity      representing the current capacity of student records.
#### Functions
int makeNewStudent(char[] name) creates a new student record by calling the Student Constructor and adds it to the STUDENTS array, allocating memory if necessary. Returns with the id number if succesful, but -1 if not.
void printListOfAllStudents() prints a list of all students to the console
bool enrollStudentInCourse(int studentID, int courseID) enrolls student with studentID in course with courseID. Returns false if student's numberOfCourses is equal to 5. Then calls Courses's addStudentToCourse method. Adds the courseID to the student's enrolledCourses array. Iterates the student's numberOfCourses by 1. Returns true if successful, and false if not.
int getStudentIdFromName(char* name) returns the ID number of the student with a given name.



### Class Enrollments
This contains the master list of enrollments and associated functions
#### Variables
private:
Enrollment[] ENROLLMENTS      dynamic array representing the master list of enrollments
int currentNumberOfEnrollments      representing the current number of enrollment items
int enrollmentCapacity      representing the current capacity of enrollments.
#### Functions
public:
Constructor Enrollments::Enrollments()
Deconstructor Enrollments::~Enrollments()
void allocateFiveMoreEnrollments()      allocates space for five more enrollments (the maximum number needed for a single student)
bool addGrade(int studentID, int classID, int grade) adds a grade for student with id studentID who is enrolled in class with id classID. Iterates over the ENROLLMENTS array for the object with matching studentID and classID. Calls that Enrollment instances AddGradeForStudent function. Returns true if successful, returns false if not.
int addEnrollment(int studentID,int courseID) generates a new Enrollment instance and adds it to ENROLLMENTS, allocating memory if necessary. Returns the id of the enrollment instance.




## Global Functions
bool saveGradeBookToDisc()  converts the gradebook to a file.
bool loadGradeBookFromDisc() converts the gradebook from a file.


## Main Function
We will want to make a menu with an infinite loop. It displays the list of options, then expects a user input to the console as a string. Using a chain of if statements, it runs the appropriate function and displays any output (if appropriate) to the console.
