#include <iostream>
#include <locale> 

// Funkce pro výpočet faktoriálu
unsigned long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    // Zase čeština
    std::locale::global(std::locale("cs_CZ.UTF-8"));

    int number;
    std::wcout << L"Zadejte číslo pro výpočet faktoriálu: ";
    std::wcin >> number;

    // Ošetření vstupu pro záporná čísla
    if (number < 0) {
        std::wcout << L"Faktoriál nelze spočítat pro záporné číslo." << std::endl;
        return 1;
    }

    unsigned long long result = factorial(number);
    std::wcout << L"Faktoriál čísla " << number << L" je: " << result << std::endl;

    return 0;
}
