# CSCE 1040 Homework 2
Andrew Sansom
## Classes

### Class Student
This represent's a single student's record.
#### Variables
- int ID        representing the ID number of the student
- char[] name       representing the name of the student
- int numberOfClasses       representing the number of classes in which the student is currently enrolled. Clearly this value should not be negative. This cannot be more than 5.
- int classification        representing the student's classification. 0=Freshman, 1=Sophomore, 2=Junior, and 3=Senior.
- int[] courses         representing the current courses in which the student is enrolled.

#### Functions

bool addCourse(int courseID) adds a course to "courses" and updates the numberOfClasses. Returns true if succesful (i.e. the student is not already at maximum enrollment) but false if not.





### Class Course
This represents the data for a course.
#### Variables
- int ID        representing the ID number of the course
- char[] name       representing the name of the course
- char[] location       representing the location of the course as  C-string
- int enollmentCurrent           representing the current enrollment of the course. Clearly this value should not be negative. It has a maximum value of 48.
- int enrollmentCapacity        representing the current maximum enrollment of the course. Clearly this value should not be negative. It has a maximum value of 48.
- int[] enrollmentIDs   dynamic array representing a collection of enrollment data
- int[] studentIDs  dynamic array repesenting a collection of student records
#### Functions
public:
- Constructor Course::Course(int ID, char[] name, char[] location)
- bool addStudentToCourse(int studentID) calls Enrollment's addEnrollment with the given studentID and the courseID. Adds studentID to the next spot in studentIDs and the returned enrollment ID to enrollmentIDs. It also updates the corresponding Student object's classes. Returns true if succesful (i.e. the student is not at maximum enrollment and the class is not already at capacity), and false is not.
- void printAllGradesOfStudent(int studentID) prints all the grades of the student for a particular class to the console.
- void printAllStudentsInClass()    prints a list of all of the students in the class to the console.
- float computeAverageOfClass() computes the average of the average of every student in a particular class. 
private:
- int findEnrollmentIdFromStudentId(int studentID) returns the enrollment ID from the corresponding student ID. This will 





### Class Enrollment
Represents a single student's grade data for a single class.
#### Variables
private:
- int ID        representing the ID number of the enrollment data
- int studentID     representing the student's ID
- int courseID      representing the course's ID
- int[10] grades        an integer array of size ten representing the 10 grades in the course
- int numberOfGrades    an integer representing the number of grades in the course.
- float average       representing the average of all of the grades
- char letterGarde           representing the letter grade ( Intervals written in mathematical interval notation [90,100] => 'A'; [80,90) => 'B'; [75,80) => 'C'; [70,75) => 'D'; [0,70) => 'F')

#### Functions
public:
bool addGradeForStudent(int grade) adds a grade to the next available spot in the grades array. Also increments numberOfGrades. Returns true if successful, false otherwise
float calculateAverage    returns the average of all of the grades in an enrollment object as a float.
char calculateLetterGrade  returns the letter grade of the student as a char.




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
