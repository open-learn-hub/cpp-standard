#include <iostream>
#include "core/common.h"
#include "data-structures/practice01.h"
#include "data-structures/practice02.h"
#include "data-structures/practice03.h"
#include "data-structures/practice04.h"

using namespace std;

int main(int argc, char* argv[])
{
    InitRandomSeed();

    ExecutePractice04();
    
    return 0;
}

void Run()
{
    int totalPractices = 3;
    std::cout << "Input Paractice (start from 1) To Run, there're " << totalPractices << " exercise(s)" << std::endl;
    int idx;
    cin >> idx;

    switch (idx)
    {
        case 1:
        practice01::ExecutePractice01();
        break;

        case 2:
        practice02::ExecutePractice02();
        break;

        case 3:
        ExecutePractice03();
        break;

        default:
            std::cout << "Your input is invalid" << std::endl;
            break;
    }
}