#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h> // Для работы с SetConsoleCP и SetConsoleOutputCP
using namespace std;

const int NOTFOUND = -1;

struct Elem
{               // Описание структуры из 2-х компонент:
    string str; // строка для хранения слова
    int cnt;    // счетчик кол-ва появлений слова
};

vector<Elem> list; // Динамический массив структур

// Функция сравнения двух элементов структур
// Сортирует по убыванию частоты, а затем по алфавиту, если частота одинаковая
bool cmp_by_cnt(const Elem& lh, const Elem& rh)
{
    if (lh.cnt == rh.cnt)
        return lh.str < rh.str; // Сравнение строк по алфавиту
    return lh.cnt > rh.cnt;     // Сравнение по убыванию частоты
}

// Получить очередное слово с клавиатуры и записать в str
// Возвращает true, если это слово не "quit"
bool GetWord(string& str)
{
    cin >> str;
    return str != "quit";
}

// Поиск слова str в массиве list
// Возвращает индекс найденного элемента или NOTFOUND
int Search(const string& str)
{
    for (int i = 0; i < list.size(); ++i)
    {
        if (str == list[i].str)
            return i;
    }
    return NOTFOUND;
}

// Вывод списка слов и их частоты
void PrintList()
{
    for (int i = 0; i < list.size(); ++i)
        cout << "\nСлово <" << list[i].str << "> встретилось " << list[i].cnt << " раз.";
    cout << endl;
}

int main()
{
    // Устанавливаем кодировку для работы с русским языком
    SetConsoleCP(1251);        // Кодировка ввода
    SetConsoleOutputCP(1251); // Кодировка вывода

    string s; // Буфер для хранения очередного слова
    cout << "Введите слова. Для завершения введите \"quit\":\n";
    while (GetWord(s))
    {
        int pos = Search(s);
        if (pos != NOTFOUND)
        { // Слово уже встречалось
            list[pos].cnt++;
        }
        else
        { // Новое слово
            Elem tmp;
            tmp.str = s;
            tmp.cnt = 1;
            list.push_back(tmp);
        }
    }

    // Сортировка списка
    sort(list.begin(), list.end(), cmp_by_cnt);

    // Вывод списка
    PrintList();
    return 0;
}
