//
//  main.c
//  lab3.2
//
//  Created by Katya Risunova on 4/4/19.
//  Copyright © 2019 Katya Risunova. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    const int n = 20;
    const int m = 20;
    int size;
    int a[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = rand() % 2;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++)
            printf ("%d ",a[i][j]);
        printf ("\n");
    }
    printf ("введите размер квадрата ");
    scanf ("%d",&size);
    int xk, yk, test = 0;
    for (int i = 0; i < n - size && test == 0; i++)
        for (int j = 0; j < m - size && test == 0; j++){
            if (a[i][j] == 0){
                test = 1;
                for (int k = 0; k < size; k++){
                    for (int l = 0; l < size; l++){
                        if (a[i + k][j + l] == 1)
                            test = 0;
                    }
                }
                if (test == 1){
                    xk = i;
                    yk = j;
                }
            }
        }
   
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (i >= xk   &&   i <= xk + size - 1   &&   j >= yk   &&   j <= yk + size - 1)
                printf ("A ");
            else
                printf ("%d ",a[i][j]);
        }
        printf ("\n");
    }
}
