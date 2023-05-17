//
// Created by aleks on 17.05.2023.
//
#include "tree.h"
#ifndef BIN_TREE_REDBLACK_TREE_H
#define BIN_TREE_REDBLACK_TREE_H
struct RB_node{
    int data;
    RB_node * right;
    RB_node * left;
    int color;
};
class RedBlackTree : public tree<RB_node>{
private:
    void recursiveFilling(RB_node * node, RB_node * buffRoot) override;
    void balancing(RB_node * node);
    void rightTurn(RB_node * node);
    void leftTurn(RB_node * node);
public:
    RedBlackTree();
    ~RedBlackTree();

};
#endif //BIN_TREE_REDBLACK_TREE_H
