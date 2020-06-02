#include <string>
using namespace std;
#ifndef FUNC_H
#define FUNC_H
#define M 40
struct rubber {
    string name;
    int alive;
    int horses = 0;
    int sabers = 0;
    int rubies = 0;
    int necklaces = 0;
    int wifes = 0;
    int coins = 0;
    int wealth = 0;
};
void menu();
int set_wealth(rubber r);
int add(int x, int y); 
rubber read(rubber rubbers[], string filename, rubber itogo);
void write(rubber rubbers[], rubber itogo, int crew);
void write_alive(rubber rubbers[], rubber itogo, int crew);
void the_most_rich(rubber rubbers[], int crew);
rubber kill(rubber rubbers[], rubber itogo, int crew);
rubber freshman(rubber rubbers[], rubber itogo, int crew);
void findname(rubber rubbers[], int crew);
void graph(rubber rubbers[], int crew);
#endif