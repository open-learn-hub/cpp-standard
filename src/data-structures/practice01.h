#ifndef PRACTICE_01_H
#define PRACTICE_01_H

#include "core/common.h"
#include <math.h>

struct Employee;

namespace practice01
{


    template<typename T>
    T* CreateArray(const int minElement, const int maxElement, int& outLength)
    {
        outLength = RandRange(maxElement - minElement + 1) + minElement;
        return new T[outLength];
    }

    template<typename T>
    void ArrayCountEvenAndOddNumbers(const T arr[], const int length, int& outEvenCount, int& outOddCount)
    {
        outEvenCount = 0;
        outOddCount = 0;
        for (int i = 0; i < length; i++)
        {
            int numAsInt = (int)*(arr + i);
            if (numAsInt % 2 == 0)
            {
                outEvenCount ++;
            }
            else
            {
                outOddCount ++;
            }
        }
    }

    void Exercise01();
    void Exercise02();
    void Exercise03();
    void ExecutePractice01();

    // Exercise 01
    void FillArrayRandomly(int arr[], const int length, const int minValue, const int maxValue);
    void FillArrayRandomly(float arr[], const int length, const float minValue, const float maxValue);

    int ArraySum(const int arr[], const int length);
    int ArrayMultiple(const int arr[], const int length);
    void SumAndMultiple(const int arr[], const int length, int& outSum, int& outMultiple);

    // Exercise 02
    float* CreateExercise02Array(int& length);

    template<typename T>
    bool IsAllPositiveNumber(const T* arr, const int length)
    {
        FuncPtr<bool, T> isNegative = [](T num)
        {
            return num < 0;
        };
        return ArrayAny(isNegative, arr, length) == false;
    }

    template<typename T>
    T ArraySumGeneric(const T* arr, const int length)
    {
        T sum = 0;
        for (int i = 0; i < length; i++)
        {
            sum += *(arr + i);
        }
        
        return sum;
    }

    template<typename T>
    bool IsSymmetry(const T arr[], const int length)
    {
        int halfLength = length / 2;

        for (int i = 0; i < halfLength; i++)
        {
            if (arr[i] != arr[length - i - 1]) return false;
        }

        return true;
    }

    template<typename T>
    bool IsPrimeNumber(T number)
    {
        if (number < 0) return false;

        int numAsInt = (int)number;
        // to support decimal numbers
        bool isInteger = abs(number - numAsInt) <= std::numeric_limits<T>::epsilon();

        if (isInteger)
        {
            if (numAsInt <= 1) return false;

            if (numAsInt == 2) return true;

            for (int i = 2; i < numAsInt; i++)
            {
                if (numAsInt % i == 0) return false;
            }

            return true;
        }
        return false;
    }

    template<typename T>
    bool IsPerfectSquareNumber(T number)
    {
        if (number < 0) return false;

        int numAsInt = (int)number;
        // to support decimal numbers
        bool isInteger = abs(number - numAsInt) <= std::numeric_limits<T>::epsilon();

        if (isInteger)
        {
            return pow((int)sqrt(numAsInt), 2) == numAsInt;
        }
        return false;
    }

    // Exercise 03
    Employee** CreateEmployeeArray(int& outLength);
    int CalculateCompanySalaryCost(const Employee* const* employees, const int length);
    int CalculateLowSalaryCost(const Employee* const* employees, const int length);
}

#endif
