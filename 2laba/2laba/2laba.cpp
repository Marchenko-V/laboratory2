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
    float rubles;
    float dollars;
    float euros;
};

wallet init(float r, float d, float e) {
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
    printf("Введите количество рублей: ");
    scanf("%f", &now.rubles);
    printf("Введите количество долларов: ");
    scanf("%f", &now.dollars);
    printf("Введите количество долларов: ");
    scanf("%f", &now.euros);
    return now;
}

void print(wallet now) {
    printf("Рублей: %f\n", now.rubles);
    printf("Долларов: %f\n", now.dollars);
    printf("Евро: %f\n", now.euros);
}

void add_wallets(wallet now, wallet new_dinamic) {
    wallet summ_wallet;
    summ_wallet.rubles = now.rubles + new_dinamic.rubles;
    summ_wallet.dollars = now.dollars + new_dinamic.dollars;
    summ_wallet.euros = now.euros + new_dinamic.euros;
    printf("В двух кошельках: \n");
    print(summ_wallet);
}

//доллар - 80 руб, евро - 93

wallet convert(wallet now) {                //функция для подсчета рублей в кошельке
    float rub;
    rub = now.rubles + (now.dollars * 80) + (now.euros * 93);
    printf("В вашем кошельке %f рублей", rub);
}

wallet purchase(wallet now) {

}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout << "Hello World!\n";
}