//
// Created by aleks on 16.05.2023.
//
#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <fstream>
#ifndef BIN_TREE_TREE_H
#define BIN_TREE_TREE_H
enum class keysForInput{randomKey = 1,consoleKey,fileKey};
template <typename Type>
class tree{
protected:
    Type * root = 0;
    int depth = 0;
    int amountOfElements = 0;
    std :: map <int, std :: vector< std :: string>> mapOfLevels;
    void mapFilling(Type * buffRoot, int level){
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
    };
    void mapRemoving(){
        for(auto iter = mapOfLevels.begin();iter != mapOfLevels.end();iter++ ){
            iter->second.clear();
        }
    }
    int depthCount(Type * root){
        if (!root) return 0;
        return 1 + fmax(depthCount(root->left), depthCount(root->right));
    }
    virtual void recursiveFilling(Type * node, Type * buffRoot) = 0;
    Type * searchForRemove(int value, Type * node){
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
    void deleteTree(Type * root){
        if(root){
            Type * buff = root;
            deleteTree(buff->right);
            deleteTree(buff->left);
            delete root;
        }
    }
public:
    Type * GetRoot(){
        return root;
    };
    int GetDepth(){
        return depth;
    };
    bool empty(){
        return amountOfElements;
    };
    int GetSize(Type * buff){
        if (buff) {
            ++amountOfElements;
            GetSize(buff->left);
            GetSize(buff->right);
            return amountOfElements;
        }
    }
    Type * getMaxNode(Type * node){
        if(!node->right) return node;
        while (node->right->right) {
            node = node->right;
        }
        return node;
    }
    void print(){
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
    void print(std :: ofstream & new_thread){
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
    virtual void insert(int value) = 0;
    Type * search(int value, Type * node){
        if(node != nullptr){
            if(node->data > value) return search(value, node->left);
            if(node->data < value) return search(value, node->right);
            if(node->data == value) return node;
        }
        else return nullptr;
    }
    void remove(int value){
        if(search(value, root)){
            if(value == root->data){
                if(root->left){
                    Type ** buffLeftDescendant = new Type *(root->left);
                    Type ** buffRightDescendant = new Type *(root->right);
                    Type * buffMaxNode =  getMaxNode(*buffLeftDescendant);
                    if(*buffRightDescendant){
                        delete root;
                        if(buffMaxNode->right){
                            Type * buff = buffMaxNode->right;
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
                    Type ** newRoot = new Type * (root->right);
                    delete root;
                    root = *newRoot;
                    delete newRoot;
                }
            }
            else{
                Type * searchResult = searchForRemove(value,root);
                if(searchResult){
                    if(searchResult->left != nullptr && searchResult->left->data == value){ // for removing of left descendant
                        if(searchResult->left->right  == searchResult->left->left){
                            delete searchResult->left;
                            searchResult->left = nullptr;
                        }
                        else{
                            if(searchResult->left->left == nullptr && searchResult->left->right != nullptr){
                                Type ** buffResult = new Type *(searchResult->left->right);
                                delete searchResult->left;
                                searchResult->left = *buffResult;
                                delete buffResult;
                            }
                            else{
                                Type ** buffLeftDescendant = new Type*(searchResult->left->left);
                                Type ** buffRightDescendant = new Type *(searchResult->left->right);
                                Type * buffMaxNode =  getMaxNode(*buffLeftDescendant);
                                if(*buffRightDescendant){
                                    delete searchResult->left;
                                    if(buffMaxNode->right){
                                        Type * buff = buffMaxNode->right;
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
                                Type ** buffResult = new Type *(searchResult->right->right);
                                delete searchResult->right;
                                searchResult->right = *buffResult;
                                delete buffResult;
                            }
                            else{
                                Type ** buffLeftDescendant = new Type *(searchResult->right->left);
                                Type ** buffRightDescendant = new Type *(searchResult->right->right);
                                Type * buffMaxNode =  getMaxNode(*buffLeftDescendant);
                                if(*buffRightDescendant){
                                    delete searchResult->right;
                                    if(buffMaxNode->right){
                                        Type * buff = buffMaxNode->right;
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
};
#endif //BIN_TREE_TREE_H
