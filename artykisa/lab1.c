//Вариант 13
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	bool Vvod = true;
	char a[50];
	
	int len;
	while (Vvod) {
	system("cls");

	printf("Введите свое число до 100, которое я конвертирую в словесный вариант!\n");
	gets_s(a);
	if (a[0]=='1' && a[1]=='0' && a[2]=='0') {
		printf("Cто\n");
		system("pause");
		return 0;
	}
	Vvod = false;
	
		if (a[1] == '\0') len = 1;

		else {
			if (a[2] == '\0')  len = 2;
			else { printf("Неправильный ввод!\n Попробуйте еще раз . . ."); system("pause"); Vvod = true; }
		}
		if (Vvod == false) {
			for (int i = 0; i < len; i++) {
				if (a[i] < '0' || a[i] > '9') {
					printf("Неправильный ввод!\n Попробуйте еще раз . . ."); system("pause"); Vvod = true;
				}
			}
		}
	}

	if (a[0] == '0' && a[1] == '0') {
		printf("Ноль\n");
		system("pause");
		return 0;
	}
	if (len == 1)
	{
		switch (a[0]) {
		case '1':  printf("Один\n");    break;
		case '2':  printf("Два\n");     break;
		case '3':  printf("Три\n");     break;
		case '4':  printf("Четыре\n");  break;
		case '5':  printf("Пять\n");    break;
		case '6':  printf("Шесть\n");   break;
		case '7':  printf("Семь\n");    break;
		case '8':  printf("Восемь\n");  break;
		case '9':  printf("Девять\n");  break;
		case '0':  printf("Ноль\n");    break;
		}
	}
	if (len == 2) {

		switch (a[0]) {
		case '1': switch (a[1]) {
		case '1':  printf("Одиннадцать\n");   system("pause"); return 0;
		case '2':  printf("Двенадцать\n");    system("pause"); return 0;
		case '3':  printf("Тринадцать\n");    system("pause"); return 0;
		case '4':  printf("Четырнадцать\n");  system("pause"); return 0;
		case '5':  printf("Пятнадцать\n");    system("pause"); return 0;
		case '6':  printf("Шестнадцать\n");   system("pause"); return 0;
		case '7':  printf("Семнадцать\n");    system("pause"); return 0;
		case '8':  printf("Восемнадцатьт\n"); system("pause"); return 0;
		case '9':  printf("Девятнадцать\n");  system("pause"); return 0;
		case '0':  printf("Десять\n");          system("pause"); return 0;
		}

		case '2':  printf("Двадцать");   break;
		case '3':  printf("Тридцать");    break;
		case '4':  printf("Сорок");       break;
		case '5':  printf("Пятьдесят");   break;
		case '6':  printf("Шестьдесят");  break;
		case '7':  printf("Семьдесят");   break;
		case '8':  printf("Восемьдесят"); break;
		case '9':  printf("Девяносто");   break;
		case '0':  printf("");            break;
		}
		switch (a[1]) {
		case '1':  printf(" Один\n");  break;
		case '2':  printf(" Два\n");    break;
		case '3':  printf(" Три\n");    break;
		case '4':  printf(" Четыре\n"); break;
		case '5':  printf(" Пять\n");   break;
		case '6':  printf(" Шесть\n");  break;
		case '7':  printf(" Семь\n");   break;
		case '8':  printf(" Восемь\n"); break;
		case '9':  printf(" Девять\n"); break;
		case '0':  printf("\n");        break;
		}
	}
	system("pause");
	return 0;
}
