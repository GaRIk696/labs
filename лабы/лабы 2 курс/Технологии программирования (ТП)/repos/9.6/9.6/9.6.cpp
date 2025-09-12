#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <codecvt>
#include <sstream>

using namespace std;

// Функция для копирования слов из файла в выходной файл
void copyWordsWithLineNumbers(const wstring& sourceFileName, wofstream& outputFile) {
    wifstream inputFile(sourceFileName);
    inputFile.imbue(locale(locale(""), new codecvt_utf8<wchar_t>()));

    // Проверка открытия входного файла
    if (!inputFile.is_open()) {
        wcerr << L"Ошибка открытия файла: " << sourceFileName << endl;
        return;
    }

    wstring line;
    int lineNumber = 1; // Номер строки
    int wordCount = 0;  // Счетчик слов

    // Запись заголовка для файла
    outputFile << L"Содержимое файла: " << sourceFileName << endl;

    // Чтение файла построчно
    while (getline(inputFile, line)) {
        wstringstream lineStream(line);
        wstring word;

        // Извлечение слов из строки
        while (lineStream >> word) {
            outputFile << lineNumber << L": " << word << endl;
            wordCount++;
        }

        lineNumber++; // Увеличиваем номер строки
    }

    inputFile.close(); // Закрытие входного файла

    // Вывод количества скопированных слов
    outputFile << L"Всего слов из файла " << sourceFileName << L": " << wordCount << endl;
    outputFile << endl;

    wcout << L"Скопировано " << wordCount << L" слов из файла: " << sourceFileName << endl;
}

int main() {
    // Установка локали для работы с русским текстом
    setlocale(LC_ALL, "Russian");

    // Имена входных и выходного файлов
    const wstring file1 = L"test1.txt";
    const wstring file2 = L"test2.txt";
    const wstring outputFileName = L"test3.txt";

    // Открытие выходного файла с поддержкой UTF-8
    wofstream outputFile(outputFileName);
    outputFile.imbue(locale(locale(""), new codecvt_utf8<wchar_t>()));

    // Проверка открытия выходного файла
    if (!outputFile.is_open()) {
        wcerr << L"Ошибка открытия выходного файла: " << outputFileName << endl;
        return 1;
    }

    // Копирование слов из обоих файлов
    wcout << L"Начинается копирование слов из файлов..." << endl;
    copyWordsWithLineNumbers(file1, outputFile);
    copyWordsWithLineNumbers(file2, outputFile);

    outputFile.close(); // Закрытие выходного файла

    wcout << L"Копирование завершено. Содержимое файлов " << file1 << L" и " << file2
        << L" скопировано в " << outputFileName << endl;

    return 0;
}
