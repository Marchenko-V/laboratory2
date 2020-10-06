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
	wallet add_wallet(wallet my, wallet wife);
	float convert(wallet now);
	float purchase(float rub);
	void init(wallet now);
};


wallet::wallet()
{
	rubles = 0;
	dollars = 0;
	euros = 0;
}

wallet::wallet(float rubles, float dollars, float euros)
{
	this->rubles = rubles;
	this->dollars = dollars;
	this->euros = euros;
}

wallet::~wallet()
{

}

void wallet::set_wallet(float rubles, float dollars, float euros) {
	this->rubles = rubles;
	this->dollars = dollars;
	this->euros = euros;
}

void wallet::print_wallet(){
	cout << "в кошельке" << endl;
	cout << "Рублей: " << rubles << endl;
	cout << "Долларов: " << dollars << endl;
	cout << "Евро: " << euros << endl;
}



wallet wallet::add_wallet(wallet my, wallet wife) {
	wallet ours;
	ours.rubles = my.rubles + wife.rubles;
	ours.dollars = my.dollars + wife.dollars;
	ours.euros = my.euros + wife.euros;
	cout << "после сложения ваших деняк";
	print_wallet();
	return ours;
}

float wallet::convert(wallet now) {
	float rub;
	cout << "сейчас мы узнаем, сколько же деняк у вас в рублях" << endl;
	rub = now.rubles + now.dollars * 83 + now.euros * 90;
	cout << "оказывается, в вашем кошельке все это время было " << rub << "рублей" << endl;
	return rub;
}

float wallet::purchase(float rub) {
	cout << "что хотите приобрести?" << endl;
	string purchase_ = "";
	cin >> purchase_;
	cout << "а сколько это стоит?" << endl;
	float price; 
	cin >> price;
	if (price > rub)
		cout << "недостаточно средств" << endl;
	else {
		rub = rub - price;
		cout << "поздравляю, вы купили " << purchase_ << endl;
		cout << "у вас осталось" << rub << "рублей в кошельке" << endl;
	}
	return rub;
}

void wallet::init(wallet now) {
	float rubles = 0, dollars = 0, euros = 0;
	cout << "Введите количество рублей: ";
	cin >> rubles;
	cout << "Количество долларов: ";
	cin >> dollars;
	cout << "Введите количество евро: ";
	cin >> euros;
	now.set_wallet(rubles, dollars, euros);
}

int main()
{
	system("color f0");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
}