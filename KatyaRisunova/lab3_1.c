//
//  main.c
//  lab3.1
//
//  Created by Katya Risunova on 4/4/19.
//  Copyright © 2019 Katya Risunova. All rights reserved.
//

#include <stdio.h>
#include <time.h>

void print (int *a, int n)
{
    for (int i = 0; i < n; i++)
        printf ("%d ", a[i]);
    printf("\n");
}


int main(int argc, const char * argv[]) {
    const int n=30;
    int soldiers [n];
    for (int i = 0; i < n; i++)
        soldiers [i] = rand() % 2;
    for (int i = 0; i < n; i++)
        if (soldiers [i] == 0)
            soldiers [i] = 6;
    print (soldiers, n);
    int test = 1;
    while (test){
        int test2 = 0;
        for (int i = 0; i < n-1; i++)
            if (soldiers[i] == 6 && soldiers[i+1] == 1){
                soldiers [i] = 1;
                soldiers [i+1] = 6;
                i++;
                test2 = 1;
            }
        test = test2;
        if (test2)
            print (soldiers, n);
    }
}
