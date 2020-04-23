//Задача: Разработать программу, меню которой позволяет выполнить след. функции:
//1. Ввод значения длины(километры, метры, сантиметры, миллиметры)
//2. Перевод длины в русские традиционные единицы(версты, аршины, сажени, вершки)
//3. Перевод длины в английские традиционные единицы( мили, ярды, футы, дюймы)
//4. Вывод отчета(километры, метры, сантиметры, миллиметры)
//5. Информация о версии проограммы и авторе
//6. Выход из программы

#include <stdlib.h>
#include <stdio.h>

float Enter(float metric)
{
    system("clear");
    printf("Choose:\n1. Kilometers\n2. Meters\n3. Centimeters\n4. Millimeters\n");
    char choice;
    scanf("%s", &choice);

    switch (choice) {
    case '1': {
        printf("\nInput: ");
        if (scanf("%f", &metric) != 1) {
            system("clear");
            printf("\nINCORRECT INPUT!\n");
            scanf("%c", &choice);
            return 0;
        }
        return metric * 1000.0;
    }; break;
    case '2': {
        printf("\nInput: ");
        if (scanf("%f", &metric) != 1) {
            system("clear");
            printf("\nINCORRECT INPUT!\n");
            scanf("%c", &choice);
            return 0;
        }
        return metric;
    }; break;
    case '3': {
        printf("\nInput: ");
        if (scanf("%f", &metric) != 1) {
            system("clear");
            printf("\nINCORRECT INPUT!\n");
            scanf("%c", &choice);
            return 0;
        }
        return metric * 0.01;
    }; break;
    case '4': {
        printf("\nInput: ");
        if (scanf("%f", &metric) != 1) {
            system("clear");
            printf("\nINCORRECT INPUT!\n");
            scanf("%c", &choice);
            return 0;
        }
        return metric * 0.001;
    }; break;
    default: {
        system("clear");
        printf("\n\nIncorrect input. Try again!\n");
        scanf("%c", &choice);
        return 0;
    }
    }
}

void Rus(float metric)
{ // Ф-ция перевода длины в русские традиционные единицы
    system("clear");
    printf("Transfer in Rus. Sys.:\n");
    printf("%s%f", "\nVersts:  ", (metric * 0.000937383));
    printf("%s%f", "\nSajen:  ", (metric * 0.4686914135733));
    printf("%s%f", "\nArshina:  ", (metric * 1.40607424071991));
    printf("%s%f", "\nVershok:  ", (metric * 22.49718785152));
    printf("\n");
    char choice;
    scanf("%s", &choice);
}

void Eng(float metric)
{ //Ф-ция перевода длины в английские традиционные единицы
    system("clear");
    printf("Transfer in Eng. Sys.:\n");
    printf("%s%f", "\nMile:  ", (metric * 0.000621371));
    printf("%s%f", "\nYard:  ", (metric * 1.09361296));
    printf("%s%f", "\nFoot:  ", (metric * 3.2808388799999997));
    printf("%s%f", "\nInch:  ", (metric * 39.370066559999997935));
    printf("\n");
    char choice;
    scanf("%s", &choice);
}

void Report(double metric)
{
    system("clear");
    printf("Report:");
    printf("%s%f", "\nKilometers:  ", (metric / 1000.0));
    printf("%s%f", "\nMeters:  ", (metric));
    printf("%s%f", "\nCentimeters:  ", (metric * 100));
    printf("%s%f", "\nMillimeters:  ", (metric * 1000));
    printf("\n");
    char choice;
    scanf("%s", &choice);
}

void Info(int i)

{
    system("clear");
    printf("Info:\n");
    printf("Version: 1.0\n");
    printf("Author: Student of the group #853503 Gromadtsov Vladislav Valerievich");
    printf("\n");
    char choice;
    scanf("%s", &choice);
}

int main()
{
    float metric = 0;
    char choice;
    for (;;) { //Вход в меню
        system("clear");
        printf("Menu:\n1. Enter\n2. Transfer in Rus\n3. Transfer in Eng\n4. Report\n5. Info\n6. Exit\n");
        scanf("%s", &choice);
        switch (choice) {
        case '1':
            metric = Enter(metric);
            break;
        case '2':
            Rus(metric);
            break;
        case '3':
            Eng(metric);
            break;
        case '4':
            Report(metric);
            break;
        case '5':
            Info(1);
            break;
        case '6':
            return 0;
            break;
        default: { // Исключение при работе с меню, при несуществующем выборе
            system("clear");
            printf("\n\nIncorrect input. Try again!\n");
            scanf("%s", &choice);
        }; break;
        }
    }
}
