#include "main.h"

/**
 * find_function - helper function to find the corresponding specifier function
 * @specifiers: string of supported conversion specifiers
 * @functions: array of pointer to corresponding conversion specifier functions
 * @c: character representing a conversion specifier
 * Return: pointer to conversion specifier function or NULL if not supported
 */

print_func find_function(const char *specifiers, print_func *functions, char c)
{
	for (int i = 0; i < strlen(specifiers); i++)
	{
		if (specifiers[i] == c)
		{
			return (functions[0]);
		}
	}
	return ((print_func)NULL);
}

/**
 *_printf - prints formatted output to stdout
 *@format: format string containing conversion specifiers
 *@...: variable arguments corresponding to conversion specifiers
 *Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	const char *specifiers = "cds%";
	print_func functions[] = {&print_char, &print_int,
		&print_string, &print_percent};

	int printed_chars = 0;

	for (const char *p = format; *p != '\0'; p++)
	{
		if (*p == '%')
		{
			p++;
			print_func fn = find_function(specifiers, functions, *p);

			if (fn != NULL)
			{
				fn(args);
			}
			else
			{
				putchar('%');
				putchar(*p);
				printed_chars += 2;
			}
		}
			else
			{
				putchar(*p);
				printed_chars++;
			}
	}
	va_end(args);
	return (printed_chars);
}
