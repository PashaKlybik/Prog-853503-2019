//
//  main.c
//  lab2_2
//
//  Created by Katya Risunova on 4/15/19.
//  Copyright © 2019 Katya Risunova. All rights reserved.
//

#include <stdio.h>

int NODrec (int n, int m)
{
    if (m == 0)
        return n;
    else
        return NODrec(m, n % m);
}

int NOD (int n, int m)
{
    int n1 = n;
    int m1 = m;
    while (m1 != 0)
    {
        int temp = m1;
        m1 = n1 % m1;
        n1 = temp;
    }
    return n1;
}

int main(int argc, const char * argv[]) {
    int n, m;
    printf("введите два числа\n");
    scanf("%d\n%d", &n, &m);
    if (m > n)
    {
        int temp = m;
        m = n;
        n = temp;
    }
    int nod1, nod2;
    nod1 = NODrec (n, m);
    nod2 = NOD (n, m);
    printf("c помощью рекурсии %d\nc помощью итерации %d\n", nod1, nod2);
}
