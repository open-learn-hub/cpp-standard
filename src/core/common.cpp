#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <math.h>

void InitRandomSeed()
{
    srand (time(NULL));
}

int RandRange(int max)
{
    return rand() % max;
}

int RandRange(int min, int max)
{
    return rand() % abs(max - min) + min;
}

float RandFloat(float min, float max)
{
    return ((float)rand() / (float)RAND_MAX) * (max - min) + min;
}

int ArrayCount(const int value, const int arr[], const int length)
{
    int res = 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == value)
        {
            res ++;
        }
    }
    return res;
}