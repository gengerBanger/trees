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
    if(root){
        if(((root->left && root->left->color == -1) || (!root->left)) && root->right &&root->right->color == 1){
            leftTurn(root);
        }
        if(root->left && root->left->color == 1 && root->left->left && root->left->left->color == 1){
            rightTurn(root);
        }
        if(root->left && root->left->color == 1 && root->right && root->right->color == 1){
            if(this->root != root) root->color *= -1;
            root->left->color *= -1;
            root->right->color *= -1;
        }
        balancing(root->left);
        balancing(root->right);
    }
}
void RedBlackTree::rightTurn(RB_node * node) {
    RB_node ** buff = new RB_node * (node);
    node = node->left;
    node->color *= -1;
    node->right = *buff;
    node->right->color *= -1;
    node->right->left = nullptr;
    delete buff;
}
void RedBlackTree::leftTurn(RB_node * node) {
    RB_node ** buff = new RB_node * (node);
    node = node->right;
    node->color *= -1;
    node->left = *buff;
    node->left->color *= -1;
    node->left->right = nullptr;
    delete buff;
}
RedBlackTree::RedBlackTree (keysForInput new_key){
    switch (new_key) {
        case keysForInput::randomKey:{
            int * amountOfNodes = new int();
            srand(time(nullptr));
            std :: cout << "\t~~Enter the amount of nodes~~\n";
            std :: cin >> *amountOfNodes;
            while(*amountOfNodes){
                RB_node *item = new RB_node;
                item->right = nullptr, item->left = nullptr, item->data = rand() % 100;
                std ::cout << item->data << " / ";
                recursiveFilling(item, root);
                (*amountOfNodes)--;
            }
            std :: cout << '\n';
            delete amountOfNodes;
            depth = depthCount(root) + 1;
            amountOfElements = GetSize(GetRoot());
            break;
        }
        case keysForInput::consoleKey:{
            int * value = new int;
            while(std :: cin >> *value) {
                RB_node *item = new RB_node;
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
                RB_node *item = new RB_node;
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
RedBlackTree :: RedBlackTree(const int *arr, const int &demArr) {
    int * value = new int;
    for(int i = 0; i < demArr;i++){
        RB_node *item = new RB_node;
        item->right = nullptr, item->left = nullptr, item->data = arr[i];
        recursiveFilling(item, root);
    }
    delete value;
    depth = depthCount(root) + 1;
    amountOfElements = GetSize(GetRoot());
}
RedBlackTree :: ~RedBlackTree(){
    deleteTree(root);
}
void RedBlackTree::insert(int value) {
    RB_node * new_node = new RB_node;
    new_node->right = new_node->left = nullptr;
    new_node->color = 1;
    recursiveFilling(new_node, this->root);
}
