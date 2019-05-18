#include <stdio.h>
#include <math.h>
/*Три отрезка. Разработать программу, меню которой позволяет
пользователю выполнить следующие функции:
• Ввести координаты начала и конца трех отрезков в двумерном
пространстве.
• Определить, можно ли из этих отрезков составить треугольник.
• Если это возможно, то определить вид треугольника
(правильный, прямоугольный, равнобедренный, произвольного
вида).
• Вычислить периметр образованного треугольника.
• Вычислить площадь треугольника
• Информация о версии и авторе программы.
• Выход из программы */
double HalfPerimeter(double *lOne, double *lTwo, double *lThree)
{
    double p=((*lOne + *lTwo + *lThree) / 2);
    return p;
}
//применим формулу Герона для площади треугольника
//S=sqrt(p(p-a)(p-b)(p-c)) где a, b, c – длины сторон, а p– полупериметр
void Square(double *lOne, double *lTwo, double *lThree)
{
    double S = sqrt(HalfPerimeter(lOne, lTwo, lThree)*(HalfPerimeter(lOne, lTwo, lThree) - *lOne)*(HalfPerimeter(lOne, lTwo, lThree) - *lTwo)*(HalfPerimeter(lOne, lTwo, lThree) - *lThree));
    printf("\nSquare %f", S);
    return;
}
//2 стороны треугольника всегда больше третьей
int Possibility(double *lOne, double *lTwo, double *lThree)
{
    if (((*lOne + *lTwo) > *lThree) && ((*lTwo + *lThree) > *lOne) && ((*lOne + *lThree) > *lTwo))
    {return 1;}
    else
    {return 0;}
}
//стороны равны - правильный(equilateral)
//2 стороны равны - равнобедренный(isosceles)
//квадрат 2 сторон равен квадрату третьей - правильный(right)
//не один из вышеперечисленных - произвольный
void Type(double *lOne, double *lTwo, double *lThree)
{
    int pr = 0, ravnB = 0;
    double s1 = sqrt(pow(*lTwo, 2) + pow(*lThree, 2));
    double s2 = sqrt(pow(*lOne, 2) + pow(*lThree, 2));
    double s3 = sqrt(pow(*lTwo, 2) + pow(*lOne, 2));
    if (*lOne == s1 || *lTwo == s2 || *lThree == s3)
    pr = 1;
    if ((*lOne == *lTwo) || (*lTwo == *lThree) || (*lOne == *lThree))
    ravnB = 1;
    if (ravnB==1 && pr==1)
    {printf("\nisosceles and right triangle");}
    if (*lOne == *lTwo == *lThree)
    {printf("\nequilateral triangle");}
    else if (pr==1)
    {printf("\nright triangle");}
    else if (ravnB==1)
    {printf("\nisosceles triangle");}
    else
    {printf("\narbitrary triangle");}
    return;
}
double Check()
{
    long result = 0;
    while (1)
    {
        int wrongSymbol = 0;
        int length = 1;
        char ch, *str = (char*)malloc(length * sizeof(char));
        while ((ch = getchar()) != '\n')
        {
            str[length - 1] = ch;
            length++;
            str = (char*)realloc(str, length * sizeof(char));
        }
        str[length - 1] = '\0';
        for (int i = 0; i < length - 1; i++)
        {
            if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.' || str[i] == ',' || str[i] == '-')
            {
                continue;
            }
            else
            {
                printf("once again\n");
                str[0] = '\0';
                wrongSymbol = 1;
                break;
            }
        }
        if (!wrongSymbol)
        {
            result = atof(str);
            break;
        }
    }
    return result;
}

double Coordinates(double *x1, double *y1, double *x2, double *y2, int index)
{
    printf("beginning of %d line \nx:", index);
    *x1 = Check();
    printf("y:");
    *y1 = Check();
    printf("end of %d line ", index);
    printf("\nx:");
    *x2 = Check();
    printf("y:");
    *y2 = Check();
    return sqrt(pow((*x2 - *x1), 2) + pow((*y2 - *y1), 2));
}
int main()
{
    printf("Created by Barkouski, 853503\n");
    while (1)
    {
        double x1 = 0, y1 = 0, x2 = 0, y2 = 0, lOne = 0, lTwo = 0, lThree = 0;
        lOne = Coordinates(&x1, &y1, &x2, &y2, 1);
        lTwo = Coordinates(&x1, &y1, &x2, &y2, 2);
        lThree = Coordinates(&x1, &y1, &x2, &y2, 3);
        if (Possibility(&lOne, &lTwo, &lThree))
        {
            printf("\ntriangle can be created");
            Type(&lOne, &lTwo, &lThree);
            printf("\nPerimeter is: %f", lOne + lTwo + lThree);
            Square(&lOne, &lTwo, &lThree);
        }
        else
        {
            printf("\ntriangle can't be created");
        }
        printf("\nPress r to repeat, any other to exit\n");
        char ans;
        ans = _getch();
        if (ans != 82 && ans != 114)
        {
            printf("end.");
            return(0);
        }
    }
}
