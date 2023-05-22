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
    RB_node * parent;
    int color;
};
class RedBlackTree : public tree<RB_node>{
private:
    void recursiveFilling(RB_node * node, RB_node * buffRoot) override;
    void balancing(RB_node * node);
    void rebalancingL(RB_node * node);
    void rebalancingR(RB_node * node);
    void rightTurn1(RB_node * node);
    void rightTurn2(RB_node * node);
    void leftTurn1(RB_node * node);
    void leftTurn2(RB_node * node);
    void rightTurnDel(RB_node * node);
    void leftTurnDel(RB_node * node);
public:
    RedBlackTree(keysForInput new_key);
    RedBlackTree(const int *arr, const int &demArr);
    ~RedBlackTree();
    void insert (int &value) override;
    void remove(int value) override;
};
#endif //BIN_TREE_REDBLACK_TREE_H
