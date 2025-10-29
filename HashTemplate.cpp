
#include"HashTemplate.h"


using std::hash;
using std::move;

//DynamicArray functions

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

template <typename T>
void DynamicArray<T>::resize(size_t newsize){
//creat new array
T* newArr = new T[newsize];

//copy over elements 
for(size_t i = 0; i < numElements; ++i){
    newArr[i] = std::move(data[i]) //loop through and copy 
}
//delete old array
delete[] data;

//update 
data = newArr;
size = newsize;

}

//assigment operators
template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other){

//free whatever data is already there
delete[] data;

//copy main attributes
numElements = other.numElements;
size = other.size;

data = new T[size];

//copy over indivdual elements
for(size_t i = 0; i < numElements; ++i){
    data[i] = other.data[i] //loop through and copy 
}

return *this;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(DynamicArray<T>&& other) {
//free whatever data is already there
delete[] data;

//copy everything
numElements = other.numElements;
size = other.size;
data = other.data;

//empty other array
other.data = nullptr;
other.size = 0;
other.numElements = 0;

return *this;

}


template <typename T>
size_t DynamicArray<T>::getSize() const{
return size;
}


template <typename T>
size_t DynamicArray<T>::getNumElements() const {
    return numElements;
}


template <typename T>
bool DynamicArray<T>::empty(){
    return if(numElements == nullptr);
}

template <typename T>
void DynamicArray<T>::push_back(const T&value){

    //check if resize is needed
    if((numElements + 1) >= size){
        resize(size * 2);
    }
    //add to next avaliable slot
    data[numElements] = value;

    //increase number of elements in array
    ++numElements;

}

//So we can use array indexing for our class
template <typename T>
T& DynamicArray<T>::operator[](size_t index) {    // NO trailing const here
    return data[index];
}

template <typename T>
const T& DynamicArray<T>::operator[](size_t index) const { // trailing const here
    return data[index];
}

//Start of HashTable functions

template<typename K, typename V>
HashTable<K, V>::~HashTable(){

}

template<typename K, typename V>
void HashTable<K, V>::rehash(){
    size_t newSize = table.size() * 2;
    DynamicArray<pair<K, V>> newArr;
    newArr.resize(newSize);
    for(size_t i = 0; i < size){
      DynamicArray<pair<K, V>>& oldArr = table[i];
     for(size_t j = 0; j < oldArr.size(); ++j){
         const K& key = oldArr[j].first;
         const V& key = oldArr[j].second;

         size_t newIndex = hash,K.{}(key) % newSize;
         newArr[newIndex].push_back({key, value});
      }
    }
    table = move(newArr);
}

template<typename K, typename V>
float HashTable<K, V>::loadFactor() const{
return static_cast<float>(numElements)/size;
}



template<typename K, typename V>
void HashTable<K, V>::insert(const K& key, const V& value){
    //hash to find index
    size_t index = hash<K>{}(key) % table.size;
    //make sure this isnt already in the table
    DynamicArray<pair<K, V>>& bucket = table[index];
    for(size_t i = 0; i < bucket.size(); ++i){
        if(bucket[i].first == key){
            bucket[i].second = value;
            return;
        }
    }
    //no dupes found
    bucket.push_back({key, value});
    ++numElements;

    //check load facotor wasnt exceeded
    if(loadFactor() > maxLoadFactor){
        rehash();
    }

}

template<typename K, typename V>
bool HashTable<K, V>::find(const K& key, V& value) const{
    size_t index = hash<K>{}(key) % table.size(); // find the index the id would be at
    DynamicArray<pair<K,V>>& traversal = table[index];
    for(size_t i = 0; i < traversal; ++i){
        if(traversal[i].first == key) {
            value = traversal[i].second;
            return true;
        }
    }
    return false;
}


template<typename K, typename V>
size_t HashTable<K, V>::getSize() {
    return size;
}

template<typename K, typename V>
size_t HashTable<K, V>::getNumElements() const {
    return numElements;
}

