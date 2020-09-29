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
#include<conio.h>
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

void add_wallets(wallet now, wallet new_) {
    wallet summ_wallet;
    summ_wallet.rubles = now.rubles + new_.rubles;
    summ_wallet.dollars = now.dollars + new_.dollars;
    summ_wallet.euros = now.euros + new_.euros;
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
        printf("после покупки у вас осталось %f рублей", rub);
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
    wallet now;
    puts("пока что в вашем кошельке нет деняк:");
    now = init(0, 0, 0);
    print(now);
    puts("но сейчас Вам придется рассказать всем о своем благосостоянии");
    now = input();
    puts("теперь все знают, что в Вашем кошельке вот сколько деняк!");
    print(now);
    puts("а сколько же это в рублях?");
    float rub;
    rub = convert(now);
    printf("оказывается, в Вашем кошельке %f рублей", rub);
    puts("не желаете ли вы что-нибудь приобрести? (1 - да)");
    int f;
    if (f == 1)
    {
        puts("что ж, подходите к выбору осознанно, чтобы не уйти в минус");
        now = purchase(now);
    }
    else
        puts("ну ладно, уговаривать не стану");
    puts("а теперь придется ввести содержимое кошелька Вашей жены");
    wallet new_;
    new_ = input();
    puts("ого, так вот как выглядит ваш семейный бюджет");
    add_wallets(now, new_);
    //работа с динамической памятью
    
    wallet* new_dinamic;

    


   
}