<<<<<<< HEAD
﻿#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib> // Pro volání externího procesu
#include <algorithm>
#include <locale> // Kde domov můj

int main() {
    // Voda hučí po lučinách
    std::locale::global(std::locale("cs_CZ.UTF-8"));

    // Unicode
    std::wcout.imbue(std::locale("cs_CZ.UTF-8"));

    // Jelikož má každý uživatel vlastní sérii čísel, která je dostupna pouze při přihlášení, 
    // uploadoval jsem soubor s čísly na externí stránku.
    // Kdyby náhodou nefungovala, je soubor přiložen jako "AOC.txt"

    std::string url = "https://filebin.net/zx3h8rz2smc33rtn/AOC.txt";
    std::string filePath = "downloaded_input.txt";

    // Nechce se mi kvůli HTTP instalovat další knihovny, používám obcházku přes Powershell
    // Zvažován byl ale curl
    std::ostringstream command;
    command << "powershell.exe -Command \"(New-Object System.Net.WebClient).DownloadFile('" << url << "', '" << filePath << "')\"";

    // Spuštění příkazu a kontrola návratové hodnoty
    int status = std::system(command.str().c_str());
    if (status != 0) {
        std::cerr << "Chyba při stahování obsahu z URL." << std::endl;
        return EXIT_FAILURE;
    }

    // Otevření staženého souboru
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Chyba při otevírání staženého souboru." << std::endl;
        return EXIT_FAILURE;
    }

    // Čtení čísel ze souboru
    std::vector<int> numbers;
    int num;
    while (file >> num) {
        numbers.push_back(num);
    }

    // Hledání dvou čísel s součtem 2020
    int result = 0;
    for (size_t i = 0; i < numbers.size(); ++i) {
        for (size_t j = i + 1; j < numbers.size(); ++j) {
            if (numbers[i] + numbers[j] == 2020) {
                result = numbers[i] * numbers[j];
                std::wcout << L"První číslo: " << numbers[i] << std::endl;
                std::wcout << L"Druhé číslo: " << numbers[j] << std::endl;
                std::wcout << L"Součin: " << result << std::endl;
                return EXIT_SUCCESS;
            }
        }
    }

    std::wcout << L"Nepodařilo se najít dvě čísla s součtem 2020." << std::endl;
    return EXIT_SUCCESS;
}
=======
﻿#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib> // Pro volání externího procesu
#include <algorithm>
#include <locale> // Kde domov můj

int main() {
    // Voda hučí po lučinách
    std::locale::global(std::locale("cs_CZ.UTF-8"));

    // Unicode
    std::wcout.imbue(std::locale("cs_CZ.UTF-8"));

    // Jelikož má každý uživatel vlastní sérii čísel, která je dostupna pouze při přihlášení, 
    // uploadoval jsem soubor s čísly na externí stránku.
    // Kdyby náhodou nefungovala, je soubor přiložen jako "AOC.txt"

    std::string url = "https://filebin.net/zx3h8rz2smc33rtn/AOC.txt";
    std::string filePath = "downloaded_input.txt";

    // Nechce se mi kvůli HTTP instalovat další knihovny, používám obcházku přes Powershell
    // Zvažován byl ale curl
    std::ostringstream command;
    command << "powershell.exe -Command \"(New-Object System.Net.WebClient).DownloadFile('" << url << "', '" << filePath << "')\"";

    // Spuštění příkazu a kontrola návratové hodnoty
    int status = std::system(command.str().c_str());
    if (status != 0) {
        std::cerr << "Chyba při stahování obsahu z URL." << std::endl;
        return EXIT_FAILURE;
    }

    // Otevření staženého souboru
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Chyba při otevírání staženého souboru." << std::endl;
        return EXIT_FAILURE;
    }

    // Čtení čísel ze souboru
    std::vector<int> numbers;
    int num;
    while (file >> num) {
        numbers.push_back(num);
    }

    // Hledání dvou čísel s součtem 2020
    int result = 0;
    for (size_t i = 0; i < numbers.size(); ++i) {
        for (size_t j = i + 1; j < numbers.size(); ++j) {
            if (numbers[i] + numbers[j] == 2020) {
                result = numbers[i] * numbers[j];
                std::wcout << L"První číslo: " << numbers[i] << std::endl;
                std::wcout << L"Druhé číslo: " << numbers[j] << std::endl;
                std::wcout << L"Součin: " << result << std::endl;
                return EXIT_SUCCESS;
            }
        }
    }

    std::wcout << L"Nepodařilo se najít dvě čísla s součtem 2020." << std::endl;
    return EXIT_SUCCESS;
}
>>>>>>> 727a7108fc9eb87adf1e9beabb9f3060274c9ed1
