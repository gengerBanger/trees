#include <iostream>
#include "bin_tree.h"
#include "RedBlack_tree.h"
#include "tests.h"
#include "tree.h"
#include "AVL_tree.h"
#include <Windows.h>
#include <chrono>
#include <iomanip>
HANDLE h_1Console;
int main() {
    std :: cout << std :: setprecision(10);
    std :: cout.setf(std :: ios_base::fixed);
    h_1Console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h_1Console, 11);
    int keyChoice;
    bool keyRun = true;
    while (keyRun){
        std :: cout << "\t~~Which tree do you want ot build~~\n1) Binary\n2) AVL\n3) Red-black\n0) Exit\n";
        std :: cin.clear();
        std :: cin >> keyChoice;
        switch (keyChoice) {
            case 1:{
                std :: cout << "\t~~How you want to check the tree~~\n1) create tests\n2) create new tree\n";
                std :: cin.clear();
                std :: cin >> keyChoice;
                switch (keyChoice) {
                    case 1:{
                        std :: cout << "~~Enter the number of tests~~\n";
                        std :: cin.clear();
                        std :: cin >> keyChoice;
                        Test <BinTree> new_test(keyChoice);
                        SetConsoleTextAttribute(h_1Console, 14);
                        std :: cout << "\t\t~~Tests are ready~~\n";
                        SetConsoleTextAttribute(h_1Console, 11);
                    }
                    case 2:{
                        std :: cout <<"\t~~How you want to create a new tree~~\n1) Random values\n2) Console values\n3) Values from file\n";
                        bool binKey = true;
                        std :: cin.clear();
                        std :: cin >> keyChoice;
                        keysForInput new_key{keyChoice};
                        BinTree new_tree(new_key);
                        new_tree.print();
                        while (binKey){
                            std :: cout << "\t~~Choose the operation~~\n1) Search item\n2) Delete item\n3) Insert item\n4) List tree elements\n5) Delete tree\n";
                            std :: cin.clear();
                            std :: cin >> keyChoice;
                            switch (keyChoice) {
                                case 1:{
                                    std :: cout << "~~Enter the value you want tot search~~\n";
                                    std :: cin.clear();
                                    std :: cin >> keyChoice;
                                    auto start = std :: chrono::high_resolution_clock::now();
                                    if(new_tree.search(keyChoice,new_tree.GetRoot())){
                                        SetConsoleTextAttribute(h_1Console, 10);
                                        std :: cout << "~~Value found~~\n";
                                        SetConsoleTextAttribute(h_1Console, 11);
                                    }
                                    else{
                                        SetConsoleTextAttribute(h_1Console, 12);
                                        std :: cout << "~~Value not found~~\n";
                                        SetConsoleTextAttribute(h_1Console, 11);
                                    }
                                    auto finish = std :: chrono::high_resolution_clock::now();
                                    std :: chrono :: duration <float> duration = finish - start;
                                    SetConsoleTextAttribute(h_1Console, 14);
                                    std :: cout << "Search time ---> "<< duration.count()<<" sec\n";
                                    SetConsoleTextAttribute(h_1Console, 11);
                                    break;
                                }
                                case 2:{
                                    std :: cout << "~~Enter the value you want tot delete~~\n";
                                    std :: cin.clear();
                                    std :: cin >> keyChoice;
                                    auto start = std :: chrono::high_resolution_clock::now();
                                    new_tree.remove(keyChoice);
                                    auto finish = std :: chrono::high_resolution_clock::now();
                                    new_tree.print();
                                    std :: chrono :: duration <float> duration = finish - start;
                                    SetConsoleTextAttribute(h_1Console, 14);
                                    std :: cout << "Remove time ---> "<< duration.count()<<" sec\n";
                                    SetConsoleTextAttribute(h_1Console, 11);
                                    break;
                                }
                                case 3:{
                                    std :: cout << "~~Enter the value you want tot insert~~\n";
                                    std :: cin.clear();
                                    std :: cin >> keyChoice;
                                    auto start = std :: chrono::high_resolution_clock::now();
                                    new_tree.insert(keyChoice);
                                    auto finish = std :: chrono::high_resolution_clock::now();
                                    new_tree.print();
                                    std :: chrono :: duration <float> duration = finish - start;
                                    SetConsoleTextAttribute(h_1Console, 14);
                                    std :: cout << "Insert time ---> "<< duration.count()<<" sec\n";
                                    SetConsoleTextAttribute(h_1Console, 11);
                                    break;
                                }
                                case 4:{
                                    bool enumKey = true;
                                    while (enumKey){
                                        std :: cout <<"\t~~What enum do you want~~\n1) Straight \n2) Reverse\n3) Symmetrical\n4) Exit\n";
                                        std :: cin >> keyChoice;
                                        switch (keyChoice) {
                                            case 1:{
                                                std :: cout << "\tStraight enumeration : \n";
                                                auto start = std :: chrono::high_resolution_clock::now();
                                                new_tree.straightEnumeration(new_tree.GetRoot());
                                                auto finish = std :: chrono::high_resolution_clock::now();
                                                std :: chrono :: duration <float> duration = finish - start;
                                                std :: cout << '\n';
                                                SetConsoleTextAttribute(h_1Console, 14);
                                                std :: cout << "Straight enumeration time ---> "<< duration.count()<<" sec\n";
                                                SetConsoleTextAttribute(h_1Console, 11);
                                                break;
                                            }
                                            case 2:{
                                                std :: cout << "\tReverse enumeration : \n";
                                                auto start = std :: chrono::high_resolution_clock::now();
                                                new_tree.reverseEnumeration(new_tree.GetRoot());
                                                auto finish = std :: chrono::high_resolution_clock::now();
                                                std :: chrono :: duration <float> duration = finish - start;
                                                std :: cout << '\n';
                                                SetConsoleTextAttribute(h_1Console, 14);
                                                std :: cout << "Reverse enumeration time ---> "<< duration.count()<<" sec\n";
                                                SetConsoleTextAttribute(h_1Console, 11);
                                                break;
                                            }
                                            case 3:{
                                                std :: cout << "\tSymmetrical enumeration : \n";
                                                auto start = std :: chrono::high_resolution_clock::now();
                                                new_tree.symmetricalEnumeration(new_tree.GetRoot());
                                                auto finish = std :: chrono::high_resolution_clock::now();
                                                std :: chrono :: duration <float> duration = finish - start;
                                                std :: cout << '\n';
                                                SetConsoleTextAttribute(h_1Console, 14);
                                                std :: cout << "Symmetrical enumeration time ---> "<< duration.count()<<" sec\n";
                                                SetConsoleTextAttribute(h_1Console, 11);
                                                break;
                                            }
                                            case 4:{
                                                enumKey = false;
                                                new_tree.print();
                                                break;
                                            }
                                        }
                                    }
                                    break;
                                }
                                case 5:{
                                    binKey = false;
                                    system("cls");
                                    break;
                                }
                            }

                        }
                    }
                }
                break;
            }
            case 3:{
                std :: cout <<"\t~~How you want to create a new tree~~\n1) Random values\n2) Console values\n3) Values from file\n";
                bool binKey = true;
                std :: cin.clear();
                std :: cin >> keyChoice;
                keysForInput new_key{keyChoice};
                RedBlackTree new_tree(new_key);
                new_tree.print();
                while (binKey){
                    std :: cout << "\t~~Choose the operation~~\n1) Search item\n2) Delete item\n3) Insert item\n4) List tree elements\n5) Delete tree\n";
                    std :: cin >> keyChoice;
                    switch (keyChoice) {
                        case 1:{
                            std :: cout << "~~Enter the value you want tot search~~\n";
                            std :: cin.clear();
                            std :: cin >> keyChoice;
                            auto start = std :: chrono::high_resolution_clock::now();
                            if(new_tree.search(keyChoice,new_tree.GetRoot())){
                                SetConsoleTextAttribute(h_1Console, 10);
                                std :: cout << "~~Value found~~\n";
                                SetConsoleTextAttribute(h_1Console, 11);
                            }
                            else{
                                SetConsoleTextAttribute(h_1Console, 12);
                                std :: cout << "~~Value not found~~\n";
                                SetConsoleTextAttribute(h_1Console, 11);
                            }
                            auto finish = std :: chrono::high_resolution_clock::now();
                            std :: chrono :: duration <float> duration = finish - start;
                            SetConsoleTextAttribute(h_1Console, 14);
                            std :: cout << "Search time ---> "<< duration.count()<<" sec\n";
                            SetConsoleTextAttribute(h_1Console, 11);
                            break;
                        }
                        case 2:{
                            std :: cout << "~~Enter the value you want tot delete~~\n";
                            std :: cin.clear();
                            std :: cin >> keyChoice;
                            auto start = std :: chrono::high_resolution_clock::now();
                            new_tree.remove(keyChoice);
                            auto finish = std :: chrono::high_resolution_clock::now();
                            new_tree.print();
                            std :: chrono :: duration <float> duration = finish - start;
                            SetConsoleTextAttribute(h_1Console, 14);
                            std :: cout << "Remove time ---> "<< duration.count()<<" sec\n";
                            SetConsoleTextAttribute(h_1Console, 11);
                            break;
                        }
                        case 3:{
                            std :: cout << "~~Enter the value you want tot insert~~\n";
                            std :: cin.clear();
                            std :: cin >> keyChoice;
                            auto start = std :: chrono::high_resolution_clock::now();
                            new_tree.insert(keyChoice);
                            auto finish = std :: chrono::high_resolution_clock::now();
                            new_tree.print();
                            std :: chrono :: duration <float> duration = finish - start;
                            SetConsoleTextAttribute(h_1Console, 14);
                            std :: cout << "Insert time ---> "<< duration.count()<<" sec\n";
                            SetConsoleTextAttribute(h_1Console, 11);
                            break;
                        }
                        case 4:{
                            bool enumKey = true;
                            while (enumKey){
                                std :: cout <<"\t~~What enum do you want~~\n1) Straight \n2) Reverse\n3) Symmetrical\n4) Exit\n";
                                std :: cin >> keyChoice;
                                switch (keyChoice) {
                                    case 1:{
                                        std :: cout << "\tStraight enumeration : \n";
                                        auto start = std :: chrono::high_resolution_clock::now();
                                        new_tree.straightEnumeration(new_tree.GetRoot());
                                        auto finish = std :: chrono::high_resolution_clock::now();
                                        std :: chrono :: duration <float> duration = finish - start;
                                        std :: cout << '\n';
                                        SetConsoleTextAttribute(h_1Console, 14);
                                        std :: cout << "Straight enumeration time ---> "<< duration.count()<<" sec\n";
                                        SetConsoleTextAttribute(h_1Console, 11);
                                        break;
                                    }
                                    case 2:{
                                        std :: cout << "\tReverse enumeration : \n";
                                        auto start = std :: chrono::high_resolution_clock::now();
                                        new_tree.reverseEnumeration(new_tree.GetRoot());
                                        auto finish = std :: chrono::high_resolution_clock::now();
                                        std :: chrono :: duration <float> duration = finish - start;
                                        std :: cout << '\n';
                                        SetConsoleTextAttribute(h_1Console, 14);
                                        std :: cout << "Reverse enumeration time ---> "<< duration.count()<<" sec\n";
                                        SetConsoleTextAttribute(h_1Console, 11);
                                        break;
                                    }
                                    case 3:{
                                        std :: cout << "\tSymmetrical enumeration : \n";
                                        auto start = std :: chrono::high_resolution_clock::now();
                                        new_tree.symmetricalEnumeration(new_tree.GetRoot());
                                        auto finish = std :: chrono::high_resolution_clock::now();
                                        std :: chrono :: duration <float> duration = finish - start;
                                        std :: cout << '\n';
                                        SetConsoleTextAttribute(h_1Console, 14);
                                        std :: cout << "Symmetrical enumeration time ---> "<< duration.count()<<" sec\n";
                                        SetConsoleTextAttribute(h_1Console, 11);
                                        break;
                                    }
                                    case 4:{
                                        enumKey = false;
                                        new_tree.print();
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        case 5:{
                            binKey = false;
                            system("cls");
                            break;
                        }
                    }
                }
                break;
            }
            case 2:{
                std :: cout << "\t~~How you want to check the tree~~\n1) create tests\n2) create new tree\n";
                std :: cin.clear();
                std :: cin >> keyChoice;
                switch (keyChoice) {
                    case 1: {
                        std::cout << "~~Enter the number of tests~~\n";
                        std::cin.clear();
                        std::cin >> keyChoice;
                        Test<AVLtree> new_test(keyChoice);
                        SetConsoleTextAttribute(h_1Console, 14);
                        std :: cout << "\t\t~~Tests are ready~~\n";
                        SetConsoleTextAttribute(h_1Console, 11);
                    }
                    case 2:{
                        std :: cout <<"\t~~How you want to create a new tree~~\n1) Random values\n2) Console values\n3) Values from file\n";
                        bool binKey = true;
                        std :: cin.clear();
                        std :: cin >> keyChoice;
                        keysForInput new_key{keyChoice};
                        AVLtree new_tree(new_key);
                        new_tree.print();
                        while (binKey){
                            std :: cout << "\t~~Choose the operation~~\n1) Search item\n2) Delete item\n3) Insert item\n4) List tree elements\n5) Delete tree\n";
                            std :: cin >> keyChoice;
                            switch (keyChoice) {
                                case 1:{
                                    std :: cout << "~~Enter the value you want tot search~~\n";
                                    std :: cin.clear();
                                    std :: cin >> keyChoice;
                                    auto start = std :: chrono::high_resolution_clock::now();
                                    if(new_tree.search(keyChoice,new_tree.GetRoot())){
                                        SetConsoleTextAttribute(h_1Console, 10);
                                        std :: cout << "~~Value found~~\n";
                                        SetConsoleTextAttribute(h_1Console, 11);
                                    }
                                    else{
                                        SetConsoleTextAttribute(h_1Console, 12);
                                        std :: cout << "~~Value not found~~\n";
                                        SetConsoleTextAttribute(h_1Console, 11);
                                    }
                                    auto finish = std :: chrono::high_resolution_clock::now();
                                    std :: chrono :: duration <float> duration = finish - start;
                                    SetConsoleTextAttribute(h_1Console, 14);
                                    std :: cout << "Search time ---> "<< duration.count()<<" sec\n";
                                    SetConsoleTextAttribute(h_1Console, 11);
                                    break;
                                }
                                case 2:{
                                    std :: cout << "~~Enter the value you want tot delete~~\n";
                                    std :: cin.clear();
                                    std :: cin >> keyChoice;
                                    auto start = std :: chrono::high_resolution_clock::now();
                                    new_tree.remove(keyChoice);
                                    auto finish = std :: chrono::high_resolution_clock::now();
                                    new_tree.print();
                                    std :: chrono :: duration <float> duration = finish - start;
                                    SetConsoleTextAttribute(h_1Console, 14);
                                    std :: cout << "Remove time ---> "<< duration.count()<<" sec\n";
                                    SetConsoleTextAttribute(h_1Console, 11);
                                    break;
                                }
                                case 3:{
                                    std :: cout << "~~Enter the value you want tot insert~~\n";
                                    std :: cin.clear();
                                    std :: cin >> keyChoice;
                                    auto start = std :: chrono::high_resolution_clock::now();
                                    new_tree.insert(keyChoice);
                                    auto finish = std :: chrono::high_resolution_clock::now();
                                    new_tree.print();
                                    std :: chrono :: duration <float> duration = finish - start;
                                    SetConsoleTextAttribute(h_1Console, 14);
                                    std :: cout << "Insert time ---> "<< duration.count()<<" sec\n";
                                    SetConsoleTextAttribute(h_1Console, 11);
                                    break;
                                }
                                case 4:{
                                    bool enumKey = true;
                                    while (enumKey){
                                        std :: cout <<"\t~~What enum do you want~~\n1) Straight \n2) Reverse\n3) Symmetrical\n4) Exit\n";
                                        std :: cin >> keyChoice;
                                        switch (keyChoice) {
                                            case 1:{
                                                std :: cout << "\tStraight enumeration : \n";
                                                auto start = std :: chrono::high_resolution_clock::now();
                                                new_tree.straightEnumeration(new_tree.GetRoot());
                                                auto finish = std :: chrono::high_resolution_clock::now();
                                                std :: chrono :: duration <float> duration = finish - start;
                                                std :: cout << '\n';
                                                SetConsoleTextAttribute(h_1Console, 14);
                                                std :: cout << "Straight enumeration time ---> "<< duration.count()<<" sec\n";
                                                SetConsoleTextAttribute(h_1Console, 11);
                                                break;
                                            }
                                            case 2:{
                                                std :: cout << "\tReverse enumeration : \n";
                                                auto start = std :: chrono::high_resolution_clock::now();
                                                new_tree.reverseEnumeration(new_tree.GetRoot());
                                                auto finish = std :: chrono::high_resolution_clock::now();
                                                std :: chrono :: duration <float> duration = finish - start;
                                                std :: cout << '\n';
                                                SetConsoleTextAttribute(h_1Console, 14);
                                                std :: cout << "Reverse enumeration time ---> "<< duration.count()<<" sec\n";
                                                SetConsoleTextAttribute(h_1Console, 11);
                                                break;
                                            }
                                            case 3:{
                                                std :: cout << "\tSymmetrical enumeration : \n";
                                                auto start = std :: chrono::high_resolution_clock::now();
                                                new_tree.symmetricalEnumeration(new_tree.GetRoot());
                                                auto finish = std :: chrono::high_resolution_clock::now();
                                                std :: chrono :: duration <float> duration = finish - start;
                                                std :: cout << '\n';
                                                SetConsoleTextAttribute(h_1Console, 14);
                                                std :: cout << "Symmetrical enumeration time ---> "<< duration.count()<<" sec\n";
                                                SetConsoleTextAttribute(h_1Console, 11);
                                                break;
                                            }
                                            case 4:{
                                                enumKey = false;
                                                new_tree.print();
                                                break;
                                            }
                                        }
                                    }
                                    break;
                                }
                                case 5:{
                                    binKey = false;
                                    system("cls");
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