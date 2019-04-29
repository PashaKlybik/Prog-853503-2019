#include <stdio.h>

void menu (int answer)
{
    printf("1-ввести промежуток времени работы\n2-вывод препдолагаемого кол-ва посителей, которые посетят в указанный промежуток времени\n3-расчет кол-ва ингридиентов и вывод общей стоимости заказа\n4-информация о стоимости\n5-расчет прибыли за указанный промежуток времени\n6-информация о версии и авторе программы\n7-выход из программы\n");
    answer=0;
    while (answer > 7 || answer < 1){
        scanf ("%d", &answer);
    }
}

void timeOfWork (int hours1, int minutes1, int hours2, int minutes2)
{
    
    while (hours1 < 9 || hours1 > 23){
        printf ("введите часы открытия\n");
        scanf ("%d", &hours1);
    }
    while (minutes1 < 0 || minutes1 > 59){
        printf ("введите минуты открытия\n");
        scanf ("%d", &minutes1);
    }
    while (hours2 < 9 || hours2 > 23){
        printf ("введите часы закрытия\n");
        scanf ("%d", &hours2);
    }
    while (minutes2 < 0 || minutes2 > 59){
        printf ("введите минуты закрытия\n");
        scanf ("%d", &minutes2);
    }
    printf ("\n\nпиццерия открылась в %d:%d и закрылась в %d:%d\n\n\n", hours1, minutes1, hours2, minutes2 );
}

int numberOfCustomers (int hours1, int minutes1, int hours2, int minutes2)
{
    int temp = hours1 + 1;
    int customers = 0;
    for (temp; temp < hours2; temp++){
        if (temp<13)
            customers += 5;
        else if (temp<18)
            customers += 14;
        else if (temp<23)
            customers += 42;
    }
    int a;
    if (hours1 < 13)
        a = 5;
    else if (hours1 < 18)
        a = 14;
    else  if (hours1 < 23)
        a = 42;
    a = a * (60 - minutes1) / 60;
    //printf("%d\n",a);
    int b;
    if (hours2 < 13)
        b = 5;
    else if (hours2 < 18)
        b = 14;
    else if (hours2 < 23)
        b = 42;
    customers = customers + b / 60 * minutes2;
    return customers;
}

void order ()
{
    int ham;
    int mushrooms;
    int vegetables;
    printf ("введите кол-во пицц\nс ветчинной: ");
    scanf ("%d", &ham);
    printf ("с грибами: ");
    scanf ("%d", &mushrooms);
    printf ("с овощами: ");
    scanf ("%d", &vegetables);
    int cost;
    cost = (90 * 7 * ham + 80 * 10 * mushrooms + 150 * 3 * vegetables + (ham + mushrooms + vegetables) * 150 * 1.5) * 4.5;
    printf("\n\nстоимость заказа: %d\n", cost);
    printf ("кол-во ветчины: %d гр.\nкол-во грибов: %d гр.\nкол-во овощей: %d гр.\nкол-во муки: %d гр.\n\n\n", ham * 90, mushrooms * 80, vegetables * 150, (ham + mushrooms + vegetables) * 150);
}

void price()
{
    printf ("\n\nстоимость пицц:\n");
    printf ("c ветчиной - %d\nс грибами - %d\nс овощами - %d\n\n", 3848, 4613, 3038);
}

void profit (int hours1, int minutes1, int hours2, int minutes2)
{
    int pr = (3848 + 4613 + 3038)* 0.1 * numberOfCustomers(hours1, minutes1, hours2, minutes2) / 3 ;
    printf ("\n\nприбыль за этот день %d\n\n", pr);
}



int main(int argc, const char * argv[]) {
    int hours1 = 0, minutes1 = 60, hours2 = 0, minutes2 = 60;
    int tme = 0;
    int answer = 0;
    while (answer != 7)
    {
        menu (answer);
        switch (answer)
        {
            case 1:  {
                if (tme){
                    hours1 = 0;
                    minutes1 = 0;
                    hours2 = 0;
                    minutes2 = 0;
                }
                timeOfWork(hours1, minutes1, hours2, minutes2);
                tme = 1;
                break;
            }
            case 2: {int number = 0;
                if (tme == 0){
                    printf("вы еще не ввели время\n");
                    break;
                }
                number = numberOfCustomers(hours1, minutes1, hours2, minutes2);
                printf ("\n\nпредпологаемое кол-во посетителей %d\n\n", number);
                break;
            }
            case 3:
                order();
                break;
            case 4:
                price();
                break;
            case 5:
                profit (hours1, minutes1, hours2, minutes2);
                break;
            case 6:
                printf("\n\nсоздатель этой программы RISA RISA developer\nверсия самая последняя\n\n");
                break;
        }
    }
    
}
