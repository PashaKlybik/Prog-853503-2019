#include <stdio.h>
int main()
{
	FILE *input;
	input = fopen("input.txt","r");
	int x1,y1,x2,y2,x3,y3,r,result = 0;
	fscanf(input,"%i%i%i%i%i%i%i",&x1,&y1,&x2,&y2,&x3,&y3,&r);
	r*=r;
	for (int i = x1; i <= x2; i++)
		for (int j = y1; j <= y2; j++)
			if ((i-x3)*(i-x3)+(j-y3)*(j-y3) > r)
				result++;
	FILE * output = fopen("output.txt","w");
	fprintf(output,"%i",result);
	fclose(output);
	fclose(input);
	return 0;
}
