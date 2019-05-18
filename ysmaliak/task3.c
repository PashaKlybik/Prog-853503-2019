//
//  main.c
//  task3
//
//  Created by Yan Smaliak on 5/17/19.
//  Copyright © 2019 Yan Smaliak. All rights reserved.
//

//check

#include <stdio.h>

int main(int argc, const char * argv[]) {
    const int str = 1000000;
    int a = 0, b = 0;
    char arr[str], newArr[str];
    printf("Введите строку: ");
    fgets(arr, str, stdin);
    for (int i = 0; i < str; i++) {
        if (arr[i] == '\n') {
            arr[i] = '\0';
            a = i;
            break;
        }
    }
    
    for (int i = 0; i < a; i++) {
        int k = 1;
        while(arr[i + k] == arr[i]) {
            k++;
        }
        if (k != 1) {
            newArr[b++] = k + '0';
        }
        newArr[b++] = arr[i];
        i += k - 1;
    }
    newArr[a] = '\0';
    printf("Cтрока после сжатия: %s\n", newArr);
}
