#define M 40
#define horse 500 
#define saber 100
#define rubie 50
#define necklace 10
#define wife 200
#include <iostream>
#include <string>
#include <fstream>
#include <io.h>
#include <algorithm>
#include <fcntl.h>
#include <locale>
#include <locale.h>
#include <Windows.h>
#include <fstream>
#include <iterator>
#include <stdlib.h>
#include <math.h>
#include <codecvt>
#include <conio.h>
#include "f.h"
void head() {
    cout << "------------------------------------------------------------------------------------------\n";
    cout << "|   Имя   | Живой |                        Имущество                         | Богатство |\n";
    cout << "|         |       |----------------------------------------------------------|           |\n";
    cout << "|         |       | Скакуны |  Сабли  | Рубины |  Ожерелья  |  Жены | Монеты |-----------|\n";
    cout << "------------------------------------------------------------------------------------------\n";
}
void write_rub(rubber r) {
    cout << "|";
    cout.width(9);
    cout << r.name;
    cout.width(1);
    cout << "|";
    cout.width(7);
    cout << r.alive;
    cout.width(1);
    cout << "|";
    cout.width(9);
    cout << r.horses;
    cout.width(1);
    cout << "|";
    cout.width(9);
    cout << r.sabers;
    cout.width(1);
    cout << "|";
    cout.width(8);
    cout << r.rubies;
    cout.width(1);
    cout << "|";
    cout.width(12);
    cout << r.necklaces;
    cout.width(1);
    cout << "|";
    cout.width(7);
    cout << r.wifes;
    cout.width(1);
    cout << "|";
    cout.width(8);
    cout << r.coins;
    cout.width(1);
    cout << "|";
    cout.width(11);
    cout << r.wealth;
    cout.width(1);
    cout << "|\n";
}
int set_wealth(rubber r) {
    return r.coins + r.horses * horse + r.sabers * saber + r.rubies * rubie + r.necklaces * necklace - r.wifes * wife;
}
int add(int a, int b) {
    return a + b;
}
rubber read(rubber rubbers[], string filename, rubber itogo) {
    srand(unsigned(std::time(0)));
    string name;
    int crew = 0;
    while (crew < M)
    {
        rubbers[crew].alive = 1;
        rubbers[crew].horses = rand() % 10;
        rubbers[crew].coins = rand() % 5000;
        rubbers[crew].necklaces = rand() % 10;
        rubbers[crew].rubies = rand() % 50;
        rubbers[crew].sabers = rand() % 5;
        rubbers[crew].wifes = rand() % 10;
        rubbers[crew].wealth = set_wealth(rubbers[crew]);
        if (rubbers[crew].alive) {
            itogo.alive++;
            itogo.horses += rubbers[crew].horses;
            itogo.coins += rubbers[crew].coins;
            itogo.necklaces += rubbers[crew].necklaces;
            itogo.rubies += rubbers[crew].rubies;
            itogo.sabers += rubbers[crew].sabers;
            itogo.wifes += rubbers[crew].wifes;
            itogo.wealth = set_wealth(itogo);
        }
        crew++;
    }
    string line; int i = 0;
    ifstream in(filename);
    for (i = 0; i < M; i++) {
        in >> line;
        rubbers[i].name = line;
    }
    in.close();
    itogo.name = "Итого";
    return itogo;
}
void menu() {
    cout << "1 - Вся таблица" << "\n";
    cout << "2 - Вывод живых" << "\n";
    cout << "3 - Самый богатый" << "\n";
    cout << "4 - Убить" << "\n";
    cout << "5 - Новый член" << "\n";
    cout << "6 - Вывод по имени" << "\n";
    cout << "7 - Диаграмма" << "\n";
    cout << "0 - Выход" << "\n";
}
void write(rubber rubbers[], rubber itogo, int crew) {
    head();
    int i = 0;
    while (i < crew) {
        write_rub(rubbers[i]);
        i++;
    }
    write_rub(itogo);
}
void write_alive(rubber rubbers[], rubber itogo, int crew) {
    head();
    int i = 0;
    while (i < crew) {
        if (rubbers[i].alive) write_rub(rubbers[i]);
        i++;
    }
    write_rub(itogo);
}
void the_most_rich(rubber rubbers[], int crew) {
    int i = 0;
    int max = 0;
    for (i = 0; i < crew; i++) {
        if (rubbers[i].wealth > max && rubbers[i].alive) max = rubbers[i].wealth;
    }
    head();
    for (i = 0; i < crew; i++) {
        if (rubbers[i].wealth == max && rubbers[i].alive) write_rub(rubbers[i]);
    }
}
rubber kill(rubber rubbers[], rubber itogo, int crew) {
    cout.imbue(locale(".1251"));
    cin.imbue(locale(".866"));
    cout << "Введите имя убитого:\n";
    string name;
    cin >> name;
    int i = -1;
    int t = 0;
    while (i < crew && t == 0) {
        i++;
        if (rubbers[i].name == name && rubbers[i].alive) {
            rubbers[i].alive = 0;
            t = 1;
        }
    }
    rubbers[i].alive = 0;
    itogo.alive--;
    itogo.horses -= rubbers[i].horses;
    itogo.coins -= rubbers[i].coins;
    itogo.necklaces -= rubbers[i].necklaces;
    itogo.rubies -= rubbers[i].rubies;
    itogo.sabers -= rubbers[i].sabers;
    itogo.wifes -= rubbers[i].wifes;
    itogo.wealth = set_wealth(itogo);
    return itogo;
}
rubber freshman(rubber rubbers[], rubber itogo, int crew) {
    wcout.imbue(locale(".1251"));
    wcin.imbue(locale(".866"));
    cout << "Введите имя:\n";
    string name;
    cin >> name;
    rubbers[crew].name = name;
    cout << "Жив:\n";
    cin >> rubbers[crew].alive;
    cout << "Скакуны:\n";
    cin >> rubbers[crew].horses;
    cout << "Сабли:\n";
    cin >> rubbers[crew].sabers;
    cout << "Рубины:\n";
    cin >> rubbers[crew].rubies;
    cout << "Ожерелья:\n";
    cin >> rubbers[crew].necklaces;
    cout << "Жены:\n";
    cin >> rubbers[crew].wifes;
    cout << "Монеты:\n";
    cin >> rubbers[crew].coins;
    rubbers[crew].wealth =
        set_wealth(rubbers[crew]);
    if (rubbers[crew].alive) {
        itogo.alive++;
        itogo.horses += rubbers[crew].horses;
        itogo.coins += rubbers[crew].coins;
        itogo.necklaces += rubbers[crew].necklaces;
        itogo.rubies += rubbers[crew].rubies;
        itogo.sabers += rubbers[crew].sabers;
        itogo.wifes += rubbers[crew].wifes;
        itogo.wealth = set_wealth(itogo);
    }
    return itogo;
}
void findname(rubber rubbers[], int crew) {
    cout.imbue(locale(".1251"));
    cin.imbue(locale(".866"));
    string name;
    cout << "Введи имя:" << endl;
    cin >> name;
    cout << "Вы ищете: ";
    cout << name;
    cout << name << "\n";
    head();
    for (int i = 0; i < crew; i++) {


        if (name == rubbers[i].name) write_rub(rubbers[i]);
    }
}
void graph(rubber rubbers[], int crew) {
    for (int i = 0; i < 99; i++) {
        printf("\n");
    }
    int len = 1800;
    int div = 15;
    int width = 650;
    cout << "\n";

    for (int i = 0; i < crew; i++) {
        wcout.width((len / crew) / div);
        if (rubbers[i].alive) cout << rubbers[i].name;
    }
    cout << "\n";
    float x;
    HDC hDC = GetDC(GetConsoleWindow());

    HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
    SelectObject(hDC, Pen);
    MoveToEx(hDC, 6, 0, NULL);
    LineTo(hDC, 6, len);
    MoveToEx(hDC, 0, width, NULL);
    LineTo(hDC, len, width);
    int l = crew;
    for (int i = 0; i < crew; i++) {
        if (rubbers[i].alive) {
            MoveToEx(hDC, 6 + i * (len / crew), width - rubbers[i].wealth / div, NULL);
            LineTo(hDC, 6 + i * (len / crew), width);
            MoveToEx(hDC, 6 + i * (len / crew), width - rubbers[i].wealth / div, NULL);
            LineTo(hDC, 6 + (i + 1) * (len / crew), width - rubbers[i].wealth / div);
            MoveToEx(hDC, 6 + (i + 1) * (len / crew), width - rubbers[i].wealth / div, NULL);
            LineTo(hDC, 6 + (i + 1) * (len / crew), width);
        }


    }
    _getch();
}
