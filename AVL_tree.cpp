//
// Created by aleks on 23.05.2023.
//
#include <stack>
#include "AVL_tree.h"
AVL_node * AVLtree ::recursiveFillingAVL(AVL_node * node, AVL_node *root) {
    if(!root){
        node->height = 1;
        return node;
    }
        if(node->data > root->data){
            root->right = recursiveFillingAVL(node, root->right);
        }
        else if(node->data < root->data) {
            root->left = recursiveFillingAVL(node, root->left);
        }
    return balancing(root);
}
int AVLtree :: getHeight(AVL_node* node) {
    if (node) return node->height;
    else return 0;
}
int AVLtree :: balanceFactor(AVL_node * node) {
    if (node) return (getHeight(node->right) - getHeight(node->left));
    else return 0;
}
void AVLtree :: fixHeight(AVL_node* node) {
    int *leftCh = new int (getHeight(node->left)), *rightCh = new int(getHeight(node->right)) ;
    if (*leftCh > *rightCh)node->height = *leftCh + 1;
    else node->height = *rightCh + 1;
    delete leftCh;
    delete rightCh;
}
AVL_node *  AVLtree :: rightTurn(AVL_node * node) {// правый поворот вокруг p
    AVL_node * buff = node->left;
    if(this->root == node) this->root = buff;
    node->left = buff->right;
    buff->right = node;
    fixHeight(node);
    fixHeight(buff);
    return  buff;
}
AVL_node * AVLtree :: leftTurn(AVL_node * node) {// левый поворот вокруг p
    AVL_node* buff = node->right;
    if(this->root == node) this->root = buff;
    node->right = buff->left;
    buff->left = node;
    fixHeight(node);
    fixHeight(buff);
    return buff;
}
AVL_node * AVLtree ::balancing(AVL_node *node) {
        fixHeight(node);
        if (balanceFactor(node) == 2) {
            if (balanceFactor(node->right) < 0)  node->right = rightTurn(node->right);
            return leftTurn(node);
        }
        if (balanceFactor(node) == -2) {
            if (balanceFactor(node->left) > 0) node->left = leftTurn(node->left);
            return rightTurn(node);
        }
    return node;
}
AVLtree::AVLtree(keysForInput new_key) {
        switch (new_key) {
            case keysForInput::randomKey:{
                int * amountOfNodes = new int();
                srand(time(nullptr));
                std :: cout << "\t~~Enter the amount of nodes~~\n";
                std :: cin >> *amountOfNodes;
                while(*amountOfNodes){
                    AVL_node *item = new AVL_node;
                    item->right = nullptr, item->left = nullptr;
                    do{
                        item->data = rand() % 201 - 100;
                    }
                    while(search(item->data, root));
                    std ::cout << item->data << " / ";
                    root = recursiveFillingAVL(item, root);
                    (*amountOfNodes)--;
                }
                std :: cout << "\n\n";
                delete amountOfNodes;
                depth = depthCount(root) + 1;
                amountOfElements = GetSize(GetRoot());
                break;
            }
            case keysForInput::consoleKey:{
                int * value = new int;
                while(std :: cin >> *value) {
                    std :: cin.clear();
                    AVL_node *item = new AVL_node;
                    item->right = nullptr, item->left = nullptr, item->data = *value;
                    root = recursiveFillingAVL(item, root);
                }
                std :: cin.clear();
                while(std :: cin.get() != '\n');
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
                    AVL_node *item = new AVL_node;
                    item->right = nullptr, item->left = nullptr,  new_thread >> item->data;
                    root = recursiveFillingAVL(item, root);
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
AVLtree :: AVLtree(const int *arr, const int &demArr) {
    int * value = new int;
    for(int i = 0; i < demArr;i++){
        AVL_node *item = new AVL_node;
        item->right = nullptr, item->left = nullptr, item->data = arr[i];
        this->root = recursiveFillingAVL(item, root);
    }
    delete value;
    depth = depthCount(root) + 1;
    amountOfElements = GetSize(GetRoot());
}
void AVLtree::insert(int &value) {
    AVL_node * new_node = new AVL_node;
    new_node->right = new_node->left = nullptr;
    new_node->data = value;
    recursiveFillingAVL(new_node, root);
    depth = depthCount(root) + 1;
}
AVL_node * AVLtree :: searchForRemove(int value, AVL_node * root, std :: stack<AVL_node *> &stackForRemove){
    if(root){
        if(root->data > value) {
            stackForRemove.push(root);
            return searchForRemove(value, root->left, stackForRemove);
        }
        if(root->data < value){
            stackForRemove.push(root);
            return searchForRemove(value, root->right, stackForRemove);
        }
        if(root->data == value) return root;
    }
    else return nullptr;
}
AVL_node * AVLtree :: getMinNode(AVL_node * node, std::stack<AVL_node *> & stackForRemove){
    AVL_node *prev = node;
    while (node->right) {
        stackForRemove.push(node);
        prev = node;
        node = node->right;
    }
    if(node->left && node != prev){
        prev->right = node->left;
    }else{
        prev->right = nullptr;
    }
    return node;
}
void AVLtree::remove(int value) {
    std :: stack<AVL_node *> new_stack;
    AVL_node *deleteElement = searchForRemove(value,root , new_stack);
    if(deleteElement){
        if(root->right == root->left){
            delete root;
            root = nullptr;
            std :: cout << "\t\t tree is empty\n\n";
            return;
        }
        if(deleteElement->left && deleteElement->right){
            new_stack.push(deleteElement);
            AVL_node * max = getMinNode(deleteElement->left, new_stack);
            if(deleteElement->left == max) deleteElement->left = max->left;
            deleteElement->data = max->data;
            delete max;
        }
        else
            if(deleteElement->left){
                new_stack.top()->left = deleteElement->left;
                delete deleteElement;
        }
            else
                if(deleteElement->right){
                    new_stack.top()->right = deleteElement->right;
                     delete deleteElement;
                }
                else{
                    if(new_stack.top()->left == deleteElement){
                        new_stack.top()->left = nullptr;
                        delete deleteElement;
                    }
                    else {
                        new_stack.top()->right = nullptr;
                        delete deleteElement;
                    }
                }
    }
    else return;
    while (!new_stack.empty()){
        AVL_node *buffNode = new_stack.top();
        if(new_stack.size() == 1){
            balancing(new_stack.top());
            break;
        }
        new_stack.pop();
        if(new_stack.top()->left == buffNode) new_stack.top()->left = balancing(buffNode);
        else new_stack.top()->right = balancing(buffNode);
    }
    depth = depthCount(root) + 1;
}
void AVLtree::recursiveFilling(AVL_node *node, AVL_node *root) {
    recursiveFillingAVL(node, root);
}
