//
// Created by aleks on 17.05.2023.
//

#include "RedBlack_tree.h"
void RedBlackTree ::recursiveFilling(RB_node *node, RB_node *buffRoot) {
    if(buffRoot){
        if(node->data > buffRoot->data){
            if(buffRoot->right != nullptr) recursiveFilling(node, buffRoot->right);
            else {
                node->color = 1;
                buffRoot->right = node;
                balancing(this->root);
            }
        }
        if(node->data < buffRoot->data) {
            if (buffRoot->left != nullptr)recursiveFilling(node, buffRoot->left);
            else{
                node->color = 1;
                buffRoot->left = node;
                balancing(this->root);
            }
        }
    }
    else {
        node->color = -1;
        root = node;
    }
}
void RedBlackTree ::balancing(RB_node * root) {
    if(((root->left && root->left->color == -1) || (!root->left)) && root->right &&root->right->color == 1){
        rightTurn(root);
    }
    if(root->left && root->left->color == 1 && root->left->left && root->left->left->color == 1){
        leftTurn(root);
    }
    if(root->left && root->left->color == 1 && root->right && root->right->color == 1){
        if(this->root != root) root->color *= -1;
        root->left->color *= -1;
        root->right->color *= -1;
    }
    balancing(root->left);
    balancing(root->right);
}
void RedBlackTree::rightTurn(RB_node * node) {
    RB_node ** buff = new RB_node * (node);
    node = node->left;
    node->left = *buff;
    delete buff;
}
void RedBlackTree::leftTurn(RB_node * node) {
    RB_node ** buff = new RB_node * (node);
    node = node->right;
    node->left = *buff;
    delete buff;
}
