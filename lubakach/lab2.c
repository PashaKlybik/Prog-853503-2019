//Треугольник. Разработать программу, меню которой позволяет выполнить следующие функции
//• Ввод координат вершин треугольника
//• Определить вид треугольника (правильный, прямоугольный,равнобедренный, произвольного вида).
//• Вывод периметра треугольника
//• Вывод площади треугольника.
//• Вычислить и вывести радиусы вписанной и описанной вокруг треугольника окружностей.
//• Выполнено в visual studio, Качан Люба, 853503, вариант 12
//• Выход из программы.#include "pch.h"
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdbool.h>

int main(){
	setlocale(LC_ALL, "RUS");
	int input=0;
	int x1 = 0, x2 = 0, x3 = 0, y1 = 0, y2 = 0, y3 = 0;
	float S, AB = 0, AC = 0, BC = 0, P, R, r, p, max, num, num1;
	bool end = false;
	printf("1.Ввод координат вершин треугольника.\n2.Определить вид треугольника (правильный, прямоугольный,равнобедренныий, произвольного вида).\n3.Вывод периметра треугольника.\n4.Вывод площади треугольника.\n5.Вычислить и вывести радиусы вписанной и описанной вокруг треугольника окружностей.\n6.Выход из программы");
	while (!end) {
			printf("\nВыбери пункт: ");
		scanf_s("%d", &input);
		switch (input) {
		case 1:
			printf("\nКоординаты x1:");
			scanf_s("%d", &x1);
			printf("\nКоординаты y1:");
			scanf_s("%d", &y1);
			printf("\nКоординаты x2:");
			scanf_s("%d", &x2);
			printf("\nКоординаты y2:");
			scanf_s("%d", &y2);
			printf("\nКоординаты x3:");
			scanf_s("%d", &x3);
			printf("\nКоординаты y3:");
			scanf_s("%d", &y3);
			AB = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
			AC = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
			BC = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
			break;

		case 2:
			if (AB == AC && AB == BC) { printf("\nТвой треугольник правильный."); }
			if (AB == AC || AB == BC || BC == AC) { printf("\nТвой треугольник равнобедренныий."); }
			if (AB > AC && AB > BC) { max = AB; num = BC; num1 = AC; }
			if (AC > AB && AC > BC) { max = AC; num = AB; num1 = BC; }
			if (BC > AB && BC > AC) { max = BC; num = AB; num1 = AC; }
			if (powl(max, 2) == powl(num, 2) + powl(num1, 2)) { printf("\nТвой треугольник прямоугольный."); }
			else { printf("\nТвой треугольник произвольный."); }

			break;
		case 3:
			P = AB + AC + BC;
			printf("\nПеримерт:%f", P);
			break;
		case 4:
			S = abs(0.5*((x1 - x3)*(y2 - y3) - (x2 - x3)*(y1 - y3)));
			printf("\nПлощадь:%f", S);
			break;
		case 5:
			p = (AB + AC + BC) / 2;
			R = (AB*AC*BC) / (4 * sqrt(p*(p - AB)*(p - AC)*(p - BC)));
			r = sqrt(((p - AB)*(p - AC)*(p - BC)) / p);
			printf("\nРадиус описанной:%f\nРадиус вписанной:%f", R, r);
			break;
		case 6:
			end = true;
			break;

		default:
			printf("\nПроверьте ввод и повторите попытку.\n");
			break;
		}
	}
	return 0;

}