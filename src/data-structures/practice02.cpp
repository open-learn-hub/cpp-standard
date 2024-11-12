#include "data-structures/practice02.h"
#include "data-structures/linkedlist.h"
#include <iostream>

void Excercise01()
{

}

void Excercise02()
{

}

void ExecutePractice02()
{
    List<int>* list = CreateList<int>();
    AddHead<int>(list, 5);
    AddHead<int>(list, 1);
    AddTail<int>(list, 2);
    AddTail<int>(list, 2);
    PrintList(list);
    PrintNode(GetNode(list, 1));
    std::cout << Count<int>(list) << std::endl;
    int length = 0;
    Node<int>** foundArr = FindAll<int>(list, 2, length);
    PrintNodes<int>(const_cast<const Node<int>**>(foundArr), length);
}


// Excercise01
Node<int>** GetNegativeItems(const List<int>* list, int& outLength)
{
    return nullptr;
}

Node<int>** GetPositiveItems(const List<int>* list, int& outLength)
{
    return nullptr;
}

Node<int>* GetLargestNegativeItem(const List<int>* list)
{
    return nullptr;

}
Node<int>* GetLargestOddItem(const List<int>* list)
{
    return nullptr;
}

// Excercise02
List<Student*>* CreateStudentList()
{
    return nullptr;
}
Student* GetHighestGPA(const List<Student*> list)
{
    return nullptr;
}
Student* GetHighestGPAStudent(const List<Student*> list)
{
    return nullptr;
}
Student* GetLowestGPAStudent(const List<Student*> list)
{
    return nullptr;
}
Student* FindStudentById(const List<Student*> list, const int id) 
{ 
    return nullptr;
}
