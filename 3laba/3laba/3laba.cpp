// 3laba.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <malloc.h>
#define MAX 20

using namespace std;

class card {
private:
	double money;
public:
	card() {
		money = 0;
	};

	card(double m) {
		money = m;
	};
	~card()
	{
	};

	void set_card(double money) {
		this->money = money;
	};

	card salary_(card now, double salary) {
		money += salary;
		cout << "поздравляю,  вам начислена зарплата в размере " << salary << endl;
		cout << "баланс вашей карты составляет" << money << endl;
		return now;
	};

	void input_() {
		cout << "введите количество деняк на карте: ";
		cin >> money;
	}

	card purchase(card now) {
		cout << "что хотите приобрести?" << endl;
		string purchase_ = "";
		cin >> purchase_;
		cout << "а сколько это стоит?" << endl;
		float price;
		cin >> price;
		if (price > money)
			cout << "недостаточно средств" << endl;
		else {
			money = money - price;
			cout << "поздравляю, вы купили " << purchase_ << endl;
			cout << "у вас осталось " << money << " рублей в кошельке" << endl;
		}
		return now;
	};

	card add_card(card my, card wife) {
		card ours;
		ours.money = my.money + wife.money;
		return ours.money;
	};

	void print() {
		cout << "на карте: " << money << endl;
	};
};

class Wallet
{
private:
	double rubles;
	double dollars;
	double euros;
	card money;
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
	};

	Wallet(double rubles, double dollars, double euros)
	{
		this->rubles = rubles;
		this->dollars = dollars;
		this->euros = euros;
	};

	~Wallet()
	{

	};

	void set_wallet(double rubles, double dollars, double euros, card money)
	{
		this->rubles = rubles;
		this->dollars = dollars;
		this->euros = euros;
		this->money = money;
	};

	void output() {
		cout << "в кошельке" << endl;
		cout << "pублей: " << rubles << endl;
		cout << "долларов: " << dollars << endl;
		cout << "eвро: " << euros << endl;
		money.print();
	};

/*
	Wallet add_wallet(Wallet my, Wallet wife, card myy, card wifee) {
		Wallet ours;
		ours.rubles = my.rubles + wife.rubles;
		ours.dollars = my.dollars + wife.dollars;
		ours.euros = my.euros + wife.euros;
		ours.money.add_card(myy, wifee);

		cout << "после сложения ваших деняк ";
		output();
		return ours;
	};
*/
	float convert(Wallet ours) {
		double rub;
		cout << "сейчас мы узнаем, сколько же деняк у вас в рублях" << endl;
		rub = ours.rubles + ours.dollars * 83 + ours.euros * 90;
		cout << "оказывается, в вашем кошельке все это время было " << rub << " рублей" << endl;
		return rub;
	};

	void input() {
		double rubles = 0, dollars = 0, euros = 0;
		card money;
		cout << "ведите количество рублей: ";
		cin >> rubles;
		cout << "количество долларов: ";
		cin >> dollars;
		cout << "количество евро: ";
		cin >> euros;
		money.input_();
		set_wallet(rubles, dollars, euros, money);
	};

	double purchase(double rub) {
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
	};

	Wallet add_wallet(Wallet my, Wallet wife) {
		Wallet ours;
		ours.rubles = my.rubles + wife.rubles;
		ours.dollars = my.dollars + wife.dollars;
		ours.euros = my.euros + wife.euros;
		ours.money.add_card(my.money, wife.money);
		cout << "после сложения ваших деняк ";
		ours.output();
		return ours;
	};

	Wallet salary(Wallet now)
	{
		cout << "введите заработную плату: ";
		double slr;
		cin >> slr;
		money.salary_(now.money, slr);
		return now;
	};
};

int main()
{
	system("color f0");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "данная программа создана для того, чтобы считать денежки в кошельке и на карте" << endl;
	Wallet* my = new Wallet(0,0,0);
	cout << "сейчас у вас нет деняк ";
	my->output();
	cout << "поэтому вы должны поведать нам о вашем финансовом состоянии" << endl;
	my->input();
	my->output();
	* my = my->salary(* my);
	Wallet* wife = new Wallet(0, 0, 0);
	wife->set_wallet(1992, 13, 48, 12345);
	cout << "у вашей жены ";
	wife->output();
	cout << "а если посчитать все совместно нажитое, то ";
	Wallet* ours = new Wallet(0, 0, 0);
	ours->set_wallet(0, 0, 0, 0);
	* ours = ours->add_wallet(* my, *wife);	
	//cout << "введите вашу зарплату" << endl;
	//double salar;
	//cin >> salar;
	
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
		children[i].input();
		children[i].output();
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



