#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <locale>
#include <cstdlib> 
#include <shlobj.h>
#pragma comment(lib, "Shell32.lib")
// Knihovny pro práci s textem a přístupu k ploše



// SOUBOR questions.txt musí být přítomen na ploše!



struct Question {
    std::wstring question;
    std::vector<std::wstring> options;
    char correctOption;
};

std::wstring getDesktopPath() {
    wchar_t* desktopPath;
    if (SUCCEEDED(SHGetKnownFolderPath(FOLDERID_Desktop, 0, NULL, &desktopPath))) {
        std::wstring result(desktopPath);
        CoTaskMemFree(desktopPath);
        return result;
    }
    else {
        std::wcerr << L"Nelze získat cestu k ploše." << std::endl;
        exit(EXIT_FAILURE);
    }
}

std::vector<Question> loadQuestions(const std::string& filename) {
    std::wstring desktopPath = getDesktopPath();
    std::wstring fullPath = desktopPath + L"\\" + std::wstring(filename.begin(), filename.end());
    std::wifstream file(fullPath);
    file.imbue(std::locale("cs_CZ.UTF-8"));

    if (!file.is_open()) {
        std::wcerr << L"Chyba při otevírání souboru " << fullPath << std::endl;
        exit(EXIT_FAILURE);
    }

    std::vector<Question> questions;
    std::wstring line;

    while (std::getline(file, line)) {
        Question q;
        q.question = line;

        for (int i = 0; i < 3; ++i) {
            if (!std::getline(file, line)) {
                std::wcerr << L"Chyba formátu souboru " << fullPath << std::endl;
                exit(EXIT_FAILURE);
            }
            q.options.push_back(line);
        }

        wchar_t correctOption;
        if (!(file >> correctOption)) {
            std::wcerr << L"Chyba formátu souboru " << fullPath << std::endl;
            exit(EXIT_FAILURE);
        }
        file.ignore(); // Ignorujeme zbytek řádku

        q.correctOption = static_cast<char>(correctOption);
        questions.push_back(q);

        // Ignorujeme prázdný řádek mezi otázkami
        std::getline(file, line);
    }

    file.close();
    return questions;
}

int takeTest(const std::vector<Question>& questions) {
    int score = 0;
    wchar_t userAnswer;

    for (const auto& q : questions) {
        std::wcout << q.question << std::endl;
        for (int i = 0; i < 3; ++i) {
            std::wcout << wchar_t('a' + i) << L". " << q.options[i] << std::endl;
        }

        std::wcout << L"Vyberte odpověď (a, b, c): ";
        std::wcin >> userAnswer;

        if (userAnswer != L'a' && userAnswer != L'b' && userAnswer != L'c') {
            std::wcout << L"Neplatná odpověď. Zadejte prosím znovu." << std::endl;
            continue;
        }

        if (userAnswer == q.correctOption) {
            std::wcout << L"Správně!" << std::endl;
            ++score;
        }
        else {
            std::wcout << L"Špatně! Správná odpověď byla: " << q.correctOption << std::endl;
        }
    }

    return score;
}

int main() {
    std::locale::global(std::locale("cs_CZ.UTF-8"));

    std::vector<Question> questions = loadQuestions("questions.txt");
    int score = takeTest(questions);

    std::wcout << L"Konec testu. Počet správných odpovědí: " << score << L"/" << questions.size() << std::endl;

    return 0;
}

// Formát souboru questions.txt :
// Otázka
// možnost1
// možnost2
// možnost3
// správná odpověď [a,b,c] - Úpravou této hodnoty se změní správná odpověď
// ~
// ZNOVU

// Formátování je absolutní a kód nepočítá se vícero správnými odpověďmi nebo jiným množstvím možností 
// Je však možné následovat strukturu a přidávat další otázky
