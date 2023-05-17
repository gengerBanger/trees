//
// Created by aleks on 16.05.2023.
//
#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#ifndef BIN_TREE_TREE_H
#define BIN_TREE_TREE_H
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
    };
    int depthCount(Type * root){
        if (!root) return 0;
        return 1 + fmax(depthCount(root->left), depthCount(root->right));
    };
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
    };
    void deleteTree(Type * root){
        if(root){
            Type * buff = root;
            deleteTree(buff->right);
            deleteTree(buff->left);
            delete root;
        }
    };
public:
    Type * GetRoot(){
        return root;
    };
    int GetDepth(){
        return depth;
    };
    int GetSize(Type * buff){
        if (buff) {
            ++amountOfElements;
            GetSize(buff->left);
            GetSize(buff->right);
            return amountOfElements;
        }
    };
    Type * getMaxNode(Type * node){
        if(!node->right) return node;
        while (node->right->right) {
            node = node->right;
        }
        return node;
    };
    bool empty(){
        return amountOfElements;
    };
    virtual void print(){};
    virtual void print(std :: ofstream & new_thread)= 0;
    virtual void insert(int value)= 0;
    virtual Type * search(int value, Type * node)= 0;
    virtual void remove(int value)= 0;
};
#endif //BIN_TREE_TREE_H
