#include <iostream>

double amount, amountUsd, amountEuro, amountRub, usdBenefit, euroBenefit, rubBenefit, profit;
const double euroBuy = 2.33, euroSale = 2.334, usdBuy = 2.082, usdSale = 2.087, rubBuy = 0.03216, rubSale = 0.0323;
char a;

bool menu();
void enter();
void change();
void Exchange();
void Info();

int main()
{
	while (true)
	{
		menu();
	}
}

void enter()
{
	system("cls");
	std::cout << "Enter amount of money\n\nF)Back\n";
	std::cin >> amount;
	std::cin >> a;
	system("cls");
	if (a == 'F') menu();
	else enter();
}

void change()
{
	system("cls");
	amountEuro = amount / euroSale;
	amountUsd = amount / usdSale;
	amountRub = amount / rubSale;
	std::cout << "For this money you get :\n" << amountEuro << " euro\n" << amountUsd << " usd\n" << amountRub << " rub\n\nF)Back\n";
	std::cin >> a;
	system("cls");
	if (a == 'F') menu();
	else change();
}

void Exchange()
{
	system("cls");
	std::cout << "Current course for today :\nSell USD " << usdSale << "  Buy USD " << usdBuy << "\nSell Euro " << euroSale << " Buy Euro " << euroBuy << "\nSell Rub " << rubSale << "  Buy Rub " << rubBuy<<"\n\nF)Back\n";
	std::cin >> a;
	system("cls");
	if (a == 'F') menu();
	else Exchange();
}

void Benefit()
{
	system("cls");
	profit = euroBenefit = amount - amount * euroBuy / euroSale;
	usdBenefit = amount - amount * usdBuy / usdSale;
	if (usdBenefit > profit) profit = usdBenefit;
	rubBenefit = amount - amount * rubBuy - rubSale;
	if (rubBenefit > profit) profit = usdBenefit;
	std::cout << "USD benefit" << usdBenefit << "\nEuro benefit " << euroBenefit << "\nRub benefit" << rubBenefit << "\nBest profit " << profit<<"\n\nF)Back\n";
	std::cin >> a;
	system("cls");
	if (a == 'F') menu();
	else Benefit();
}

void Info()
{
	system("cls");
	std::cout << "Contact phone +37517 289 94 30 Shakuro Darya mail darya.shakuro\nContact phone +37517 289 92 95 Petrovich Darya mail darya.petrovich@priorbank.by \nPriorbank 1998 - 2019\n\nF)Back\n";
	std::cin >> a;
	system("cls");
	if (a == 'F') menu();
	else Info();
}

bool menu()
{
	int choose;
	std::cout << "Choose variant\n1)Enter amount\n2)Change\n3)Exchange rate\n4)Benefit\n5)Info\n6)Close\n";
	std::cin >> choose;
	switch (choose)
	{
	case 1: enter(); break;
	case 2: change(); break;
	case 3: Exchange(); break;
	case 4: Benefit(); break;
	case 5: Info(); break;
	case 6: exit(0); break;
	default: menu(); break;
	}
}
