//
//  main.c
//  task5
//
//  Created by Yan Smaliak on 5/18/19.
//  Copyright © 2019 Yan Smaliak. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    int x1, x2, y1, y2, px, py, pr, count = 0;
    printf("X1: ");
    scanf ("%d", &x1);
    printf("Y1: ");
    scanf ("%d", &y1);
    printf("X2: ");
    scanf ("%d", &x2);
    printf("Y2: ");
    scanf ("%d", &y2);
    printf("Px: ");
    scanf ("%d", &px);
    printf("Py: ");
    scanf ("%d", &py);
    printf("Pr: ");
    scanf ("%d", &pr);
    
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            if (sqrt((i - px)*(i - px) + (j - py)*(j - py)) > pr) {
                count++;
            }
        }
    }
    printf ("Ответ: %d\n", count);
}
