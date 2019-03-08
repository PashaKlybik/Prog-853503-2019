#include <stdio.h>

void printfbinary (int x)
{
    int arr[50], i = 0;

    for (i; x >= 1; i++) {
        arr[i] = x % 2;
        x /= 2;
    }
    for (i; i > 0; i--) {
        printf("%d", arr[i - 1]);
    }
}

int main()
{
    int m, x = 7;

    printf("Enter m: ");
    scanf("%d", &m);

    printf("\nDecimal \tBinary\n");

    for (int i = 0; x < m; i++) {
        printf("\n%d\t\t", x);
        printfbinary(x);

        x <<= 3;
        if (i % 2 == 1) x += 7;
    }

    return 0;
}
