//
// Created by aleks on 11.05.2023.
//
#ifndef BIN_TREE_TESTS_H
#define BIN_TREE_TESTS_H
#include <cmath>
#include <fstream>
template <typename Type>
class Test{
private:
    void testCreation(Type &Tree, const int * array, const int & arrayDimension, std :: ofstream & new_thread1) {
        int * elementToRemove = new int (array[rand() % arrayDimension]);
        int * elementToSearch = new int (array[rand() % arrayDimension] - rand() % 2);
        int * elementToInsert =  new int (rand() % 100);
        new_thread1 << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        new_thread1 << "Tree :\n";
        Tree.print(new_thread1);
        new_thread1 << '\n';
        new_thread1 << "~~Remove " + std::to_string(*elementToRemove) + '\n';
        Tree.remove(*elementToRemove);
        Tree.print(new_thread1);
        new_thread1 << '\n';
        new_thread1 << "~~Search " + std::to_string(*elementToSearch) + '\n';
        if(Tree.search(*elementToSearch, Tree.GetRoot())) new_thread1 << "Node found\n";
        else new_thread1 << "Node not found\n";
        new_thread1 << '\n';
        new_thread1 << "~~Insert " + std::to_string(*elementToInsert) + '\n';
        Tree.insert(*elementToInsert);
        Tree.print(new_thread1);
        new_thread1 << '\n';
        delete elementToInsert;
        delete elementToSearch;
        delete elementToRemove;
    }
    int amountOfTests;
public:
    Test(const int value) {
        amountOfTests = value;
        std :: ofstream new_thread1(R"(D:\\CLionProjects\\bin_tree\\test&answers.txt)");
        srand(time(nullptr));
        while(amountOfTests){
            int amountOfNodes = rand() % 11 + 5;
            int arrayOfNodes[amountOfNodes];
            for(int i = 0; i < amountOfNodes; i++){
                arrayOfNodes[i] = rand() % 201 - 100;
            }
            Type new_tree(arrayOfNodes, amountOfNodes);
            testCreation(new_tree, arrayOfNodes, amountOfNodes, new_thread1);
            amountOfTests--;
        }
        new_thread1.close();
    }
};
#endif //BIN_TREE_TESTS_H
