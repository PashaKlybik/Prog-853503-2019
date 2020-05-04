
#include <stdio.h>
int main()
{
	char line[1024];
	fgets(line, 100, stdin);
	char temp, curtemp=line[0];
	int num = 0;
	for (int i = 0; line[i] != '\0'; i++) {
		temp = line[i];
		if (temp == curtemp) {
			num++;
		}
		else {
			if (num>2) {
				printf("%d", num);
				printf("%c",curtemp);
				num = 1;
			}
			else {
				for (int i = 0; i < num; i++)
					printf("%c", curtemp);
				num = 1;
			}
		
		}
		curtemp = temp;
	}
	return 0;
}



