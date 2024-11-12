#include "data-structures/practice02.h"
#include "data-structures/linkedlist.h"
#include <iostream>

void Excercise01()
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
    Node<int>** foundArr = FindAll(list, 2, length);
    PrintNodes<int>(foundArr, length);
}
