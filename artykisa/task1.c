//GNU nano 2.9.3 main.c 
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int main()
{
printf("Enter your number!\n");
long long int number;
int amount=0;
scanf("%lli", &number);
char buf[7];
for(long long int i=4;i<=number;i++){
if(number%i==0){
sprintf(buf, "%lli",i);
for(int j=0; buf[j]!='\0'; j++){
if(buf[j]=='4' || buf[j]=='7')
amount++;
}
}
}
printf("%d\n", amount);
return 0;
}
