#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "core/callback.h"

using namespace std;

struct Employee
{
    string fullName;
    int employeeCode;
    int baseSalary;
    int workDays;
    int earnPerDay;
    int performanceBonusPercent; // eg: 10 for 10%
    int allowancePercent; // eg: 5 for 5%

    int salary; // This is not guaranteed, use CalculateSalary or UpdateSalary before use
};

// Utilities
int CalculateBaseSalary(const Employee* emp);
int CalculateSalary(const Employee* emp);
int CalculateAllowance(const Employee* emp);
int CalculateBonus(const Employee* emp);
void PrintEmployeeWithSalaryRange(const int minSalary, const int maxSalary, const Employee* const* emp, const int length);
Employee* FindEmployeeById(const int id, Employee* const employees[], const int length);
void SortByAcsending(ComparerFuncPtr<int, const Employee*> comparer, Employee** employees, const int length);
void PrintEmployeeInformation(const Employee* emp);
void PrintEmployeeInformation(const Employee* const* employees, const int length);
int SalaryCompare(const Employee* a, const Employee* b);

// -- Utilities

// Write functions 
void UpdateSalary(Employee* emp);
void UpdateAllEmployeesSalary(Employee** const employees, const int length);

// -- Write functions
#endif