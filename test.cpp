#include <cassert>
#include <iostream>
#include <string>

#include"HashTemplate.h"
#include"product.h"

int main(void){


Product testProd;
testProd.uniqID = "U284Ba395";
testProd.productInfo = "This is the first test product";
testProd.categories.push_back("Kid's games");
testProd.categories.push_back("Toys");

std::cout << "Product ID: " << testProd.uniqID << std::endl;
std::cout << "Category count: " << testProd.categories.getSize() << std::endl;


}
