#include <iostream>
#include <string>
#include <locale> // Potřebujeme pro použití std::wcout a std::wcin s Unicode

void printSpaces(int n) {
    for (int i = 0; i < n; ++i)
        std::wcout << L" ";
}

void printStars(int n) {
    for (int i = 0; i < n; ++i)
        std::wcout << L"*";
}

void printTree(int height) {
    for (int i = 0; i < height; ++i) {
        printSpaces(height - i - 1);
        printStars(2 * i + 1);
        std::wcout << std::endl;
    }
    printSpaces(height - 1);
    std::wcout << L"*" << std::endl;
}

int main() {
    int height;
    // Nastavení locale na "českou" locale pro správné zpracování českých znaků
    std::locale::global(std::locale("cs_CZ.UTF-8"));

    std::wcout << L"Zadejte výšku stromu: ";
    std::wcin >> height;

    printTree(height);

    return 0;
}
