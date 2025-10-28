#include<iostream>
#include <cstddef>

using std::hash;

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

size_t size() const;
size_t numElements() const;
bool empty();
void push_back(const T& value);
T& operator[](size_t index);     
const T& operator[](size_t index) const; 


};




template <typename K, typename V>
class HashTable {



};