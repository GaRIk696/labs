#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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
        stringstream ss(line);
        string word1, word2;
        bool firstWord = true;

        while (ss >> word1) {
            if (firstWord) {
                firstWord = false;
                if (ss >> word2) {
                    outputFile << word2 << " " << word1 << " ";
                }
                else {
                    outputFile << word1 << " ";
                }
            }
            else {
                firstWord = true;
                outputFile << word1 << " ";
            }
        }
        outputFile << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}