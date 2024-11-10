#ifndef CALLBACK_H
#define CALLBACK_H

template <typename TRes, typename T>
using FuncPtr = TRes(*)(T); // Single input with a return type

template <typename TRes, typename T>
using ComparerFuncPtr = TRes(*)(T, T); // To compare 2 instances of T, result for this function: 0 mean equal, 1 mean first greater and versus versa

#endif