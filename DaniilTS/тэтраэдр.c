#include <tchar.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
   Тэтраэдр. Разработать программу, меню которой
   озволяет выполнить следующие функции:
   *  Ввод длины ребра тэтраэдра.
   *  Вывод общей длины всех рёбер тэтраэдра.
   *  Вывод площади всех граней тэтрадра.
   *  Вывод объёма тэтраэдра.
   *  Вывод высоты тэтраэдра.
   *  Вывод радиуса вписанного шара.
   *  Информация о версии и авторе программы.
   *  Выход из программы.
*/

float Edge;
void Length_for_tetrahedron(void);
void Length(void);
void total_S(void);
void v(void);
void height(void);
void rotib(void);
void Exit(void);
void Information(void)
{
	printf("///////////////////////////////////////////////////////////\n");
	printf("/ The program was prepared by a student of the 1st course,/\n");
	printf("/ The Faculty of Computer Systems and Networks,           /\n");
	printf("/ Of Speciality - Informatics and Programm technologies,  /\n");
	printf("/ Daniil Dzmitrievich Tsukrov.                            /\n");
	printf("/ Version of Program: 1.0.0                               /\n");
	printf("///////////////////////////////////////////////////////////\n");
}
void Menu(void)
{
	char ch;
	int Button;
	Information();
	start:
	printf("\n*****************************MENU****************************************\n");
	printf("*You can do the following things(write the number of the command to act):\n");
	printf("*(1)-enter the edge length\n*(2)-print the total length of edges\n");
	printf("*(3)-display the area\n*(4)-display the volume\n*(5)-display the height\n");
	printf("*(6)-display the Radius of the inscribed ball\n*(7)-Exit\n");
	printf("*************************************************************************\n");

	scanf("%c",&ch);

	if( (ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
	{
		printf("B");
	}
	else if( (ch>='0' && ch<='9'))
	printf("C");
	else
	printf("O");

	system("cls");
	switch(Button)
	{
		case 1:Length_for_tetrahedron();break;
		case 2:Length();break;
		case 3:total_S();break;
		case 4:v();break;
		case 5:height();break;
		case 6:rotib();break;
		case 7:Exit();break;
		default:
		{
			system("cls");
			printf("There is no such command.Please, try again.");
			goto start;
		}
	}
}
void Continue(void)
{
	char ch;
	here:
	printf("\nWould you like to continue your work?(Y/N)");
	scanf(" %c", &ch);
	switch(ch)
	{
		case 'Y':
		{
			system("cls");
			Menu();
			break;
		}

		case 'N':
		{
			Exit();
			break;
		}

		default:
		{
			system("cls");
			printf("There is no such command.Please try again.");
			goto here;
		}
	}
}

int main()
{
	Menu();
	return 0;
}

void Length_for_tetrahedron()
{
	here1:
	printf("Enter edge lengths for tetrahedron:\nEdge: ");
	scanf("%f", &Edge);
	if (Edge<=0)
	{
		system("cls");
		printf("Edge can not be less or equal to the zero. Please try again.\n");
		goto here1;
	}
	Continue();
}
void Length()
{
	float Total_length;
	Total_length = Edge * 6;
	printf("Total_length: %f", Total_length);
	Continue();
}
void total_S()
{
	float Total_S, Side_area;
	Total_S = ( powl(Edge,2) ) * sqrt(3);
	printf("Total S: %f", Total_S);
	Side_area = ( ( sqrt(3) ) * powl(Edge,2) ) / 4;
	printf("\nSide area: %f",Side_area);
	Continue();
}
void v()
{
	float V;
	V = ( powl(Edge,3) * sqrt(3) ) / 12;
	printf("Tetrahedron volume: %f", V);
	Continue();
}
void height()
{
	float Height;
	Height = ( (sqrt(2) ) / (sqrt(3) ) ) * Edge;
	printf("Height: %f", Height);
	Continue();
}
void rotib()
{
	float Radius_of_the_inscribed_ball;
	Radius_of_the_inscribed_ball = Edge / ( 2 * sqrt(6) );
	printf("Radius of the inscribed ball: %f", Radius_of_the_inscribed_ball );
	Continue();
}
void Exit()
{
	exit(1);
}