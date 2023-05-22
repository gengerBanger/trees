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
                node->parent = buffRoot;
                if(buffRoot->color == 1)balancing(node);
            }
        }
        if(node->data < buffRoot->data) {
            if (buffRoot->left != nullptr)recursiveFilling(node, buffRoot->left);
            else{
                node->color = 1;
                buffRoot->left = node;
                node->parent = buffRoot;
                if(buffRoot->color == 1)balancing(node);
            }
        }
    }
    else {
        node->color = -1;
        node->parent = nullptr;
        root = node;
    }
}
void RedBlackTree ::balancing(RB_node * node) {//9 82 29 87 27 55 95 67    44 6 62 23 6 39 76 86 52 83
        if(node->parent->parent->data < node->data){
                if(node->parent->parent->left && node->parent->parent->left->color == 1){
                    node->parent->color *= -1;
                    if(node->parent->parent != this->root)node->parent->parent->color *= -1;
                    node->parent->parent->left->color *= -1;
                    if(node->parent->parent->parent && node->parent->parent->parent->color == 1)balancing(node->parent->parent);
                }
                else{
                    if(!node->parent->parent->left || (node->parent->parent->left->color == -1 && node->parent->parent->left->right == node->parent->parent->left->left)){
                        if(node->parent->right == node) leftTurn1(node->parent->parent);
                        else leftTurn2(node->parent->parent);
                        return;
                    }
                }
        }
        else{
                if(node->parent->parent->right && node->parent->parent->right->color == 1){
                    node->parent->color *= -1;
                    if(node->parent->parent != this->root)node->parent->parent->color *= -1;
                    node->parent->parent->right->color *= -1;
                    if(node->parent->parent->parent && node->parent->parent->parent->color == 1)balancing(node->parent->parent);
                }
                else {
                    if(!node->parent->parent->right || node->parent->parent->right->color == -1 && node->parent->parent->right->right == node->parent->parent->right->left){
                        if(node->parent->left == node)rightTurn1(node->parent->parent);
                        else rightTurn2(node->parent->parent);
                        return;
                    }
                }
        }
}
void RedBlackTree::rightTurn1(RB_node * x) {// правый поворот вокруг p
    RB_node *y = x->left;
    if(this->root == x) this->root = y;
    x->color *= -1;
    y->color *= -1;
    x->left = y->right;
    if(y->right) y->right->parent = x;
    y->parent = x->parent;
    if(x->parent == nullptr) root = y;
    else if(x->parent->left == x) x->parent->left = y;
        else x->parent->right = y;
    x->parent = y;
    y->right = x;
}
void RedBlackTree ::rightTurn2(RB_node * node) {
    RB_node * buff = node;
    if(node == this->root) this->root = node->left->right;
    RB_node * lch = node->left->right->left;
    RB_node * rch = node->left->right->right;
    node = node->left->right;
    node->parent = buff->parent;
    if(buff->parent){
        if(buff->parent->left == buff) buff->parent->left = node;
        else buff->parent->right = node;
    }
    node->right = buff;
    node->left = buff->left;
    node->right->left = nullptr;
    if(rch){
        node->left->right = rch;
        node->left->right->parent = node->left;
        if(lch) node->left->right->left = lch;
        node->left->right->left->parent = node->left->right;
    }
    else{
        if(lch){
            node->left->right = lch;
            node->left->right->parent = node->left;
        }
        else node->left->right = node->left->right = nullptr;
    }
    node->right->parent = node->left->parent = node;
    node->color = -1;
    node->right->color = 1;
}
void RedBlackTree::rightTurnDel(RB_node * x) {// правый поворот вокруг p
    RB_node *y = x->left;
    x->left = y->right;
    if(y->right) y->right->parent = x;
    y->parent = x->parent;
    if(x->parent == nullptr) root = y;
    else if(x->parent->left == x) x->parent->left = y;
    else x->parent->right = y;
    x->parent = y;
    y->right = x;
}
void RedBlackTree::leftTurn1(RB_node * x) {
    RB_node *y = x->right;
    if(this->root == x) this->root = y;
    x->color *= -1;
    if(this->root == x )y->color = -1;
    else y->color *= -1;
    x->right = y->left;
    if(y->left) y->left->parent = x;
    y->parent = x->parent;
    if(x->parent == nullptr)root = y;
    else if(x->parent->left == x)x->parent->left = y;
        else x->parent->right = y;
    x->parent = y;
    y->left = x;
}
void RedBlackTree ::leftTurn2(RB_node * node) {
    RB_node * buff = node;
    if(node == this->root) this->root = node->right->left;
    RB_node * lch = node->right->left->left;
    RB_node * rch = node->right->left->right;
    node = node->right->left;
    node->parent = buff->parent;
    if(buff->parent){
        if(buff->parent->left == buff) buff->parent->left = node;
        else buff->parent->right = node;
    }
    node->left = buff;
    node->right = buff->right;
    node->left->right = nullptr;
    if(rch){
        node->right->left = rch;
        node->right->left->parent = node->right;
        if(lch) node->right->left->left = lch;
        node->right->left->left->parent = node->right->left;
    }
    else{
        if(lch){
            node->right->left = lch;
            node->right->left->parent = node->right;
        }
        else node->right->left = node->right->left = nullptr;
    }
    node->left->parent = node->right->parent = node;
    node->color = -1;
    node->left->color = 1;
}
void RedBlackTree::leftTurnDel(RB_node * x) {
    RB_node *y = x->right;
    x->right = y->left;
    if(y->left) y->left->parent = x;
    y->parent = x->parent;
    if(x->parent == nullptr)root = y;
    else if(x->parent->left == x)x->parent->left = y;
    else x->parent->right = y;
    x->parent = y;
    y->left = x;
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
void RedBlackTree::insert(int &value) {
    RB_node * new_node = new RB_node;
    new_node->right = new_node->left = nullptr;
    new_node->color = 1;
    new_node->data = value;
    recursiveFilling(new_node, this->root);
}
RB_node * getMinNode(RB_node * node){
    node = node->right;
    while (node->left) {
        node = node->left;
    }
    return node;
}
void RedBlackTree ::remove(int value) {
    RB_node * buffres = search(value, root);
    if(buffres){
        if(buffres->color == -1){
            if(buffres->right && !buffres->left) {
                std :: swap (buffres->data, buffres->right->data);
                delete buffres->right;
                buffres->right = nullptr;
                return;
            }
            if(buffres->left && !buffres->right){
                std :: swap (buffres->data, buffres->left->data);
                delete buffres->left;
                buffres->left = nullptr;
                return;
            }
        }
        if(buffres->left && buffres->right){
            std :: swap(getMinNode(buffres)->data,buffres->data);
            buffres = search(value,root);
        }
        if(buffres->color == 1 && buffres->left == buffres->right){
            if(buffres->parent->left == buffres) buffres->parent->left = nullptr;
            else buffres->parent->right = nullptr;
            delete buffres;
            return;
        }
        if(buffres->left == buffres->right && buffres->parent->right->color == -1) rebalancingL(buffres);
        else rebalancingR(buffres);
        depth = depthCount(root) + 1;
    }
    else std :: cout << "Node not found\n";
}
void RedBlackTree ::rebalancingR(RB_node *buffres) {
    if(buffres->parent->left->color == -1){
        if (buffres->parent->left->left->color == -1 && buffres->parent->left->right->color == 1) {
            std::swap(buffres->parent->left->right->color, buffres->parent->left->color);
            leftTurnDel(buffres->parent->left->right);
            rebalancingR(buffres);
        }
        if (buffres->parent->left->left->color == 1) {
            buffres->parent->left->color = buffres->parent->color;
            buffres->parent->color = -1;
            buffres->parent->left->left->color = -1;
            rightTurnDel(buffres->parent->left);
            buffres->parent->right = nullptr;
            delete buffres;
            return;
        }
        if (buffres->parent->left->right->color == -1 && buffres->parent->left->left->color == -1) {
            buffres->parent->left->color = 1;
            if (buffres->parent->color == -1) rebalancingL(buffres);
            else{
                buffres->parent->right = nullptr;
                delete buffres;
                return;
            }
        }
    }
    if( buffres->parent->left->color == 1) {
        buffres->parent->color = 1;
        buffres->parent->left->color = -1;
        rightTurnDel(buffres->parent->left);
        rebalancingR(buffres);
    }
}
void RedBlackTree ::rebalancingL(RB_node *buffres) {
        if (buffres->parent->right->right->color == -1 && buffres->parent->right->left->color == 1) {
            std::swap(buffres->parent->right->left->color, buffres->parent->right->color);
            rightTurnDel(buffres->parent->right->left);
            rebalancingL(buffres);
        }
        if (buffres->parent->right->right->color == 1) {
            buffres->parent->right->color = buffres->parent->color;
            buffres->parent->color = -1;
            buffres->parent->right->right->color = -1;
            leftTurnDel(buffres->parent->right);
            buffres->parent->left = nullptr;
            delete buffres;
            return;
        }
        if (buffres->parent->right->right->color == -1 && buffres->parent->right->left->color == -1) {
            buffres->parent->right->color = 1;
            if (buffres->parent->color == -1) rebalancingL(buffres);
            else{
                buffres->parent->left = nullptr;
                delete buffres;
                return;
            }
        }
    if(buffres->left == buffres->right && buffres->parent->right->color == 1) {
        buffres->parent->color = 1;
        buffres->parent->right->color = -1;
        leftTurnDel(buffres->parent->right);
        rebalancingL(buffres);
    }
}
/*if(value == root->data){
            if(root->left){
                RB_node ** buffLeftDescendant = new RB_node *(root->left);
                RB_node ** buffRightDescendant = new RB_node *(root->right);
                RB_node * buffMaxNode =  getMaxNode(*buffLeftDescendant);
                if(*buffRightDescendant){
                    delete root;
                    if(buffMaxNode->right){
                        RB_node * buff = buffMaxNode->right;
                        if(buffMaxNode->right->left){
                            buffMaxNode->right = buffMaxNode->right->left;
                            buff->left = *buffLeftDescendant;
                        }
                        else buffMaxNode->right = nullptr;
                        root = buff;
                    }
                    else {
                        root = buffMaxNode;
                    }
                    root->right = *buffRightDescendant;
                    if(!(buffMaxNode-> right))root->left = *buffLeftDescendant;
                }
                else{
                    delete root;
                    root = *buffLeftDescendant;
                }
                delete buffLeftDescendant;
                delete buffRightDescendant;
            }
            else {
                RB_node ** newRoot = new RB_node * (root->right);
                delete root;
                root = *newRoot;
                delete newRoot;
            }
            root->color = -1;
            if(root->right) root->right->parent = root;
            if(root->left) root->left->parent = root;
        }
        else{
            RB_node * searchResult = searchForRemove(value,root);
            if(searchResult){
                if(searchResult->left != nullptr && searchResult->left->data == value){ // for removing of left descendant
                    if(searchResult->left->right  == searchResult->left->left){
                        delete searchResult->left;
                        searchResult->left = nullptr;
                    }
                    else{
                        if(searchResult->left->left == nullptr && searchResult->left->right != nullptr){
                            RB_node ** buffResult = new RB_node *(searchResult->left->right);
                            delete searchResult->left;
                            searchResult->left = *buffResult;
                            searchResult->left->color = *newColor;
                            *//*searchResult->left->parent = searchResult->left;*//*
                            delete buffResult;
                        }
                        else{
                            RB_node ** buffLeftDescendant = new RB_node*(searchResult->left->left);
                            RB_node ** buffRightDescendant = new RB_node *(searchResult->left->right);
                            RB_node * buffMaxNode =  getMaxNode(*buffLeftDescendant);
                            if(*buffRightDescendant){
                                delete searchResult->left;
                                if(buffMaxNode->right){
                                    RB_node * buff = buffMaxNode->right;
                                    if(buffMaxNode->right->left){
                                        buffMaxNode->right = buffMaxNode->right->left;
                                        buff->left = *buffLeftDescendant;
                                    }
                                    else buffMaxNode->right = nullptr;
                                    searchResult->left = buff;

                                }
                                else {
                                    searchResult->left = buffMaxNode;
                                }
                                searchResult->left->right = *buffRightDescendant;
                                if(!buffMaxNode-> right)searchResult->left->left = *buffLeftDescendant;
                            }
                            else{
                                delete searchResult->left;
                                searchResult->left = *buffLeftDescendant;
                            }
                            searchResult->left->color = *newColor;
                            delete buffLeftDescendant;
                            delete buffRightDescendant;
                        }
                    }//10 6 8 4 5 3 k
                }//16 10 3 8 9 7 2 1 15 20 17 14 21 25 k
                else{ // for removing of right descendant
                    if(searchResult->right->right  == searchResult->right->left){
                        delete searchResult->right;
                        searchResult->right = nullptr;
                    }
                    else{
                        if(searchResult->right->left == nullptr && searchResult->right->right != nullptr){
                            RB_node ** buffResult = new RB_node *(searchResult->right->right);
                            delete searchResult->right;
                            searchResult->right = *buffResult;
                            searchResult->right->color = *newColor;
                            delete buffResult;
                        }
                        else{
                            RB_node ** buffLeftDescendant = new RB_node *(searchResult->right->left);
                            RB_node ** buffRightDescendant = new RB_node *(searchResult->right->right);
                            RB_node * buffMaxNode =  getMaxNode(*buffLeftDescendant);
                            if(*buffRightDescendant){
                                delete searchResult->right;
                                if(buffMaxNode->right){
                                    RB_node * buff = buffMaxNode->right;
                                    if(buffMaxNode->right->left){
                                        buffMaxNode->right = buffMaxNode->right->left;
                                        buff->left = *buffLeftDescendant;
                                    }
                                    else buffMaxNode->right = nullptr;
                                    searchResult->right = buff;
                                }
                                else {
                                    searchResult->right = buffMaxNode;
                                }
                                searchResult->right->right = *buffRightDescendant;
                                if(!buffMaxNode-> right)searchResult->right->left = *buffLeftDescendant;
                            }
                            else{
                                delete searchResult->left;
                                searchResult->left = *buffLeftDescendant;
                            }
                            searchResult->right->color = *newColor;
                            delete buffLeftDescendant;
                            delete buffRightDescendant;
                        }
                    }
                }
            }
        }*/