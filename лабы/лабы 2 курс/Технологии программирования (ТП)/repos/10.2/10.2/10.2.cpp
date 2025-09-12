#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <iomanip> // Для манипуляторов вывода
using namespace std;

struct price {
    string tovar, magazin, stoimost;
};
price list[15];
int kol = 0;

void printTableHeader() {
    cout << left << setw(20) << "Название товара"
        << setw(20) << "Магазин"
        << setw(10) << "Стоимость" << "\n";
    cout << string(50, '-') << "\n";
}

void full() {
    printTableHeader();
    for (int i = 0; i <= kol; ++i) {
        cout << left << setw(20) << list[i].tovar
            << setw(20) << list[i].magazin
            << setw(10) << list[i].stoimost << " руб.\n";
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int n;
    int i = 0;
    int k = 0;
    int m = 0;
    int buffer[20];
    char a;
    string t1, t2, t3;

    ifstream fin("10.2.txt");
    if (!fin) {
        cout << "Ошибка при открытии файла!";
        return 1;
    }
    else {
        cout << "Введите стоимость: ";
        cin >> n;
        cout << "\n";

        while (!fin.eof()) {
            a = fin.get();
            if ((a != ' ') && (k == 0))
                list[i].tovar += a;
            if (a == ' ')
                k += 1;
            if ((a != ' ') && (k == 1))
                list[i].magazin += a;
            if ((a != ' ') && (a != '\n') && (k == 2) && (!fin.eof()))
                list[i].stoimost += a;
            if (a == '\n') {
                k = 0;
                ++i;
                ++kol;
            }
        }
    }

    // Сортировка списка
    for (int i = 0; i <= kol; ++i) {
        for (int j = 0; j <= kol - 1; ++j) {
            if (list[j].tovar > list[j + 1].tovar) {
                t1 = list[j].tovar;
                t2 = list[j].magazin;
                t3 = list[j].stoimost;
                list[j].tovar = list[j + 1].tovar;
                list[j].magazin = list[j + 1].magazin;
                list[j].stoimost = list[j + 1].stoimost;
                list[j + 1].tovar = t1;
                list[j + 1].magazin = t2;
                list[j + 1].stoimost = t3;
            }
        }
    }

    for (int i = 0; i <= kol; ++i)
        buffer[i] = atoi(list[i].stoimost.c_str());

    // Вывод полного списка товаров
    cout << "Полный список товаров\n";
    full();
    cout << "\n";

    // Вывод товаров, превышающих заданную стоимость
    cout << "Товары, стоимость которых равна или превышает заданную\n";
    printTableHeader();
    for (int i = 0; i <= kol; ++i) {
        if (buffer[i] >= n) {
            cout << left << setw(20) << list[i].tovar
                << setw(20) << list[i].magazin
                << setw(10) << list[i].stoimost << " руб.\n";
            ++m;
        }
    }

    if (m == 0)
        cout << "Таких товаров нет!";
    fin.close();
    return 0;
}
