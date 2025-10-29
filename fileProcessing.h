#ifndef FILEPROCESSING_H
#define FILEPROCESSING_H

#include<string>
#include"HashTemplate.h"
#include"product.h"

using std::string;

class fileProcessor {
public:
    void loadInventory(const string&filename, HashTable<string, Product>& idTable, HashTable<string, DynamicArray<Product*>>& categoryTable) const;
private:
    void parseCategories(const string* categorys, Product& product) const;

};



#endif