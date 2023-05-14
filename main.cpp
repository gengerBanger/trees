#include <iostream>
#include "bin_tree.h"
#include "tests.h"
int main() {
    int keyChoice;
    bool keyRun = true;
    while (keyRun){
        std :: cout << "~~How you want to check the program\n1) create tests\n2) create new tree\n0) Exit\n";
        std :: cin.clear();
        while(std :: cin.get() != '\n');
        std :: cin >> keyChoice;
        switch (keyChoice) {
            case 1:{
                std :: cout << "Enter the number of tests\n";
                std :: cin.clear();
                while(std :: cin.get() != '\n');
                std :: cin >> keyChoice;
                Test new_test(keyChoice);
            }
            case 2:{
                std :: cout <<"~~How you want to create a new tree?\n1) Random values\n2) Console values\n3) Values from file\n";
                std :: cin.clear();
                while(std :: cin.get() != '\n');
                std :: cin >> keyChoice;
                keysForInput new_key{keyChoice};
                BinTree new_tree(new_key);
                new_tree.print();
            }
            case 0:{
                keyRun = false;
            }
        }

    }


    system("pause");
    return 0;
}