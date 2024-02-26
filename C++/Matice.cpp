#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip> // Pro výstup v tabulce

// Struktura pro uložení matice
struct Matrix {
    std::vector<std::vector<int>> data;
    int rows;
    int cols;
};

// Funkce pro načtení matice od uživatele
Matrix readMatrix() {
    Matrix mat;
    std::string sizeInput;

    std::cout << "Zadejte rozměr matice ve formátu 'ŘÁDKYxSLOUPCE např. 2x2': ";
    std::cin >> sizeInput;

    char x;
    std::stringstream sizeStream(sizeInput);
    sizeStream >> mat.rows >> x >> mat.cols;

    if (x != 'x') {
        std::cerr << "Nesprávný formát rozměru matice." << std::endl;
        return { {}, 0, 0 };
    }

    std::cout << "Zadejte prvky matice:" << std::endl;
    for (int i = 0; i < mat.rows; ++i) {
        std::vector<int> row;
        for (int j = 0; j < mat.cols; ++j) {
            int val;
            std::cin >> val;
            row.push_back(val);
        }
        mat.data.push_back(row);
    }

    return mat;
}

// Funkce pro výpis matice
void printMatrix(const Matrix& mat) {
    std::cout << "Matice:" << std::endl;
    for (const auto& row : mat.data) {
        for (int val : row) {
            std::cout << std::setw(5) << val;
        }
        std::cout << std::endl;
    }
}

// Funkce pro sečtení dvou matic
Matrix addMatrices(const Matrix& mat1, const Matrix& mat2) {
    if (mat1.rows != mat2.rows || mat1.cols != mat2.cols) {
        std::cerr << "Nelze sečíst matice: rozdílné rozměry." << std::endl;
        return { {}, 0, 0 };
    }

    Matrix result = { mat1.data, mat1.rows, mat1.cols };

    for (int i = 0; i < mat1.rows; ++i) {
        for (int j = 0; j < mat1.cols; ++j) {
            result.data[i][j] += mat2.data[i][j];
        }
    }

    return result;
}

// Funkce pro odečtení dvou matic
Matrix subtractMatrices(const Matrix& mat1, const Matrix& mat2) {
    if (mat1.rows != mat2.rows || mat1.cols != mat2.cols) {
        std::cerr << "Nelze odečíst matice: rozdílné rozměry." << std::endl;
        return { {}, 0, 0 };
    }

    Matrix result = { mat1.data, mat1.rows, mat1.cols };

    for (int i = 0; i < mat1.rows; ++i) {
        for (int j = 0; j < mat1.cols; ++j) {
            result.data[i][j] -= mat2.data[i][j];
        }
    }

    return result;
}

// Funkce pro násobení dvou matic
Matrix multiplyMatrices(const Matrix& mat1, const Matrix& mat2) {
    if (mat1.cols != mat2.rows) {
        std::cerr << "Nelze vynásobit matice: nesprávné rozměry." << std::endl;
        return { {}, 0, 0 };
    }

    Matrix result;
    result.rows = mat1.rows;
    result.cols = mat2.cols;
    result.data.resize(result.rows, std::vector<int>(result.cols, 0));

    for (int i = 0; i < mat1.rows; ++i) {
        for (int j = 0; j < mat2.cols; ++j) {
            for (int k = 0; k < mat1.cols; ++k) {
                result.data[i][j] += mat1.data[i][k] * mat2.data[k][j];
            }
        }
    }

    return result;
}

int main() {
    // Nastavení češtiny jako výchozí locale
    std::locale::global(std::locale(""));

    // Načtení první matice
    std::cout << "První matice:" << std::endl;
    Matrix matrix1 = readMatrix();

    // Načtení druhé matice
    std::cout << "Druhá matice:" << std::endl;
    Matrix matrix2 = readMatrix();

    // Sčítání matic
    Matrix sum = addMatrices(matrix1, matrix2);
    std::cout << "Součet matic:" << std::endl;
    printMatrix(sum);

    // Odečítání matic
    Matrix difference = subtractMatrices(matrix1, matrix2);
    std::cout << "Rozdíl matic:" << std::endl;
    printMatrix(difference);

    // Násobení matic
    Matrix product = multiplyMatrices(matrix1, matrix2);
    std::cout << "Součin matic:" << std::endl;
    printMatrix(product);

    return 0;
}
