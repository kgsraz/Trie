
#include <iostream>
#include <vector>
#include "Trie.h"

int main() {
    setlocale(LC_ALL, "RU");
    Trie trie;

    // Заполнение Trie предустановленным словарем
    std::vector<std::string> dictionary = { "apple", "appetite", "application", "banana", "band", "bandana", "bat", "biography" };
    for (const std::string& word : dictionary) {
        trie.insert(word);
    }

    std::string input;
    std::cout << "Введите префикс для автодополнения. Для выхода введите 'exit': " << std::endl;

    while (true) {
        std::getline(std::cin, input);
        if (input == "exit") {
            break;
        }

        std::vector<std::string> suggestions = trie.autocomplete(input);

        if (suggestions.empty()) {
            std::cout << "Нет предложений для: " << input << std::endl;
        }
        else {
            std::cout << "Предложения: ";
            for (const std::string& suggestion : suggestions) {
                std::cout << suggestion << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}