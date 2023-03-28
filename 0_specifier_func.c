#include "main.h"

/**
 * print_char - implementation of the %c coversion specifier
 * @args: va_list containing the argument to print
 * Descript: Function prints character argument passed as parameter to stdout
 */

void print_char(va_list args)
{
	int value = va_arg(args, int);

	putchar(value);
}

/**
 * print_int - implementation of the %d conversion specifier
 * @args: va_list containing the argument to print
 * Descrpition: Function prints integer argument passed as parameter to stdout
 */

void print_int(va_list args)
{
	int value = va_arg(args, int);
	char buffer[20];
	int i = 0;

	if (value == 0)
	{
	putchar('0');

	return;

	}
	else if (value < 0)
	{
	putchar('-');
	value = -value;
	}
	while (value > 0)
	{
	buffer[i++] = value % 10 + '0';
	value /= 10;
	}
	while (i-- > 0)
	{
	putchar(buffer[i]);
	}
}

/**
 * print_string - implementation of the %s conversion specifier
 * @args: va_list containing the argument to print
 * Description: Function prints string argument passed as parameter to stdout
 */

void print_string(va_list args)
{
	char *str = va_arg(args, char *);

	while (*str)
	{
	putchar(*str);
	str++;
	}
}

/**
 * print_percent - implementation of the %% conversion specifier
 * @args: va_list containing the argument to print
 * Description: Function prints the percent sign to the stdout
 */

void print_percent(va_list args)
{
	putchar('%');
}
