//
//  main.c
//  task1
//
//  Created by Yan Smaliak on 5/17/19.
//  Copyright © 2019 Yan Smaliak. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

int main() {
    int number, sum = 0;
    printf("Введите число: ");
    scanf("%d", &number);
    for (int i = 1; i <= number / 2; i++)
        if ((number % i) == 0) {
//            printf("%d ", i);
            int numberI = i;
            bool test = false;
            while (numberI != 0) {
                if ((numberI % 10) == 4 || (numberI % 10) == 7) {
                    test = true;
                }
                numberI = (numberI - (numberI % 10)) / 10;
            }
            if (test == true) {
                sum++;
            }
        }
    printf ("Почти счасливых делителей: %d\n", sum);
}
