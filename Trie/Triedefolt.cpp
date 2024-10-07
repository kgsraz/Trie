#include "Trie.h"

// Конструктор
Trie::Trie() {
    root = new TrieNode();
}

// Деструктор
Trie::~Trie() {
    clear(root);
}

// Метод для очистки памяти
void Trie::clear(TrieNode* node) {
    for (auto& pair : node->children) {
        clear(pair.second);
    }
    delete node;
}

// Метод для добавления слова в Trie
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

// Вспомогательный метод для сбора предложений
void Trie::collectSuggestions(TrieNode* node, const std::string& prefix, std::vector<std::string>& suggestions) {
    if (node->isEndOfWord) {
        suggestions.push_back(prefix);
    }
    for (auto& pair : node->children) {
        collectSuggestions(pair.second, prefix + pair.first, suggestions);
    }
}

// Метод для автодополнения
std::vector<std::string> Trie::autocomplete(const std::string& prefix) {
    TrieNode* current = root;
    std::vector<std::string> suggestions;

    // Поиск узла по префиксу
    for (char ch : prefix) {
        if (current->children.find(ch) == current->children.end()) {
            return suggestions; // Возвращаем пустой вектор, если префикс не найден
        }
        current = current->children[ch];
    }

    // Сбор предложений
    collectSuggestions(current, prefix, suggestions);
    return suggestions;
}
