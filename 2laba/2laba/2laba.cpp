// Лабораторная 2 - работа со структурами
/*
* Создаем кошелек
* В структуре будет количество рублей и количество копеек
* Сложение двух кошельков - сложение деняк в них
* можно добавить еще евро и доллары, а потом их переводить в рубли
*
* меню:
* 1. Ввод данных:
* *рубли:
* *копейки:
* *доллары:
* *евро:
* *если хотите выйти, нажмите ecs
*
* 2. Вывод полученных данных:
* *рубли:
* *копейки:
* *доллары:
* *евро:
*
* 3. Посчитать деньги в кошельке в рублях
* 4. Посчитать все деньги в долларах
*
*/



#include <iostream>
#include<malloc.h>
#include<string.h>
#define LEN 100
#define standart "no_name"

struct wallet{
    int rubles;
    int dollars;
    int euro;
};

wallet init(int r, int d, int e) {
    wallet now;
    now.rubles = r;
    now.dollars = d;
    now.euro = e;
    return now;
}


int main()
{
    std::cout << "Hello World!\n";
}