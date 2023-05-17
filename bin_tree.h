//
// Created by aleks on 07.05.2023.
//
#include <iostream>
#include <map>
#include <vector>
#include "tree.h"
#ifndef BIN_TREE_BIN_TREE_H
#define BIN_TREE_BIN_TREE_H
struct Node{
    int data;
    Node * right;
    Node * left;
};
enum class keysForInput{randomKey = 1,consoleKey,fileKey};
class BinTree : public tree<Node> {
private:
    /*Node * root = nullptr;
    int amountOfElements = 0;
    int depth = 0;*/
    /*std :: map <int, std :: vector< std :: string>> mapOfLevels;*/
    /*void mapFilling(Node * buffRoot, int level);
    void mapRemoving();
    int depthCount(Node * root);*/
    void recursiveFilling(Node * node, Node * buffRoot) override;
    /*Node * searchForRemove(int value, Node * node);
    void deleteTree(Node * root);*/
public:
    BinTree(keysForInput new_key);
    BinTree(const int *arr, const int &demArr);
    ~BinTree();
    /*Node * GetRoot();
    int GetDepth();
    int GetSize(Node * node);
    Node * getMaxNode(Node * node);
    bool empty();*/
    void print() override;
    void print(std :: ofstream & new_thread)override;
    void insert(int value)override;
    Node * search(int value, Node * node)override;
    void remove(int value)override;
    void straightEnumeration (Node * root);
    void reverseEnumeration(Node * root);
    void symmetricalEnumeration (Node * root);
};

#endif //BIN_TREE_BIN_TREE_H
