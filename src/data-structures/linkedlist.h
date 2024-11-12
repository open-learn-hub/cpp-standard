#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <functional>

using namespace std;

// 1.1.1
template<typename T>
struct Node
{
    T data;
    Node* pNext;
};

// 1.1.2
template<typename T>
struct List
{
    Node<T>* root;
};

// 1.2.2
template<typename T>
Node<T>* CreateNode(T data)
{
    Node<T>* n = new Node<T>();
    n->data = data;
    n->pNext = nullptr;
    return n;
}

// 1.2.1
template<typename T>
List<T>* CreateList()
{
    List<T>* list = new List<T>();
    list->root = nullptr;    
    return list;
}

// 1.5
template<typename T>
List<T>* CreateList(const T arr[], const int length)
{
    List<T>* list = CreateList<T>();
    for (int i = 0; i < length; i++)
    {
        AddTail(list, arr[i]);
    }
    return list;
}

// 1.3
template<typename T>
void AddHead(List<T>* list, T data)
{
    Node<T>* n = CreateNode<T>(data);
    if (list->root == nullptr)
    {
        list->root = n;
    }
    else
    {
        n->pNext = list->root;
        list->root = n;
    }
}

template<typename T>
void AddHead(List<T>* list, Node<T>* n)
{
    if (list->root == nullptr)
    {
        list->root = n;
    }
    else
    {
        n->pNext = list->root;
        list->root = n;
    }
}

// 1.4
template<typename T>
void AddTail(List<T>* list, T data)
{
    Node<T>* n = CreateNode<T>(data);
    if (list->root == nullptr)
    {
        list->root = n;
        return;
    }
    
    // Find tail
    Node<T>* current = list->root;
    while (current != nullptr)
    {
        if (current->pNext == nullptr)
        {
            // Found, then link new item, then break
            current->pNext = n;
            break;
        }
        current = current->pNext;
    }
}

template<typename T>
void AddTail(List<T>* list, Node<T>* n)
{
    if (list->root == nullptr)
    {
        list->root = n;
        return;
    }
    
    // Find tail
    Node<T>* current = list->root;
    while (current != nullptr)
    {
        if (current->pNext == nullptr)
        {
            // Found, then link new item, then break
            current->pNext = n;
            break;
        }
        current = current->pNext;
    }
}

// 1.8
template<typename T>
bool IsEmpty(const List<T>* list)
{
    return list == nullptr || list->root == nullptr;
}

// 1.9
template<typename T>
Node<T>* GetNode(const List<T>* list, const int nodeIndex)
{
    Node<T>* current = list->root;
    int counter = 0;
    while (counter < nodeIndex)
    {
        current = current->pNext;
        counter++;

        if (current == nullptr)
        {
            break;
        }
    }
    return current;
}

// 1.10
template<typename T>
Node<T>* FindNode(const List<T>* list, const T value)
{
    Node<T>* current = list->root;
    
    while (current != nullptr)
    {
        if (current->data == value)
        {
            return current;
        }
        current = current->pNext;
    }
    return nullptr;
}

template<typename T>
Node<T>** FindAll(const List<T>* list, const T value, int& outCount)
{
    Node<T>* current = list->root;
    List<T>* res = CreateList<T>();
    std::function<bool(T)> func = [value](T item)
    {
        return value == item;
    };
    outCount = 0;
    outCount = Count<T>(list, func);
    Node<T>** arr = new Node<T>*[outCount];
    int arrIdx = 0;
    
    while (current != nullptr)
    {
        if (current->data == value)
        {
            arr[arrIdx] = current;
            arrIdx++;
        }
        current = current->pNext;
    }
    return arr;
}

template<typename T>
int Count(List<T>* list, std::function<bool(T)> predicate)
{
    Node<T>* current = list->root;
    int counter = 0;
    while (current != nullptr)
    {
        if (predicate == nullptr || predicate(current->data))
        {
            counter++;
        }
        current = current->pNext;
    }
    return counter;
}

template<typename T>
int Count(List<T>* list)
{
    Node<T>* current = list->root;
    int counter = 0;
    while (current != nullptr)
    {
        counter++;
        current = current->pNext;
    }
    return counter;
}

// 1.6, 1.7
template<typename T>
void PrintList(const List<T>* list)
{
    if (list == nullptr)
    {
        std::cout << "{list null}" << std::endl;
        return;
    }

    bool hasItem = false;
    Node<T>* current = list->root;
    std::cout << "{" << std::endl;
    while (current != nullptr)
    {
        std::cout << "\t[" << current << " : " << current->data << "]" << std::endl;
        current = current->pNext;
        hasItem = true;
    }

    if (!hasItem)
    {
        std::cout << std::endl;
    }
    std::cout << "}" << std::endl;
}

// template<typename T>
// void PrintNodes(Node<T>** arr, const int length)
// {
//     if (arr == nullptr)
//     {
//         std::cout << "{array null}" << std::endl;
//         return;
//     }

//     bool hasItem = false;
//     std::cout << "{" << std::endl;
//     for (int i = 0; i < length; i++)
//     {
//         std::cout << "\t[" << arr[i] << " : " << arr[i]->data << "]" << std::endl;
//         hasItem = true;
//     }
    
//     if (!hasItem)
//     {
//         std::cout << std::endl;
//     }
//     std::cout << "}" << std::endl;
// }

template<typename T>
void PrintNode(const Node<T>* node)
{
    if (node == nullptr)
    {
        std::cout << "[nullptr]" << std::endl; 
        return;
    }

    std::cout << "[" << node << " : " << node->data << "]" << std::endl;
}

#endif