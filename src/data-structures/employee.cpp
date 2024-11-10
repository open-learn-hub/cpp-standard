#include "employee.h"
#include <iostream>
#include <math.h>

int CalculateBaseSalary(const Employee* emp)
{
    return emp->baseSalary + emp->earnPerDay * emp->workDays;
}

int CalculateSalary(const Employee* emp)
{
    return CalculateBaseSalary(emp) + CalculateAllowance(emp) + CalculateBonus(emp);
}

int CalculateAllowance(const Employee* emp)
{
    int baseSalary = CalculateBaseSalary(emp);
    if (baseSalary < 5000)
    {
        float allowance = baseSalary * (emp->allowancePercent / 100.0f);
        return round(allowance);
    }
    return 0;
}

int CalculateBonus(const Employee* emp)
{
    int baseSalary = CalculateBaseSalary(emp);
    if (baseSalary >= 8000)
    {
        float bonus = baseSalary * (emp->performanceBonusPercent / 100.0f);
        return round(bonus);
    }
    return 0;
}

void PrintEmployeeWithSalaryRange(const int minSalary, const int maxSalary, const Employee* const* emp, const int length)
{
    for (int i = 0; i < length; i++)
    {
        const Employee* e = emp[i];
        int salary = CalculateSalary(e);
        if (salary <= maxSalary && salary >= minSalary)
        {
            PrintEmployeeInformation(e);
        }
    }
}

Employee* FindEmployeeById(const int id, Employee* const employees[], const int length)
{
    for (int i = 0; i < length; i++)
    {
        if (employees[i]->employeeCode == id)
        {
            return employees[i];
        }
    }
    return NULL;
}

void PrintEmployeeInformation(const Employee* emp)
{
    std::cout << "[Employee]" 
    << " Id: " << emp->employeeCode
    << " Name: " << emp->fullName
    << " Dayworks: " << emp->workDays
    << " Salary: " << CalculateSalary(emp)
    << std::endl;
}

void PrintEmployeeInformation(const Employee* const* emp, const int length) 
{
    for (int i = 0; i < length; i++)
    {
        std::cout << "No." << (i + 1) << " ";
        PrintEmployeeInformation(emp[i]);
    }
}

void UpdateSalary(Employee* emp)
{
    emp->salary = CalculateSalary(emp);
}

void UpdateAllEmployeesSalary(Employee** const employees, const int length)
{
    for (int i = 0; i < length; i++)
    {
        UpdateSalary(employees[i]);
    }
    std::cout << "Employees Salary have been updated !" << std::endl;
}

int SalaryCompare(const Employee* a, const Employee* b)
{
    int aSalary = CalculateSalary(a);
    int bSalary = CalculateSalary(b);

    if (aSalary > bSalary) return 1;
    if (aSalary < bSalary) return -1;
    return 0;
}

void SortByAcsending(ComparerFuncPtr<int, const Employee*> comparer, Employee** employees, const int length)
{
    // Using linear sort
    int sortingIdx = 0;
    for (int i = 0; i < length; i ++)
    {
        for (int j = sortingIdx; j < length; j++)
        {
            int compareRes = comparer(employees[sortingIdx], employees[j]);
            if (compareRes > 0)
            {
                Employee* temp = employees[j];
                employees[j] = employees[sortingIdx];
                employees[sortingIdx] = temp;
            }
        }
        sortingIdx++;
    }
}