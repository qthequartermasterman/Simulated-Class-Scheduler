//
//  main.cpp
//  csce1040Homework2
//
//  Created by Andrew Sansom on 2/13/19.
//  Copyright © 2019 Andrew Sansom. All rights reserved.
//

#include <iostream>
#include <string>

#include "courses.hpp"
#include "students.hpp"
#include "enrollments.hpp"


Enrollments Enrollments;
Students Students;
Courses Courses;

int main(int argc, const char * argv[]) {
    // We will want to make a menu with an infinite loop. It displays the list of options, then expects a user input to the console as a string. Using a chain of if statements, it runs the appropriate function and displays any output (if appropriate) to the console.
    char menuString[] = "What would you like to do? \nPlease insert the number of the corresponding action. \n0. Quit \n1. Add a new course \n2. Add a new student \n3. Add a student to a course \n4. Add grades for a student in a course \n 5. Print a list of all grades for a student in a course \n6. Print a list of all students in a course \n7. Compute the average for a student in a course 8. Print a list of all courses \n9. Print a list of all students \n10. Compute the average for a course \n11. Store Grade book (to a disk file) \n12. Load Grade book (from a disk file)";
    int userOption; //Stores the operation that the user requests
    std::cout << menuString << std::endl;
    std::cin >> userOption;
    while (userOption != 0){
        switch (userOption){
            case 1:
                std::string courseName;
                std::cout << "What is the name of the new course?\n";
                std::cin >> courseName;
                // TODO: Implement the thing.
                break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: break;
            case 6: break;
            case 7: break;
            case 8: break;
            case 9: break;
            case 10: break;
            case 11: break;
            case 12: break;
            default:
                std::cout << "Unknown operation requested. Please enter a number between 0 and 12 inclusive.\n";
                break;
  
        }
        std::cin >> userOption;
    }
    return 0;
}
