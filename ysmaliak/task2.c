//
//  main.c
//  task2
//
//  Created by Yan Smaliak on 5/17/19.
//  Copyright © 2019 Yan Smaliak. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int *arr, size, numberOfCycles, sum = 0;
    printf("Размер массива: ");
    scanf ("%d", &size);
    arr = (int*)malloc(size * sizeof(int));
    printf("Введите элементы массива: ");
    
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf ("Количество циклов: ");
    scanf ("%d", &numberOfCycles);
    
    while (numberOfCycles > 0){
        int min = arr[0];
        for (int i = 1; i < size; i++) {
            if (min > arr[i]) {
                min = arr[i];
            }
        }
        for (int i = 0; i < size; i++) {
            arr[i] = min - arr[i];
        }
        numberOfCycles--;
    }

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    printf ("%d\n", sum);
}
