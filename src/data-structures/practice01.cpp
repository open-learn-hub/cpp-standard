#include "core/common.h"
#include "practice01.h"
#include <iostream>
#include "core/callback.h"
#include "data-structures/employee.h"

using namespace practice01;

void practice01::FillArrayRandomly(int arr[], const int length, const int minValue, const int maxValue)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = RandRange(minValue, maxValue);
    }
    
}

int practice01::ArraySum(const int arr[], const int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += *(arr + i);
    }
    
    return sum;
}

int practice01::ArrayMultiple(const int arr[], const int length)
{
    int res = 0;
    for (int i = 0; i < length; i++)
    {
        if (i == 0)
        {
            res = *(arr + i);
        }
        else
        {
            res *= *(arr + i);
        }
    }
    return res;
}

void practice01::SumAndMultiple(const int arr[], const int length, int& outSum, int& outMultiple)
{
    outSum = ArraySum(arr, length);
    outMultiple = ArrayMultiple(arr, length);    
}

void practice01::FillArrayRandomly(float arr[], const int length, const float minValue, const float maxValue)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = RandFloat(minValue, maxValue);
    }
}

void practice01::Exercise01()
{
    std::cout << "Start Exercise 01" << std::endl;
    // 1.1
    int arrayLength = 0;
    int* array = CreateArray<int>(10, 20, arrayLength);
    FillArrayRandomly(array, arrayLength, -268, 339);

    // 1.2
    ArrayPrint<int>(array, arrayLength);

    // 1.3
    std::cout << "Array sum = " << ArraySum(array, arrayLength) << std::endl;

    // 1.4
    int outSum, outMultiple;
    SumAndMultiple(array, arrayLength, outSum, outMultiple);
    std::cout << "Array sum = " << outSum << " Multiple = " << outMultiple << std::endl;

    // 1.5 count X
    int x = array[RandRange(arrayLength)];
    int count = ArrayCount(x, array, arrayLength);
    std::cout << "There're " << count << " time(s) the " << x << " appears in the array" << std::endl;

    
    // 1.6
    float* fArray = CreateArray<float>(10, 20, arrayLength);
    FillArrayRandomly(fArray, arrayLength, -5.0f, 10.0f);
    ArrayPrint<float>(fArray, arrayLength);

    int evenCount, oddCount;
    ArrayCountEvenAndOddNumbers(fArray, arrayLength, evenCount, oddCount);
    std::cout << "The array contains " << evenCount << " even number(s) and " << oddCount << " odd number(s)." << std::endl;

    // 1.7
    std::cout << "The min value in the array is " << ArrayFindMinValue(fArray, arrayLength) << std::endl;

    // 1.8
    float* revertedArr = CreateArrayRevert(fArray, arrayLength);
    std::cout << "The reveted array is below" << std::endl;
    ArrayPrint(revertedArr, arrayLength); 

    // 1.9
    FuncPtr<bool, float> isNegativeFunc = [](float it)
    {
        return it < 0.0f;
    };
    int negativeArrLength = 0;
    float* negativeArr = CreateArrayFromArray(isNegativeFunc, fArray, arrayLength, negativeArrLength);
    std::cout << "The negative values in the array are below" << std::endl;
    ArrayPrint(negativeArr, negativeArrLength);

    // 1.10
    std::cout << "The 1.9, I'm going to use integer array for easier observe, the array is below" << std::endl;
    arrayLength = 0;
    array = CreateArray<int>(10, 20, arrayLength);
    FillArrayRandomly(array, arrayLength, -5, 5);
    ArrayPrint(array, arrayLength);

    x = array[RandRange(arrayLength)];
    // To support capture value
    std::function<bool(int)> isMatchFunc = [x](int input)
    {
        return input == x;
    };
    int rangeX = RandRange(0, arrayLength / 3);
    int rangeY = RandRange(arrayLength / 3, arrayLength);

    count = ArrayCount(isMatchFunc, array, arrayLength, rangeX, rangeY);
    std::cout << "There're " << count << " time(s) the " << x << " appears in the array range [" << rangeX << "," << rangeY << "]" << std::endl;

    // 1.11
    // To support capture value
    int subArrayLength = 0;
    int* subArray = CreateArrayFromArray(array, arrayLength, rangeX, rangeY, subArrayLength);
    std::cout << "The Sub Array is created in the array range [" << rangeX << "," << rangeY << "]" << std::endl;
    ArrayPrint(subArray, subArrayLength);

    std::cout << "Completed Exercise 01" << std::endl;
}

float* practice01::CreateExercise02Array(int& length)
{
    length = 10;
    return new float[length] { 0.8f, 5.6f, 9.1f, 7.3f, 10.0f, 5.9f, 7.2f, 9.3f, 8.0f, 8.7f };
}

