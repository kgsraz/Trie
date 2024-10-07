#include "Trie.h"

// �����������
Trie::Trie() {
    root = new TrieNode();
}

// ����������
Trie::~Trie() {
    clear(root);
}

// ����� ��� ������� ������
void Trie::clear(TrieNode* node) {
    for (auto& pair : node->children) {
        clear(pair.second);
    }
    delete node;
}

// ����� ��� ���������� ����� � Trie
void Trie::insert(const std::string& word) {
    TrieNode* current = root;
    for (char ch : word) {
        if (current->children.find(ch) == current->children.end()) {
            current->children[ch] = new TrieNode();
        }
        current = current->children[ch];
    }
    current->isEndOfWord = true;
}

// ��������������� ����� ��� ����� �����������
void Trie::collectSuggestions(TrieNode* node, const std::string& prefix, std::vector<std::string>& suggestions) {
    if (node->isEndOfWord) {
        suggestions.push_back(prefix);
    }
    for (auto& pair : node->children) {
        collectSuggestions(pair.second, prefix + pair.first, suggestions);
    }
}

// ����� ��� ��������������
std::vector<std::string> Trie::autocomplete(const std::string& prefix) {
    TrieNode* current = root;
    std::vector<std::string> suggestions;

    // ����� ���� �� ��������
    for (char ch : prefix) {
        if (current->children.find(ch) == current->children.end()) {
            return suggestions; // ���������� ������ ������, ���� ������� �� ������
        }
        current = current->children[ch];
    }

    // ���� �����������
    collectSuggestions(current, prefix, suggestions);
    return suggestions;
}
