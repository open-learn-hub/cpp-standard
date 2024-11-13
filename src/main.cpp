#include <iostream>
#include "core/common.h"
#include "data-structures/practice01.h"
#include "data-structures/practice02.h"

using namespace std;

int main(int argc, char* argv[])
{
    InitRandomSeed();

    int totalPractices = 2;
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

        default:
            std::cout << "Your input is invalid" << std::endl;
            break;
    }
    
    return 0;
}