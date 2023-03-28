#include "print.h"

/* Implementation of the print_char specifier function */
void print_char(va_list args)
{
	int value = va_arg(args, int);

	putchar(value);
}

/* Implementation of the print_decimal specifier function */
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

/* Implementation of the print_string specifier function */
void print_string(va_list args)
{
	char *str = va_arg(args, char *);

	while (*str)
	{
	putchar(*str);
	str++;
	}
}

/* Implementation of the print_percent specifier function */
void print_percent(va_list args)
{
	putchar('%');
}
