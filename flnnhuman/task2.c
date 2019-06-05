#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *Mod(int const *a, int size) {
    int *b = (int *) malloc(size * sizeof(int)), min = a[0];
    for (int i = 0; i < size; ++i) {
        if (a[i] < min) { min = a[i]; }
    }
    for (int i = 0; i < size; ++i) {
        b[i] = min - a[i];
    }
    return b;
}

int Sum(int const *a, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += a[i];
    }
    return sum;
}

int main() {
    int size, repeats;
    scanf("%d", &size);
    int *a = (int *) malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &repeats);
    for (int i = 0; i < repeats; ++i) {
        a = Mod(a, size);
    }
    printf("sum= %d", Sum(a, size));
    return 0;
}