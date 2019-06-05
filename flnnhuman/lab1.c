#include <stdio.h>


int main() {

        int c;
        while (1) {
            c = 8;
            printf("Enter your number\nNumber:");

            scanf("%d", &c);
            if (c <= 7) { printf("\nnumber should be more then 7!\n"); }
            else break;

        }
        int x = 0, y = 0, a = 3, b = 5;
        if (c % 5 == 0) {
            x = 0;
            y = c / 5;
        }
        else x = c / 3;

        while (1) {
            if ((x * a + y * b) == c) { break; }
            if ((x * a + y * b) == c - 2) {
                x--;
                y++;
                continue;
            }
            if ((x * a + y * b) == c - 1) {
                x += 2;
                y--;
                continue;
            }
            printf("\n%d", (x * a + y * b));
        }

        if (y < 0) {
            x = 0;
            y = c / 5;
            while (1) {
                if((x * a + y * b) == c - 4){
                    x+=3;
                    y--;
                    continue;
                }

                if ((x * a + y * b) == c - 3) {
                    x++;
                    continue;
                }

                if ((x * a + y * b) == c - 2) {y-=2;
                    x+=4;
                    continue;
                }

                if ((x * a + y * b) == c - 1) {
                    x += 2;
                    y--;
                    continue;
                }
                if ((x * a + y * b) == c) { break; }
            }
        }
        printf("\nYou will get \n%d 3's \n%d 5's", x, y);


    return 0;
}