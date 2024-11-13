#include "data-structures/practice02.h"
#include "data-structures/linkedlist.h"
#include <iostream>

void Excercise01()
{
    // 1.1 
    // See linkedlist.h

    // 1.2.1
    Node<int>* integerNode = CreateNode(0);
    
    // 1.2.2
    List<int>* iList = CreateList<int>();

    // 1.3
    AddHead<int>(iList, 2);
    AddHead<int>(iList, 1);

    // 1.4
    AddTail<int>(iList, 3);
    AddTail<int>(iList, 4);

    std::cout << "List result from 1.1 -> 1.4" << std::endl;
    PrintList(iList);

    Release(iList, true);
    delete iList;
    iList = nullptr;

    // 1.5
    int intArrLength = 7;
    int* intArr = new int[intArrLength] { 0, 1, -3 , 2, 2, -22, 3}; 

    iList = CreateList(intArr, intArrLength);
    std::cout << "List created from array" << std::endl;

    // 1.6 1.7
    PrintList(iList);


    // 1.8
    std::cout << "Is list empty: " << (IsEmpty(iList) ? "true" : "false") << std::endl;

    // 1.9
    int value2Find = 2;
    int foundIdx = FindIndex(iList, value2Find);
    std::cout << "Index of " << value2Find << " in the list is: " << foundIdx << std::endl;

    // 1.10
    value2Find = 1;
    Node<int>* found = FindNode(iList, value2Find);
    if (found != nullptr)
    {
        std::cout << "Found node ";
        PrintNode(found);
    }
    else
    {
        std::cout << "Could not found node with value " << value2Find << std::endl;
    }
    found = nullptr;

    // 1.11
    value2Find = 2;
    int foundCount = 0;
    Node<int>** allFound = FindAll(iList, value2Find, foundCount);
    if (foundCount > 0)
    {
        std::cout << "Found nodes with value: " << value2Find;
        PrintNodes(const_cast<const Node<int>**>(allFound), foundCount);
    }
    else
    {
        std::cout << "Could not find node with value: " << value2Find << std::endl;
    }

    // 1.12
    int negativeCount, positiveCount;
    Node<int>** n = GetNegativeItems(iList, negativeCount);
    Node<int>** p = GetPositiveItems(iList, positiveCount);

    std::cout << "There're " << positiveCount << " positive number(s) and " << negativeCount << " negative number(s) in the list." << std::endl;
    PrintNodes(const_cast<const Node<int>**>(n), negativeCount);
    PrintNodes(const_cast<const Node<int>**>(p), positiveCount);
    delete n; n = nullptr;
    delete p; p = nullptr;

    // 1.13
    found = GetLargestNegativeItem(iList);
    if (found != nullptr)
    {
        std::cout << "Found the largest negative node ";
        PrintNode(found);
    }
    else
    {
        std::cout << "There is no negative number in the list" << std::endl;
    }
    found = nullptr;

    // 1.13
    found = GetLargestOddItem(iList);
    if (found != nullptr)
    {
        std::cout << "Found the largest odd node ";
        PrintNode(found);
    }
    else
    {
        std::cout << "There is no odd number in the list" << std::endl;
    }
    found = nullptr;

    // 1.14
    int value2Replace = 2;
    int newValue = -1;
    std::cout << "Replacing the first item with value " << value2Replace << " by " << newValue << ". Result below" << std::endl;
    ReplaceFirst(iList, value2Replace, newValue);
    PrintList(iList);

    // 1.15
    std::cout << "Copying the list to new one, Destination result below" << std::endl;
    List<int>* destList = CreateList<int>();
    Copy(iList, destList);
    PrintList(destList);
}

void Excercise02()
{

}

void ExecutePractice02()
{
    Excercise01();
}


// Excercise01
Node<int>** GetNegativeItems(const List<int>* list, int& outLength)
{
    std::function<bool(int)> func = [](int value)
    {
        return value < 0;
    };
    outLength = Count(list, func);
    
    Node<int>** arr = new Node<int>*[outLength];
    Node<int>* current = list->root;
    int captureIdx = 0;
    while (current != nullptr)
    {
        if (func(current->data))
        {
            arr[captureIdx] = current;
            captureIdx++;
        }
        current = current->pNext;
    }
    return arr;
}

Node<int>** GetPositiveItems(const List<int>* list, int& outLength)
{
    std::function<bool(int)> func = [](int value)
    {
        return value >= 0;
    };
    outLength = Count(list, func);
    
    Node<int>** arr = new Node<int>*[outLength];
    Node<int>* current = list->root;
    int captureIdx = 0;
    while (current != nullptr)
    {
        if (func(current->data))
        {
            arr[captureIdx] = current;
            captureIdx++;
        }
        current = current->pNext;
    }
    return arr;
}

Node<int>* GetLargestNegativeItem(const List<int>* list)
{
    int length = 0;
    Node<int>** negatives = GetNegativeItems(list, length);
    Node<int>* res = nullptr;
    if (length > 0)
    {
        res = negatives[0];
        for (int i = 1; i < length; i++)
        {
            if (res->data < negatives[i]->data)
            {
                res = negatives[i];
            }
        }
    }
    return res;

}
Node<int>* GetLargestOddItem(const List<int>* list)
{
    int length = 0;
    Node<int>** negatives = GetNegativeItems(list, length);
    PrintNodes(const_cast<const Node<int>**>(negatives), length);
    Node<int>* res = nullptr;
    if (length > 0)
    {
        for (int i = 0; i < length; i++)
        {
            if (abs(negatives[i]->data % 2) == 1)
            {
                if (res == nullptr)
                {
                    res = negatives[i];
                }
                else if (negatives[i]->data > res->data)
                {
                    res = negatives[i];
                }
            }
        }
    }
    return res;
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
