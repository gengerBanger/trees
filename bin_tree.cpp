//
// Created by aleks on 07.05.2023.
//

#include "bin_tree.h"
#include <iostream>
#include <cmath>
#include <fstream>
Node * BinTree :: getMaxNode(Node * root) {
    if(!root->right) return root;
    while (root->right->right) {
        root = root->right;
    }
    return root;
}
int BinTree :: depthCount(Node* root)
{
    if (!root) return 0;
    return 1 + fmax(depthCount(root->left), depthCount(root->right));
}
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
void BinTree :: mapFilling( Node * buffRoot, int level){ // filling in the dictionary of elements by levels
    if(buffRoot){
        mapOfLevels[level].push_back(std ::to_string(buffRoot->data));
        ++level;
        mapFilling(buffRoot->left,level);
        mapFilling(buffRoot->right,level);
    }
    else {
        int * buffLVL = new int(level);
        mapOfLevels[level].push_back("&");
        int * i = new int(1);
        while(++(*buffLVL) < depth){
            for(int j = 0; j < *i;j++){
                mapOfLevels[*buffLVL].push_back(".");
                mapOfLevels[*buffLVL].push_back(".");
            }
            *i *= 2;
        }
        delete i;
        delete buffLVL;
    }
}
void BinTree ::mapRemoving() {// deleting a dictionary
    for(auto iter = mapOfLevels.begin();iter != mapOfLevels.end();iter++ ){
        iter->second.clear();
    }
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

void BinTree ::deleteTree(Node * root) {
    if(root){
        Node * buff = root;
        deleteTree(buff->right);
        deleteTree(buff->left);
        delete root;
    }
}
BinTree :: ~BinTree(){
    deleteTree(root);
}
void BinTree ::print() {
    mapRemoving();
    mapFilling(root, 0);
    int *increaseDepth = new int(pow(depth, 2));
    int *amountOfSpaces = new int(2);
    for(auto iterMap = mapOfLevels.begin();iterMap != mapOfLevels.end();iterMap++){
        if (iterMap->first == 0){
            for(int i = 0; i < *increaseDepth; i++){
                std :: cout << ' ';
            }
        }
        else{
            for(int i = 0; i < floor(float(*increaseDepth) / *amountOfSpaces); i++){
                std :: cout << ' ';
            }
            *amountOfSpaces *= 2;
        }
        int evenSpace = 0;
        for(auto iterVec = iterMap->second.begin();iterVec != iterMap->second.end(); iterVec++){
            if(iterMap != mapOfLevels.begin()){
                auto buffIter = iterMap;
                buffIter--;
                std :: cout << *iterVec;
                evenSpace++;
                if(evenSpace % 4 == 0){
                    for(int i = 0; i < floor(float(*increaseDepth) / float(*amountOfSpaces / 4) - 1) ;i++){
                        std :: cout << " ";
                    }
                }
                else{
                    if(evenSpace % 2 != 0){
                        for(int i = 0; i < floor(float(*increaseDepth) / float(*amountOfSpaces / 4));i++){
                            std :: cout << "_";
                        }
                    }
                    else for(int i = 0; i < floor(float(*increaseDepth) / float(*amountOfSpaces / 4)) ;i++){
                            std :: cout << " ";
                        }
                }
            }
            else{
                std :: cout << *iterVec;
                evenSpace++;
            }
        }
        std :: cout << "\n\n";
    }
    delete increaseDepth;
    delete amountOfSpaces;
}
void BinTree ::print(std :: ofstream & new_thread) {
    mapRemoving();
    mapFilling(root, 0);
    new_thread << '\n';
    int *increaseDepth = new int(pow(depth, 2));
    int *amountOfSpaces = new int(2);
    for(auto iterMap = mapOfLevels.begin();iterMap != mapOfLevels.end();iterMap++){
        if (iterMap->first == 0){
            for(int i = 0; i < *increaseDepth; i++){
                new_thread << ' ';
            }
        }
        else{
            for(int i = 0; i < floor(float(*increaseDepth) / *amountOfSpaces); i++){
                new_thread << ' ';
            }
            *amountOfSpaces *= 2;
        }
        int evenSpace = 0;
        for(auto iterVec = iterMap->second.begin();iterVec != iterMap->second.end(); iterVec++){
            if(iterMap != mapOfLevels.begin()){
                auto buffIter = iterMap;
                buffIter--;
                new_thread <<*iterVec;
                evenSpace++;
                    if(evenSpace % 2 != 0){
                        for(int i = 0; i < floor(float(*increaseDepth) / float(*amountOfSpaces / 4));i++){
                            new_thread << '_';
                        }
                    }
                    else for(int i = 0; i < floor(float(*increaseDepth) / float(*amountOfSpaces / 4) - 1) ;i++){
                            new_thread << ' ';
                        }
            }
            else{
                new_thread <<*iterVec;
                evenSpace++;
            }
        }
        new_thread <<"\n\n";
    }
    delete increaseDepth;
    delete amountOfSpaces;
}
Node * BinTree ::GetRoot() {
    return root;
}
int BinTree :: GetSize(Node * buff) {
    if (buff) {
        ++amountOfElements;
        GetSize(buff->left);
        GetSize(buff->right);
        return amountOfElements;
    }
}
int BinTree ::GetDepth() {
    return depth;
}
bool BinTree ::empty() {
    return amountOfElements;
}
void BinTree ::insert(int value) { // inserting a new node
    Node *new_node = new Node;
    new_node->data = value;
    new_node->left = new_node->right = nullptr;
    recursiveFilling(new_node,root);
    depth = depthCount(root) + 1;
}
Node * BinTree ::search(int value, Node * node) {// searching of node
    if(node != nullptr){
        if(node->data > value) return search(value, node->left);
        if(node->data < value) return search(value, node->right);
        if(node->data == value) return node;
    }
    else return nullptr;
}
Node * BinTree ::searchForRemove(int value, Node *node) {// searching the root-node for an element
    if(node != nullptr){
        if(node->data > value){
            if((node->left != nullptr && node->left->data == value) || (node->right != nullptr && node->right->data == value)) return node;
            else return searchForRemove(value, node->left);
        }
        if(node->data < value) {
            if((node->right != nullptr && node->right->data == value) || (node->left != nullptr && node->left->data == value)) return node;
            else return searchForRemove(value, node->right);
        }
    }
    else return nullptr;
}
void BinTree ::remove(int value){
    if(search(value, root)){
        if(value == root->data){
            if(root->left){
                Node ** buffLeftDescendant = new Node *(root->left);
                Node ** buffRightDescendant = new Node *(root->right);
                Node * buffMaxNode =  getMaxNode(*buffLeftDescendant);
                if(*buffRightDescendant){
                    delete root;
                    if(buffMaxNode->right){
                        Node * buff = buffMaxNode->right;
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
                    if(!buffMaxNode-> right)root->left = *buffLeftDescendant;
                }
                else{
                    delete root;
                    root->left = *buffLeftDescendant;
                }
                delete buffLeftDescendant;
                delete buffRightDescendant;
            }
            else {
                Node ** newRoot = new Node * (root->right);
                delete root;
                root = *newRoot;
                delete newRoot;
            }
        }
        else{
            Node * searchResult = searchForRemove(value,root);
            if(searchResult){
                if(searchResult->left != nullptr && searchResult->left->data == value){ // for removing of left descendant
                    if(searchResult->left->right  == searchResult->left->left){
                        delete searchResult->left;
                        searchResult->left = nullptr;
                    }
                    else{
                        if(searchResult->left->left == nullptr && searchResult->left->right != nullptr){
                            Node ** buffResult = new Node *(searchResult->left->right);
                            delete searchResult->left;
                            searchResult->left = *buffResult;
                            delete buffResult;
                        }
                        else{
                            Node ** buffLeftDescendant = new Node *(searchResult->left->left);
                            Node ** buffRightDescendant = new Node *(searchResult->left->right);
                            Node * buffMaxNode =  getMaxNode(*buffLeftDescendant);
                            if(*buffRightDescendant){
                                delete searchResult->left;
                                if(buffMaxNode->right){
                                    Node * buff = buffMaxNode->right;
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
                            Node ** buffResult = new Node *(searchResult->right->right);
                            delete searchResult->right;
                            searchResult->right = *buffResult;
                            delete buffResult;
                        }
                        else{
                            Node ** buffLeftDescendant = new Node *(searchResult->right->left);
                            Node ** buffRightDescendant = new Node *(searchResult->right->right);
                            Node * buffMaxNode =  getMaxNode(*buffLeftDescendant);
                            if(*buffRightDescendant){
                                delete searchResult->right;
                                if(buffMaxNode->right){
                                    Node * buff = buffMaxNode->right;
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
                                searchResult->right = *buffLeftDescendant;
                            }
                            delete buffLeftDescendant;
                            delete buffRightDescendant;

                        }
                    }
                }
            }
        }
        depth = depthCount(root) + 1;
    }
    else std :: cout << "Node not found\n";
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

