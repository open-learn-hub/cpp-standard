#include "data-structures/practice02.h"
#include "data-structures/linkedlist.h"
#include <iostream>

void practice02::Exercise01()
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

void practice02::Exercise02()
{
    // 1.1 see studen.h

    // 1.2 1.3 linkedlist.h

    // 1.4 1.5 see AddHead and AddTail in linkedlist.h

    // 1.6
    List<Student*>* students = CreateStudentList();

    // 1.7
    PrintStudents(students);

    // 1.8
    float highestGPA = GetHighestGPA(students);
    std::cout << "The highest GPA " << highestGPA << std::endl;

    // 1.9
    StudentPtr found = FindStudentById(students, 123);
    std::cout << "Find student by id 123" << std::endl;
    PrintStudent(found);

    // 1.10
    Student* student = GetHighestGPAStudent(students);
    std::cout << "Highest GPA student" << std::endl;
    PrintStudent(student);

    // 1.11
    student = GetLowestGPAStudent(students);
    std::cout << "Lowest GPA student" << std::endl;
    PrintStudent(student);
}

void practice02::ExecutePractice02()
{
    int totalExercises = 2;
    std::cout << "Input Exercise (start from 1) To Run, there're " << totalExercises << " exercise(s)" << std::endl;
    int idx;
    cin >> idx;

    switch (idx)
    {
        case 1:
        Exercise01();
        break;

        case 2:
        Exercise02();
        break;

        default:
            std::cout << "Your input is invalid" << std::endl;
            break;
    }
}


// Excercise01
Node<int>** practice02::GetNegativeItems(const List<int>* list, int& outLength)
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

Node<int>** practice02::GetPositiveItems(const List<int>* list, int& outLength)
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

Node<int>* practice02::GetLargestNegativeItem(const List<int>* list)
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
Node<int>* practice02::GetLargestOddItem(const List<int>* list)
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
List<StudentPtr>* practice02::CreateStudentList()
{
    List<Student*>* list = CreateList<Student*>();
    AddTail(list, new Student { .id = 123, .fullName = "Nguyen Van A", .gpa = 9.1, .performance = EAcademicPerformance::A });
    AddTail(list, new Student { .id = 124, .fullName = "Nguyen Van B", .gpa = 8.8, .performance = EAcademicPerformance::A });
    AddTail(list, new Student { .id = 125, .fullName = "Nguyen Van C", .gpa = 9.1, .performance = EAcademicPerformance::A });
    AddTail(list, new Student { .id = 126, .fullName = "Nguyen Van D", .gpa = 2.1, .performance = EAcademicPerformance::D });
    AddTail(list, new Student { .id = 127, .fullName = "Nguyen Van E", .gpa = 9.7, .performance = EAcademicPerformance::A });
    AddTail(list, new Student { .id = 128, .fullName = "Nguyen Van F", .gpa = 4.1, .performance = EAcademicPerformance::C });
    AddTail(list, new Student { .id = 129, .fullName = "Nguyen Van G", .gpa = 8.3, .performance = EAcademicPerformance::A });
    AddTail(list, new Student { .id = 130, .fullName = "Nguyen Van H", .gpa = 7.9, .performance = EAcademicPerformance::B });
    AddTail(list, new Student { .id = 131, .fullName = "Nguyen Van K", .gpa = 9.0, .performance = EAcademicPerformance::A });
    return list;
}
float practice02::GetHighestGPA(const List<StudentPtr>* list)
{
    StudentPtr student = GetHighestGPAStudent(list);
    if (student != nullptr)
    {
        return student->gpa;
    }
    return -1;
}
StudentPtr practice02::GetHighestGPAStudent(const List<StudentPtr>* list)
{
    if (list == nullptr) return nullptr;

    const Node<StudentPtr>* current = list->root;
    StudentPtr res = nullptr;
    
    while (current != nullptr)
    {
        if (res == nullptr)
        {
            res = current->data;
        }
        else if (res->gpa < current->data->gpa)
        {
            res = current->data;
        }
        current = current->pNext;
    }
    return res;
}
StudentPtr practice02::GetLowestGPAStudent(const List<StudentPtr>* list)
{
    if (list == nullptr) return nullptr;

    const Node<StudentPtr>* current = list->root;
    StudentPtr res = nullptr;
    
    while (current != nullptr)
    {
        if (res == nullptr)
        {
            res = current->data;
        }
        else if (res->gpa > current->data->gpa)
        {
            res = current->data;
        }
        current = current->pNext;
    }
    return res;
}
StudentPtr practice02::FindStudentById(const List<StudentPtr>* list, const int id) 
{ 
    if (list == nullptr) return nullptr;

    const Node<StudentPtr>* current = list->root;
    
    while (current != nullptr)
    {
        if(current->data->id == id)
        {
            return current->data;
        }
        current = current->pNext;
    }
    return nullptr;
}
void practice02::PrintStudents(const List<StudentPtr>* list)
{
    if (list == nullptr) return;

    Node<Student*>* current = list->root;;
    while (current != nullptr)
    {
        PrintStudent(current->data);
        current = current->pNext;
    }
}