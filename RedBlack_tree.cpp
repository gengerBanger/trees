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
                item->right = nullptr, item->left = nullptr, item->data = rand() % 201 - 100;
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
                std :: cin.clear();
                RB_node *item = new RB_node;
                item->right = nullptr, item->left = nullptr, item->data = *value;
                recursiveFilling(item, root);
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
void RedBlackTree::insert(int &value) {
    RB_node * new_node = new RB_node;
    new_node->right = new_node->left = nullptr;
    new_node->color = 1;
    new_node->data = value;
    recursiveFilling(new_node, this->root);
    depth = depthCount(root) + 1;
}
RB_node * getMinNode(RB_node * node){
    node = node->left;
    while(node->right){
        node = node->right;
    }
    return node;
}
void RedBlackTree ::remove(int value) {
    RB_node * buffres = search(value, root);
    if(buffres){
        if(buffres->left && buffres->right){
            RB_node * newNode = getMinNode(buffres);
            std :: swap(newNode->data,buffres->data);
            buffres = newNode;
        }
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
        if(buffres->color == 1 && buffres->left == buffres->right){
            if(buffres->parent->left == buffres) buffres->parent->left = nullptr;
            else buffres->parent->right = nullptr;
            delete buffres;
            return;
        }
        if(buffres->color == -1 && buffres->left == buffres->right){
            if(buffres->parent->color == 1){
                if(buffres->parent->left->right == buffres->parent->left->left){
                    buffres->parent->color = -1;
                    buffres->parent->left->color = 1;
                    buffres->parent->left = nullptr;
                    delete buffres;
                    return;
                }
                if(buffres->parent->right->right == buffres->parent->right->left){
                    buffres->parent->color = -1;
                    buffres->parent->right->color = 1;
                    buffres->parent->left = nullptr;
                    delete buffres;
                    return;
                }
                if(buffres->parent->left->right->color == 1){
                    RB_node * parent = buffres->parent;
                    RB_node * uncle = buffres->parent->left;
                    rightTurn2(buffres->parent);
                    uncle->color = -1;
                    parent->color = 1;
                    buffres->parent->right = nullptr;
                    delete buffres;
                    return;
                }
                if(buffres->parent->left->left->color == 1){
                    RB_node * parent = buffres->parent;
                    RB_node * uncle = buffres->parent->left;
                    rightTurn1(buffres->parent);
                    uncle->color = -1;
                    parent->color = 1;
                    buffres->parent->right = nullptr;
                    delete buffres;
                    return;
                }
                if(buffres->parent->right->right->color == 1){
                    RB_node * parent = buffres->parent;
                    RB_node * uncle = buffres->parent->right;
                    leftTurn1(buffres->parent);
                    uncle->color = -1;
                    parent->color = 1;
                    buffres->parent->left = nullptr;
                    delete buffres;
                    return;
                }
                if(buffres->parent->right->left->color == 1){
                    RB_node * parent = buffres->parent;
                    RB_node * uncle = buffres->parent->right;
                    leftTurn2(buffres->parent);
                    uncle->color = -1;
                    parent->color = 1;
                    buffres->parent->left = nullptr;
                    delete buffres;
                    return;
                }
            }
            else{
                if(buffres->parent->left->color == 1){
                    if(buffres->parent->left->left){
                        RB_node * parent = buffres->parent;
                        RB_node * uncle = buffres->parent->left->right;
                        rightTurn1(buffres->parent);
                        uncle->color = -1;
                        parent->color = -1;
                        buffres->parent->right = nullptr;
                        delete buffres;
                        return;
                    }
                    else{
                        if(buffres->parent->left->right){
                            RB_node * parent = buffres->parent;
                            RB_node * uncle = buffres->parent->left->right;
                            rightTurn2(buffres->parent);
                            uncle->color = -1;
                            parent->color = -1;
                            buffres->parent->right = nullptr;
                            delete buffres;
                            return;
                        }
                        else{
                            if(buffres->parent->left->left->left == buffres->parent->left->left->right){
                                RB_node * parent = buffres->parent;
                                RB_node * brother = buffres->parent->left;
                                rightTurn1(buffres->parent);
                                parent->color = -1;
                                brother->color = -1;
                                buffres->parent->right = nullptr;
                                delete buffres;
                                return;
                            }
                            if(buffres->parent->left->right->left == buffres->parent->left->right->right){
                                RB_node * parent = buffres->parent;
                                RB_node * brother = buffres->parent->left;
                                rightTurn1(buffres->parent);
                                parent->color = -1;
                                brother->color = -1;
                                buffres->parent->right = nullptr;
                                delete buffres;
                                return;
                            }
                        }
                    }
                }
                if(buffres->parent->right->color == 1){
                    if(buffres->parent->right->left){
                        RB_node * parent = buffres->parent;
                        RB_node * uncle = buffres->parent->right->left;
                        leftTurn2(buffres->parent);
                        uncle->color = -1;
                        parent->color = -1;
                        buffres->parent->left = nullptr;
                        delete buffres;
                        return;
                    }
                    else{
                        if(buffres->parent->right->right){
                            RB_node * parent = buffres->parent;
                            RB_node * uncle = buffres->parent->right->right;
                            leftTurn1(buffres->parent);
                            uncle->color = -1;
                            parent->color = -1;
                            buffres->parent->left = nullptr;
                            delete buffres;
                            return;
                        }
                        else{
                            if(buffres->parent->right->left->left == buffres->parent->right->left->right){
                                return;
                            }
                            if(buffres->parent->right->right->left == buffres->parent->right->right->right){
                                return;
                            }
                        }
                    }
                }
                if(buffres->parent->left->color == -1) {
                    if(buffres->parent->left->left == buffres->parent->left->right){
                        buffres->parent->left->color = 1;
                        buffres->parent->right = nullptr;
                        delete buffres;
                        return;
                    }
                    if (buffres->parent->left->right) {
                        RB_node *parent = buffres->parent;
                        RB_node *uncle = buffres->parent->left->right;
                        rightTurn2(buffres->parent);
                        uncle->color = -1;
                        parent->color = -1;
                        buffres->parent->right = nullptr;
                        delete buffres;
                        return;
                    }
                    if (buffres->parent->left->left) {
                        RB_node *parent = buffres->parent;
                        RB_node *uncle = buffres->parent->left->left;
                        rightTurn1(buffres->parent);
                        uncle->color = -1;
                        parent->color = -1;
                        buffres->parent->right = nullptr;
                        delete buffres;
                        return;
                    }
                }
                if(buffres->parent->right->color == -1){
                    if(buffres->parent->right->left == buffres->parent->right->right){
                        buffres->parent->right->color = 1;
                        buffres->parent->left = nullptr;
                        delete buffres;
                        return;
                    }
                    if(buffres->parent->right->left){
                        RB_node * parent = buffres->parent;
                        RB_node * uncle = buffres->parent->right->left;
                        leftTurn2(buffres->parent);
                        uncle->color = -1;
                        parent->color = -1;
                        buffres->parent->left = nullptr;
                        delete buffres;
                        return;
                    }
                    if(buffres->parent->right->right){
                        RB_node * parent = buffres->parent;
                        RB_node * uncle = buffres->parent->right->right;
                        leftTurn1(buffres->parent);
                        uncle->color = -1;
                        parent->color = -1;
                        buffres->parent->left = nullptr;
                        delete buffres;
                        return;
                    }
                }
            }
        }
    }
    else std :: cout << "Node not found\n";
}

