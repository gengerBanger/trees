//
// Created by aleks on 11.05.2023.
//
#ifndef BIN_TREE_TESTS_H
#define BIN_TREE_TESTS_H
#include "bin_tree.h"
class Test{
private:
    void testCreation( BinTree &tree,const int * array, const int & arrayDimension, std :: ofstream & new_thread1);
    int amountOfTests;
public:
    Test(int value);
};
#endif //BIN_TREE_TESTS_H
