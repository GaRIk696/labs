#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <locale>
#include <codecvt>

using namespace std;

// Функция для очистки строки от знаков препинания 
wstring cleanString(wstring str) {
    wstring result = L"";
    for (wchar_t c : str) {
        if (iswalpha(c)) {
            result += towlower(c);
        }
    }
    return result;
}

int main() {
    // Установка локали для корректной работы с русским текстом
    setlocale(LC_ALL, "Russian");

    // Имя входного файла задано автоматически
    wstring filename = L"test1.txt";

    // Открытие файла в UTF-8
    wifstream inputFile(filename, ios::in);
    inputFile.imbue(locale(locale(""), new codecvt_utf8<wchar_t>));

    if (!inputFile.is_open()) {
        wcerr << L"Ошибка открытия файла: " << filename << endl;
        return 1;
    }

    map<wstring, int> wordCounts;
    wstring longestWord;
    wstring word;

    while (inputFile >> word) {
        wstring cleanedWord = cleanString(word);
        if (cleanedWord.empty()) continue;

        wordCounts[cleanedWord]++;
        if (cleanedWord.length() > longestWord.length()) {
            longestWord = cleanedWord;
        }
    }

    inputFile.close();

    if (longestWord.empty()) {
        wcout << L"Файл пуст или содержит только знаки препинания." << endl;
        return 0;
    }

    wcout << L"Самое длинное слово: " << longestWord << endl;
    wcout << L"Количество повторений: " << wordCounts[longestWord] << endl;

    return 0;
}
