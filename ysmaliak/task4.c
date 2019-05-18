//
//  main.c
//  task4
//
//  Created by Yan Smaliak on 5/18/19.
//  Copyright © 2019 Yan Smaliak. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int min, max, difference, count = 0;
    printf("S: ");
    scanf("%d", &min);
    printf("F: ");
    scanf("%d", &max);
    printf("K: ");
    scanf("%d", &difference);
    
    for (int i = min; i <= max; i++) {
        int sale = 0, price = i;
        while (price > 0) {
            sale = sale * 10 + price % 10;
            price = (price - price % 10) / 10;
        }
        if (abs(i - sale) <= difference) {
            count++;
        }
    }
    printf ("Ответ: %d\n", count);
}
