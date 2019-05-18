#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define VERSION 1
#define AUTHOR "Vlad Pesetski"

void UpdateInterface();

int GetRadius(int type);

void GetSurfArea(int radius);

void GetVolume(int radius);

void GetCustomArea(int radius);

void GetTetrahedron(int radius);

int main() {
    char ch;
    int radius = 0;
    while (1) {
        UpdateInterface();
        do {
            ch = getchar();

            if (ch == '\n') { continue; }   //пропуск '\n', чтобы не вылетада ошибка о некорректном вводе
            if (ch < 49 || ch > 55) { printf("invalid input.\ninput:"); }
        } while (ch < 49 || ch > 55);

        if (ch == '1') { radius = GetRadius(0); }
        if (ch == '2') { GetSurfArea(radius); }
        if (ch == '3') { GetVolume(radius); }
        if (ch == '4') { GetTetrahedron(radius); }
        if (ch == '5') { GetCustomArea(radius); }
        if (ch == '6') { printf("VERSION: %d\nAuthor:%s ", VERSION, AUTHOR); }
        if (ch == '7') { return 0; }
    }

}

void UpdateInterface() {
    printf("\n\n\n1. input radius\n"
           "2. get ball's surface area\n"
           "3. get ball's volume\n"
           "4. get size of side of inscribed tetrahedron\n"
           "5. get cross-sectional area, carried out at a distance k from the center of the ball\n"
           "6. version\n"
           "7. exit\n"
           "input:"
    );


}

int GetRadius(const int type) {  //принимает переменную инт, от которой зависит сообщение, которое будет выведено
    char str[13];
    char text[2][10]={"Radius = ","K = "};
    bool check;

    do {
        check = true;
    printf("\n%s",text[type]);

        scanf("%s", str);

        for (int i = 0; i < strlen(str); ++i) {
            if (str[i] < 48 || str[i] > 57)check = false;
        }
    } while (!check);
    return strtol(str, (char **) NULL, 10);
}

void GetSurfArea(const int radius) {
    printf("ball's surface area = %f\n", 4 * M_PI * radius * radius);
}

void GetVolume(const int radius) {
    printf("ball's Volume: %f\n", 4.0 / 3 * M_PI * pow(radius, 3));

}

void GetCustomArea(const int radius) {
    int k = GetRadius(1);
    if (k > radius) {
        printf("K should be more then Radius");
        return;
    }
    if (k == radius) {
        printf("Area = 0");
        return;
    }
    printf("area of circle with radius K = %f\n", M_PI * pow(sqrt(radius * radius - k * k), 2));
}

void GetTetrahedron(const int radius) {
    printf("Side = %f", radius * sin(M_PI / 3) * 2);

}