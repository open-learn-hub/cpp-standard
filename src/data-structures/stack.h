#ifndef STACK_H
#define STACK_H
#include <functional>
#include <iostream>

template<typename T>
struct StackNode
{
    T data;
    StackNode<T>* pNext;
};
template<typename T>
using StackNodePtr = StackNode<T>*;

template<typename T>
struct Stack
{
    StackNode<T>* pTop;
};

template<typename T>
using StackPtr = Stack<T>*;

template<typename T>
Stack<T>* CreateStack()
{
    Stack<T>* stack = new Stack<T>();
    stack->pTop = nullptr;
    return stack;
}


template<typename T>
StackNodePtr<T> CreateStackNode(const T value)
{
    StackNode<T>* node = new StackNode<T>();
    node->data = value;
    node->pNext = nullptr;

    return node;
}

template<typename T>
void Push(StackPtr<T> stack, const T value)
{
    StackNodePtr<T> node = CreateStackNode(value);
    if (stack->pTop == nullptr)
    {
        stack->pTop = node;
    }
    else
    {
        node->pNext = stack->pTop;
        stack->pTop = node;
    }
}

template<typename T>
T Pop(StackPtr<T> stack)
{
    StackNodePtr<T> top = stack->pTop;
    if (top == nullptr)
    {
        throw std::exception("Stack is empty");
    }

    T result = top->data;
    stack->pTop = top->pNext;

    delete top;
    top = nullptr;

    return result;
}

template<typename T>
T Peek(StackPtr<T> stack)
{
    return stack->pTop->data;
}

template<typename T>
bool IsEmpty(const StackPtr<T> stack)
{
    return stack->pTop == nullptr;
}

template<typename T>
void Foreach(const StackPtr<T> stack, std::function<void(T)> handler)
{
    if (stack == nullptr || handler == nullptr) return;

    StackNodePtr<T> current = stack->pTop;
    while (current != nullptr)
    {
        handler(current->data);
        current = current->pNext;
    }
}

template<typename T>
int Count(StackPtr<T> stack, std::function<void(T)> handler)
{
    if (stack == nullptr) return 0;

    int count = 0;
    StackNodePtr current = stack->pTop;
    while (current != nullptr)
    {
        if (handler == nullptr || handler(*(current->data)))
        {
            count++;
        }
        current = current->pNext;
    }
    
    return count; 
}

template<typename T>
int Count(const StackPtr<T> stack)
{
    return Count(stack, nullptr);
}

#endif