//
// Created by aleks on 11.05.2023.
//
#include <iostream>
#include "tests.h"
#include <cmath>
#include <fstream>
Test :: Test(const int value) {
    amountOfTests = value;
    std :: ofstream new_thread1(R"(D:\\CLionProjects\\bin_tree\\test&answers.txt)");
    srand(time(nullptr));
    keysForInput new_key{keysForInput::arrayKey};
    while(amountOfTests){
        int amountOfNodes = rand() % 11 + 5;
        int arrayOfNodes[amountOfNodes];
        for(int i = 0; i < amountOfNodes; i++){
            arrayOfNodes[i] = rand() % 201 - 100;
        }
        BinTree new_tree(arrayOfNodes, amountOfNodes);
        testCreation(new_tree, arrayOfNodes, amountOfNodes, new_thread1);
        amountOfTests--;
    }
    new_thread1.close();
}

void Test :: testCreation( BinTree &tree, const int * array, const int & arrayDimension, std :: ofstream & new_thread1) {
    int * elementToRemove = new int (array[rand() % arrayDimension]);
    int * elementToSearch = new int (array[rand() % arrayDimension] - rand() % 2);
    int * elementToInsert =  new int (rand() % 100);
    new_thread1 << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    new_thread1 << "Tree :\n";
    tree.print(new_thread1);
    new_thread1 << '\n';
    new_thread1 << "~~Remove " + std::to_string(*elementToRemove) + '\n';
    tree.remove(*elementToRemove);
    tree.print(new_thread1);
    new_thread1 << '\n';
    new_thread1 << "~~Search " + std::to_string(*elementToSearch) + '\n';
    if(tree.search(*elementToSearch, tree.GetRoot())) new_thread1 << "Node found\n";
    else new_thread1 << "Node not found\n";
    new_thread1 << '\n';
    new_thread1 << "~~Insert " + std::to_string(*elementToInsert) + '\n';
    tree.insert(*elementToInsert);
    tree.print(new_thread1);
    new_thread1 << '\n';
}
