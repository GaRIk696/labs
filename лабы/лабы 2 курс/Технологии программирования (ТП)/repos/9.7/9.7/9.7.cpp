#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// Функция для чтения слов из файла и возврата их в виде вектора
vector<string> readWordsFromFile(const string& filename) {
    ifstream inputFile(filename);
    vector<string> words;

    if (!inputFile.is_open()) {
        cerr << "Ошибка открытия файла: " << filename << endl;
        return words; // Возвращаем пустой вектор, если файл не открыт
    }

    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string word;
        // Читаем слова из строки
        while (iss >> word) {
            words.push_back(word); // Добавляем слово в вектор
        }
    }

    inputFile.close(); // Закрываем входной файл
    return words;
}

// Функция для перемешивания слов и записи их в выходной файл
void shuffleWordsAndWriteToFile(const vector<string>& words1, const vector<string>& words2, const string& outputFilename) {
    ofstream outputFile(outputFilename);

    if (!outputFile.is_open()) {
        cerr << "Ошибка открытия выходного файла." << endl;
        return;
    }

    size_t maxLength = max(words1.size(), words2.size());

    // Перемешиваем слова
    for (size_t i = 0; i < maxLength; ++i) {
        if (i < words1.size()) {
            outputFile << words1[i] << " "; // Записываем слово из первого файла
        }
        if (i < words2.size()) {
            outputFile << words2[i] << " "; // Записываем слово из второго файла
        }
    }

    outputFile.close(); // Закрываем выходной файл
}

int main() {
    setlocale(LC_ALL, "Russian");
    const string file1 = "test1.txt"; // Имя первого файла
    const string file2 = "test2.txt"; // Имя второго файла
    const string outputFileName = "test3.txt"; // Имя выходного файла

    // Чтение слов из файлов
    vector<string> wordsFromFile1 = readWordsFromFile(file1);
    vector<string> wordsFromFile2 = readWordsFromFile(file2);

    // Запись перемешанных слов в выходной файл
    shuffleWordsAndWriteToFile(wordsFromFile1, wordsFromFile2, outputFileName);

    cout << "Перемешивание завершено. Результат сохранен в файле " << outputFileName << endl;

    return 0;
}