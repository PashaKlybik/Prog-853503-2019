/*
lab#2 task#9
*/

#include <stdio.h>

void output(double length_mm)
{
    system("clear");
    printf("Metric system:\n%g mm\n%g cm\n%g m\n%g km\n\n", length_mm, length_mm / 10, length_mm / 1000, length_mm / 10000);
    printf("Obsolete Russian system:\n%g vershok (tip)\n%g arshin (yard)\n%g sazhen (fathom)\n%g versta (turn)\n\n", length_mm / 44.45, length_mm / 711.2, length_mm / 21336, length_mm / 10668000);
    printf("English units:\n%g in\n%g yd\n%g ft\n%g mi\n\n", length_mm / 25.4, length_mm / 914.4, length_mm / 304.8, length_mm / 1609344);
}

int main()
{
    int control = 1;
    double input;

    while (control)
    {
        printf("Select an option from the list below:\n1. Input length in mm.\n2. Input length in cm.\n3. Input length in m.\n4. Input length in km.\n0. Exit.\n");
        scanf("%i", &control);
        system("clear");
        switch (control)
        {
        case 1:
            scanf("%lf", &input);
            output(input);
            break;
        case 2:
            scanf("%lf", &input);
            output(input * 10);
            break;
        case 3:
            scanf("%lf", &input);
             output(input * 1000);
            break;
        case 4:
            scanf("%lf", &input);
             output(input * 10000);
            break;
        case 0:
            return 0;
            break;
        default:
            printf("Incorrect input.");
            break;
        }
    }
}