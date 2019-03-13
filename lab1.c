/ * Вариант 22.
Найти все натуральные числа, не превосходящие заданного м,
двоичная запись
пар нулевой и единице (например: 11001100). Показать десятичную и
двоичную запись этих чисел. * /

# include  < stdlib.h >
# include  < stdio.h >
# include  < math.h >
# include  < string.h >
# include  < locale >
# include  < ctype.h >
# include  < Windows.h >
# include  < stdbool.h >

// Функция перевода числа из двоичной системы счисления в десятичную.
int  BinToDec ( long  int bin) {
	long  int dec = 0 ;
	для ( int i = 1 ; bin> 0 ; i * = 2 )
	{
		dec + = (bin% 10 ) * i;
		bin / = 10 ;
	}
	возврат декабрь;
}

// Функция перевода числа из десятичной системы счисления в двоичную.
int  DecToBin ( long  int dec) {
	long  int bin = 0 ;
	для ( int i = 0 ; dec> 0 ; i ++)
	{
		bin + = (dec% 2 ) * powl ( 10 , i);
		dec / = 2 ;
	}
	возвратный контейнер;
}

// Функция переводит переменные типа char в int.
int  CharToInt ( char array []) {
	long  int a = 0 ;
	for ( int i = 0 ; array [i]! = ' \ 0 ' ; i ++)
	{
		a = 10 * a + (array [i] - ' 0 ' );
	}
	вернуть ;
}

// функция проверяется
bool  IsNumeral ( char Numeral) {
	if (Numeral> = ' 0 ' && Numeral <= ' 9 ' ) {
		вернуть  истину ;
	}
	еще {
		вернуть  ложь ;
	}
}

// Функция проверяет правильность ввода.
int  InputCheck () {
	массив символов [ 100 ];
	gets_s (массив);
	для ( int i = 0 ; i < strlen (массив); i ++)
	{
		if ((array [ 0 ] == ' 0 ' ) || ( IsNumeral (array [i]) == false )) {
			printf ( " Число введено неправильно, пожалуйста, ввод. \ n " );
			return  InputCheck ();
		}
	}
	return  CharToInt (массив);
}

int  main ()
{
	// Русификация консоли.
	SetConsoleCP ( 1251 );
	SetConsoleOutputCP ( 1251 );

	long  int m, a, b = 11 , c;
	проверка bool = true ;

	printf ( " Введите число: " );
	m = InputCheck ();
	a = DecToBin (м);
	printf ( " Двоичная запись вашего числа: % d \ n " , a);
	c = BinToDec (b);
	// Поиск чисел удовлетворяющих условию.
	if (m <c) {
		printf ( " В пределах до % d численных удовлетворяющих условию не существует. \ n " , м);
	}
	еще {
		printf ( " искомые числа: \ n " );
		while (m> = c)
		{
			printf ( " \ n в десятичной: % d \ n в двоичной: % d \ n " , c, b);
			if (check == true ) {
				b = b * 100 ;
				проверка = ложь ;
			}
			еще {
				b = (b * 100 ) + 11 ;
				проверка = правда ;
			}
			c = BinToDec (b);
		}
	}
	вернуть  0 ;
}
