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
#include<locale.h>
#include <Windows.h>
#define LEN 100


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
    printf("введите количество рублей: ");
    scanf("%f", &now.rubles);
    printf("введите количество долларов: ");
    scanf("%f", &now.dollars);
    printf("введите количество долларов: ");
    scanf("%f", &now.euros);
    return now;
}

void print(wallet now) {
    printf("рублей: %f\n", now.rubles);
    printf("долларов: %f\n", now.dollars);
    printf("евро: %f\n", now.euros);
}

void add_wallets(wallet now, wallet new_dinamic) {
    wallet summ_wallet;
    summ_wallet.rubles = now.rubles + new_dinamic.rubles;
    summ_wallet.dollars = now.dollars + new_dinamic.dollars;
    summ_wallet.euros = now.euros + new_dinamic.euros;
    printf("в двух кошельках: \n");
    print(summ_wallet);
}

//доллар - 80 руб, евро - 93

float convert(wallet now) {                //функция для подсчета рублей в кошельке
    float rub;
    rub = now.rubles + (now.dollars * 80) + (now.euros * 93);
    return rub;
}

wallet purchase(wallet now) {           //такая функция чтобы что-то купить
    float cost;
    char product[LEN];
    puts("введите название товара: ");
    gets_s(product);
    printf("введите цену товара в рублях: ");
    scanf("%f", &cost);
    float rub;
    rub = convert(now);
    if (cost > rub)
    {
        printf("к сожалению, у Вас недостаточно деняк, чтобы купить ");
        puts(product);
    }
    else
    {
        printf("урааа, Вы купили ");
        puts(product);
        rub = rub - cost;
        printf("после покупки у вас останется %f рублей", rub);
    }
    float dol, eu;
    if (((rub / 93) >= now.euros) && (rub > 0));
    else {
        now.euros = rub / 93;
        rub = rub - now.euros;
    }
    if ((rub / 80) >= now.dollars && (rub > 0));
    else {
        now.dollars= rub / 80;
        rub = rub - now.dollars;
    }
    if (rub > 0)
        now.rubles = rub;
    return now;
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    printf("в Вашем кошельке %f рублей", rub);
    std::cout << "Hello World!\n";
}