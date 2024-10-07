#pragma once
#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

class TrieNode {
public:
    std::map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class Trie {
private:
    TrieNode* root;

    void collectSuggestions(TrieNode* node, const std::string& prefix, std::vector<std::string>& suggestions);

public:
    Trie();
    ~Trie();

    void insert(const std::string& word);
    std::vector<std::string> autocomplete(const std::string& prefix);
    void clear(TrieNode* node);
};

#endif // TRIE_H
