#include "data-structures/linkedlist.h"
#include "data-structures/student.h"

void Excercise01();
void Excercise02();


void ExecutePractice02();

// Excercise01
Node<int>** GetNegativeItems(const List<int>* list, int& outLength);
Node<int>** GetPositiveItems(const List<int>* list, int& outLength);

Node<int>* GetLargestNegativeItem(const List<int>* list);
Node<int>* GetLargestOddItem(const List<int>* list);

// Excercise02
List<Student*>* CreateStudentList();
Student* GetHighestGPA(const List<Student*>* list);
Student* GetHighestGPAStudent(const List<Student*>* list);
Student* GetLowestGPAStudent(const List<Student*>* list);
Student* FindStudentById(const List<Student*>* list, const int id);
void PrintStudents(const List<Student*>* list);

