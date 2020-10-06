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
* *доллары:
* *евро:
* *если хотите выйти, нажмите ecs
*
* 2. Вывод полученных данных:
* *рубли:
* *доллары:
* *евро:
*
* 3. Посчитать деньги в кошельке в рублях
* 4. Реализовать покупку товара
*
*/



#include <iostream>
#include<malloc.h>
#include<string.h>
#include<locale.h>
#include<conio.h>
#include <Windows.h>
#define LEN 100
#pragma warning (disable : 4996)
 
typedef struct 
{
    float rubles;
    float dollars;
    float euros;
} wallet;

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
    printf("введите количество евро: ");
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
    scanf("%s", &product);
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
    getch();
    system("cls");
    puts("но сейчас Вам придется рассказать всем о своем благосостоянии");
    getch();
    now = input();
    puts("теперь все знают, что в Вашем кошельке вот сколько деняк!");
    print(now);
    getch();
    puts("а сколько же это в рублях?");
    float rub;
    rub = convert(now);
    printf("оказывается, в Вашем кошельке %f рублей", rub);
    puts("не желаете ли вы что-нибудь приобрести? (1 - да)");
    int f;
    scanf("%d", &f);
    fflush(stdin);
    if (f == 1)
    {
        puts("что ж, подходите к выбору осознанно, чтобы не уйти в минус");
        now = purchase(now);
    }
    else
        puts("ну ладно, уговаривать не стану");
    getch();
    system("cls");
    puts("а теперь придется ввести содержимое кошелька Вашей жены");
    wallet new_;
    new_ = input();
    puts("ого, так вот как выглядит ваш семейный бюджет");
    add_wallets(now, new_);
    getch();
    system("cls");

    //работа с динамической памятью
    wallet* now_dinamic, *new_dinamic;
    puts("а теперь то же самое, только с динамической памятью");
    getch();
    system("cls");
    now_dinamic = (wallet*)malloc(sizeof(wallet));
    new_dinamic = (wallet*)malloc(sizeof(wallet));
    puts("пока что в вашем кошельке нет деняк:");
    now_dinamic = &(init(0, 0, 0));
    print(*now_dinamic);
    puts("но сейчас Вам придется рассказать всем о своем благосостоянии");
    getch();
    now_dinamic = &(input());
    puts("теперь все знают, что в Вашем кошельке вот сколько деняк!");
    getch();
    print(*now_dinamic);
    puts("а сколько же это в рублях?");
    getch();
    rub = convert(*now_dinamic);
    printf("оказывается, в Вашем кошельке %f рублей \n", rub);
    getch();
    puts("не желаете ли вы что-нибудь приобрести? (1 - да, 0 или любое число - нет)");
    scanf("%d", &f);
    fflush(stdin);
    if (f == 1)
    {
        puts("что ж, подходите к выбору осознанно, чтобы не уйти в минус\n");
        now_dinamic = &(purchase(*now_dinamic));
    }
    else
        puts("ну ладно, уговаривать не стану");
    puts("а теперь придется ввести содержимое кошелька Вашей жены");
    new_dinamic = &(input());
    puts("ого, так вот как выглядит ваш семейный бюджет");
    add_wallets(*now_dinamic, *new_dinamic);
    printf("на всякий случай выведу адреса\n ");
    printf("Ваш кошелек можно найти вот тут: %p\n", now_dinamic);
    printf("а кошелек Вашей жены здесь: %p\n", new_dinamic);
    getch();
    system("cls");
    puts("спасибо, что воспользовались услугой нашей компании!");
    free(now_dinamic);
    free(new_dinamic);
}