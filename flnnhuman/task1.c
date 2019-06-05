#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int IsHappy(const char *str){
    bool noAnother=true, particularly = false;
    for (int i = 0; str[i]!=
    '\0'; ++i) {
        if(str[i]!='7' && str[i]!='4'){noAnother=false;}
        if (str[i]=='7' || str[i]=='4'){particularly=true;}
    }
    if(particularly) { return 1;}
    else return 0;


}

void HappyNumbers(int number){
    int counter =0;
    puts("dividers: ");
   for (int i = 1; i <= number /2; ++i) {
        if (number%i == 0){
            char temp_str[13];
            itoa(i,temp_str,10);
            counter+= IsHappy(temp_str);
            printf("%d ",i);

        }
    }

    printf("%d ",number);

    char temp_str[13];
    itoa(number,temp_str,10);
    counter+= IsHappy(temp_str);

    printf("\nhappy: %d",counter);


}

int main() {
    char str[13];
    printf("Program starts!\n");
    gets(str);
    HappyNumbers(strtol(str,(char **) NULL,10));

    return 0;
}