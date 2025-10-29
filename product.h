#ifndef PRODUCT_H
#define PRODUCT_H


#include<string>
#include"HashTemplate.h"

using std::string;

struct Product {
    string uniqID;
    string productInfo; //the whole string of product information
    DynamicArray<string> categories; // an array of just the categories 

    Product() = default;
};

#endif