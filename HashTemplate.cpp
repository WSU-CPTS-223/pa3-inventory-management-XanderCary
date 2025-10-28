#include"HashTemplate.h"

template <typename T>
DynamicArray<T>::DynamicArray(){
data = nullptr;
numElements = 0;
size = 0;
}

template <typename T>
DynamicArray<T>::~DynamicArray(){
    //I will add to this later 
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& other){
numElements = other.numElements
size = other.size  //copy numElements and size then make new array to begin copying
data = new T[size];
for(size_t i = 0; i < numElements; ++i){
    data[i] = other.data[i] //loop through and copy 
}
}

template <typename T>
DynamicArray<T>::DynamicArray(DynamicArray&& other){
//make shallow copy
size = other.size;
data = other.data;
numElements = other.numElements
//reset other 
other.data = nullptr;
other.size = 0;
other.numElements = 0;
}