void practice01::Exercise02()
{
    std::cout << "Start Exercise 02" << std::endl;

    // 2.1
    int length = 0;
    float* fArray = CreateExercise02Array(length);

    // 2.2
    ArrayPrint(fArray, length);

    // 2.3
    std::string msg = IsAllPositiveNumber<float>(fArray, length) ? "True" : "False";
    std::cout << "Is the array contains all positive numbers? : " << msg << std::endl;

    // The 2.4 2.5 do not exist

    // 2.6
    msg = IsSymmetry(fArray, length) ? "True" : "False";
    std::cout << "Is the array symmetry? : " << msg << std::endl;

    // 2.7.1
    int primeCount = ArrayCount(IsPrimeNumber, fArray, length);
    std::cout << "There's " << primeCount << " prime number(s) in the array" << std::endl;

    // 2.7.2
    int perfectSquareCount = ArrayCount(IsPerfectSquareNumber, fArray, length);
    std::cout << "There's " << perfectSquareCount << " perfect square number(s) in the array" << std::endl;

    // 2.8
    float numberToFind = 8.0f;
    int foundIndex = ArrayFindIndex(numberToFind, fArray, length);
    if (foundIndex < 0)
    {
        std::cout << "The " << numberToFind << " does not exsit in the array." << std::endl;
    }
    else
    {
        std::cout << "The " << numberToFind << " is found at index " << foundIndex << " in the array." << std::endl;
    }

    // 2.9
    int primeArrayLength = 0;
    float* primeArray = CreateArrayFromArray(IsPrimeNumber, fArray, length, primeArrayLength);
    std::cout << "Prime Array is below" << std::endl;
    ArrayPrint(primeArray, primeArrayLength);

    // 2.10
    int perfectSquareArrayLength = 0;
    float* perfectSquareArray = CreateArrayFromArray(IsPerfectSquareNumber, fArray, length, perfectSquareArrayLength);
    std::cout << "Perfect Square Array is below" << std::endl;
    ArrayPrint(perfectSquareArray, perfectSquareArrayLength);

    // 2.11
    FuncPtr<bool, float> isNegativeFunc = [](float it)
    {
        return it < 0.0f;
    };
    int negativeArrLength = 0;
    float* negativeArr = CreateArrayFromArray(isNegativeFunc, fArray, length, negativeArrLength);
    std::cout << "The negative values in the array are below" << std::endl;
    ArrayPrint(negativeArr, negativeArrLength);

    // 2.12
    FuncPtr<bool, float> isPositiveFunc = [](float it)
    {
        return it >= 0.0f;
    };
    int positiveArrLength = 0;
    float* positiveArr = CreateArrayFromArray(isPositiveFunc, fArray, length, positiveArrLength);
    std::cout << "The positive values in the array are below" << std::endl;
    ArrayPrint(positiveArr, positiveArrLength);
    std::cout << "Sum all positive number is: " << ArraySumGeneric(positiveArr, positiveArrLength) << std::endl;

    // 2.13
    float* reveredArray = CreateArrayRevert(fArray, length);
    std::cout << "The reverted array is below" << std::endl;
    ArrayPrint(reveredArray, length);


    std::cout << "Completed Exercise 02" << std::endl;
}

void practice01::Exercise03()
{
    std::cout << "Start Exercise 03" << std::endl;

    // 3.1
    int empLength = 0;
    Employee** employees = CreateEmployeeArray(empLength);

    // 3.2
    std::cout << "We have " << empLength << " employees in total, they are:" << std::endl;
    PrintEmployeeInformation(employees, empLength);

    // 3.3
    UpdateAllEmployeesSalary(employees, empLength);

    // 3.4
    std::cout << "Company Salary Cost: " << CalculateCompanySalaryCost(employees, empLength) << std::endl;
    
    // 3.5
    std::cout << "Company Low Salary Cost: " << CalculateLowSalaryCost(employees, empLength) << std::endl;

    // 3.6
    int employeeId2Find = RandRange(empLength);
    Employee* foundEmp = FindEmployeeById(employeeId2Find, employees, empLength);
    if (foundEmp == NULL)
    {
        std::cout << "Could not found employee with id " << employeeId2Find << std::endl;    
    }
    else
    {
        std::cout << "Found employee with id " << employeeId2Find << std::endl;
        PrintEmployeeInformation(foundEmp);
    }

    // 3.7
    SortByAcsending(SalaryCompare, employees, empLength);
    
    std::cout << "Sorted Employees by salary acseding" << std::endl;
    PrintEmployeeInformation(employees, empLength);

    std::cout << "Sorted Employees by salary desceding" << std::endl;
    PrintEmployeeInformation(CreateArrayRevert(employees, empLength), empLength);

    std::cout << "Completed Exercise 03" << std::endl;
}

Employee** practice01::CreateEmployeeArray(int& outLength)
{
    outLength = 10;
    Employee** arr = new Employee*[outLength];
    for (int i = 0; i < outLength; i++)
    {
        Employee* e = new Employee();
        e->employeeCode = i + 1;
        e->performanceBonusPercent = 10;
        e->allowancePercent = 5;
        e->earnPerDay = 180;
        e->baseSalary = 1800;
        e->fullName = "Employee " + std::to_string(i + 1);
        e->workDays = RandRange(14, 30);
        arr[i] = e;
    }
    return arr;
}

int practice01::CalculateCompanySalaryCost(const Employee* const* employees, const int length)
{
    int res = 0;
    for (int i = 0; i < length; i++)
    {
        res += CalculateSalary(employees[i]);
    }
    return res;
}

int practice01::CalculateLowSalaryCost(const Employee* const* employees, const int length)
{
    int res = 0;
    for (int i = 0; i < length; i++)
    {
        int salary = CalculateSalary(employees[i]);
        if (salary < 5000) // low cost
        {
            res += salary;
        }
    }
    return res;
}

void practice01::ExecutePractice01()
{
    int totalExercises = 3;
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
        
        case 3:
        Exercise03();
        break;

        default:
            std::cout << "Your input is invalid" << std::endl;
            break;
    }   
}