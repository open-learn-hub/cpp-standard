#include "practice05.h"
#include "hashtable.h"
#include <math.h>
#include "core/common.h"
#include "linkedlistdll.h"
#include <functional>

void ExecutePractice05()
{
    HashTable<int>* table = CreateHashTable<int>(DivideHashFunction);

    // for (int i = 0; i < 10; i ++)
    // {
    //     Add(table, RandRange(20));
    // }
    Add(table, 50);
    Add(table, 73);
    Add(table, 35);
    Add(table, 36);
    Add(table, 64);
    Add(table, -64);
    Add(table, 28);
    Add(table, 90);
    Add(table, 21);
    Add(table, 53);
    Add(table, 13);

    PrintHashTable(table);
}

int DivideHashFunction(int size, const int& value)
{
    return abs(value % size);
}

void PrintHashTable(HashTable<int>* hashtable)
{
    std::function<void(int)> printFunc = [](int value)
    {
        std::cout << "[" << value << "]";
    };
    
    std::cout << "{" << std::endl;
    for (int i = 0; i < TABLE_MAX_SIZE; i++)
    {
        int currentCount = dll::Count(hashtable->buckets[i]);
        if (currentCount > 0)
        {
            std::cout << "\tBucket " << i << ": ";
            dll::Foreach(hashtable->buckets[i], printFunc);
            std::cout << std::endl;
        }
        else
        {
            std::cout << "\tBucket " << i << ": []" << std::endl;
        }
    }
    std::cout << std::endl << "}" << std::endl;
}
