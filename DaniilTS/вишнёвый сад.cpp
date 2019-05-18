#include <stdio.h>
#include <iostream.h>

int main()
{
	int X1,Y1,X2,Y2,PX,PY,PR,amount_of_trees, number_of_points,deltaX,deltaY;

	while (1)
	{
		cout << "bottom left corner:\nX1:";
		cin >> X1;
		cout << "Y1:";
		cin >> Y1;
		cout << "top right corner:\nX2:";
		cin >> X2;
		cout << "Y2:";
		cin >> Y2;
		if (X1==X2&&Y1==Y2)
		{
			system("cls");
			cout << "rectangle cannot be a point.\n";
			continue;
		}
		else if (X1==X2||Y1==Y2)
		{
			system("cls");
			cout << "Rectangle cannot be a straight.\n";
			continue;
		}
		else if (X2<X1||Y2<Y1)
		{
			system("cls");
			cout<<"Read the condition again,please.\n";
			continue;
		}
		cout << "coordinates of the water bottle:\nPX:";
		cin >> PX;
		cout << "PY:";
		cin >> PY;
		cout << "watering radius:\nPR:";
		cin >> PR;
		if (PR==0)
		{
			system("cls");
			cout << "irrigation radius cannot be zero.\n";
			continue;
		}
		break;
	}

	deltaX = (X2 - X1);
	deltaY = (Y2 - Y1);
	number_of_points = ( deltaX + 1 ) * ( deltaY + 1 ) ;
	cout << "The number of trees is:" << number_of_points;
	amount_of_trees = number_of_points;
	for (int i = X1; i <= X2; i++)
	{
		for (int j = Y1; j <= Y2; j++)
		{
			if (  powl(i-PX,2) + powl(j-PY,2) > powl(PR,2) )
			{
				number_of_points--;
			}
		}
	}

	cout << "\nAmount of trees without water: " <<amount_of_trees - number_of_points;

////////////////////////////////////////////////////////////////////////////////

	system("pause");
	return 0;
}
