#ifndef PRACTICE_03_H
#define PRACTICE_03_H

#include "student.h"
#include "linkedlistdll.h"

void ExecutePractice03();

dll::List<StudentPtr>* CreateStudentList();
void PrintStudents(const dll::List<StudentPtr>* list);

#endif