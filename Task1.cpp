#include <iostream>
#include <string>
#include <fstream>
#include "f.h"


using namespace std;
int crew = M;
rubber rubbers[40];
rubber itogo;



int main()
{
    setlocale(0, "");
    itogo = read(rubbers, "names.txt", itogo);
    menu();
    int i;
    cin >> i;
    while (i != 0) {
        switch (i) {
        case(1):
            write(rubbers, itogo, crew);
            break;
        case(2):
            write_alive(rubbers, itogo, crew);
            break;
        case(3):
            the_most_rich(rubbers, crew);
            break;
        case(4):
            itogo = kill(rubbers, itogo, crew);
            break;
        case(5):
            itogo = freshman(rubbers, itogo, crew);
            crew++;
            break;
        case(6):
            findname(rubbers, crew);
            break;
        case(7):
            graph(rubbers, crew);
            break;

        }
        menu();
        cin >> i;
    }
}
