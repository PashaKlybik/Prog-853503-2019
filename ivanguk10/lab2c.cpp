//Лабораторная работа 2, вариант 7.
//Приорбанк. Разработать программу, меню которой позволяет выполнить следующие функции
//• Ввод денежной суммы в белорусских рублях
//• Вывод аналогичной суммы в долларах США, евро и российских рублях.
//• Вывод таблицы курсов валют (покупка-продажа, взять данные на день разработки программы).
//• Расчет прибыли от операции для каждой валюты. Определение наиболее выгодной для банка валюты для сделки.
//• Краткая информация о банке и контакты.
//• Выход из программы.
// Курсы валют взяты за 17.05.2019 в 13:50.
#include "pch.h"
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>


using namespace std;

//функция для определения наиболее выгодной валюты

string currency(float usd, float eur, float rub) {
	float max = std::max(std::max(usd, eur), rub);
	if (max == usd) {
		return "usd";
	}
	else if (max == eur) {
		return "eur";
	}
	else {
		return "rub";
	}
}


int main() {
	int input;
	float byn = 0, bynToUsd = 0.48, moneyInUsd, bynToEur = 0.43, moneyInEur, bynToRub = 30.89, moneyInRub, BuyusdToByn = 2.072, BuyeurToByn = 2.313, BuyrubToByn = 0.0316, SellusdToByn = 2.096, SelleurToByn = 2.339, SellrubToByn = 0.0328;
	bool end = false;

	cout << "1. Entering a sum of money in Belarusian rubles.\n2. Output the same sum in US dollars, euros and Russian rubles.\n3. Output  the table of exchange rates (buy and sale, take the data on the day of the program development).\n4. Calculation of profit from operations for each currency. Determining the most profitable currency for a bank for a transaction.\n5. Brief information about the bank and contacts.\n6. Exit from the program.\n";

	while (!end) {
		cout << "\nSelect a menu item: ";
		cin >> input;
		switch (input) {
		case 1:
			cout << "\nEnter the sum in Belarusian rubles: ";
			cin >> byn;
			break;

		case 2:
			if (byn != 0) {
				moneyInUsd = byn * bynToUsd;
				moneyInEur = byn * bynToEur;
				moneyInRub = byn * bynToRub;

				cout << "\nSum in USD: " << moneyInUsd;
				cout << "\nSum in EURO: " << moneyInEur;
				cout << "\nSum in Rubles: " << moneyInRub << "\n";
			}
			else {
				cout << "\nYou have not entered the sum yet.\n";
			}
			break;
		case 3:
			cout << "\nExchange rates \nBuy:\n";
			cout << "1 USD: " << BuyusdToByn << "\n1 EUR: " << BuyeurToByn << "\n1 RUB: " << BuyrubToByn << "\n\n";
			cout << "Sell:\n";
			cout << "1 USD: " << SellusdToByn << "\n1 EUR: " << SelleurToByn << "\n1 RUB: " << SellrubToByn << "\n\n";
			break;
		case 4:
			cout << "\nProfit from operations with USD: " << SellusdToByn - BuyusdToByn << "\nProfit from operations with EUR: " << SelleurToByn - BuyeurToByn<< "\nProfit from operations with RUB: " << SellrubToByn - BuyrubToByn;

			cout << "\nThe most profitable currency for a bank for a transaction: "  << currency(SellusdToByn - BuyusdToByn, SelleurToByn - BuyeurToByn, SellrubToByn -
				BuyrubToByn) << "\n";
			break;
		case 5:
			cout << "\n «Priorbank» is a Belarusian commercial bank.\nThe main beneficiary owner of Priorbank OJSC is Raiffeisen\nLandesbanken Holding AG — subsidiary Raiffeisen Bank International AG.\n«Priorbank» is a universal bank providing a wide range of banking services.\nContacts: +375 17 289 90 90; Velcom, MTS, life: 487\n";
			break;
		case 6:
			end = true;
			break;

		default:
			cout << "\nCheck the input and try again..\n";
			break;
		}
	}
	return 0;
}