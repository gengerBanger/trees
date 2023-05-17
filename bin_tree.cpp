//
// Created by aleks on 07.05.2023.
//

#include "bin_tree.h"
#include <iostream>
#include <cmath>
#include <fstream>
void BinTree ::  recursiveFilling(Node * node, Node * buffRoot){ // filling in the tree
    if(buffRoot){
        if(node->data > buffRoot->data){
            if(buffRoot->right != nullptr) recursiveFilling(node, buffRoot->right);
            else buffRoot->right = node;
        }
        if(node->data < buffRoot->data) {
            if (buffRoot->left != nullptr)recursiveFilling(node, buffRoot->left);
            else buffRoot->left = node;
        }
    }
    else root = node;
}
BinTree :: BinTree (keysForInput new_key){
    switch (new_key) {
        case keysForInput::randomKey:{
            int * amountOfNodes = new int();
            srand(time(nullptr));
            std :: cout << "\t~~Enter the amount of nodes~~\n";
            std :: cin >> *amountOfNodes;
            while(*amountOfNodes){
                Node *item = new Node;
                item->right = nullptr, item->left = nullptr, item->data = rand() % 100;
                recursiveFilling(item, root);
                (*amountOfNodes)--;
            }
            delete amountOfNodes;
            depth = depthCount(root) + 1;
            amountOfElements = GetSize(GetRoot());
            break;
        }
        case keysForInput::consoleKey:{
            int * value = new int;
            while(std :: cin >> *value) {
                Node *item = new Node;
                item->right = nullptr, item->left = nullptr, item->data = *value;
                recursiveFilling(item, root);
            }
            delete value;
            depth = depthCount(root) + 1;
            amountOfElements = GetSize(GetRoot());
            break;
        }
        case keysForInput::fileKey:{
            int * amountOfNodes = new int();
            srand(time(nullptr));
            std :: ifstream new_thread;
            new_thread.open(R"(D:\\CLionProjects\\bin_tree\\bin_tree.txt)");
            std :: cout << "\t~~Enter the amount of nodes~~\n";
            std :: cin >> *amountOfNodes;
            while(*amountOfNodes){
                Node *item = new Node;
                item->right = nullptr, item->left = nullptr,  new_thread >> item->data;
                recursiveFilling(item, root);
                (*amountOfNodes)--;
            }
            delete amountOfNodes;
            new_thread.close();
            depth = depthCount(root) + 1;
            amountOfElements = GetSize(GetRoot());
            break;
        }
    }
}
BinTree::BinTree(const int *arr, const int &demArr) {
    int * value = new int;
    for(int i = 0; i < demArr;i++){
        Node *item = new Node;
        item->right = nullptr, item->left = nullptr, item->data = arr[i];
        recursiveFilling(item, root);
    }
    delete value;
    depth = depthCount(root) + 1;
    amountOfElements = GetSize(GetRoot());
}
BinTree :: ~BinTree(){
    deleteTree(root);
}
void BinTree ::insert(int value) { // inserting a new node
    Node *new_node = new Node;
    new_node->data = value;
    new_node->left = new_node->right = nullptr;
    recursiveFilling(new_node,root);
    depth = depthCount(root) + 1;
}

void BinTree :: straightEnumeration(Node * root) {
    if(root){
        std :: cout << std::to_string(root->data) + ' ';
        straightEnumeration(root->left);
        straightEnumeration(root->right);
    }
}
void BinTree :: reverseEnumeration(Node * root) {
    if(root){
        straightEnumeration(root->left);
        straightEnumeration(root->right);
        std :: cout << std::to_string(root->data) + ' ';
    }
}
void BinTree ::symmetricalEnumeration(Node * root) {
    if(root){
        straightEnumeration(root->left);
        std :: cout << std::to_string(root->data) + ' ';
        straightEnumeration(root->right);
    }
}

