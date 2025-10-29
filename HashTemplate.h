#ifndef HASHTEMPLATE_H
#define HASHTEMPLATE_H

#include<iostream>
#include <cstddef>
#include"product.h"

using std::hash;
using std::pair;

//Dynamic array
template <typename T>
class DynamicArray {
private:


T* data; // what is actually in the index
size_t numElements; // number of elements in the array
size_t size; // total capasity 

void resize(size_t newsize); //for resizing the array when the load factor > .7 

public:

//Constructor Destructor copy constructor and mover
DynamicArray();
~DynamicArray();
DynamicArray(const DynamicArray& other);
DynamicArray(DynamicArray&& other);

//assigment operators
DynamicArray& operator=(const DynamicArray& other);
DynamicArray& operator=(DynamicArray&& other);

size_t getSize() const;
size_t getNumElements() const;
bool empty();
void push_back(const T& value);
T& operator[](size_t index);     
const T& operator[](size_t index) const; 


};




template <typename K, typename V>
class HashTable {
private:

DynamicArray<DynamicArray<pair<K, V>>> table;

size_t numElements;
float maxLoadFactor;
size_t getIndex(const K& key) const;
void rehash();

public:

HashTable(size_t startSize = 10);
~HashTable();

void insert(const K& key, const V& value);
bool find(const K& key, V& value) const;

float loadFactor() const;
size_t getNumElements() const;
size_t getSize();


};

#endif //HASHTEMPLATE_H