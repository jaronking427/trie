#include <iostream> 
#include <string> 
#include <queue> 

struct trieNode{
    char key = ' ';
    trieNode * children[26];
    bool end = true;
    int searched = 0;
};

class Trie{
private:
    trieNode * root;
    trieNode * createNode(char key);
    void printListHelper(trieNode * currentNode, std::string word);
    void printSuggestionsHelper(trieNode * currentNode, std::string word);
public:
    Trie();
    void printList();
    void insertItem(std::string input);
    bool searchItem(std::string input);
    void printSuggestions(std::string input);
};
bool convertToLower(std::string &input);
