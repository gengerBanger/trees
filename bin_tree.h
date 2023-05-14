//
// Created by aleks on 07.05.2023.
//
#include <iostream>
#include <map>
#include <vector>
#ifndef BIN_TREE_BIN_TREE_H
#define BIN_TREE_BIN_TREE_H
struct Node{
    int data;
    Node * right;
    Node * left;
};
class BinTree{
private:
    Node * root = nullptr;
    int amountOfElements = 0;
    int depth = 0;
    std :: map <int, std :: vector< std :: string>> mapOfLevels;
    void mapFilling(Node * buffRoot, int level);
    void mapRemoving();
    int depthCount(Node * root);
    void recursiveFilling(Node * node, Node * buffRoot);
    Node * searchForRemove(int value, Node * node);
    void deleteTree(Node * root);
public:
    BinTree(int key);
    BinTree(const int *arr, const int &demArr);
    ~BinTree();
    Node * GetRoot();
    int GetDepth();
    int GetSize(Node * node);
    Node * getMaxNode(Node * node);
    bool empty();
    void print();
    void print(std :: ofstream & new_thread);
    void insert(int value);
    Node * search(int value, Node * node);
    void remove(int value);
    void straightEnumeration (Node * root);
    void reverseEnumeration(Node * root);
    void symmetricalEnumeration (Node * root);
};
enum class keysForInput{randomKey = 1,consoleKey,fileKey,arrayKey};
#endif //BIN_TREE_BIN_TREE_H