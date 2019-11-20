/*=============course.cpp================*/
/*
 DESCRIPTION:   Contains functions necessary to maintain one course record.
 AUTHOR:        Andrew P. Sansom
 VERSION:       1.0.0
 VERSION DATE:  20 Feb 2019
 EMAIL:         andrewsansom@my.unt.edu
 COURSE:        CSCE 1040
 =============course.cpp================*/

#include "course.h"
#include <iomanip>

void course::print(){
    std::cout << "Course: " << std::setw(12) << name << " Location: " << std::setw(12) << location << " ID: " << std::setw(5) << ID << std::endl;
}
