//
// Created by aleks on 23.05.2023.
//
#include "tree.h"
#include <stack>
#ifndef BIN_TREE_AVL_TREE_H
#define BIN_TREE_AVL_TREE_H
struct AVL_node{
    int data;
    AVL_node * right;
    AVL_node * left;
    int height;
};
class AVLtree : public tree<AVL_node>{
private:
    void  recursiveFilling(AVL_node * node, AVL_node * buffroot)override;
    AVL_node *  recursiveFillingAVL(AVL_node * node, AVL_node * root);
    AVL_node * balancing(AVL_node * node);
    int getHeight(AVL_node * node);
    int balanceFactor(AVL_node * node);
    void fixHeight(AVL_node* node);
    AVL_node * rightTurn(AVL_node * x);
    AVL_node *  leftTurn(AVL_node * x);
    AVL_node * searchForRemove(int value, AVL_node * root, std :: stack<AVL_node *> & stackForRemove);
    AVL_node * getMinNode(AVL_node * node, std::stack<AVL_node *> & stackForRemove);
public:
    AVLtree(keysForInput new_key);
    AVLtree(const int *arr, const int &demArr);
    void insert (int &value) override;
    void remove(int value) override;
};
#endif //BIN_TREE_AVL_TREE_H
