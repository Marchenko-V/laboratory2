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
	void init();
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

void output() {
	float rubles = 0, dollars = 0, euros = 0;
	cout << "Введите количество рублей: ";
	cin >> rubles;
	cout << "Количество долларов: ";
	cin >> dollars;
	cout << "Введите количество евро: ";
	cin >> euros;
}

int main()
{
	system("color f0");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "данная программа создана для того, чтобы считать денежки в кошельке" << endl;
	cout << "" << endl;
	wallet my;
	my.init();
	my.print_wallet();
	wallet wife;
	wife.set_wallet(992, 13, 48);
	cout << "у вашей жены ";
	wife.print_wallet();
	cout << "а если посчитать все совместно нажитое, то ";
	wallet* ours = new wallet;
	ours->set_wallet(0, 0, 0);
	ours->add_wallet(my, wife);
	float rub;
	rub = ours->convert(* ours);
	rub = ours->purchase(rub);
	delete ours;

	cout << "на случай, если у вас родятся дети, можно создать сколько угодно кошельков для них" << endl;
	cout << "сколько детей вы планируете иметь?" << endl;
	int n;
	cin >> n;
	wallet* children = new wallet[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Адрес кошелька ребенка № " << i + 1 << " " << &children[i] << endl;
	}
	delete[] children;
	wallet* buffer1 = (wallet*)malloc(10 * sizeof(wallet)),      // выделяем память под 10 элементов массива типа int, с предварительной инициализацией   
		* buffer2 = (wallet*)calloc(10, sizeof(wallet)),        // выделяем память под 10 элементов массива типа int, без инициализации
		* buffer3 = (wallet*)realloc(buffer2, 50 * sizeof(wallet));// перераспределить память в блоке buffer2, новый размер блока - 50 элементов

	free(buffer1);                                              // высвобождаем блок памяти buffer1
	free(buffer3);
	return 0;


}