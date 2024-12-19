#include <iostream> 
#include <string>
#include <queue>
#include "trie.hpp"

Trie::Trie(){
    root = new trieNode;
    for(int i=0; i<26; i++){
        root->children[i] = nullptr;
    }
}
void Trie::insertItem(std::string input){
    if(!convertToLower(input)){
        std::cout << "Error: Please use characters a-z" << std::endl;
    }
    trieNode * currentNode = root;
    for(int i=0; i<input.length(); i++){
        if(currentNode->children[static_cast<int>(input[i])%26]){
            currentNode = currentNode->children[static_cast<int>(input[i])%26];
            continue;
        }
        currentNode->end = false;
        currentNode->children[static_cast<int>(input[i])%26] = createNode(input[i]);
        currentNode = currentNode->children[static_cast<int>(input[i])%26];
    }
}
bool Trie::searchItem(std::string input){
    trieNode * currentNode = root;
    for(int i=0; i<input.length(); i++){
        currentNode = currentNode->children[static_cast<int>(input[i])%26];
        if(!currentNode){
            return false;
        }
    }
    currentNode->searched++;
    return true;
}
trieNode * Trie::createNode(char key){
    trieNode * newNode = new trieNode;
    newNode->key = key;
    for(int i=0; i<26; i++){
        newNode->children[i] = nullptr;
    }
    return newNode;
}
void Trie::printListHelper(trieNode * currentNode, std::string word){
    if(currentNode->end){
        std::cout << word << std::endl;
        return;
    }
    for(int i=0; i<26; i++){
        if(currentNode->children[i]){
            printListHelper(currentNode->children[i], word+currentNode->children[i]->key);
        }
    }
    return;
}
void Trie::printList(){
    printListHelper(root, "");
}
bool convertToLower(std::string &input){
    for(int i=0; i<input.length(); i++){
        if(isalpha(input[i])){
            if(isupper(input[i])){
                input[i] = tolower(input[i]);
            }
        }
        else{
            return false;
        } 
    }
    return true;
}
void Trie::printSuggestions(std::string input){
    trieNode * currentNode = root;
    for(int i=0; i<static_cast<int>(input.length()); i++){
        if(!currentNode->children[static_cast<int>(input[i])%26]){
            std::cout << "No results found" << std::endl;
            return;
        }
        else{
            currentNode = currentNode->children[static_cast<int>(input[i])%26];
        }
    }
    printListHelper(currentNode, input);
}