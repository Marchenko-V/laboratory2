// 3laba.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <malloc.h>

using namespace std;



class wallet
{
private:
	float rubles;
	float dollars;
	float euros;
public:
	wallet();
	wallet(float rubles, float dollars, float euros);
	~wallet();
	void set_wallet(float rubles, float dollars, float euros);
	void print_wallet();
	void add_wallet(wallet now);
	void convert(wallet now);
	void purchase(wallet now);
};


wallet::wallet()
{
	rubles = 0;
	dollars = 0;
	euros = 0;
}



int main()
{
    std::cout << "Hello World!\n";
}