#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include "core/callback.h"
#include <functional>

using namespace std;

void InitRandomSeed();
int RandRange(int max);
int RandRange(int min, int max);
float RandFloat(float min, float max);

// Array utilities
template<typename T>
void ArrayPrint(const T arr[], const int length)
{
    std::cout << "size: " << length << " [";
    
    
    for (int i = 0 ; i < length; i++)
    {
        std::cout << *(arr + i);
        if (i != length - 1)
        {
            std::cout << ',';
        }
    }
    std::cout << "]" << std::endl;
}

template<typename T>
int ArrayCount(FuncPtr<bool, T> predicate, const T* arr, const int length)
{
   int res = 0;
   for (int i = 0; i < length; i++)
   {
       if (predicate(*(arr + i)))
       {
           res ++;
       }
   }
   return res;
}

template<typename T>
T ArrayFindMinValue(const T* arr, const int length)
{
   int res = INT16_MAX;
   for (int i = 0; i < length; i++)
   {
       T current = *(arr + i);
       if (current < res)
       {
           res = current;
       }
   }
   return res;
}

template<typename T>
T ArrayFindMaxValue(const T* arr, const int length)
{
   int res = INT16_MIN;
   for (int i = 0; i < length; i++)
   {
       T current = *(arr + i);
       if (current > res)
       {
           res = current;
       }
   }
   return res;
}

template<typename T>
T* CreateArrayRevert(const T* arr, const int length)
{
    T* revertedArr = new T[length];
    std::copy(arr, arr + length, revertedArr);

    int halfLength = length / 2;
    for (int i = 0; i < halfLength; i ++)
    {
        T it1 = revertedArr[i];
        T it2 = revertedArr[length - 1 - i];
        // Swap it1 and it2
        T temp = it2;
        revertedArr[length - 1 - i] = it1;
        revertedArr[i] = temp;
    }

    return revertedArr;
}

template<typename T>
T* CreateArrayFromArray(FuncPtr<bool, T> predicate, const T arr[], const int length, int& outNewArrayLength)
{
    int matchCount = 0;
    for (int i = 0; i < length; i++)
    {
        if (predicate(arr[i]))
        {
            matchCount ++;
        }
    }
    outNewArrayLength = matchCount;
    T* newArray = new T[matchCount];
    int idx = 0;
    for (int i = 0; i < length; i++)
    {
        if (predicate(arr[i]))
        {
            newArray[idx] = arr[i];
            idx++;
        }
    }
    
    return newArray;
}

template<typename T>
T* CreateArrayFromArray(const T arr[], const int length, const int fromIndex, const int toIndex, int& outNewArrayLength)
{
    outNewArrayLength = toIndex - fromIndex + 1;
    // Invalid argument
    if (fromIndex < 0 || toIndex >= length || outNewArrayLength < 0) return NULL;
    
    T* newArray = new T[outNewArrayLength];
    int idx = 0;
    for (int i = fromIndex; i >= 0 && i < length && i <= toIndex; i++)
    {
        newArray[idx] = arr[i];
        idx++;
    }
    return newArray;
}

template<typename T>
int ArrayCount(FuncPtr<bool, T> predicate ,const int arr[], const int length, const int fromIndex, const int toIndex)
{
    int res = 0;
    for (int i = fromIndex; i >= 0 && i < length && i < toIndex; i++)
    {
        if (predicate(arr[i]))
        {
            res++;
        }
    }
    return res;
}

template<typename T>
int ArrayCount(std::function<bool(T)> predicate ,const int arr[], const int length, const int fromIndex, const int toIndex)
{
    int res = 0;
    for (int i = fromIndex; i >= 0 && i < length && i < toIndex; i++)
    {
        if (predicate(arr[i]))
        {
            res++;
        }
    }
    return res;
}

template<typename T>
bool ArrayAny(FuncPtr<bool, T> predicate, const T arr[], const int length)
{
    for (int i = 0; i < length; i++)
    {
        if (predicate(arr[i]))
        {
            return true;
        }
    }
    return false;
}

template<typename T>
int ArrayFindIndex(T value, const T arr[], const int length)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
    return -1;
}


int ArrayCount(int value,const int arr[], const int length);

// -- Array utilities
#endif