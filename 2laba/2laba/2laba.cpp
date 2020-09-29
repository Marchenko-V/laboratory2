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
#include <Windows.h>
#define LEN 100
#define standart "no_name"

struct wallet{
    int rubles;
    int dollars;
    int euros;
};

wallet init(int r, int d, int e) {
    wallet now;
    now.rubles = r;
    now.dollars = d;
    now.euros = e;
    return now;
}

wallet input()
{
    wallet now;
    now = init(0, 0, 0);
    printf("enter the amount of rubles: ");
    scanf("%d", &now.rubles);
    printf("enter the amount of dollars: ");
    scanf("%d", &now.dollars);
    printf("enter the amount of euros: ");
    scanf("%d", &now.euros);
    return now;
}

void print(wallet now) {
    printf("rubles: %d", now.rubles);
    printf("dollars: %d", now.dollars);
    printf("euros: %d", now.euros);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout << "Hello World!\n";
}