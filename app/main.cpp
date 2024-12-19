#include <iostream>
#include "../code/trie.hpp"

void clearScreen();
int main(){
    Trie structure = Trie();
    int choice;
    std::string item;
    while(true){
        std::cout << "[1] - Insert an item\n" 
            << "[2] - Search an item\n"
            << "[3] - Test autocomplete\n" 
            << "[4] - Print all words\n"
            << "[5] - Quit "<< std::endl;

        std::cin >> choice;
        switch(choice){
            case 1:
                clearScreen();
                std::cout << "Please enter a string:" << std::endl;
                std::cin >> item; 
                structure.insertItem(item);
                clearScreen();
                break;
            case 2:
                clearScreen();
                std::cout << "Please enter a string:" << std::endl;
                std::cin >> item;
                if(structure.searchItem(item)){
                    std::cout << item << " found" << std::endl;
                }
                else
                    std::cout << item << " not found" << std::endl;
                break;
            case 3:
                std::cout << "Enter Query:";
                std::cin >> item;
                clearScreen();
                structure.printSuggestions(item);
                break;
            case 4:
                clearScreen();
                structure.printList();
                break;
            case 5:
                return 0;
                break;
            default:
                std::cout << "Please enter a valid number!" << std::endl;
                break;

        }
    }
    return 0;
}

void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}