/*
		������� 3.
��� �������. ����������� ���������, ���� �������
��������� ������������ ��������� ��������� �������:
- ������ ���������� ������ � ����� �������� � ��������� ������������
- ����������, ����� �� �� ���� �������� ��������� �����������
- ���� ��� ��������, ���������� ��� ������������
- ��������� �������� ������������� ������������
- ��������� ������� ������������� ������������
- ���������� � ������ � ������ ���������
- ����� �� ���������
*/

#include <iostream>
#include "functionHeader.h"

using namespace std;

int main()
{
	printf("Greetings. Let's start. Follow the text.\n");
	int choice;
	Points points[3];
	while (1)
	{
		cout << "\n1. Input sides' coordinates\n"
			 << "2. Existing check\n"
			 << "3. Triangle type\n"
			 << "4. Perimetre\n"
			 << "5. Square\n"
			 << "6. Version and author information\n"
			 << "7. Exit\n";
		
		cin >> choice;
		FinalOutput(points, choice);
		if (choice == 7)
			break;
		else
			cin.clear();
	}
	system("pause");
	return 0;
}