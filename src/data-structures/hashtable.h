#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define TABLE_MAX_SIZE 5

#include "linkedlistdll.h"
#include <functional>
#include <iostream>

template<typename T>
using Bucket = dll::List<T>;

template<typename T>
using BucketPtr = dll::List<T>*;

template<typename T>
BucketPtr<T> CreateBucket()
{
    return new Bucket<T>();
}

template<typename T>
struct HashTable
{
    BucketPtr<T>* buckets;
    std::function<int(int,T)> hashFunction;
    int keySize;
};

template<typename T>
using HashTablePtr = HashTable<T>*;


template<typename T>
HashTablePtr<T> CreateHashTable(std::function<int(int,T)> hashFunction)
{
    HashTablePtr<T> hashtable = new HashTable<T>();
    hashtable->keySize = TABLE_MAX_SIZE;
    hashtable->buckets = new BucketPtr<T>[hashtable->keySize];
    for (int i = 0; i < hashtable->keySize; i ++)
    {
        hashtable->buckets[i] = CreateBucket<T>();
    }
    hashtable->hashFunction = hashFunction;    
    return hashtable;
}

template<typename T>
HashTablePtr<T> CreateHashTable(std::function<int(int,T)> hashFunction, const int keySize)
{
    HashTablePtr<T> hashtable = new HashTable<T>();
    hashtable->buckets = new BucketPtr<T>[keySize];
    for (int i = 0; i < keySize; i ++)
    {
        hashtable->buckets[i] = CreateBucket<T>();
    }
    hashtable->hashFunction = hashFunction;
    hashtable->keySize = keySize;
    return hashtable;
}

template<typename T>
void Add(HashTablePtr<T> table, const T value)
{
    int index = table->hashFunction(table->keySize, value);    
    if (index >= 0 && index < table->keySize)
    {
        dll::Add(table->buckets[index], value);
        return;
    }
    throw std::exception("Failed to calculate hashed index");
}

#endif