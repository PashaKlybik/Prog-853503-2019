#include <stdio.h>
#include <conio.h>
#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

void search(int k)
{
	int a;
	if (k%2==0)//���������� ����, ������� �������� ���������
	{
		a=k/2;
		a=a+10;
		a=a%10;//������ ������� �� �������, ������ �����, ������� �������� ���������
		printf("%d",a);//����� ���� ���������� ���������
	}
	else//���������� ����, ������� �������� ���������
	{
		k=k+1;//����� ������� ����� �����
		a=k/2;
		a=a+10;
		a=a/10;//������ �������, ������ �����, ������� �������� ���������
		printf("%d",a);//����� ����� ���������� ���������
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int k;
	while (1)
	{
		printf("Vvedite k-uy cifru, chto vi hotite naity:");
		scanf("%d",&k);
		if (k>=1&&k<=196)
		{
			search(k);//������� ������ � ������ �-��� ����� �� ������������������
			break;
		}
	}
	getch();
	return 0;
}
