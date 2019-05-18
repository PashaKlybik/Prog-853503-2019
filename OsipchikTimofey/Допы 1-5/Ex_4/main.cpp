#include <iostream>
#include <cmath>

//#include <ctime>
//#include <cstdlib>


int num_revrce(int num);
int changes(int num1, int num2, int num3);

int main()
{
    int coastA = 9999950, coastB = 100000000, price = 2;

    int count = 0;
    while(coastA <= coastB)
    {
        if (abs(coastA - num_revrce(coastA)) <= price)
        {
            //cout << num1 << '\t' << num_revrce(num1) << endl;
            count++;
        }
        coastA++;
    }
    std::cout << count;
    //cout << changes(coastA, coastB, price);

    //std::cout << std::endl << "runtime = " << clock()/1000.0;
    return 0;
}


int num_revrce(int num)
{
    int rev = 0;
    while(num)
    {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    return rev;
}

int changes(int num1, int num2, int num3)
{
    int count = 0;
    while(num1 <= num2)
    {
        if (abs(num1 - num_revrce(num1)) <= num3)
        {
            //cout << num1 << '\t' << num_revrce(num1) << endl;
            count++;
        }
        num1++;
    }
    return count;
}
