#include <stdio.h>
int main()
{
	FILE *input;
	input = fopen("input.txt","r");
	int size = 0, cycles = 0;
	if(input)
		fscanf(input,"%i",&size);
	else 
		return 0;
	int numbers[size];
	int min, tmpmin;
	fscanf(input,"%i",&min);
	numbers[0] = tmpmin = min;
	for	(int i = 1; i < size; i++)
	{
		fscanf(input,"%i",&numbers[i]);
		if(numbers[i]<min)
			min = numbers[i];
	}	
	fscanf(input,"%i",&cycles);
	for(int i = 0; i < cycles; i++)
	{
		for	(int j = 0; j < size; j++)
		{
			numbers[j]=min-numbers[j];
			if(numbers[j]<tmpmin)
				tmpmin = numbers[j];
				
		}
		min = tmpmin;
	}
	long int resultSum = 0;
	for (int i = 0; i < size; i++)
	{
		resultSum+=numbers[i];
	}
	FILE * output = fopen("output.txt","w");
	fprintf(output,"%li",resultSum);
	fclose(output);
	return 0;
}
