#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    ifstream inputFile("test1.txt");
    ofstream outputFile("test2.txt");

    if (!inputFile.is_open()) {
        cerr << "Ошибка открытия входного файла." << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cerr << "Ошибка открытия выходного файла." << endl;
        inputFile.close();
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        string result = "";
        bool spaceFound = false;

        for (char c : line) {
            if (c == ' ' || c == '\t') {
                if (!spaceFound) {
                    result += ' ';
                    spaceFound = true;
                }
            }
            else {
                result += c;
                spaceFound = false;
            }
        }
        outputFile << result << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "Текст обработан. Результат сохранен в test2.txt" << endl;
    return 0;
}