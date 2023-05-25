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
class BinTree : public tree<Node> {
private:
    void recursiveFilling(Node * node, Node * buffRoot) override;
public:
    BinTree(keysForInput new_key);
    BinTree(const int *arr, const int &demArr);
    void insert(int &value)override;
    void straightEnumeration (Node * root);
    void reverseEnumeration(Node * root);
    void symmetricalEnumeration (Node * root);
};
#endif //BIN_TREE_BIN_TREE_H
