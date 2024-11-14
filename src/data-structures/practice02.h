#ifndef PRACTICE_02_H
#define PRACTICE_02_H

#include "data-structures/linkedlist.h"
#include "data-structures/student.h"

using namespace sll;

namespace practice02
{
    void Exercise01();
    void Exercise02();


    void ExecutePractice02();

    // Excercise01
    Node<int>** GetNegativeItems(const List<int>* list, int& outLength);
    Node<int>** GetPositiveItems(const List<int>* list, int& outLength);

    Node<int>* GetLargestNegativeItem(const List<int>* list);
    Node<int>* GetLargestOddItem(const List<int>* list);

    // Excercise02
    List<StudentPtr>* CreateStudentList();
    float GetHighestGPA(const List<StudentPtr>* list);
    StudentPtr GetHighestGPAStudent(const List<StudentPtr>* list);
    StudentPtr GetLowestGPAStudent(const List<StudentPtr>* list);
    StudentPtr FindStudentById(const List<StudentPtr>* list, const int id);
    void PrintStudents(const List<StudentPtr>* list);
}
#endif