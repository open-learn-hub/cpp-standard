#ifndef PRACTICE_04_H
#define PRACTICE_04_H

#include "student.h"
#include "stack.h"

void ExecutePractice04();


Stack<StudentPtr>* CreateStudentStack();
void PrintStudents(const StackPtr<StudentPtr> students);

#endif