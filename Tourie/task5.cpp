#include <iostream>
using namespace std;

int main()
{
	int X1, Y1, X2, Y2;
	cout << "Enter size X1,Y1,X2,Y2:";
	cin >> X1 >> Y1 >> X2 >> Y2;
	int Px, Py, Pr;
	cout << "Enter coordinates and radius of water:";
	cin >> Px >> Py >> Pr;
	int count = 0;
	int dx, dy;
	for (int i = X1; i <= X2; i++)
	{
		for (int j = Y1; j <= Y2; j++)
		{
			dx = Px - i;
			dy = Py - j;
			if (Pr * Pr < dx * dx + dy * dy)
			{
				count++;
			}
		}
	}
	cout << count;
}
