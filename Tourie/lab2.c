//Вариант 10
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Car
{
	double price;
	double year_of_issue;
	double engine_capacity;
	double distance;
	Car(double input_price, double input_year, double input_capacity, double input_distance)
	{
		price = input_price;
		year_of_issue = input_year;
		engine_capacity = input_capacity;
		distance = input_distance;
	}
};

int strlen(char* s);
bool TryStrToDouble(char* s);

int main()
{
	// ----------------------------------check input--------------------------------------
	do
	{
		double price_double;
		do
		{
			printf("Car cost in Europe:");
			char price[256];
			gets_s(price, 256);
			if (TryStrToDouble(price) && price != "" && price != "0")
			{
				price_double = atof(price);
				break;
			}
			else
			{
				printf("Incorrect input!\n");
			}
		} while (1);

		double year_double;
		do
		{
			printf("\nYear of issue:");
			char year[256];
			gets_s(year, 256);
			if (TryStrToDouble(year) && year != "" && year != "0")
			{
				year_double = atof(year);
				break;
			}
			else
			{
				printf("Incorrect input!\n");
			}
		} while (1);

		double capacity_double;
		do
		{
			printf("\nCapacity:");
			char capacity[256];
			gets_s(capacity, 256);
			if (TryStrToDouble(capacity) && capacity != "" && capacity != "0")
			{
				capacity_double = atof(capacity);
				break;
			}
			else
			{
				printf("Incorrect input!\n");
			}
		} while (1);

		double distance_double;
		do
		{
			printf("\nDistance:");
			char distance[256];
			gets_s(distance, 256);
			if (TryStrToDouble(distance) && distance != "" && distance != "0")
			{
				distance_double = atof(distance);
				break;
			}
			else
			{
				printf("Incorrect input!\n");
			}
		} while (1);
		// ----------------------------------------------end of input-------
		Car obj(price_double, year_double, capacity_double, distance_double); // creating an object of car

		double transit_cost = 0.5 * obj.distance;
		double release_cost = 0;
		if (obj.year_of_issue <= 3 || (obj.year_of_issue > 3 && obj.year_of_issue <= 10 && obj.engine_capacity >= 2500))
		{
			release_cost += 0.6 * obj.engine_capacity;
		}
		else if (obj.year_of_issue > 3 && obj.year_of_issue <= 10 && obj.engine_capacity < 2500)
		{
			release_cost += 0.35 * obj.engine_capacity;
		}
		else if (obj.year_of_issue > 10 && obj.year_of_issue < 14)
		{
			release_cost += 0.6 * obj.engine_capacity;
		}
		else if (obj.year_of_issue >= 14)
		{
			release_cost += 2 * obj.engine_capacity;
		}
		printf("Transfer: %f", transit_cost);
		printf("\nCost in Belarus: %f", release_cost);
		printf("\nTry again?(y)");
		char solution[10];
		gets_s(solution, 10);
		if (solution[0] != 'y' && solution[1] == '\0')
		{
			printf("\n");
			break;
		}
	} while (1);
	printf("version 1.0\n Author: Pundis Makar");
	return 0;
}

int strlen(char* s)
{
	int length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	return length;
}

bool TryStrToDouble(char* s)
{
	int length = strlen(s);
	int num_of_chars = 0;
	for (int i = 0; i < length; i++)
	{
		if (s[i] >= '1' || s[i] <= '9' || s[i] == '.' || s[i] == ',')
		{
			if (s[i] == '.' || s[i] == ',')
			{
				s[i] = '.';
				num_of_chars++;
			}
				
			if (num_of_chars > 1)
			{
				return false;
			}
			continue;
		}
		return false;
	}
	return true;
}
