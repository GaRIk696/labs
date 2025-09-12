#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <codecvt>

using namespace std;

int main() {
    // Установка локали для корректного отображения русского текста
    setlocale(LC_ALL, "Russian");

    // Автоматически заданные имена файлов
    wstring inputFileName = L"test1.txt";
    wstring outputFileName = L"test2.txt";

    // Открываем входной файл с поддержкой UTF-8
    wifstream inputFile(inputFileName);
    inputFile.imbue(locale(locale(), new codecvt_utf8<wchar_t>()));

    // Открываем выходной файл с поддержкой UTF-8
    wofstream outputFile(outputFileName);
    outputFile.imbue(locale(locale(), new codecvt_utf8<wchar_t>()));

    // Проверяем, удалось ли открыть входной файл
    if (!inputFile.is_open()) {
        wcerr << L"Ошибка при открытии входного файла: " << inputFileName << endl;
        return 1; // Завершаем программу с ошибкой
    }

    // Проверяем, удалось ли открыть выходной файл
    if (!outputFile.is_open()) {
        wcerr << L"Ошибка при открытии выходного файла: " << outputFileName << endl;
        return 1; // Завершаем программу с ошибкой
    }

    // Копирование содержимого
    wstring line;
    while (getline(inputFile, line)) { // Считываем построчно
        outputFile << line << endl;   // Записываем в выходной файл
    }

    // Закрываем файлы
    inputFile.close();
    outputFile.close();

    wcout << L"Содержимое файла успешно скопировано из " << inputFileName
        << L" в " << outputFileName << endl;

    return 0; // Успешное завершение программы
}
