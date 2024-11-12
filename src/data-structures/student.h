#ifndef STUDENT_H
#define STUDENT_H

#include <string>

enum EAcademicPerformance
{
    A = 0,
    B = 1,
    C = 2,
    D = 3,
};

struct Student
{
    int id;
    std::string fullName;
    float gpa;
    enum EAcademicPerformance performance;
};

void PrintStudent(Student* student);

#endif