#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <codecvt>
#include <algorithm>

using namespace std;

int main() {
    // Установка локали для поддержки русского языка
    setlocale(LC_ALL, "Russian");

    // Имена файлов задаются автоматически
    wstring inputFileName = L"test1.txt";
    wstring outputFileName = L"test2.txt";
    wstring searchWord;

    wcout << L"Введите слово для поиска: ";
    wcin >> searchWord;

    // Открытие входного файла с поддержкой UTF-8
    wifstream inputFile(inputFileName);
    inputFile.imbue(locale(locale(), new codecvt_utf8<wchar_t>()));

    if (!inputFile.is_open()) {
        wcerr << L"Ошибка открытия входного файла: " << inputFileName << endl;
        return 1;
    }

    wofstream outputFile(outputFileName);
    outputFile.imbue(locale(locale(), new codecvt_utf8<wchar_t>()));

    if (!outputFile.is_open()) {
        wcerr << L"Ошибка открытия выходного файла: " << outputFileName << endl;
        return 1;
    }

    // Преобразование слова для поиска в нижний регистр
    wstring lowerSearchWord = searchWord;
    transform(lowerSearchWord.begin(), lowerSearchWord.end(), lowerSearchWord.begin(), ::towlower);

    wstring line;
    while (getline(inputFile, line)) {
        // Преобразование строки к нижнему регистру для нечувствительного к регистру поиска
        wstring currentLine = line;
        transform(currentLine.begin(), currentLine.end(), currentLine.begin(), ::towlower);

        if (currentLine.find(lowerSearchWord) != wstring::npos) {
            outputFile << line << endl; // Запись исходной строки в выходной файл
        }
    }

    inputFile.close();
    outputFile.close();

    wcout << L"Обработка завершена. Результат сохранен в файле " << outputFileName << endl;

    return 0;
}
