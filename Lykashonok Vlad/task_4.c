#include <stdio.h>
int main()
{
	FILE *input;
	input = fopen("input.txt","r");
	int a,b,c,rev = 0,result = 0,p;
	fscanf(input,"%i",&a);
	fscanf(input,"%i",&b);
	fscanf(input,"%i",&c);

	for (int i = a; i <= b; i++)
	{
		a = i;
		rev = 0;
		while(a>0)
		{
			rev = rev*10 + a%10;
			a/=10;
		}
		p = (i-rev) > 0 ? i-rev:(i-rev)*(-1);
		if (p<=c)
			result++;		
	}
	FILE * output = fopen("output.txt","w");
	fprintf(output,"%i",result);
	fclose(output);

	fclose(input);
	return 0;
}
