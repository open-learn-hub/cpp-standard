#include "student.h"
#include <iostream>

using namespace std;

void PrintStudent(const Student* student) 
{
    if (student == nullptr) 
    {
        std::cout << "[Student] nullptr" << std::endl;  
        return;  
    }

    std::cout << "[Student]"
    << " Id: " << student ->id
    << " Full Name: " << student->fullName
    << " GPA: " << student->gpa
    << " Performance: " << student->performance
    << std::endl;
}