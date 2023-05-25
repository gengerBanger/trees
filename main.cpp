#include <iostream>
#include "bin_tree.h"
#include "RedBlack_tree.h"
#include "tests.h"
#include "tree.h"
#include "AVL_tree.h"
//20 10 30 5 15 25 40 3 8 12 17 22 26 36 50
int main() {
    int keyChoice;
    bool keyRun = true;
    while (keyRun){
        std :: cout << "~~Which tree do you want ot build?\n1) Binary\n2) AVL\n3) Red-black\n0) Exit\n";
        std :: cin.clear();
        std :: cin >> keyChoice;
        switch (keyChoice) {
            case 1:{
                std :: cout << "~~How you want to check the tree\n1) create tests\n2) create new tree\n";
                std :: cin.clear();
                std :: cin >> keyChoice;
                switch (keyChoice) {
                    case 1:{
                        std :: cout << "Enter the number of tests\n";
                        std :: cin.clear();
                        std :: cin >> keyChoice;
                        Test <BinTree> new_test(keyChoice);
                        std :: cout << "\t~~Tests are ready~~\n";
                    }
                    case 2:{
                        std :: cout <<"~~How you want to create a new tree?\n1) Random values\n2) Console values\n3) Values from file\n";
                        bool binKey = true;
                        std :: cin.clear();
                        std :: cin >> keyChoice;
                        keysForInput new_key{keyChoice};
                        BinTree new_tree(new_key);
                        new_tree.print();
                        while (binKey){
                            std :: cout << "~~Choose the operation\n1) Search item\n2) Delete item\n3) Insert item\n4) Exit\n";
                            std :: cin.clear();
                            std :: cin >> keyChoice;
                            switch (keyChoice) {
                                case 1:{
                                    std :: cout << "Enter the value you want tot search\n";
                                    std :: cin.clear();
                                    std :: cin >> keyChoice;
                                    if(new_tree.search(keyChoice,new_tree.GetRoot())) std :: cout << "Value found\n";
                                    else std :: cout << "Value not found\n";
                                    break;
                                }
                                case 2:{
                                    std :: cout << "Enter the value you want tot delete\n";
                                    std :: cin.clear();
                                    std :: cin >> keyChoice;
                                    new_tree.remove(keyChoice);
                                    new_tree.print();
                                    break;
                                }
                                case 3:{
                                    std :: cout << "Enter the value you want tot insert\n";
                                    std :: cin.clear();
                                    std :: cin >> keyChoice;
                                    new_tree.insert(keyChoice);
                                    new_tree.print();
                                    break;
                                }
                                case 4:{
                                    binKey = false;
                                    break;
                                }
                            }

                        }
                    }
                }
                break;
            }
            case 3:{
                std :: cout <<"~~How you want to create a new tree?\n1) Random values\n2) Console values\n3) Values from file\n";
                bool binKey = true;
                std :: cin.clear();
                std :: cin >> keyChoice;
                keysForInput new_key{keyChoice};
                RedBlackTree new_tree(new_key);
                new_tree.print();
                while (binKey){
                    std :: cout << "~~Choose the operation\n1) Search item\n2) Delete item\n3) Insert item\n4) Exit\n";
                    std :: cin >> keyChoice;
                    switch (keyChoice) {
                        case 1:{
                            std :: cout << "Enter the value you want tot search\n";
                            std :: cin.clear();
                            std :: cin >> keyChoice;
                            if(new_tree.search(keyChoice,new_tree.GetRoot())) std :: cout << "Value found\n";
                            else std :: cout << "Value not found\n";
                            break;
                        }
                        case 2:{
                            std :: cout << "Enter the value you want tot delete\n";
                            std :: cin.clear();
                            std :: cin >> keyChoice;
                            new_tree.remove(keyChoice);
                            new_tree.print();
                            break;
                        }
                        case 3:{
                            std :: cout << "Enter the value you want tot insert\n";
                            std :: cin.clear();
                            std :: cin >> keyChoice;
                            new_tree.insert(keyChoice);
                            new_tree.print();
                            break;
                        }
                        case 4:{
                            binKey = false;
                            break;
                        }
                    }

                }
                break;
            }
            case 2:{
                std :: cout << "~~How you want to check the tree\n1) create tests\n2) create new tree\n";
                std :: cin.clear();
                std :: cin >> keyChoice;
                switch (keyChoice) {
                    case 1: {
                        std::cout << "Enter the number of tests\n";
                        std::cin.clear();
                        std::cin >> keyChoice;
                        Test<AVLtree> new_test(keyChoice);
                        std :: cout << "\t~~Tests are ready~~\n";
                    }
                    case 2:{
                        std :: cout <<"~~How you want to create a new tree?\n1) Random values\n2) Console values\n3) Values from file\n";
                        bool binKey = true;
                        std :: cin.clear();
                        std :: cin >> keyChoice;
                        keysForInput new_key{keyChoice};
                        AVLtree new_tree(new_key);
                        new_tree.print();
                        while (binKey){
                            std :: cout << "~~Choose the operation\n1) Search item\n2) Delete item\n3) Insert item\n4) Exit\n";
                            std :: cin >> keyChoice;
                            switch (keyChoice) {
                                case 1:{
                                    std :: cout << "Enter the value you want tot search\n";
                                    std :: cin.clear();
                                    std :: cin >> keyChoice;
                                    if(new_tree.search(keyChoice,new_tree.GetRoot())) std :: cout << "Value found\n";
                                    else std :: cout << "Value not found\n";
                                    break;
                                }
                                case 2:{
                                    std :: cout << "Enter the value you want tot delete\n";
                                    std :: cin.clear();
                                    std :: cin >> keyChoice;
                                    new_tree.remove(keyChoice);
                                    new_tree.print();
                                    break;
                                }
                                case 3:{
                                    std :: cout << "Enter the value you want tot insert\n";
                                    std :: cin.clear();
                                    std :: cin >> keyChoice;
                                    new_tree.insert(keyChoice);
                                    new_tree.print();
                                    break;
                                }
                                case 4:{
                                    binKey = false;
                                    break;
                                }
                            }
                    }
                        break;
                }
                }
                break;
            }
            case 0:{
                keyRun = false;
                break;
            }
        }
    }
    system("pause");
    return 0;
}