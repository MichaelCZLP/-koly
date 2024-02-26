#include <iostream>
#include <locale>

// Funkce pro prohození hodnot dvou proměnných pomocí ukazatelů
void swapValues(int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    // Čeština
    std::locale::global(std::locale("cs_CZ.UTF-8"));

    int a = 5, b = 10;

    std::wcout << L"Před prohozením:" << std::endl;
    std::wcout << L"a = " << a << L", b = " << b << std::endl;

    // Volání funkce pro prohození hodnot pomocí ukazatelů
    swapValues(&a, &b);

    std::wcout << L"Po prohození:" << std::endl;
    std::wcout << L"a = " << a << L", b = " << b << std::endl;

    return 0;
}
