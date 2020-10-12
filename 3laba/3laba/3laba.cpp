// 3laba.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <malloc.h>
#define MAX 20

using namespace std;
class Human
{
	//Поля класса
private:
	string fio;
	int age;
	Wallet wallet;
	double salary;
	Human()
	{
		fio = "Иванов";
		age = 0;
		salary = 0;
	}
	Human(string fio, int age, double salary, Wallet wallet)
	{
		this->fio = fio;
		this->age = age;
		this->salary = salary;
		this->wallet = wallet;
	}
	~Human()
	{

	};
	//Методы класса
};


class Wallet
{
private:
	double rubles;
	double dollars;
	double euros;
public:
	/*wallet();
	wallet(float rubles, float dollars, float euros);
	~wallet();
	void set_wallet(float rubles, float dollars, float euros);
	void print_wallet();
	wallet add_wallet(wallet my, wallet wife);
	float convert(wallet now);
	float purchase(float rub);
	void input();
};*/


	Wallet()
	{
		rubles = 0;
		dollars = 0;
		euros = 0;
	}

	Wallet(float rubles, float dollars, float euros)
	{
		this->rubles = rubles;
		this->dollars = dollars;
		this->euros = euros;
	}

	~Wallet()
	{

	}

	void set_wallet(float rubles, float dollars, float euros)
	{
		this->rubles = rubles;
		this->dollars = dollars;
		this->euros = euros;
	}

	void output(Wallet now) {
		cout << "в кошельке" << endl;
		cout << "pублей: " << now.rubles << endl;
		cout << "долларов: " << now.dollars << endl;
		cout << "eвро: " << now.euros << endl;
	}

	Wallet add_wallet(Wallet my, Wallet wife) {
		Wallet ours;
		ours.rubles = my.rubles + wife.rubles;
		ours.dollars = my.dollars + wife.dollars;
		ours.euros = my.euros + wife.euros;
		cout << "после сложения ваших деняк ";
		output(ours);
		return ours;
	}

	float convert(Wallet ours) {
		float rub;
		cout << "сейчас мы узнаем, сколько же деняк у вас в рублях" << endl;
		rub = ours.rubles + ours.dollars * 83 + ours.euros * 90;
		cout << "оказывается, в вашем кошельке все это время было " << rub << " рублей" << endl;
		return rub;
	}

	float purchase(float rub) {
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
			cout << "у вас осталось " << rub << " рублей в кошельке" << endl;
		}
		return rub;
	}

	Wallet input() {
		float rubles = 0, dollars = 0, euros = 0;
		Wallet now;
		cout << "ведите количество рублей: ";
		cin >> rubles;
		cout << "количество долларов: ";
		cin >> dollars;
		cout << "количество евро: ";
		cin >> euros;
		now.set_wallet(rubles, dollars, euros);
		return now;
	}
};


int main()
{
	system("color f0");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "данная программа создана для того, чтобы считать денежки в кошельке" << endl;
	cout << "" << endl;
	Wallet* my = new Wallet(0,0,0);
	cout << "сейчас у вас нет деняк ";
	my->output(* my);
	cout << "поэтому вы должны поведать нам о вашем финансовом состоянии" << endl;
	*my = my->input();
	my->output(* my);
	Wallet* wife = new Wallet(0, 0, 0);
	wife->set_wallet(992, 13, 48);
	cout << "у вашей жены ";
	wife->output(* wife);
	cout << "а если посчитать все совместно нажитое, то ";
	Wallet* ours = new Wallet(0, 0, 0);
	ours->set_wallet(0, 0, 0);
	* ours = ours->add_wallet(* my, *wife);	
	float rub = 0;
	rub = ours->convert(* ours);
	rub = ours->purchase(rub);

	cout << "на случай, если у вас родятся дети, можно создать сколько угодно кошельков для них" << endl;
	cout << "сколько детей вы планируете иметь?" << endl;
	int n;
	cin >> n;
	Wallet* children = new Wallet[n];
	

	cout << "а теперь введите количество деняк, подаренных вашим детям родственниками" << endl;
	string* name_children = (string*)calloc(MAX, sizeof(string));
	for (int i = 0; i < n; i++)
	{
		cout << "Введите имя" << endl;
		cin >> name_children[i];
		*(children + i) = children[i].input();
		children[i].output(children[i]);
	}
	for (int i = 0; i < n; i++)
	{
		cout << "Адрес кошелька ребенка с именем " << name_children[i] << " : " << &children[i] << endl;
	}
	//delete[] children;
	free (name_children);
	Wallet* buffer1 = (Wallet*)malloc(10 * sizeof(Wallet)),      // выделяем память под 10 элементов массива типа int, с предварительной инициализацией   
		* buffer2 = (Wallet*)calloc(10, sizeof(Wallet)),        // выделяем память под 10 элементов массива типа int, без инициализации
		* buffer3 = (Wallet*)realloc(buffer2, 50 * sizeof(Wallet));// перераспределить память в блоке buffer2, новый размер блока - 50 элементов

	free(buffer1);                                              // высвобождаем блок памяти buffer1
	free(buffer3);
	return 0;


}



