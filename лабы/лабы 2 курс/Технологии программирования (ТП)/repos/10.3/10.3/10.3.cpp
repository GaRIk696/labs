#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <iomanip> // Для манипуляторов вывода
using namespace std;

struct student {
    string name, group, marks;
    int mark[10];
};
student list[15];
int kol = 0;

void printTableHeader() {
    cout << left << setw(30) << "ФИО студента"
        << setw(15) << "Группа"
        << "Оценки (5 шт.)" << "\n";
    cout << string(60, '-') << "\n";
}

void full() {
    printTableHeader();
    for (int i = 0; i <= kol; ++i) {
        cout << left << setw(30) << list[i].name
            << setw(15) << list[i].group;
        for (int j = 0; j < 5; ++j)
            cout << list[i].mark[j] << " ";
        cout << "\n";
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int n, stop;
    int i = 0, k = 0, m = 0;
    int buffer[20];
    double sredn[20];
    string a, t1, t2;
    int t3[10];
    double t4;

    ifstream fin("10.3.txt");
    if (!fin) {
        cout << "Ошибка при открытии файла!";
        return 1;
    }
    else {
        cout << "Введите минимальную оценку: ";
        cin >> n;
        cout << "\n";

        while (!fin.eof()) {
            a = fin.get();
            if (a == " ")
                k += 1;
            if (k <= 2)
                list[i].name += a;
            if ((a != " ") && (k == 3))
                list[i].group += a;
            if ((a != " ") && (a != "\n") && (k == 4) && (!fin.eof()))
                list[i].marks += a;
            if (a == "\n") {
                k = 0;
                ++i;
                ++kol;
            }
        }
    }

    for (int i = 0; i <= kol; ++i) {
        buffer[i] = atoi(list[i].marks.c_str());
        list[i].mark[0] = buffer[i] / 10000;
        list[i].mark[1] = (buffer[i] - list[i].mark[0] * 10000) / 1000;
        list[i].mark[2] = (buffer[i] - list[i].mark[0] * 10000 - list[i].mark[1] * 1000) / 100;
        list[i].mark[3] = (buffer[i] - list[i].mark[0] * 10000 - list[i].mark[1] * 1000 - list[i].mark[2] * 100) / 10;
        list[i].mark[4] = (buffer[i] - list[i].mark[0] * 10000 - list[i].mark[1] * 1000 - list[i].mark[2] * 100 - list[i].mark[3] * 10);
        sredn[i] = 0;
        for (int j = 0; j < 5; ++j) {
            sredn[i] += list[i].mark[j];
        }
        sredn[i] /= 5;
    }

    // Сортировка по среднему баллу
    for (int i = 0; i <= kol; ++i) {
        for (int j = 0; j <= kol - 1; ++j) {
            if (sredn[j] > sredn[j + 1]) {
                t1 = list[j].name;
                t2 = list[j].group;
                for (int l = 0; l < 5; ++l)
                    t3[l] = list[j].mark[l];
                t4 = sredn[j];
                list[j].name = list[j + 1].name;
                list[j].group = list[j + 1].group;
                for (int l = 0; l < 5; ++l)
                    list[j].mark[l] = list[j + 1].mark[l];
                sredn[j] = sredn[j + 1];
                list[j + 1].name = t1;
                list[j + 1].group = t2;
                for (int l = 0; l < 5; ++l)
                    list[j + 1].mark[l] = t3[l];
                sredn[j + 1] = t4;
            }
        }
    }

    // Полный список студентов
    cout << "Полная информация о студентах:\n";
    full();
    cout << "\n";

    // Студенты с оценками выше заданного
    cout << "Студенты, имеющие хотя бы одну оценку выше " << n << ":\n";
    printTableHeader();
    for (int i = 0; i <= kol; ++i) {
        stop = 0;
        for (int j = 0; j < 5; ++j) {
            if ((list[i].mark[j] > n) && (stop == 0)) {
                cout << left << setw(30) << list[i].name
                    << setw(15) << list[i].group;
                for (int l = 0; l < 5; ++l)
                    cout << list[i].mark[l] << " ";
                cout << "\n";
                ++m;
                stop = 1;
            }
        }
    }

    if (m == 0)
        cout << "Таких студентов нет!";
    fin.close();
    return 0;
}